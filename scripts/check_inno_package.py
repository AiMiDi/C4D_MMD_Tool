"""Compile and exercise a private copy of the maintained Inno template.

Optional installation exercises only generated hosts below the fresh fixture
directory, using a private AppId. It never discovers a real Cinema 4D install.
By default SDK payloads are distinct markers. --release-build-root instead uses
audited Release binaries and their built runtime files. Both modes keep private
installation paths and identities; neither accepts a public release or loads C4D.
"""

from pathlib import Path
import argparse
import hashlib
import json
import os
import re
import shutil
import subprocess
import uuid

REPO = Path(__file__).resolve().parents[1]
VERSIONS = {"R20": "sdk_r20", "R21": "sdk_r21", "S22": "sdk_r21",
            "R23": "sdk_r23", "S24": "sdk_r23", "R25": "sdk_r25", "S26": "sdk_r25",
            "2023": "sdk_2023", "2024": "sdk_2024", "2025": "sdk_2025", "2026": "sdk_2026"}
MCP_FILES = ("run_mmdtool_mcp.py", "mmdtool_mcp/__init__.py", "mmdtool_mcp/schema.py",
             "mmdtool_mcp/host.py", "mmdtool_mcp/server.py")


def identity(path):
    return {"path": str(path), "bytes": path.stat().st_size,
            "sha256": hashlib.sha256(path.read_bytes()).hexdigest()}


def run(arguments, log):
    result = subprocess.run([str(item) for item in arguments], capture_output=True,
                            text=True, encoding="utf-8", errors="replace", timeout=180,
                            creationflags=subprocess.CREATE_NO_WINDOW)
    log.write_text(result.stdout + result.stderr, encoding="utf-8")
    if result.returncode:
        raise RuntimeError(f"Exit {result.returncode}; inspect {log}")


def replace_once(text, pattern, replacement):
    changed, count = re.subn(pattern, lambda _: replacement, text, flags=re.MULTILINE)
    if count != 1:
        raise ValueError(f"Fixture adaptation expected one match, found {count}: {pattern}")
    return changed


def verify_payloads(root, payloads):
    count = 0
    for version, sdk in VERSIONS.items():
        installed = root / "hosts" / version / "plugins/CMT_Installer_Validation"
        for relative, expected in payloads[sdk].items():
            target = installed / relative
            if not target.is_file() or identity(target)["sha256"] != expected["sha256"]:
                raise AssertionError(f"Installed payload differs: {target}")
            count += 1
        if (installed / "mcp/tests").exists() or list((installed / "mcp").rglob("__pycache__")):
            raise AssertionError("Non-runtime adapter files installed")
        marker = root / "hosts" / version / "artist-scene.c4d"
        if marker.read_bytes() != b"preserve unrelated host content":
            raise AssertionError("Unrelated host content changed")
    return count


def check(compiler, root, exercise_install, release_build_root=None):
    if os.name != "nt":
        raise ValueError("Inno package validation requires Windows")
    compiler, root = compiler.resolve(), root.resolve()
    if not compiler.is_file() or compiler.name.lower() != "iscc.exe":
        raise ValueError("Provide the actual ISCC.exe compiler")
    temporary = Path("S:/tmp").resolve()
    if not root.is_relative_to(temporary) or root == temporary:
        raise ValueError("Private installer fixtures must be strictly below S:/tmp")
    release_audit = None
    if release_build_root is not None:
        from check_release_artifacts import inspect
        release_build_root = release_build_root.resolve()
        release_audit = inspect(release_build_root)
        if not release_audit["package_inputs_ready"]:
            raise ValueError("Release inputs failed audit; run check_release_artifacts.py for details")
    root.mkdir(parents=True, exist_ok=False)
    receipt = {"schema_version": 1, "status": "running", "compiler": identity(compiler),
               "fixture_root": str(root), "native_plugin_loaded": False,
               "release_installer_accepted": False, "installed": False,
               "uninstalled": False, "test_payloads": release_build_root is None, "checks": []}
    if release_audit is not None:
        (root / "release-inputs.json").write_text(json.dumps(release_audit, indent=2), encoding="utf-8")
        receipt["release_build_root"] = str(release_build_root)
    control = root / "installer-control"
    installed_once = False
    try:
        project = root / "project"
        shutil.copytree(REPO / "setup/Common", project / "setup/Common")
        shutil.copytree(REPO / "setup/Languages", project / "setup/Languages")
        script = project / "setup/Common/installer_script.iss"
        receipt["original_template"] = identity(REPO / "setup/Common/installer_script.iss")
        fixture_id = "{" + str(uuid.uuid4()).upper() + "}"
        text = script.read_text(encoding="utf-8")
        text = replace_once(text, r'^#define APP_GUID "[^"\r\n]+"$', f'#define APP_GUID "{fixture_id}"')
        # The shortcut precedes every registry lookup in GetInitInstallDir.
        shortcut = "begin\n  Result := '" + str(root / "hosts").replace("'", "''") + "\\' + ver;\n  Exit;\n  dir_valid := false;"
        text = replace_once(text, r"begin\r?\n  dir_valid := false;", shortcut)
        script.write_text(text, encoding="utf-8")
        common = project / "setup/Common/common_setup.iss"
        settings = common.read_text(encoding="utf-8")
        settings = replace_once(settings, r"^UninstallFilesDir=.*$", "UninstallFilesDir={app}")
        settings += "\n[Setup]\nPrivilegesRequired=lowest\n"
        common.write_text(settings, encoding="utf-8")
        payloads = {}
        for sdk in sorted(set(VERSIONS.values())):
            plugin = project / "_build_msvc" / sdk / "bin/Release/plugins/mmdtool"
            plugin.mkdir(parents=True)
            if release_build_root is not None:
                built = release_build_root / sdk / "bin/Release/plugins/mmdtool"
                shutil.copy2(built / "mmdtool.xdl64", plugin / "mmdtool.xdl64")
                shutil.copytree(built / "res", plugin / "res")
                shutil.copytree(built / "mcp", plugin / "mcp")
                audited = next(record for record in release_audit["sdks"] if record["sdk"] == sdk)
                for expected in (audited["binary"], *audited["resources"], *audited["adapter"]):
                    copied = plugin / Path(expected["path"]).relative_to(built)
                    if identity(copied)["sha256"] != expected["sha256"]:
                        raise AssertionError("Release input changed during copy: " + str(copied))
            else:
                # Distinct markers catch incorrect R/S SDK pairing during install.
                (plugin / "mmdtool.xdl64").write_bytes(("NON-PRODUCTION INNO FIXTURE " + sdk).encode())
                layout = "R20-S24" if sdk in ("sdk_r20", "sdk_r21", "sdk_r23") else "S24_up"
                shutil.copytree(REPO / "res" / layout, plugin / "res")
                if not (plugin / "res/cmt_config.json").exists():
                    shutil.copy2(REPO / "res/S24_up/cmt_config.json", plugin / "res/cmt_config.json")
                for relative in MCP_FILES:
                    target = plugin / "mcp" / relative
                    target.parent.mkdir(parents=True, exist_ok=True)
                    shutil.copy2(REPO / "mcp" / relative, target)
            payloads[sdk] = {}
            for path in sorted(plugin.rglob("*")):
                if path.is_file():
                    relative = path.relative_to(plugin).as_posix()
                    if relative == "mmdtool.xdl64": relative = "MMDTool.xdl64"
                    payloads[sdk][relative] = identity(path)
        (root / "payloads.json").write_text(json.dumps(payloads, indent=2), encoding="utf-8")
        for version in VERSIONS:
            host = root / "hosts" / version
            host.mkdir(parents=True)
            (host / "Cinema 4D.exe").write_bytes(b"private fixture host marker; not executable")
            (host / "artist-scene.c4d").write_bytes(b"preserve unrelated host content")
        run(["pwsh", "-NoProfile", "-File", REPO / "cmake/prepare_installer_resources.ps1",
             "-ProjectRoot", project], root / "adapt.log")
        receipt["adapted_template"] = identity(script)
        output = root / "compiled"
        output.mkdir()
        run([compiler, "/Qp", "/O" + str(output), "/FCMT_Installer_Validation",
             "/DPluginName=CMT_Installer_Validation", "/DPluginNameUnderlined=CMT_Installer_Validation",
             "/DPluginVersion=0.0.0.0", script], root / "compile.log")
        installer = output / "CMT_Installer_Validation.exe"
        receipt["installer"] = identity(installer)
        receipt["checks"].append("Maintained template compiled by actual ISCC with paired resources/MCP")
        if exercise_install:
            arguments = [installer, "/VERYSILENT", "/SUPPRESSMSGBOXES", "/NORESTART", "/SP-",
                         "/CURRENTUSER", "/NOICONS", "/NOCLOSEAPPLICATIONS", "/NORESTARTAPPLICATIONS",
                         "/DIR=" + str(control)]
            # From here the finally block also cleans a partially completed install.
            installed_once = True
            run(arguments + ["/LOG=" + str(root / "install-native.log")], root / "install-command.log")
            receipt["installed"] = True
            receipt["installed_file_checks"] = verify_payloads(root, payloads)
            receipt["checks"].append("All 11 components install their matching eight SDK fixture payloads")
            stale = root / "hosts/R20/plugins/CMT_Installer_Validation/obsolete.txt"
            stale.write_bytes(b"stale plugin fixture")
            run(arguments + ["/LOG=" + str(root / "upgrade-native.log")], root / "upgrade-command.log")
            if stale.exists(): raise AssertionError("Upgrade retained stale plugin file")
            verify_payloads(root, payloads)
            receipt["checks"].append("Repeat install removes stale plugin content and preserves unrelated host files")
        receipt["status"] = "passed"
    except Exception as error:
        receipt["status"], receipt["error"] = "failed", str(error)
        raise
    finally:
        if installed_once:
            uninstaller = control / "unins000.exe"
            try:
                if not uninstaller.resolve().is_relative_to(root):
                    raise AssertionError("Uninstaller outside private fixture")
                if not uninstaller.is_file(): raise AssertionError("Private uninstaller missing")
                run([uninstaller, "/VERYSILENT", "/SUPPRESSMSGBOXES", "/NORESTART",
                     "/LOG=" + str(root / "uninstall-native.log")], root / "uninstall-command.log")
                for version, sdk in VERSIONS.items():
                    plugin = root / "hosts" / version / "plugins/CMT_Installer_Validation"
                    if any((plugin / name).exists() for name in payloads[sdk]):
                        raise AssertionError(f"Installed files survived uninstall: {plugin}")
                    if (root / "hosts" / version / "artist-scene.c4d").read_bytes() != b"preserve unrelated host content":
                        raise AssertionError("Uninstall changed unrelated host content")
                receipt["uninstalled"] = True
                receipt["checks"].append("Private uninstall removes installed payloads and preserves unrelated host files")
            except Exception as error:
                receipt["status"], receipt["cleanup_error"] = "failed", str(error)
        (root / "receipt.json").write_text(json.dumps(receipt, indent=2, ensure_ascii=False), encoding="utf-8")
    if receipt["status"] != "passed": raise RuntimeError(f"Validation failed; inspect {root / 'receipt.json'}")
    return receipt


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--compiler", required=True, type=Path)
    parser.add_argument("--output", required=True, type=Path, help="A new fixture directory below S:/tmp")
    parser.add_argument("--exercise-install", action="store_true")
    parser.add_argument("--release-build-root", type=Path,
                        help="Use audited real Release modules/runtime instead of marker payloads")
    args = parser.parse_args()
    print(json.dumps(check(args.compiler, args.output, args.exercise_install, args.release_build_root),
                     indent=2, ensure_ascii=False))
