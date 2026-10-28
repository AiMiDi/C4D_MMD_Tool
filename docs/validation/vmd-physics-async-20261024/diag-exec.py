"""t52 诊断：把本地 python 片段送进真实宿主执行（复用 host-driver 的连接/解析逻辑）。

用法：python diag-exec.py --file <script.py> [--timeout 120]
输出：HOST_STDOUT_BEGIN/END + DRIVER_RESULT:{json}
"""
import argparse
import json
import pathlib
import sys

RESTORE = pathlib.Path(__file__).resolve().parent.parent / "vmd-host-restore-20261024"
sys.path.insert(0, str(RESTORE))
import importlib

driver = importlib.import_module("host-driver")


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--file", required=True)
    parser.add_argument("--timeout", type=float, default=120.0)
    args = parser.parse_args()

    code = pathlib.Path(args.file).read_text(encoding="utf-8")
    result = driver.run_host_code(code, timeout=int(args.timeout),
                                  tolerate_error_with_stdout=True)
    stdout = result.get("stdout", "") or ""
    print("HOST_STDOUT_BEGIN")
    print(stdout.rstrip())
    print("HOST_STDOUT_END")
    print("DRIVER_RESULT:" + json.dumps({"elapsed_s": result.get("elapsed_s"),
                                        "teardown_error": result.get("teardown_error")},
                                       ensure_ascii=False))
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
