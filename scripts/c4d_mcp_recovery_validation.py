"""Real typed MCP timeout/reconnection and two-phase host restart acceptance.

The loopback fault proxy delays one response AFTER real Cinema 4D execution.
It does not simulate native business results or expose additional plugin tools.
Restart only an owned, cleaned test host between the before/after phases.
Credentials are forwarded locally and are never written to receipts or logs.
"""

import argparse
import base64
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
import json
from pathlib import Path
import re
import threading
import time
import urllib.error
import urllib.request
import uuid

from c4d_production_mcp_validation import (
    ValidationRun, StdioClient, atomic_json, file_identity, prepare,
    HostConnection, HostError, TOOL_BY_NAME, validate,
)
from mmdtool_mcp.host import NoRedirect


class DelayedResponseProxy:
    """Forward real HTTP; inject one lost/late response for a specific UUID."""

    def __init__(self, endpoint, operation_id):
        self.endpoint, self.operation_id = endpoint, operation_id
        self.forwarded_mutations = 0
        self.native_response_received = threading.Event()
        proxy = self

        class Handler(BaseHTTPRequestHandler):
            def log_message(self, *_):
                pass

            def do_POST(self):
                body = self.rfile.read(int(self.headers["Content-Length"]))
                request = json.loads(body)
                code = request.get("params", {}).get("arguments", {}).get("code", "")
                encoded = re.search(r'b64decode\("([A-Za-z0-9+/=]+)"\)', code)
                payload = json.loads(base64.b64decode(encoded.group(1))) if encoded else {}
                delayed = payload.get("operation_id") == proxy.operation_id
                if delayed:
                    proxy.forwarded_mutations += 1
                headers = {key: value for key, value in self.headers.items()
                           if key.lower() in ("authorization", "content-type", "accept",
                                              "mcp-session-id", "mcp-protocol-version")}
                opener = urllib.request.build_opener(urllib.request.ProxyHandler({}), NoRedirect())
                upstream = urllib.request.Request(proxy.endpoint, data=body, headers=headers, method="POST")
                try:
                    response = opener.open(upstream, timeout=30)
                except urllib.error.HTTPError as error:
                    response = error
                with response:
                    content_type = response.headers.get("Content-Type", "application/json")
                    if content_type.startswith("text/event-stream"):
                        data = bytearray()
                        while True:
                            line = response.readline()
                            data.extend(line)
                            if not line or (line.strip() == b"" and b"data:" in data):
                                break
                        data = bytes(data)
                    else:
                        data = response.read(16 * 1024 * 1024 + 1)
                    status = response.status
                    session = response.headers.get("Mcp-Session-Id")
                if delayed:
                    proxy.native_response_received.set()
                    time.sleep(2.5)
                try:
                    self.send_response(status)
                    self.send_header("Content-Type", content_type)
                    self.send_header("Content-Length", str(len(data)))
                    if session:
                        self.send_header("Mcp-Session-Id", session)
                    self.end_headers()
                    self.wfile.write(data)
                except (BrokenPipeError, ConnectionResetError, ConnectionAbortedError):
                    pass  # Expected when the real adapter has timed out.

        self.server = ThreadingHTTPServer(("127.0.0.1", 0), Handler)
        self.server.daemon_threads = True
        self.url = "http://127.0.0.1:" + str(self.server.server_port) + "/mcp"
        threading.Thread(target=self.server.serve_forever, daemon=True).start()

    def close(self):
        self.server.shutdown()
        self.server.server_close()


def typed(client, name, arguments, expected=True):
    response = client.request("tools/call", {"name": name, "arguments": arguments})
    if "error" in response:
        raise AssertionError("Typed protocol failure: " + str(response["error"]["code"]))
    result = response["result"]["structuredContent"]
    validate(result, TOOL_BY_NAME[name]["outputSchema"], "native_result")
    if result["success"] != expected:
        raise AssertionError("Unexpected native result: " + str(result))
    return result


def phase(args):
    root = Path(args.output).resolve()
    stage_output = root / args.phase
    prepare(stage_output, args.expected_binary, args.build_cache)
    run = ValidationRun(stage_output, args.endpoint, args.token_file, 30)
    run.stage_name = "recovery-" + args.phase
    result = {"status": "running", "phase": args.phase, "native_executed": False,
              "macos": "deferred_unverified", "older_host_ui": "unverified"}
    client = proxy = None
    try:
        result["setup"] = run.setup()
        result["native_executed"] = True
        document = run.values["documents"]["A"]
        if args.phase == "after-restart":
            previous = json.loads((root / "before-restart.json").read_text(encoding="utf-8"))
            if previous["status"] != "passed" or file_identity(previous["scene"]["path"]) != previous["scene"]:
                raise AssertionError("Accepted restart scene changed")
            if result["setup"]["identity"]["loaded_binary"]["sha256"] != previous["module_sha256"]:
                raise AssertionError("Restart loaded another module")
            if result["setup"]["identity"]["pid"] == previous["host_pid"]:
                raise AssertionError("The host was not restarted")
            run.native("load_restart_scene", label="A", path=previous["scene"]["path"])
            document = run.documents("A")
        else:
            run.call("mmdtool_import_pmx", {"document": document, "path": run.fixture("model.pmx"),
                     "position_multiple": 1.})
        model = run.call("mmdtool_list_models", {"document": document})["data"]["models"][0]["handle"]
        target = {"document": document, "model": model}
        run.values["models"] = {"A1": model}
        morphs = run.call("mmdtool_inspect_model", {**target, "section": "morphs"})["data"]["items"]
        morph = next(item for item in morphs if item["name"] == "tint")["handle"]
        options = {"python_executable": args.python_executable, "adapter_entry": args.adapter_entry}

        if args.phase == "before-restart":
            operation_id = str(uuid.uuid4())
            proxy = DelayedResponseProxy(args.endpoint, operation_id)
            client = StdioClient(proxy.url, args.token_file, 1, **options)
            if len(client.request("tools/list", {})["result"]["tools"]) != 16:
                raise AssertionError("Packaged adapter lost tools")
            capabilities = typed(client, "mmdtool_capabilities", {})
            arguments = {**target, "morph_handle": morph, "strength": .37, "operation_id": operation_id}
            unknown = typed(client, "mmdtool_set_morph_strength", arguments, False)
            if unknown["state"] != "outcome_unknown" or unknown["code"] != "transport_timeout":
                raise AssertionError("Lost real HTTP response did not produce outcome_unknown")
            if not proxy.native_response_received.is_set():
                raise AssertionError("The fault occurred before real native execution")
            duplicate = typed(client, "mmdtool_set_morph_strength", arguments, False)
            if duplicate != unknown or proxy.forwarded_mutations != 1:
                raise AssertionError("The adapter replayed an uncertain mutation")
            recovered = typed(client, "mmdtool_operation_status", {"query_operation_id": operation_id})
            operation = recovered["data"]["operation"]
            if not operation["success"] or operation["state"] != "completed":
                raise AssertionError("Native status did not recover the actual mutation")
            completed = typed(client, "mmdtool_set_morph_strength", arguments)
            if completed != operation or proxy.forwarded_mutations != 1:
                raise AssertionError("Recovered operation was executed again")
            actual_morphs = run.call("mmdtool_inspect_model", {**target, "section": "morphs"})["data"]["items"]
            if abs(next(item["strength"] for item in actual_morphs if item["name"] == "tint") - .37) > 1e-8:
                raise AssertionError("Recovered mutation did not change the actual native strength")
            result["timeout"] = {"fault": "response_delayed_after_actual_native_execution", "seconds": 2.5,
                "unknown": unknown, "duplicate": duplicate, "recovered": recovered,
                "completed": completed, "native_mutation_requests": proxy.forwarded_mutations}
            slot = run.call("mmdtool_import_motion", {**target, "path": run.fixture("motion_a.vmd"),
                            "position_multiple": 1.})["data"]["slot"]
            camera = run.call("mmdtool_import_camera", {"document": document, "path": run.fixture("camera.vmd"),
                              "position_multiple": 1.})["data"]["camera"]
            scene = root / "restart-scene.c4d"
            run.native("save_reopen", label="A", path=str(scene))
            fresh_document = run.documents("A")
            fresh_target = {"document": fresh_document, "model": run.call("mmdtool_list_models", {
                "document": fresh_document})["data"]["models"][0]["handle"]}
            current = run.call("mmdtool_inspect_model", {**fresh_target, "section": "morphs"})["data"]["items"]
            fresh_slot = run.call("mmdtool_list_animation_slots", fresh_target)["data"]["slots"][0]["handle"]
            fresh_camera = next(item["handle"] for item in run.call("mmdtool_capabilities")["data"]["cameras"]
                                if item["document"] == fresh_document)
            result.update({"scene": file_identity(scene), "host_session": capabilities["data"]["host_session"],
                "host_pid": result["setup"]["identity"]["pid"], "module_sha256": result["setup"]["identity"]["loaded_binary"]["sha256"],
                "handles": {**fresh_target, "morph": next(item["handle"] for item in current if item["name"] == "tint"),
                            "slot": fresh_slot, "camera": fresh_camera}, "operation_id": operation_id,
                "http_session_id": run.host.session_id,
                "packaged_adapter": file_identity(args.adapter_entry),
                "clean_python": str(Path(args.python_executable).resolve())})
        else:
            expired = HostConnection(args.endpoint, args.token_file, 30)
            if previous["http_session_id"]:
                expired.session_id = previous["http_session_id"]
                try:
                    expired.call_production("mmdtool_capabilities", {}, str(uuid.uuid4()))
                except HostError as error:
                    if error.code != "host_session_expired":
                        raise
                    result["expired_http_session"] = error.code
                else:
                    raise AssertionError("The restarted host accepted an expired HTTP session")
            else:
                result["expired_http_session"] = "not_applicable_host_did_not_issue_http_session_id"
            expired.initialize()
            result["http_reconnected"] = expired.call_production("mmdtool_capabilities", {}, str(uuid.uuid4()))
            client = StdioClient(args.endpoint, args.token_file, 30, **options)
            capabilities = typed(client, "mmdtool_capabilities", {})
            if capabilities["data"]["host_session"] == previous["host_session"]:
                raise AssertionError("Restart did not invalidate the native session nonce")
            old = previous["handles"]
            rejections = [typed(client, "mmdtool_list_models", {"document": old["document"]}, False),
                typed(client, "mmdtool_inspect_model", {"document": document, "model": old["model"]}, False),
                typed(client, "mmdtool_set_morph_strength", {**target, "morph_handle": old["morph"], "strength": .9}, False),
                typed(client, "mmdtool_select_animation_slot", {**target, "slot": old["slot"]}, False),
                typed(client, "mmdtool_export_camera", {"document": document, "camera": old["camera"],
                    "path": str(root / "must-not-exist.vmd")}, False)]
            unavailable = typed(client, "mmdtool_operation_status", {"query_operation_id": previous["operation_id"]}, False)
            if unavailable["state"] != "outcome_unknown" or (root / "must-not-exist.vmd").exists():
                raise AssertionError("Restart incorrectly recovered an old record or wrote a stale target")
            result.update({"host_session": capabilities["data"]["host_session"], "rejections": rejections,
                           "old_operation": unavailable, "fresh_model_inspection": typed(client, "mmdtool_inspect_model", target)})
        result["cleanup"] = run.cleanup()
        run.write_receipt()
        if not result["cleanup"]["original_document_restored"] or result["cleanup"]["cleanup_pending"]:
            raise AssertionError("Test scene cleanup incomplete")
        result["status"] = "passed"
    finally:
        if client:
            client.close()
        if proxy:
            proxy.close()
        if result["status"] != "passed":
            result["status"] = "failed"
            # The maintained runner handles uncertain execution without replay.
            run.finish(uncertain=bool(run.state.get("pending_operation") or run.state.get("pending_helper")))
        atomic_json(root / (args.phase + ".json"), result)
    return result


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--phase", choices=("before-restart", "after-restart"), required=True)
    for field in ("output", "expected-binary", "build-cache", "endpoint", "token-file", "python-executable", "adapter-entry"):
        parser.add_argument("--" + field, required=True)
    result = phase(parser.parse_args())
    print(json.dumps({"phase": result["phase"], "status": result["status"]}))


if __name__ == "__main__":
    main()
