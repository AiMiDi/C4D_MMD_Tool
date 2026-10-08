"""Use the maintained production bridge for native fixture import/export.

This is test infrastructure, not an additional public MCP tool. It works with
normal Release modules and never enables the optional runtime regression bridge.
"""

import contextlib
import io
from pathlib import Path
import sys
import uuid

from c4d_runtime_regression import Suite

sys.path.insert(0, str(Path(__file__).resolve().parents[1] / "mcp"))
from mmdtool_mcp.host import fixed_host_code


def production_suite(c4d, manifest, *, import_options=None):
    class ProductionSuite(Suite):
        def production_call(self, name, arguments):
            namespace = {}
            with contextlib.redirect_stdout(io.StringIO()):
                exec(fixed_host_code(name, arguments, str(uuid.uuid4())), namespace)
            result = namespace["_result"]
            self.assert_true(result["success"], str(result))
            return result["data"]

        def call(self, action, path="", expected=True, **settings):
            if not expected or settings:
                raise ValueError("Native fixture helper supports basic import/export only")
            c4d.documents.SetActiveDocument(self.doc)
            capabilities = self.production_call("mmdtool_capabilities", {})
            if action == "hello":
                return capabilities
            document = next(item["handle"] for item in capabilities["documents"] if item["active"])
            if action == "import_model":
                result = self.production_call("mmdtool_import_pmx", {"document": document,
                    "path": str(path), "position_multiple": 1., **(import_options or {})})
                models = self.nodes(1056724)
                self.assert_true(len(models) == 1, "Expected one fixture model")
                self.doc.SetActiveObject(models[0], c4d.SELECTION_NEW)
                return result
            if action == "export_model":
                models = self.production_call("mmdtool_list_models", {"document": document})["models"]
                self.assert_true(len(models) == 1, "Expected one fixture model")
                return self.production_call("mmdtool_export_pmx", {"document": document,
                    "model": models[0]["handle"], "path": str(path), "position_multiple": 1., "overwrite": True})
            raise ValueError("Unsupported native fixture action: " + action)

    return ProductionSuite(c4d, manifest)
