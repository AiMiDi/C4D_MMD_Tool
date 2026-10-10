"""Verify that the native runner's old-plugin preflight leaves C4D untouched."""
from pathlib import Path
import sys
import types
import unittest
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "scripts"))
from c4d_sizing_mcp_validation import SizingValidation
from test_adapter import envelope, native_result_data, temporary_directory
from mmdtool_mcp.schema import TOOLS


class PreflightTests(unittest.TestCase):
    def test_old_plugin_blocks_before_owning_or_mutating_documents(self):
        calls = []

        class Host:
            def initialize(self):
                pass

            def request(self, *args, **kwargs):
                raise AssertionError("Blocked preflight must not run native document helpers")

        class Client:
            def __init__(self, *args):
                pass

            def request(self, method, params):
                calls.append((method, params))
                if method == "tools/list":
                    return {"result": {"tools": TOOLS}}
                self_name = params["name"]
                if self_name != "mmdtool_capabilities":
                    raise AssertionError("Blocked preflight may only discover capabilities")
                data = native_result_data(self_name)
                data["supported_operations"] = [n for n in data["supported_operations"] if not n.startswith("mmdtool_sizing_")]
                return {"result": {"structuredContent": envelope(data=data)}}

            def close(self):
                pass

        with temporary_directory() as directory:
            args = types.SimpleNamespace(output=directory, endpoint="http://127.0.0.1:5556/mcp",
                                         token_file="not-read", timeout=60, expected_binary="not-read", build_cache=None)
            with patch("c4d_sizing_mcp_validation.HostConnection", return_value=Host()), patch(
                    "c4d_sizing_mcp_validation.StdioClient", Client):
                run = SizingValidation(args)
                run.execute()
                run.cleanup()
            self.assertEqual(run.receipt["status"], "blocked")
            self.assertFalse(run.receipt["native_executed"])
            self.assertFalse(run.owned)
            self.assertEqual(run.jobs, [])
            self.assertEqual(run.receipt["remaining_owned_documents"], [])
            self.assertEqual(len(calls), 2)


if __name__ == "__main__":
    unittest.main()
