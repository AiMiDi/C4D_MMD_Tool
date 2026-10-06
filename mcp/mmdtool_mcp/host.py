"""Authenticated local Streamable HTTP transport and a fixed production call.

Transport errors never echo response bodies, headers, URLs containing secrets,
or arbitrary exception messages. A failed mutation request is not retried.
"""

from __future__ import annotations

import base64
import ipaddress
import json
from pathlib import Path
import socket
from typing import Any
import urllib.error
import urllib.parse
import urllib.request

from .schema import OPTION_IDS, PROTOCOL_VERSION

SUPPORTED_MCP_VERSIONS = ("2025-06-18", "2025-03-26", "2024-11-05")
MAX_HOST_RESPONSE_BYTES = 16 * 1024 * 1024
RESULT_MARKER = "CMT_MCP_RESULT:"


class HostError(RuntimeError):
    def __init__(self, code: str, message: str, *, outcome_unknown: bool = False):
        super().__init__(message)
        self.code = code
        self.outcome_unknown = outcome_unknown


def error_envelope(code: str, message: str, operation_id: str = "", *,
                   outcome_unknown: bool = False, host_session: str = "") -> dict[str, Any]:
    result = {"success": False, "code": code, "message": message,
              "operation_id": operation_id,
              "state": "outcome_unknown" if outcome_unknown else "failed",
              "data": {}, "warnings": []}
    if host_session:
        result["host_session"] = host_session
    return result


def validate_endpoint(endpoint: str) -> str:
    try:
        parsed = urllib.parse.urlsplit(endpoint)
        hostname = parsed.hostname
        parsed.port  # Reject malformed ports before credentials are loaded.
    except ValueError as error:
        raise HostError("invalid_configuration", "Malformed local host endpoint.") from error
    if parsed.scheme not in ("http", "https") or not hostname or parsed.username or parsed.password:
        raise HostError("invalid_configuration", "Use an HTTP(S) localhost endpoint without inline credentials.")
    if parsed.query or parsed.fragment:
        raise HostError("invalid_configuration", "The host endpoint cannot contain a query or fragment.")
    try:
        local = hostname == "localhost" or ipaddress.ip_address(hostname).is_loopback
    except ValueError:
        local = hostname == "localhost"
    if not local:
        raise HostError("invalid_configuration", "This adapter supports only the local Cinema 4D host.")
    return endpoint


class NoRedirect(urllib.request.HTTPRedirectHandler):
    """Never forward the local bearer credential to a redirected endpoint."""

    def redirect_request(self, req, fp, code, msg, headers, newurl):
        return None


class HostConnection:
    def __init__(self, endpoint: str, token_file: str | Path, timeout: float = 180):
        self.endpoint = validate_endpoint(endpoint)
        self.token_file = Path(token_file)
        self.timeout = timeout
        self.session_id: str | None = None
        self.protocol_version = SUPPORTED_MCP_VERSIONS[0]
        self._next_id = 0
        # Local host communication must not traverse ambient HTTP proxies.
        self._opener = urllib.request.build_opener(urllib.request.ProxyHandler({}), NoRedirect())

    def _token(self) -> str:
        try:
            with self.token_file.open("r", encoding="utf-8") as source:
                token = source.read(8193).strip()
        except (OSError, UnicodeError) as error:
            raise HostError("authentication_required", "Cannot read token-file; select the token file created by Cinema 4D MCP.") from error
        if not token or len(token) > 8192 or "\r" in token or "\n" in token:
            raise HostError("authentication_required", "Token-file is empty or invalid; refresh the host credential.")
        return token

    def request(self, method: str, params: dict[str, Any], *, notification: bool = False,
                may_mutate: bool = False) -> dict[str, Any]:
        self._next_id += 1
        message: dict[str, Any] = {"jsonrpc": "2.0", "method": method, "params": params}
        message_id = self._next_id
        if not notification:
            message["id"] = message_id
        headers = {"Content-Type": "application/json", "Accept": "application/json, text/event-stream",
                   "Authorization": "Bearer " + self._token()}
        if self.session_id:
            headers["Mcp-Session-Id"] = self.session_id
            headers["MCP-Protocol-Version"] = self.protocol_version
        request = urllib.request.Request(self.endpoint,
                                         data=json.dumps(message, allow_nan=False).encode("utf-8"),
                                         headers=headers, method="POST")
        try:
            with self._opener.open(request, timeout=self.timeout) as response:
                session = response.headers.get("Mcp-Session-Id")
                if session:
                    self.session_id = session
                if notification and response.status == 202:
                    return {}
                content_type = response.headers.get("Content-Type", "").split(";", 1)[0].strip()
                if content_type == "text/event-stream":
                    result = self._read_sse(response, message_id)
                else:
                    body = response.read(MAX_HOST_RESPONSE_BYTES + 1)
                    if len(body) > MAX_HOST_RESPONSE_BYTES:
                        raise HostError("host_protocol_error", "Host response exceeds the adapter limit.",
                                        outcome_unknown=may_mutate)
                    result = json.loads(body) if body else {}
        except urllib.error.HTTPError as error:
            error.close()
            if error.code in (401, 403):
                code = "authentication_required" if error.code == 401 else "permission_denied"
                raise HostError(code, "Host rejected authorization; check token-file and host Python execution permission.") from error
            if error.code == 404 and self.session_id:
                self.session_id = None
                raise HostError("host_session_expired", "Host session expired; query operation status after reconnecting.",
                                outcome_unknown=may_mutate) from error
            raise HostError("host_http_error", f"Host returned HTTP {error.code}.",
                            outcome_unknown=may_mutate) from error
        except HostError as error:
            if may_mutate:
                error.outcome_unknown = True
            raise
        except (TimeoutError, socket.timeout) as error:
            raise HostError("transport_timeout", "Host wait timed out; query the operation ID before retrying.",
                            outcome_unknown=may_mutate) from error
        except (urllib.error.URLError, ConnectionError, OSError) as error:
            raise HostError("host_unavailable", "Cannot reach Cinema 4D MCP; start the configured host service.",
                            outcome_unknown=may_mutate) from error
        except (ValueError, UnicodeError) as error:
            raise HostError("host_protocol_error", "Host returned an invalid JSON-RPC response.",
                            outcome_unknown=may_mutate) from error
        if notification:
            return {}
        if not isinstance(result, dict) or result.get("id") != message_id:
            raise HostError("host_protocol_error", "Host response does not match the request.",
                            outcome_unknown=may_mutate)
        if "error" in result:
            # Server errors can contain user data; never reflect arbitrary text.
            raise HostError("host_request_rejected", "Host rejected the fixed production API request; check execution permission.",
                            outcome_unknown=may_mutate)
        if not isinstance(result.get("result"), dict):
            raise HostError("host_protocol_error", "Host JSON-RPC result is missing.", outcome_unknown=may_mutate)
        return result["result"]

    @staticmethod
    def _read_sse(response, message_id: int) -> dict[str, Any]:
        data_lines: list[str] = []
        total_bytes = 0
        for raw_line in response:
            total_bytes += len(raw_line)
            if total_bytes > MAX_HOST_RESPONSE_BYTES:
                raise HostError("host_protocol_error", "Host SSE response exceeds the adapter limit.")
            line = raw_line.decode("utf-8").rstrip("\r\n")
            if line.startswith("data:"):
                data_lines.append(line[5:].lstrip(" "))
            elif not line and data_lines:
                message = json.loads("\n".join(data_lines))
                data_lines.clear()
                if isinstance(message, dict) and message.get("id") == message_id:
                    return message
        if data_lines:
            message = json.loads("\n".join(data_lines))
            if isinstance(message, dict) and message.get("id") == message_id:
                return message
        raise HostError("host_protocol_error", "Host SSE closed before the matching response.")

    def initialize(self) -> None:
        result = self.request("initialize", {"protocolVersion": SUPPORTED_MCP_VERSIONS[0],
                              "capabilities": {},
                              "clientInfo": {"name": "mmdtool-mcp", "version": "1.0.0"}})
        version = result.get("protocolVersion")
        if version not in SUPPORTED_MCP_VERSIONS:
            raise HostError("unsupported_host", "Host MCP protocol version is unsupported.")
        self.protocol_version = version
        if "tools" not in result.get("capabilities", {}):
            raise HostError("unsupported_host", "Host MCP does not advertise tools.")
        self.request("notifications/initialized", {}, notification=True)
        definitions = self.request("tools/list", {})
        if not any(item.get("name") == "exec_python" for item in definitions.get("tools", [])):
            raise HostError("permission_denied", "Host exec_python is unavailable; enable authorized Python execution in Cinema 4D MCP.")

    def call_production(self, name: str, arguments: dict[str, Any], operation_id: str,
                        *, may_mutate: bool = False) -> dict[str, Any]:
        code = fixed_host_code(name, arguments, operation_id)
        host_result = self.request("tools/call", {"name": "exec_python", "arguments": {
                                   "code": code, "timeout_seconds": int(min(self.timeout, 600)),
                                   "max_iterations": 50000000}}, may_mutate=may_mutate)
        if host_result.get("isError"):
            raise HostError("host_execution_failed", "Host Python execution failed or was denied; inspect host permission and plugin availability.",
                            outcome_unknown=may_mutate)
        output = host_result.get("structuredContent", {})
        texts = [item.get("text", "") for item in host_result.get("content", [])
                 if item.get("type") == "text"]
        if isinstance(output, dict) and isinstance(output.get("stdout"), str):
            texts.append(output["stdout"])
        for text in texts:
            try:
                wrapped = json.loads(text)
            except (ValueError, TypeError):
                wrapped = None
            if isinstance(wrapped, dict) and isinstance(wrapped.get("stdout"), str):
                text = wrapped["stdout"]
            for line in text.splitlines():
                if line.startswith(RESULT_MARKER):
                    try:
                        result = json.loads(line[len(RESULT_MARKER):])
                    except ValueError as error:
                        raise HostError("host_protocol_error", "Production API returned malformed JSON.",
                                        outcome_unknown=may_mutate) from error
                    if isinstance(result, dict):
                        return result
        raise HostError("host_protocol_error", "Production API did not return its result marker.",
                        outcome_unknown=may_mutate)


# All executable statements are maintained constants. Only a base64 JSON data
# literal is substituted, so quotes, Unicode and Python fragments remain data.
_HOST_CODE = '''import base64, hashlib, json, os, c4d
_payload = json.loads(base64.b64decode("__PAYLOAD__").decode("utf-8"))
_result = None
_doc = c4d.documents.GetActiveDocument()
_hook = _doc.FindSceneHook(1057017) if _doc else None
if _hook is None:
    _result = {"success": False, "code": "plugin_unavailable", "message": "MMD Tool production SceneHook is not loaded.", "operation_id": _payload["operation_id"], "state": "failed", "data": {}, "warnings": []}
else:
    _request = c4d.BaseContainer()
    _request.SetInt32(0, 1)
    _request.SetString(1, _payload["operation"])
    _request.SetString(2, _payload["operation_id"])
    _request.SetString(3, _payload.get("document", ""))
    _request.SetString(4, _payload.get("target", ""))
    _options = c4d.BaseContainer()
    for _key, _value in _payload["options"].items():
        _field = int(_key)
        if isinstance(_value, bool):
            _options.SetBool(_field, _value)
        elif _field in (101, 116, 117):
            _options.SetFloat(_field, float(_value))
        elif isinstance(_value, int):
            _options.SetInt32(_field, _value)
        elif isinstance(_value, float):
            _options.SetFloat(_field, _value)
        else:
            _options.SetString(_field, _value)
    _request.SetContainer(5, _options)
    _packet = c4d.BaseContainer(1057017)
    _packet.SetContainer(2000000, _request)
    _packet.SetString(2000001, "")
    _hook.Message(c4d.MSG_BASECONTAINER, _packet)
    _raw = _packet.GetString(2000001)
    if not _raw:
        # Some Python message bindings copy input containers. The native hook
        # exposes a readonly member cache, without modifying its persistent BC.
        try:
            _raw = _hook.GetParameter(c4d.DescID(c4d.DescLevel(2000001, c4d.DTYPE_STRING, 0)), c4d.DESCFLAGS_GET_0)
        except Exception:
            _raw = ""
    if not isinstance(_raw, str):
        _raw = ""
    if _raw:
        _result = json.loads(_raw)
    else:
        _result = {"success": False, "code": "plugin_unavailable", "message": "MMD Tool production message transport is absent or disabled; use a current normal build with production API enabled.", "operation_id": _payload["operation_id"], "state": "failed", "data": {}, "warnings": []}
def _verify_export_identity(_export):
    try:
        _path = _export["data"]["path"]
        _before = os.stat(_path)
        _hash = hashlib.sha256()
        _size = 0
        with open(_path, "rb") as _file:
            while True:
                _chunk = _file.read(1024 * 1024)
                if not _chunk:
                    break
                _hash.update(_chunk)
                _size += len(_chunk)
        _after = os.stat(_path)
        if _size != _export["data"]["bytes"] or _before.st_size != _after.st_size or _before.st_mtime_ns != _after.st_mtime_ns:
            raise ValueError("file identity changed")
        _export["data"]["size"] = _size
        _export["data"]["sha256"] = _hash.hexdigest()
    except (OSError, KeyError, ValueError):
        _export["success"] = False
        _export["code"] = "export_verification_failed"
        _export["message"] = "Export completed but destination identity could not be verified; inspect the output file before retrying."
        _export["state"] = "outcome_unknown"
        _export.setdefault("warnings", []).append("The destination may already contain the exported file.")
if _result.get("success") and _payload["operation"] in ("mmdtool_export_pmx", "mmdtool_export_motion", "mmdtool_export_camera"):
    _verify_export_identity(_result)
if _result.get("success") and _payload["operation"] == "mmdtool_operation_status":
    _original = _result.get("data", {}).get("operation")
    if isinstance(_original, dict) and _original.get("success") and "path" in _original.get("data", {}) and "bytes" in _original.get("data", {}):
        _verify_export_identity(_original)
print("CMT_MCP_RESULT:" + json.dumps(_result, ensure_ascii=False, allow_nan=False))
'''


def fixed_host_code(name: str, arguments: dict[str, Any], operation_id: str) -> str:
    payload = {"protocol": PROTOCOL_VERSION, "operation": name, "operation_id": operation_id,
               "document": arguments.get("document", ""),
               "target": arguments.get("model", arguments.get("camera", "")),
               "options": {str(OPTION_IDS[key]): value for key, value in arguments.items()
                           if key in OPTION_IDS}}
    encoded = base64.b64encode(json.dumps(payload, ensure_ascii=False, allow_nan=False).encode("utf-8")).decode("ascii")
    return _HOST_CODE.replace("__PAYLOAD__", encoded)
