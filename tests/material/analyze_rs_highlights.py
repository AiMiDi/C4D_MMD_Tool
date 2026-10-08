"""Offline checks for native_rs_highlight_test receipts and RGBA PNGs.

No host calls. Pillow is needed only by the command-line PNG reader. Thresholds
describe a fixed diagnostic scene, not an MMD reference or a calibrated BRDF.
"""
from dataclasses import asdict, dataclass
from pathlib import Path
import argparse
import hashlib
import json
import math
import re

PROFILE = "ordinary-rs-highlight-v1"
CASES = {"white_broad": ([1., 1., 1.], 2.), "white_narrow": ([1., 1., 1.], 510.),
         "red": ([1., 0., 0.], 30.), "zero": ([0., 0., 0.], 30.)}


@dataclass(frozen=True)
class Limits:
    min_foreground_fraction: float = .10
    min_white_peak: float = .04
    max_narrow_area_ratio: float = .75
    min_red_dominance: float = 3.
    max_zero_absolute: float = 2. / 255.
    max_zero_relative: float = .02
    max_repeat_mae: float = 2. / 255.
    max_device_mae: float = 4. / 255.
    max_device_p99: float = 12. / 255.


def read_png(path):
    from PIL import Image
    with Image.open(path) as image:
        if image.format != "PNG" or image.mode != "RGBA":
            raise ValueError("Expected an RGBA PNG with preserved coverage")
        width, height = image.size
        if width > 1024 or height > 1024:
            raise ValueError("Diagnostic image exceeds the supported resolution")
        pixel_data = image.get_flattened_data() if hasattr(image, "get_flattened_data") else image.getdata()
        return width, height, [tuple(channel / 255. for channel in pixel)
                               for pixel in pixel_data]


def measure(image, limits):
    width, height, pixels = image
    if width < 16 or height < 16 or width * height != len(pixels):
        raise ValueError("Invalid image dimensions or pixel count")
    if any(len(p) != 4 or any(not math.isfinite(v) or not 0 <= v <= 1 for v in p) for p in pixels):
        raise ValueError("Pixels must contain finite normalized RGBA")
    opaque = [i for i, p in enumerate(pixels) if p[3] >= .99]
    if len(opaque) / len(pixels) < limits.min_foreground_fraction:
        raise ValueError("Insufficient foreground coverage; blank or transparent render")
    # Fixed central disk avoids sphere silhouette/Fresnel and alpha edges.
    radius = min(width, height) * .30
    region = [i for i in opaque if ((i % width + .5 - width / 2) ** 2
                                   + (i // width + .5 - height / 2) ** 2) <= radius ** 2]
    if len(region) < .10 * len(pixels):
        raise ValueError("Sphere is missing from the fixed central region")
    levels = [max(pixels[i][:3]) for i in region]
    peak = max(levels)
    half_area = sum(value >= peak * .5 for value in levels) if peak else 0
    rgb = [sum(pixels[i][channel] for i in region) / len(region) for channel in range(3)]
    return {"coverage": len(opaque) / len(pixels), "peak": peak,
            "half_peak_area": half_area, "mean_rgb": rgb}, region


def differences(first, second, region):
    if first[:2] != second[:2]:
        raise ValueError("Comparison dimensions differ")
    values = sorted(abs(first[2][i][c] - second[2][i][c]) for i in region for c in range(3))
    return {"mae": sum(values) / len(values), "p99": values[int(.99 * (len(values) - 1))],
            "alpha_max": max(abs(a[3] - b[3]) for a, b in zip(first[2], second[2]))}


def analyze(directory, *, loader=read_png, limits=Limits(), compare_devices=False):
    directory = Path(directory)
    report = {"status": "failed", "profile": PROFILE, "limits": asdict(limits),
              "limits_calibrated_against_native_mmd": False, "native_mmd_fidelity_accepted": False,
              "backend_execution_verified": False, "checks": [], "images": [], "errors": []}
    report["device_comparison_required"] = compare_devices

    def check(name, passed, **observed):
        report["checks"].append(dict(name=name, passed=bool(passed), **observed))

    try:
        identity = json.loads((directory / "identity.json").read_text(encoding="utf-8-sig"))
        if not isinstance(identity, dict) or not isinstance(identity.get("module"), dict):
            raise ValueError("Invalid identity document")
        report["identity"] = identity
        if identity.get("fixture_profile") != PROFILE:
            raise ValueError("Missing or incompatible fixture profile")
        module_hash = identity.get("module", {}).get("sha256", "")
        if not re.fullmatch(r"[a-fA-F0-9]{64}", module_hash):
            raise ValueError("Missing loaded module SHA-256")
        if identity.get("view_transform_baked") is not False:
            raise ValueError("Unknown or baked view transform; cannot use this profile")
        cleanup = json.loads((directory / "cleanup.json").read_text(encoding="utf-8-sig"))
        if not isinstance(cleanup, dict):
            raise ValueError("Invalid cleanup document")
        check("cleanup", not cleanup.get("errors", ["missing"]) and
              cleanup.get("remaining_owned_documents") == [] and
              all(cleanup.get(key) is True for key in (
                  "original_document_restored", "devices_restored", "hybrid_restored")))
        rows = json.loads((directory / "renders.json").read_text(encoding="utf-8-sig"))
        groups, labels, baselines = {}, set(), {}
        for row in rows:
            label, device, case = row["label"], row["device"], row["case"]
            if not re.fullmatch(r"[a-zA-Z0-9_-]+", label) or label in labels:
                raise ValueError("Duplicate or invalid render label")
            labels.add(label)
            if device not in ("cpu", "gpu") or case not in CASES:
                raise ValueError("Unknown device or case")
            color, power = CASES[case]
            if row.get("specular_color") != color or row.get("specular_power") != power:
                raise ValueError("Recorded material inputs differ from case profile: " + label)
            if row.get("status") != "rendered_pending_analysis" or row.get("error") is not None or row.get("result") != 0:
                raise ValueError("Failed or unfinished render: " + label)
            selected = [name for name, enabled in row.get("devices", []) if enabled]
            if not selected or any(("CPU" in name) != (device == "cpu") for name in selected):
                raise ValueError("Requested and selected devices disagree: " + label)
            # Resolve archived evidence locally, not the original absolute path.
            path = directory / (label + ".png")
            digest = hashlib.sha256(path.read_bytes()).hexdigest()
            if digest != row.get("sha256"):
                raise ValueError("Image hash mismatch: " + label)
            image = loader(path)
            if list(image[:2]) != identity.get("resolution"):
                raise ValueError("Image resolution differs from identity")
            metrics, region = measure(image, limits)
            report["images"].append(dict(label=label, sha256=digest, **metrics))
            groups.setdefault((device, case), []).append((row, image, metrics, region))
        devices = sorted({device for device, case in groups})
        if not devices:
            raise ValueError("No completed render cases")
        if compare_devices and devices != ["cpu", "gpu"]:
            raise ValueError("Device comparison requires both CPU and GPU results")
        report["render_devices"] = devices
        for device in devices:
            if any((device, case) not in groups for case in CASES):
                raise ValueError("Incomplete case matrix for " + device)
            base = {}
            for case in CASES:
                entries = [item for item in groups[device, case] if not item[0].get("reopen")]
                if not entries:
                    raise ValueError("Missing non-reopened baseline: " + device + "/" + case)
                base[case] = entries[0]
                baselines[device, case] = entries[0]
            broad, narrow, red, zero = [base[case][2] for case in CASES]
            check(device + "/visible_highlight", min(broad["peak"], narrow["peak"]) >= limits.min_white_peak)
            area_ratio = narrow["half_peak_area"] / max(1, broad["half_peak_area"])
            check(device + "/power_narrows_highlight", area_ratio <= limits.max_narrow_area_ratio,
                  half_peak_area_ratio=area_ratio)
            r, g, b = red["mean_rgb"]
            check(device + "/red_highlight", red["peak"] >= limits.min_white_peak and
                  r >= limits.min_red_dominance * max(g, b, 1. / 255.), mean_rgb=red["mean_rgb"])
            ceiling = max(limits.max_zero_absolute, limits.max_zero_relative * narrow["peak"])
            check(device + "/zero_highlight", zero["peak"] <= ceiling, peak=zero["peak"], ceiling=ceiling)
            repeats = [item for item in groups[device, "white_narrow"]
                       if not item[0].get("reopen")][1:]
            reopens = [item for item in groups[device, "white_narrow"] if item[0].get("reopen") is True]
            for name, items in (("repeat", repeats), ("reopen", reopens)):
                if not items:
                    raise ValueError("Missing " + name + " for " + device)
                for item in items:
                    delta = differences(base["white_narrow"][1], item[1], base["white_narrow"][3])
                    check(device + "/" + name + "/" + item[0]["label"],
                          delta["mae"] <= limits.max_repeat_mae and delta["p99"] <= 3 * limits.max_repeat_mae
                          and delta["alpha_max"] <= 1. / 255., **delta)
        for case in CASES if compare_devices else ():
            cpu, gpu = baselines["cpu", case], baselines["gpu", case]
            delta = differences(cpu[1], gpu[1], cpu[3])
            check("requested_device_comparison/" + case,
                  delta["mae"] <= limits.max_device_mae and delta["p99"] <= limits.max_device_p99
                  and delta["alpha_max"] <= 1. / 255., **delta)
        if all(item["passed"] for item in report["checks"]):
            report["status"] = "response_checks_passed"
    except (OSError, ValueError, KeyError, TypeError, IndexError, ImportError) as error:
        report["errors"].append(str(error))
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("directory", type=Path)
    parser.add_argument("--output", type=Path, required=True, help="New report file; never overwrites receipts")
    parser.add_argument("--compare-devices", action="store_true", help="Also require and compare CPU/GPU matrices")
    args = parser.parse_args()
    report = analyze(args.directory, compare_devices=args.compare_devices)
    with args.output.open("x", encoding="utf-8") as stream:
        json.dump(report, stream, indent=2, allow_nan=False)
    print(report["status"])
    return 0 if report["status"] == "response_checks_passed" else 1


if __name__ == "__main__":
    raise SystemExit(main())
