"""Serial newline-delimited stdio MCP server and operation coordinator."""

from __future__ import annotations

import argparse
from collections import OrderedDict
from dataclasses import dataclass
import hashlib
import json
import math
import os
import sys
import time
from typing import Any, BinaryIO
import uuid

from . import __version__
from .host import HostConnection, HostError, SUPPORTED_MCP_VERSIONS, error_envelope
from .schema import MAX_REQUEST_BYTES, PROTOCOL_VERSION, TOOLS, TOOL_BY_NAME, ValidationError, validate, validated_arguments


@dataclass
class OperationRecord:
    tool_name: str
    fingerprint: str
    host_session: str
    result: dict[str, Any]
    created_at: float


class Adapter:
    """One serial adapter session; the native host owns durable deduplication."""

    def __init__(self, host: HostConnection, *, clock=time.monotonic):
        self.host = host
        self.clock = clock
        self.connected = False
        self.host_session = ""
        self.capabilities: dict[str, Any] = {}
        self.records: OrderedDict[str, OperationRecord] = OrderedDict()
        self.retention_seconds = 1800
        self.record_capacity = 1024

    @staticmethod
    def _fingerprint(name: str, arguments: dict[str, Any]) -> str:
        payload = {"name": name, "arguments": {key: value for key, value in arguments.items()
                                                if key != "operation_id"}}
        serialized = json.dumps(payload, sort_keys=True, ensure_ascii=False, allow_nan=False)
        return hashlib.sha256(serialized.encode("utf-8")).hexdigest()

    def _prune_records(self) -> None:
        threshold = self.clock() - self.retention_seconds
        for operation_id in list(self.records):
            if self.records[operation_id].created_at < threshold:
                del self.records[operation_id]
        while len(self.records) > self.record_capacity:
            self.records.popitem(last=False)

    def _ensure_connected(self) -> None:
        if self.connected:
            return
        self.host.initialize()
        handshake = self.host.call_production("mmdtool_capabilities", {}, str(uuid.uuid4()))
        validate(handshake, TOOL_BY_NAME["mmdtool_capabilities"]["outputSchema"], "host_result")
        if not handshake["success"]:
            raise HostError(handshake["code"], handshake["message"])
        data = handshake["data"]
        if data.get("protocol_version") != PROTOCOL_VERSION:
            raise HostError("incompatible_protocol", "MMD Tool production API version is incompatible with this adapter.")
        if not isinstance(data.get("host_session"), str) or not data["host_session"]:
            raise HostError("host_protocol_error", "Production capabilities do not identify the host session.")
        if not isinstance(data.get("supported_operations"), list):
            raise HostError("host_protocol_error", "Production capabilities do not list supported operations.")
        self.host_session = data["host_session"]
        self.capabilities = data
        self.retention_seconds = min(max(int(data.get("retention_seconds", 1800)), 1), 86400)
        self.record_capacity = min(max(int(data.get("record_capacity", 1024)), 1), 16384)
        self.connected = True

    def call(self, name: str, raw_arguments: Any) -> dict[str, Any]:
        arguments = validated_arguments(name, raw_arguments)
        operation_id = arguments.get("operation_id", str(uuid.uuid4()))
        fingerprint = self._fingerprint(name, arguments)
        self._prune_records()
        previous = self.records.get(operation_id)
        if previous:
            if previous.fingerprint != fingerprint:
                return error_envelope("operation_id_conflict", "This operation ID was already used with different arguments.", operation_id)
            # In particular, an unknown outcome is returned without a second
            # HTTP request. Recovery uses the separate status tool.
            return previous.result
        may_mutate = not TOOL_BY_NAME[name]["annotations"]["readOnlyHint"]
        try:
            self._ensure_connected()
            if name not in self.capabilities["supported_operations"]:
                raise HostError("unsupported_operation", "The loaded plugin does not support this operation.")
            if name == "mmdtool_operation_status":
                queried = self.records.get(arguments["query_operation_id"])
                if queried and queried.host_session != self.host_session:
                    return error_envelope("outcome_unknown", "The host restarted; the earlier operation record cannot be recovered.",
                                          operation_id, outcome_unknown=True, host_session=self.host_session)
            result = self.host.call_production(name, arguments, operation_id, may_mutate=may_mutate)
            validate(result, TOOL_BY_NAME[name]["outputSchema"], "host_result")
            if result["operation_id"] != operation_id:
                raise HostError("host_protocol_error", "Production result operation ID does not match the request.",
                                outcome_unknown=may_mutate)
            if name == "mmdtool_operation_status" and result["success"]:
                original = result["data"].get("operation")
                queried = self.records.get(arguments["query_operation_id"])
                if queried and isinstance(original, dict):
                    validate(original, TOOL_BY_NAME[queried.tool_name]["outputSchema"], "operation")
                    if original.get("operation_id") == arguments["query_operation_id"]:
                        queried.result = original
            result.setdefault("host_session", self.host_session)
        except ValidationError:
            result = error_envelope("host_protocol_error", "Production result does not conform to the negotiated schema.",
                                    operation_id, outcome_unknown=may_mutate, host_session=self.host_session)
        except HostError as error:
            self.connected = False
            result = error_envelope(error.code, str(error), operation_id,
                                    outcome_unknown=error.outcome_unknown, host_session=self.host_session)
        self.records[operation_id] = OperationRecord(name, fingerprint, self.host_session, result, self.clock())
        self._prune_records()
        return result


class RpcError(ValueError):
    def __init__(self, code: int, message: str):
        super().__init__(message)
        self.code = code


class StdioServer:
    def __init__(self, adapter: Adapter):
        self.adapter = adapter
        self.initialized = False
        self.ready = False

    def handle(self, message: Any) -> dict[str, Any] | None:
        message_id = message.get("id") if isinstance(message, dict) else None
        notification = isinstance(message, dict) and "id" not in message
        try:
            if not isinstance(message, dict) or message.get("jsonrpc") != "2.0" or not isinstance(message.get("method"), str):
                raise RpcError(-32600, "Invalid JSON-RPC request")
            if not notification and (isinstance(message_id, bool) or not isinstance(message_id, (str, int))):
                raise RpcError(-32600, "Request ID must be a string or integer")
            method = message["method"]
            params = message.get("params", {})
            if not isinstance(params, dict):
                raise RpcError(-32602, "params must be an object")
            if method == "initialize":
                if self.initialized:
                    raise RpcError(-32600, "Already initialized")
                if notification:
                    raise RpcError(-32600, "initialize requires a request ID")
                version = params.get("protocolVersion")
                if not isinstance(version, str):
                    raise RpcError(-32602, "protocolVersion is required")
                chosen = version if version in SUPPORTED_MCP_VERSIONS else SUPPORTED_MCP_VERSIONS[0]
                self.initialized = True
                result = {"protocolVersion": chosen, "capabilities": {"tools": {"listChanged": False}},
                          "serverInfo": {"name": "mmdtool-mcp", "version": __version__},
                          "instructions": "Discover document/object handles with mmdtool_capabilities. Query operation IDs after timeout; never repeat an uncertain mutation."}
            elif method == "notifications/initialized":
                if not self.initialized:
                    raise RpcError(-32600, "Initialize first")
                self.ready = True
                return None
            elif method == "ping":
                result = {}
            elif method.startswith("notifications/"):
                # No cancellable asynchronous work is advertised. A cancellation
                # does not prove native rollback; callers query operation status.
                return None
            else:
                if not self.ready:
                    raise RpcError(-32600, "Complete the initialization handshake first")
                if method == "tools/list":
                    if params.get("cursor"):
                        raise RpcError(-32602, "This fixed tool catalog does not use cursors")
                    result = {"tools": TOOLS}
                elif method == "tools/call":
                    if set(params) - {"name", "arguments", "_meta"}:
                        raise RpcError(-32602, "Unknown tools/call parameter")
                    name = params.get("name")
                    if not isinstance(name, str) or name not in TOOL_BY_NAME:
                        raise RpcError(-32602, "Unknown tool")
                    try:
                        envelope = self.adapter.call(name, params.get("arguments", {}))
                    except ValidationError as error:
                        raise RpcError(-32602, str(error)) from error
                    result = {"content": [{"type": "text", "text": json.dumps(envelope, ensure_ascii=False, allow_nan=False)}],
                              "structuredContent": envelope, "isError": not envelope["success"]}
                else:
                    raise RpcError(-32601, "Method not found")
            if notification:
                return None
            return {"jsonrpc": "2.0", "id": message_id, "result": result}
        except RpcError as error:
            if notification:
                return None
            return {"jsonrpc": "2.0", "id": message_id,
                    "error": {"code": error.code, "message": str(error)}}

    def serve(self, source: BinaryIO, destination: BinaryIO) -> None:
        while True:
            line = source.readline(MAX_REQUEST_BYTES + 1)
            if not line:
                return
            if len(line) > MAX_REQUEST_BYTES:
                while line and not line.endswith(b"\n"):
                    line = source.readline(MAX_REQUEST_BYTES + 1)
                response = {"jsonrpc": "2.0", "id": None,
                            "error": {"code": -32600, "message": "Request exceeds adapter byte limit"}}
            else:
                try:
                    message = json.loads(line.decode("utf-8"), parse_constant=lambda _: (_ for _ in ()).throw(ValueError()))
                    response = self.handle(message)
                except (ValueError, UnicodeError):
                    response = {"jsonrpc": "2.0", "id": None,
                                "error": {"code": -32700, "message": "Invalid UTF-8 JSON"}}
                except Exception:
                    # Keep credentials and host exception internals out of both
                    # stdout and stderr; preserve valid JSON-RPC framing.
                    response = {"jsonrpc": "2.0", "id": message.get("id") if isinstance(message, dict) else None,
                                "error": {"code": -32603, "message": "Internal adapter error"}}
            if response is not None:
                destination.write(json.dumps(response, ensure_ascii=False, allow_nan=False).encode("utf-8") + b"\n")
                destination.flush()


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Typed stdio MCP adapter for the local Cinema 4D MMD Tool.")
    parser.add_argument("--endpoint", default=os.environ.get("CMT_MCP_ENDPOINT", "http://127.0.0.1:5556/mcp"))
    parser.add_argument("--token-file", default=os.environ.get("CMT_MCP_TOKEN_FILE"),
                        help="Local token file created by the enabled Cinema 4D MCP server.")
    parser.add_argument("--timeout", type=float, default=180,
                        help="Host wait in seconds (1-600). Timeouts never repeat mutations.")
    args = parser.parse_args(argv)
    if not args.token_file:
        parser.error("--token-file or CMT_MCP_TOKEN_FILE is required; no credential is printed")
    if not math.isfinite(args.timeout) or not 1 <= args.timeout <= 600:
        parser.error("--timeout must be finite and between 1 and 600 seconds")
    try:
        host = HostConnection(args.endpoint, args.token_file, args.timeout)
    except HostError as error:
        print(f"{error.code}: {error}", file=sys.stderr)
        return 2
    StdioServer(Adapter(host)).serve(sys.stdin.buffer, sys.stdout.buffer)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
