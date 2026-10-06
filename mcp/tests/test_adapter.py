"""Protocol/transport fixtures run without Cinema 4D or real credentials."""

from __future__ import annotations

from contextlib import redirect_stdout
import hashlib
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import io
import json
import math
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import types
import unittest
import uuid
from unittest.mock import patch

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from mmdtool_mcp.host import HostConnection, HostError, RESULT_MARKER, error_envelope, fixed_host_code, validate_endpoint
from mmdtool_mcp.schema import OPTION_IDS, TOOLS, TOOL_BY_NAME, ValidationError, validate, validated_arguments
from mmdtool_mcp.server import Adapter, StdioServer


def envelope(operation_id="", data=None):
    return {"success": True, "code": "ok", "message": "", "operation_id": operation_id,
            "state": "completed", "data": data or {}, "warnings": []}


def native_result_data(name, arguments=None):
    """Dispatcher result shapes, including the fixed bridge's export identity."""
    arguments = arguments or {}
    model = {"handle": "model-1", "name": "阿芙", "mode": "edit",
             "physics_enabled": True, "bone_count": 4, "morph_count": 1, "slot_count": 1}
    slots = {"slots": [{"handle": "model-1:slot:1", "name": "动作", "max_frame": 30, "active": True}],
             "active_slot": "model-1:slot:1", "total": 1, "next_offset": -1}
    exported = {"path": r"C:\fixtures\export.pmx", "bytes": 16, "size": 16, "sha256": "0" * 64}
    samples = {
        "mmdtool_capabilities": {
            "protocol_version": 1, "plugin_version": "production-api-1", "host_version": 2026400,
            "host_session": "fixture-session", "supported_operations": list(TOOL_BY_NAME),
            "documents": [{"handle": "doc-1", "name": "test", "active": True}],
            "cameras": [{"handle": "camera-1", "document": "doc-1", "name": "Camera", "type": "ordinary"}],
            "retention_seconds": 900, "record_capacity": 256, "max_page_size": 256,
            "max_input_bytes": 256 * 1024 * 1024, "transport_supported": True,
            "material_types": ["standard"], "execution": "synchronous-main-thread"},
        "mmdtool_list_models": {"models": [model], "total": 1, "next_offset": -1},
        "mmdtool_inspect_model": {"model": model, "items": [], "total": 0, "next_offset": -1},
        "mmdtool_import_pmx": {"model": model},
        "mmdtool_export_pmx": exported,
        "mmdtool_import_motion": {"slot": "model-1:slot:1", "bone_count": 4, "morph_count": 1,
                                  "frame_count": 30, "unmatched_bones": [], "unmatched_morphs": []},
        "mmdtool_export_motion": exported,
        "mmdtool_import_camera": {"camera": "camera-1", "frame_count": 2},
        "mmdtool_export_camera": exported,
        "mmdtool_list_animation_slots": slots,
        "mmdtool_select_animation_slot": {"active_slot": "model-1:slot:1"},
        "mmdtool_set_mode": {"mode": arguments.get("mode", "anim")},
        "mmdtool_set_physics_enabled": {"physics_enabled": arguments.get("enabled", True)},
        "mmdtool_set_morph_strength": {"morph_handle": "model-1:morph:1", "strength": 0.5},
        "mmdtool_evaluate_frame": {"frame": 30, "unit": "vmd_frames", "seconds": 1,
                                   "fps": 30, "finite": True, "bone_count": 4},
        "mmdtool_operation_status": {"operation": envelope("original", {"mode": "anim"})},
    }
    if name == "mmdtool_inspect_model" and arguments.get("section") == "slots":
        return slots
    return samples[name]


def temporary_directory():
    configured = os.environ.get("CMT_TEST_TEMP_DIR")
    temporary_root = Path(configured) if configured else Path(r"S:\tmp") if os.name == "nt" else Path(tempfile.gettempdir())
    temporary_root.mkdir(parents=True, exist_ok=True)
    result = tempfile.TemporaryDirectory(prefix="cmt-mcp-test-", dir=temporary_root)
    # Verify the resolved recursive-cleanup target is a child of our explicitly
    # chosen fixture workspace before unittest takes ownership of cleanup.
    if temporary_root.resolve() not in Path(result.name).resolve().parents:
        raise RuntimeError("Unsafe fixture directory")
    return result


class FakeHost:
    def __init__(self):
        self.calls = []
        self.initialize_count = 0
        self.host_session = "fixture-session"
        self.fail_next = None
        self.results = {}

    def initialize(self):
        self.initialize_count += 1

    def call_production(self, name, arguments, operation_id, *, may_mutate=False):
        self.calls.append((name, arguments, operation_id, may_mutate))
        if name == "mmdtool_capabilities":
            data = native_result_data(name)
            data["host_session"] = self.host_session
            return envelope(operation_id, data)
        if self.fail_next:
            failure, self.fail_next = self.fail_next, None
            raise failure
        if name == "mmdtool_operation_status":
            original = self.results.get(arguments["query_operation_id"])
            return envelope(operation_id, {"operation": original}) if original else error_envelope(
                "outcome_unknown", "Record missing", operation_id, outcome_unknown=True)
        result = envelope(operation_id, native_result_data(name, arguments))
        self.results[operation_id] = result
        return result


class SchemaTests(unittest.TestCase):
    def test_completed_results_match_native_shapes_and_require_success_data(self):
        for name, definition in TOOL_BY_NAME.items():
            with self.subTest(tool=name):
                validate(envelope("fixture", native_result_data(name)), definition["outputSchema"])
                with self.assertRaises(ValidationError):
                    validate(envelope("fixture", {}), definition["outputSchema"])

    def test_inspection_accepts_native_slot_and_model_response_alternatives(self):
        definition = TOOL_BY_NAME["mmdtool_inspect_model"]["outputSchema"]
        for section in ("summary", "bones", "morphs", "slots"):
            with self.subTest(section=section):
                data = native_result_data("mmdtool_inspect_model", {"section": section})
                validate(envelope("fixture", data), definition)
                data.pop("next_offset")
                with self.assertRaises(ValidationError):
                    validate(envelope("fixture", data), definition)
        validate(envelope("fixture", {"slots": [], "active_slot": "", "total": 0, "next_offset": -1}), definition)

    def test_noncompleted_and_failed_envelopes_do_not_require_success_data(self):
        for name, definition in TOOL_BY_NAME.items():
            for success, state in ((True, "queued"), (True, "running"),
                                   (False, "failed"), (False, "outcome_unknown")):
                with self.subTest(tool=name, state=state):
                    validate({**envelope("fixture"), "success": success, "state": state}, definition["outputSchema"])
        pending = {**envelope("original"), "state": "running"}
        validate(envelope("fixture", {"operation": pending}), TOOL_BY_NAME["mmdtool_operation_status"]["outputSchema"])

    def test_all_sixteen_discoverable_tools_have_closed_inputs_and_outputs(self):
        self.assertEqual(len(TOOLS), 16)
        self.assertEqual(len(TOOL_BY_NAME), 16)
        for item in TOOLS:
            with self.subTest(tool=item["name"]):
                self.assertFalse(item["inputSchema"]["additionalProperties"])
                self.assertEqual(item["outputSchema"]["type"], "object")
                self.assertIn("data", item["outputSchema"]["properties"])
                self.assertIn("readOnlyHint", item["annotations"])
                for key in item["inputSchema"]["properties"]:
                    self.assertTrue(key in OPTION_IDS or key in ("operation_id", "document", "model", "camera"))

    def test_each_tool_accepts_a_valid_fixture_and_rejects_unknown_fields(self):
        samples = {"document": "d:session:1", "model": "m:session:2", "camera": "c:session:3",
                   "path": r"C:\test\阿芙.pmx", "slot": "s:session:4", "mode": "anim", "enabled": True,
                   "morph_handle": "f:session:5", "strength": 0.5, "frame": 30, "unit": "vmd_frames",
                   "query_operation_id": str(uuid.uuid4())}
        for item in TOOLS:
            with self.subTest(tool=item["name"]):
                arguments = {key: samples[key] for key in item["inputSchema"]["required"]}
                validated_arguments(item["name"], arguments)
                with self.assertRaises(ValidationError):
                    validated_arguments(item["name"], {**arguments, "private_sdk_parameter": 1})

    def test_fractional_offset_and_bool_number_rejected(self):
        base = {"document": "d", "model": "m", "path": r"C:\a.vmd"}
        for bad in (1.5, True, "1"):
            with self.subTest(value=bad), self.assertRaises(ValidationError):
                validated_arguments("mmdtool_import_motion", {**base, "time_offset": bad})

    def test_nonfinite_strength_and_out_of_range_scale_rejected(self):
        for bad in (math.nan, math.inf, -math.inf):
            with self.subTest(value=bad), self.assertRaises(ValidationError):
                validated_arguments("mmdtool_set_morph_strength", {"document": "d", "model": "m", "morph_handle": "f", "strength": bad})
        with self.assertRaises(ValidationError):
            validated_arguments("mmdtool_import_pmx", {"document": "d", "path": r"C:\a.pmx", "position_multiple": 0})

    def test_handle_uuid_page_and_local_path_limits(self):
        invalid = ({"document": ""}, {"document": "d", "limit": 257},
                   {"document": "d", "offset": -1}, {"document": "d", "operation_id": "not-a-uuid"})
        for arguments in invalid:
            with self.assertRaises(ValidationError):
                validated_arguments("mmdtool_list_models", arguments)
        for path in ("relative.pmx", "https://example.com/model.pmx", "a\x00b"):
            with self.assertRaises(ValidationError):
                validated_arguments("mmdtool_import_pmx", {"document": "d", "path": path})

    def test_native_unknown_top_level_and_wrong_data_type_rejected(self):
        for result in ({**envelope(), "secret": "x"}, envelope(data={"protocol_version": "1"})):
            with self.assertRaises(ValidationError):
                validate(result, TOOL_BY_NAME["mmdtool_capabilities"]["outputSchema"])


    def test_pmx_option_dependencies_reject_before_connection(self):
        for name, target in (("mmdtool_import_pmx", {}), ("mmdtool_export_pmx", {"model": "m"})):
            base = {"document": "d", "path": r"C:\a.pmx", **target}
            for invalid in ({"bones": False}, {"polygon": False},
                            {"bones": False, "weights": False, "ik": True, "inherit": False}):
                with self.subTest(tool=name, arguments=invalid), self.assertRaises(ValidationError):
                    validated_arguments(name, {**base, **invalid})
            valid = validated_arguments(name, {**base, "bones": False, "weights": False,
                                               "ik": False, "inherit": False})
            self.assertFalse(valid["weights"])


class OperationTests(unittest.TestCase):
    def test_malformed_completed_mutation_is_unknown_and_not_repeated(self):
        original = self.host.call_production

        def malformed_mode(name, arguments, operation_id, **kwargs):
            result = original(name, arguments, operation_id, **kwargs)
            if name == "mmdtool_set_mode":
                result["data"] = {}
            return result

        self.host.call_production = malformed_mode
        first = self.adapter.call("mmdtool_set_mode", self.arguments)
        repeated = self.adapter.call("mmdtool_set_mode", self.arguments)
        self.assertEqual(first["code"], "host_protocol_error")
        self.assertEqual(first["state"], "outcome_unknown")
        self.assertEqual(repeated, first)
        self.assertEqual(sum(call[0] == "mmdtool_set_mode" for call in self.host.calls), 1)

    def test_recovered_operation_is_validated_against_its_original_tool(self):
        self.host.fail_next = HostError("transport_timeout", "Timed out", outcome_unknown=True)
        self.adapter.call("mmdtool_set_mode", self.arguments)
        self.host.results[self.operation_id] = envelope(self.operation_id, {})
        result = self.adapter.call("mmdtool_operation_status", {"query_operation_id": self.operation_id})
        self.assertEqual(result["code"], "host_protocol_error")
        self.assertEqual(self.adapter.records[self.operation_id].result["state"], "outcome_unknown")

    def setUp(self):
        self.host = FakeHost()
        self.adapter = Adapter(self.host)
        self.operation_id = str(uuid.uuid4())
        self.arguments = {"document": "d", "model": "m", "mode": "anim", "operation_id": self.operation_id}

    def test_mutation_deduplicates_and_conflicting_reuse_rejects(self):
        first = self.adapter.call("mmdtool_set_mode", self.arguments)
        self.assertEqual(first, self.adapter.call("mmdtool_set_mode", self.arguments))
        self.assertEqual(len(self.host.calls), 2)  # handshake + one mutation
        conflict = self.adapter.call("mmdtool_set_mode", {**self.arguments, "mode": "edit"})
        self.assertEqual(conflict["code"], "operation_id_conflict")
        self.assertEqual(len(self.host.calls), 2)

    def test_timeout_never_repeats_mutation_and_status_recovers(self):
        self.host.fail_next = HostError("transport_timeout", "Timed out", outcome_unknown=True)
        failed = self.adapter.call("mmdtool_set_mode", self.arguments)
        self.assertEqual(failed["state"], "outcome_unknown")
        self.assertEqual(self.adapter.call("mmdtool_set_mode", self.arguments), failed)
        self.assertEqual(len(self.host.calls), 2)
        self.host.results[self.operation_id] = envelope(self.operation_id, {"mode": "anim"})
        status = self.adapter.call("mmdtool_operation_status", {"query_operation_id": self.operation_id})
        self.assertTrue(status["success"])
        self.assertTrue(self.adapter.call("mmdtool_set_mode", self.arguments)["success"])
        mutation_calls = [call for call in self.host.calls if call[0] == "mmdtool_set_mode"]
        self.assertEqual(len(mutation_calls), 1)

    def test_restart_does_not_treat_unknown_outcome_as_rollback(self):
        self.host.fail_next = HostError("transport_timeout", "Timed out", outcome_unknown=True)
        self.adapter.call("mmdtool_set_mode", self.arguments)
        self.host.host_session = "restarted-session"
        status = self.adapter.call("mmdtool_operation_status", {"query_operation_id": self.operation_id})
        self.assertEqual(status["state"], "outcome_unknown")
        self.assertFalse(any(call[0] == "mmdtool_operation_status" for call in self.host.calls))

    def test_no_mutation_before_compatible_handshake(self):
        original = self.host.call_production
        def wrong_version(name, arguments, operation_id, **kwargs):
            result = original(name, arguments, operation_id, **kwargs)
            if name == "mmdtool_capabilities":
                result["data"]["protocol_version"] = 2
            return result
        self.host.call_production = wrong_version
        result = self.adapter.call("mmdtool_set_mode", self.arguments)
        self.assertEqual(result["code"], "incompatible_protocol")
        self.assertEqual(len(self.host.calls), 1)

    def test_failed_validation_never_connects(self):
        with self.assertRaises(ValidationError):
            self.adapter.call("mmdtool_set_mode", {**self.arguments, "mode": "invalid"})
        self.assertEqual(self.host.initialize_count, 0)

    def test_capacity_boundary_does_not_evict_the_repeated_operation(self):
        self.adapter.call("mmdtool_set_mode", self.arguments)
        self.adapter.record_capacity = 1
        self.adapter.call("mmdtool_set_mode", self.arguments)
        self.assertEqual(len(self.host.calls), 2)


class StdioTests(unittest.TestCase):
    def setUp(self):
        self.server = StdioServer(Adapter(FakeHost()))

    def initialize(self):
        result = self.server.handle({"jsonrpc": "2.0", "id": 1, "method": "initialize",
                                    "params": {"protocolVersion": "2025-06-18"}})
        self.assertIn("tools", result["result"]["capabilities"])
        self.assertIsNone(self.server.handle({"jsonrpc": "2.0", "method": "notifications/initialized"}))

    def test_null_request_ids_reject_before_handshake_or_mutation(self):
        response = self.server.handle({"jsonrpc": "2.0", "id": None, "method": "initialize",
                                       "params": {"protocolVersion": "2025-06-18"}})
        self.assertEqual(response["error"]["code"], -32600)
        self.assertFalse(self.server.initialized)
        self.initialize()
        response = self.server.handle({"jsonrpc": "2.0", "id": None, "method": "tools/call",
                                       "params": {"name": "mmdtool_set_mode", "arguments": {
                                           "document": "doc-1", "model": "model-1", "mode": "anim"}}})
        self.assertEqual(response["error"]["code"], -32600)
        self.assertFalse(self.server.adapter.host.calls)

    def test_handshake_discovery_and_structured_call(self):
        early = self.server.handle({"jsonrpc": "2.0", "id": 0, "method": "tools/list"})
        self.assertEqual(early["error"]["code"], -32600)
        self.initialize()
        listed = self.server.handle({"jsonrpc": "2.0", "id": 2, "method": "tools/list"})
        self.assertEqual(len(listed["result"]["tools"]), 16)
        called = self.server.handle({"jsonrpc": "2.0", "id": 3, "method": "tools/call",
                                     "params": {"name": "mmdtool_capabilities", "arguments": {}}})
        self.assertEqual(json.loads(called["result"]["content"][0]["text"]), called["result"]["structuredContent"])
        self.assertFalse(called["result"]["isError"])

    def test_protocol_errors_and_nonfinite_json_preserve_framing(self):
        data = b'{bad}\n{"jsonrpc":"2.0","id":2,"method":"ping","params":{"x":NaN}}\n{"jsonrpc":"2.0","id":3,"method":"ping"}\n'
        destination = io.BytesIO()
        self.server.serve(io.BytesIO(data), destination)
        responses = [json.loads(line) for line in destination.getvalue().splitlines()]
        self.assertEqual([item.get("error", {}).get("code") for item in responses], [-32700, -32700, None])
        self.assertEqual(responses[-1]["id"], 3)

    def test_unknown_tools_are_protocol_errors(self):
        self.initialize()
        response = self.server.handle({"jsonrpc": "2.0", "id": 2, "method": "tools/call", "params": {"name": "exec_python"}})
        self.assertEqual(response["error"]["code"], -32602)

    def test_subprocess_discovery_is_dependency_free_and_does_not_read_token(self):
        messages = [{"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {"protocolVersion": "2025-06-18"}},
                    {"jsonrpc": "2.0", "method": "notifications/initialized"},
                    {"jsonrpc": "2.0", "id": 2, "method": "tools/list"}]
        process = subprocess.run([sys.executable, str(Path(__file__).resolve().parents[1] / "run_mmdtool_mcp.py"),
                                  "--token-file", "fixture-does-not-exist"],
                                 input="\n".join(json.dumps(item) for item in messages).encode() + b"\n",
                                 stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=10)
        self.assertEqual(process.returncode, 0)
        self.assertFalse(process.stderr)
        responses = [json.loads(line) for line in process.stdout.splitlines()]
        self.assertEqual(len(responses), 2)
        self.assertEqual(len(responses[-1]["result"]["tools"]), 16)


class HostTransportTests(unittest.TestCase):
    def setUp(self):
        self.temporary = temporary_directory()
        self.addCleanup(self.temporary.cleanup)
        self.token = "fixture-sensitive-credential"
        self.token_file = Path(self.temporary.name) / "token"
        self.token_file.write_text(self.token, encoding="utf-8")
        self.requests = []
        self.status = 200
        self.sse = False
        owner = self
        class Handler(BaseHTTPRequestHandler):
            def log_message(self, *args):
                pass
            def do_POST(self):
                message = json.loads(self.rfile.read(int(self.headers["Content-Length"])))
                owner.requests.append((message, dict(self.headers)))
                status = 202 if "id" not in message and owner.status == 200 else owner.status
                self.send_response(status)
                self.send_header("Content-Type", "text/event-stream" if owner.sse else "application/json")
                self.send_header("Mcp-Session-Id", "fixture-http-session")
                self.end_headers()
                if status == 202:
                    return
                if status != 200:
                    self.wfile.write(owner.token.encode())
                    return
                result = {"protocolVersion": "2025-06-18", "capabilities": {"tools": {}}} if message["method"] == "initialize" else {"tools": [{"name": "exec_python"}]} if message["method"] == "tools/list" else {"content": [{"type": "text", "text": json.dumps({"stdout": RESULT_MARKER + json.dumps(envelope("test-operation"))})}]}
                response = json.dumps({"jsonrpc": "2.0", "id": message["id"], "result": result})
                body = "data: {\"jsonrpc\":\"2.0\",\"method\":\"notifications/message\"}\n\ndata: " + response + "\n\n" if owner.sse else response
                self.wfile.write(body.encode())
        self.http = ThreadingHTTPServer(("127.0.0.1", 0), Handler)
        self.worker = threading.Thread(target=self.http.serve_forever, daemon=True)
        self.worker.start()
        self.addCleanup(self.http.server_close)
        self.addCleanup(self.http.shutdown)
        self.host = HostConnection(f"http://127.0.0.1:{self.http.server_port}/mcp", self.token_file, 2)

    def test_http_handshake_headers_and_wrapped_stdout(self):
        self.host.initialize()
        self.assertEqual(self.host.session_id, "fixture-http-session")
        self.assertEqual(self.requests[-1][1]["Mcp-Session-Id"], "fixture-http-session")
        self.assertEqual(self.requests[-1][1]["Mcp-Protocol-Version"], "2025-06-18")
        result = self.host.call_production("mmdtool_capabilities", {}, "test-operation")
        self.assertTrue(result["success"])

    def test_sse_ignores_notifications_and_matches_request_id(self):
        self.sse = True
        self.host.initialize()
        self.assertEqual(self.host.protocol_version, "2025-06-18")

    def test_401_403_errors_never_echo_token_or_response_body(self):
        for status, code in ((401, "authentication_required"), (403, "permission_denied")):
            self.status = status
            with self.assertRaises(HostError) as caught:
                self.host.initialize()
            self.assertEqual(caught.exception.code, code)
            self.assertNotIn(self.token, str(caught.exception))

    def test_missing_token_and_unavailable_host_are_actionable(self):
        self.host.token_file = Path(self.temporary.name) / "missing"
        with self.assertRaises(HostError) as caught:
            self.host.initialize()
        self.assertEqual(caught.exception.code, "authentication_required")
        self.host.token_file = self.token_file
        with patch.object(self.host._opener, "open", side_effect=ConnectionRefusedError("sensitive details")):
            with self.assertRaises(HostError) as caught:
                self.host.initialize()
        self.assertEqual(caught.exception.code, "host_unavailable")
        self.assertNotIn("sensitive details", str(caught.exception))

    def test_timeout_and_lost_session_are_unknown_without_retry(self):
        with patch.object(self.host._opener, "open", side_effect=TimeoutError()) as call:
            with self.assertRaises(HostError) as caught:
                self.host.request("tools/call", {}, may_mutate=True)
            self.assertTrue(caught.exception.outcome_unknown)
            self.assertEqual(call.call_count, 1)
        self.host.session_id = "expired"
        self.status = 404
        with self.assertRaises(HostError) as caught:
            self.host.request("tools/call", {}, may_mutate=True)
        self.assertEqual(caught.exception.code, "host_session_expired")
        self.assertTrue(caught.exception.outcome_unknown)
        self.assertIsNone(self.host.session_id)

    def test_only_local_endpoints_and_no_inline_secrets(self):
        for endpoint in ("http://example.com/mcp", "file:///secret", "http://secret@127.0.0.1/mcp", "http://127.0.0.1/mcp?token=secret"):
            with self.assertRaises(HostError) as caught:
                validate_endpoint(endpoint)
            self.assertNotIn("secret", str(caught.exception))
        self.assertEqual(validate_endpoint("http://[::1]:5556/mcp"), "http://[::1]:5556/mcp")


class FixedBridgeTests(unittest.TestCase):
    def execute(self, name, arguments, native_data=None, *, copy_message_data=False):
        class Container(dict):
            def __init__(self, container_id=0): super().__init__(); self.container_id = container_id
            def SetInt32(self, key, value): self[key] = value
            def SetBool(self, key, value): self[key] = value
            def SetFloat(self, key, value): self[key] = value
            def SetString(self, key, value): self[key] = value
            def SetContainer(self, key, value): self[key] = value
            def GetString(self, key): return self.get(key, "")
        storage = Container()
        class Hook:
            response = ""
            def GetDataInstance(self): raise AssertionError("Transport must not access persistent data")
            def Message(self, message, packet):
                if message != 9 or packet.container_id != 1057017:
                    raise AssertionError("Transport did not use its qualified SDK message")
                storage.update(packet)
                self.response = json.dumps(envelope("operation", native_data))
                if not copy_message_data:
                    packet[2000001] = self.response
            def GetParameter(self, *args): return self.response
        host_module = types.SimpleNamespace(BaseContainer=Container, documents=types.SimpleNamespace(
            GetActiveDocument=lambda: types.SimpleNamespace(FindSceneHook=lambda _: Hook())),
            MSG_BASECONTAINER=9, DTYPE_STRING=130, DESCFLAGS_GET_0=0,
            DescID=lambda value: value, DescLevel=lambda *values: values)
        output = io.StringIO()
        with patch.dict(sys.modules, {"c4d": host_module}), redirect_stdout(output):
            exec(fixed_host_code(name, arguments, "operation"), {})
        return storage[2000000], json.loads(output.getvalue().split(RESULT_MARKER)[1])

    def test_unicode_and_python_fragments_stay_encoded_data(self):
        malicious = "C:\\阿芙\\'); __import__('os').system('unexpected'); #.pmx"
        code = fixed_host_code("mmdtool_import_pmx", {"document": "doc", "path": malicious}, "operation")
        self.assertNotIn(malicious, code)
        request, result = self.execute("mmdtool_import_pmx", {"document": "doc", "path": malicious})
        self.assertEqual(request[5][100], malicious)
        self.assertEqual(request[3], "doc")
        self.assertTrue(result["success"])

    def test_float_container_types_and_explicit_target(self):
        request, _ = self.execute("mmdtool_set_morph_strength", {"document": "doc", "model": "model",
                                  "morph_handle": "morph", "strength": 1})
        self.assertIsInstance(request[5][116], float)
        self.assertEqual(request[4], "model")

    def test_readonly_response_fallback_when_message_payload_is_copied(self):
        request, result = self.execute("mmdtool_capabilities", {}, copy_message_data=True)
        self.assertTrue(result["success"])
        self.assertEqual(request[1], "mmdtool_capabilities")
        self.assertNotIn("GetDataInstance()", fixed_host_code("mmdtool_capabilities", {}, "operation"))

    def test_export_adds_sha256_and_checks_complete_length(self):
        with temporary_directory() as folder:
            destination = Path(folder) / "test.vmd"
            destination.write_bytes(b"complete fixture")
            _, result = self.execute("mmdtool_export_motion", {}, {"path": str(destination), "bytes": 16})
            self.assertTrue(result["success"])
            self.assertEqual(result["data"]["size"], 16)
            self.assertEqual(result["data"]["sha256"], hashlib.sha256(b"complete fixture").hexdigest())
            _, invalid = self.execute("mmdtool_export_motion", {}, {"path": str(destination), "bytes": 15})
            self.assertEqual(invalid["code"], "export_verification_failed")
            self.assertFalse(invalid["success"])

    def test_committed_export_verification_failure_is_unknown_and_not_retried(self):
        with temporary_directory() as folder:
            destination = Path(folder) / "committed.vmd"
            committed_bytes = b"complete fixture"
            destination.write_bytes(committed_bytes)
            _, invalid = self.execute("mmdtool_export_motion", {},
                                      {"path": str(destination), "bytes": len(committed_bytes) - 1})
            self.assertEqual(invalid["state"], "outcome_unknown")
            self.assertEqual(destination.read_bytes(), committed_bytes)
            self.assertNotIn(str(destination), invalid["message"])

            host = FakeHost()
            production_call = host.call_production

            def call_with_committed_export(name, arguments, operation_id, *, may_mutate=False):
                if name == "mmdtool_export_motion":
                    host.calls.append((name, arguments, operation_id, may_mutate))
                    return {**invalid, "operation_id": operation_id}
                return production_call(name, arguments, operation_id, may_mutate=may_mutate)

            host.call_production = call_with_committed_export
            adapter = Adapter(host)
            arguments = {"operation_id": str(uuid.uuid4()), "document": "doc-1",
                         "model": "model-1", "path": str(destination)}
            first = adapter.call("mmdtool_export_motion", arguments)
            repeated = adapter.call("mmdtool_export_motion", arguments)
            self.assertEqual(first["state"], "outcome_unknown")
            self.assertEqual(repeated, first)
            self.assertEqual(sum(call[0] == "mmdtool_export_motion" for call in host.calls), 1)

    def test_status_recovery_also_verifies_export_identity(self):
        with temporary_directory() as folder:
            destination = Path(folder) / "test.pmx"
            destination.write_bytes(b"exported fixture")
            original = envelope("original-operation", {"path": str(destination), "bytes": 16})
            _, result = self.execute("mmdtool_operation_status", {}, {"operation": original})
            recovered = result["data"]["operation"]
            self.assertTrue(recovered["success"])
            self.assertEqual(recovered["data"]["sha256"], hashlib.sha256(b"exported fixture").hexdigest())


if __name__ == "__main__":
    unittest.main()
