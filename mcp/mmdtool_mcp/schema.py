"""Tool contracts and a validator for the JSON Schema subset used here.

Keeping definitions and validation together prevents discovery from accepting
options that the fixed native bridge cannot encode. No dynamic SDK fields or
client-provided Python are accepted.
"""

from __future__ import annotations

import copy
import math
import ntpath
import posixpath
import re
from typing import Any

PROTOCOL_VERSION = 1
MAX_PAGE_SIZE = 256
MAX_REQUEST_BYTES = 65536

# These IDs are the versioned production protocol, not private SDK parameters.
OPTION_IDS = {
    "path": 100, "position_multiple": 101, "strategy": 102,
    "motion": 103, "morph": 104, "model_info": 105, "time_offset": 106,
    "ignore_physics": 107, "local_names": 108, "bake": 109,
    "rotation": 110, "overwrite": 111, "slot": 112, "mode": 113,
    "enabled": 114, "morph_handle": 115, "strength": 116, "frame": 117,
    "unit": 118, "set_playhead": 119, "offset": 120, "limit": 121,
    "section": 122, "polygon": 123, "normals": 124, "uv": 125,
    "materials": 126, "bones": 127, "weights": 128, "ik": 129,
    "inherit": 130, "expressions": 131, "multipart": 132,
    "english": 133, "english_check": 134, "material_type": 135,
    "query_operation_id": 136,
}


class ValidationError(ValueError):
    """A field-specific input or native-result contract failure."""


def obj(properties: dict[str, Any], required: tuple[str, ...] = ()) -> dict[str, Any]:
    return {"type": "object", "properties": properties,
            "required": list(required), "additionalProperties": False}


def string(description: str = "", *, maximum: int = 1024) -> dict[str, Any]:
    return {"type": "string", "minLength": 1, "maxLength": maximum,
            "description": description}


def choice(*values: str, default: str | None = None) -> dict[str, Any]:
    result: dict[str, Any] = {"type": "string", "enum": list(values)}
    if default is not None:
        result["default"] = default
    return result


def boolean(default: bool) -> dict[str, Any]:
    return {"type": "boolean", "default": default}


HANDLE = string("Opaque handle returned by this live plugin session; never a name or PMX index.")
OPERATION_ID = {**string("UUID used for deduplication; query this ID after an uncertain outcome."),
                "format": "uuid", "maxLength": 36}
PATH = string("Absolute local file path. The adapter does not download assets.", maximum=4096)
SCALE = {"type": "number", "exclusiveMinimum": 0, "maximum": 1000000,
         "default": 8.5}
OFFSET = {"type": "integer", "minimum": -100000000, "maximum": 100000000,
          "default": 0, "description": "Integral VMD frames at 30 fps."}
PAGING = {"offset": {"type": "integer", "minimum": 0, "maximum": 100000000,
                     "default": 0},
          "limit": {"type": "integer", "minimum": 1, "maximum": MAX_PAGE_SIZE,
                    "default": 64}}
PMX_SWITCHES = {name: boolean(True) for name in
                ("polygon", "normals", "uv", "materials", "bones", "weights",
                 "ik", "inherit", "expressions")}


def input_schema(*, target: str | None = None, document: bool = True,
                 properties: dict[str, Any] | None = None,
                 required: tuple[str, ...] = ()) -> dict[str, Any]:
    fields = {"operation_id": copy.deepcopy(OPERATION_ID)}
    required_fields = list(required)
    if document:
        fields["document"] = copy.deepcopy(HANDLE)
        required_fields.append("document")
    if target:
        fields[target] = copy.deepcopy(HANDLE)
        required_fields.append(target)
    fields.update(copy.deepcopy(properties or {}))
    return obj(fields, tuple(required_fields))


DOCUMENT = obj({"handle": HANDLE, "name": {"type": "string"},
                "active": {"type": "boolean"}}, ("handle", "name", "active"))
MODEL = obj({"handle": HANDLE, "name": {"type": "string"},
             "mode": choice("edit", "anim"), "physics_enabled": {"type": "boolean"},
             "bone_count": {"type": "integer"}, "morph_count": {"type": "integer"},
             "slot_count": {"type": "integer"}},
            ("handle", "name", "mode", "physics_enabled", "bone_count", "morph_count", "slot_count"))
INSPECTION_ITEM = obj({"handle": HANDLE, "name": {"type": "string"},
                       "strength": {"type": "number"}, "type": {"type": "integer"},
                       "max_frame": {"type": "integer"}, "active": {"type": "boolean"}},
                      ("handle", "name"))
ANIMATION_SLOT = obj({"handle": HANDLE, "name": {"type": "string"},
                      "max_frame": {"type": "integer"}, "active": {"type": "boolean"}},
                     ("handle", "name", "max_frame", "active"))
FILE_IDENTITY = {"path": PATH, "size": {"type": "integer", "minimum": 0},
                 "bytes": {"type": "integer", "minimum": 0},
                 "sha256": {"type": "string", "pattern": "^[0-9a-f]{64}$"}}


def array(item: dict[str, Any]) -> dict[str, Any]:
    return {"type": "array", "items": item}


def output_schema(data: dict[str, Any], *, completed_required: tuple[str, ...] = (),
                  completed_alternatives: tuple[tuple[str, ...], ...] = ()) -> dict[str, Any]:
    # Data properties are operation-specific; native counts and future additive
    # API details may be added without breaking an older client.
    result = obj({"success": {"type": "boolean"}, "code": {"type": "string"},
                "message": {"type": "string"}, "operation_id": {"type": "string"},
                "state": choice("queued", "running", "completed", "failed", "outcome_unknown"),
                "host_session": {"type": "string"},
                "data": {"type": "object", "properties": data, "additionalProperties": True},
                "warnings": array({"type": "string"})},
               ("success", "code", "message", "operation_id", "state", "data", "warnings"))
    if completed_required or completed_alternatives:
        if completed_alternatives:
            complete_data = {"anyOf": [{"required": list(fields)} for fields in completed_alternatives]}
        else:
            complete_data = {"required": list(completed_required)}
        # Accepted/running and failed/unknown envelopes may contain no data.
        # Both discovery and local validation require complete successful data.
        result["if"] = {"properties": {"success": {"const": True}, "state": {"const": "completed"}},
                        "required": ["success", "state"]}
        result["then"] = {"properties": {"data": complete_data}}
    return result


def tool(name: str, description: str, schema: dict[str, Any],
         data: dict[str, Any], *, read_only: bool = False,
         completed_required: tuple[str, ...] | None = None,
         completed_alternatives: tuple[tuple[str, ...], ...] = ()) -> dict[str, Any]:
    return {"name": name, "description": description, "inputSchema": schema,
            "outputSchema": output_schema(data,
                completed_required=tuple(data) if completed_required is None else completed_required,
                completed_alternatives=completed_alternatives),
            "annotations": {"readOnlyHint": read_only,
                            "destructiveHint": not read_only,
                            "idempotentHint": read_only, "openWorldHint": False}}


TOOLS = [
    tool("mmdtool_capabilities", "Check host/plugin/API compatibility and discover live document handles.",
         input_schema(document=False),
         {"protocol_version": {"type": "integer"}, "plugin_version": {"type": "string"},
          "host_version": {"type": ["string", "integer"]}, "host_session": {"type": "string"},
          "supported_operations": array({"type": "string"}), "documents": array(DOCUMENT),
          "cameras": array(obj({"handle": HANDLE, "document": HANDLE, "name": {"type": "string"},
                                "type": choice("ordinary", "mmd")}, ("handle", "document", "name", "type"))),
          "retention_seconds": {"type": "integer"}, "record_capacity": {"type": "integer"},
          "max_page_size": {"type": "integer"},
          "max_input_bytes": {"type": "integer"}, "transport_supported": {"type": "boolean"},
          "execution": {"type": "string"},
          "material_types": array(choice("standard", "redshift", "octane", "corona", "redshift_toon"))}, read_only=True),
    tool("mmdtool_list_models", "List MMD models in the explicitly selected document, with opaque handles.",
         input_schema(properties=PAGING),
         {"models": array(MODEL), "total": {"type": "integer"}, "next_offset": {"type": "integer"}},
         read_only=True),
    tool("mmdtool_inspect_model", "Inspect one model; paginate bones, morphs or slots using section.",
         input_schema(target="model", properties={**PAGING, "section": choice(
             "summary", "bones", "morphs", "slots", default="summary")}),
         {"model": MODEL, "items": array(INSPECTION_ITEM), "slots": array(ANIMATION_SLOT),
          "active_slot": {"type": "string"}, "total": {"type": "integer"},
          "next_offset": {"type": "integer"}}, read_only=True,
         completed_alternatives=(("model", "items", "total", "next_offset"),
                                 ("slots", "active_slot", "total", "next_offset"))),
    tool("mmdtool_import_pmx", "Import a local PMX into one document as one Undo action.",
         input_schema(properties={"path": PATH, "position_multiple": SCALE, **PMX_SWITCHES,
                                  "multipart": boolean(False), "english": boolean(False),
                                  "english_check": boolean(False), "material_type": choice(
                                      "standard", "redshift", "octane", "corona", "redshift_toon", default="standard")},
                      required=("path",)),
         {"model": MODEL, "counts": {"type": "object"}}, completed_required=("model",)),
    tool("mmdtool_export_pmx", "Export one PMX; existing files require overwrite=true. Preserve source state.",
         input_schema(target="model", properties={"path": PATH, "position_multiple": SCALE,
                      **PMX_SWITCHES, "overwrite": boolean(False)}, required=("path",)), FILE_IDENTITY),
    tool("mmdtool_import_motion", "Import VMD with explicit append/replace/merge semantics and channel switches.",
         input_schema(target="model", properties={"path": PATH, "position_multiple": SCALE,
                      "strategy": choice("append", "replace", "merge", default="append"),
                      "motion": boolean(True), "morph": boolean(True), "model_info": boolean(True),
                      "time_offset": OFFSET, "ignore_physics": boolean(True), "local_names": boolean(True)},
                      required=("path",)),
         {"slot": HANDLE, "bone_count": {"type": "integer"}, "morph_count": {"type": "integer"},
          "frame_count": {"type": "integer"}, "unmatched_bones": array({"type": "string"}),
          "unmatched_morphs": array({"type": "string"})}),
    tool("mmdtool_export_motion", "Export VMD with channel switches and optional isolated baking.",
         input_schema(target="model", properties={"path": PATH, "position_multiple": SCALE,
                      "motion": boolean(True), "morph": boolean(True), "model_info": boolean(True),
                      "time_offset": OFFSET, "bake": boolean(True), "rotation": choice(
                          "quaternion", "euler", default="quaternion"), "overwrite": boolean(False)},
                      required=("path",)),
         {**FILE_IDENTITY, "bone_count": {"type": "integer"}, "morph_count": {"type": "integer"},
          "frame_count": {"type": "integer"}}, completed_required=tuple(FILE_IDENTITY)),
    tool("mmdtool_import_camera", "Import a VMD camera into the explicitly selected document.",
         input_schema(properties={"path": PATH, "position_multiple": SCALE, "time_offset": OFFSET},
                      required=("path",)), {"camera": HANDLE, "frame_count": {"type": "integer"}}),
    tool("mmdtool_export_camera", "Export an identified MMD or ordinary camera to VMD without source conversion.",
         input_schema(target="camera", properties={"path": PATH, "position_multiple": SCALE,
                      "time_offset": OFFSET, "bake": boolean(True), "rotation": choice(
                          "quaternion", "euler", default="quaternion"), "overwrite": boolean(False)},
                      required=("path",)), {**FILE_IDENTITY, "frame_count": {"type": "integer"}},
         completed_required=tuple(FILE_IDENTITY)),
    tool("mmdtool_list_animation_slots", "List animation slot handles, names and duration; no index targeting.",
         input_schema(target="model", properties=PAGING),
         {"slots": array(ANIMATION_SLOT), "active_slot": {"type": "string"},
          "total": {"type": "integer"}, "next_offset": {"type": "integer"}}, read_only=True),
    tool("mmdtool_select_animation_slot", "Select an existing slot by its handle as one Undo action.",
         input_schema(target="model", properties={"slot": HANDLE}, required=("slot",)),
         {"active_slot": HANDLE}),
    tool("mmdtool_set_mode", "Switch EDIT/ANIM, preserving native bind-state commit and restore behavior.",
         input_schema(target="model", properties={"mode": choice("edit", "anim")}, required=("mode",)),
         {"mode": choice("edit", "anim")}),
    tool("mmdtool_set_physics_enabled", "Change physics with the native rebuild behavior as one Undo action.",
         input_schema(target="model", properties={"enabled": {"type": "boolean"}}, required=("enabled",)),
         {"physics_enabled": {"type": "boolean"}}),
    tool("mmdtool_set_morph_strength", "Set the finite strength of an existing morph by handle.",
         input_schema(target="model", properties={"morph_handle": HANDLE,
                      "strength": {"type": "number", "minimum": -1000000, "maximum": 1000000}},
                      required=("morph_handle", "strength")),
         {"morph_handle": HANDLE, "strength": {"type": "number"}}),
    tool("mmdtool_evaluate_frame", "Evaluate in explicit units; temporary sampling preserves the source playhead.",
         input_schema(target="model", properties={"frame": {"type": "number", "minimum": -100000000,
                      "maximum": 100000000}, "unit": choice("vmd_frames", "document_frames", "seconds"),
                      "set_playhead": boolean(False)}, required=("frame", "unit")),
         {"frame": {"type": "number"}, "unit": {"type": "string"},
          "seconds": {"type": "number"}, "fps": {"type": "integer"},
          "finite": {"type": "boolean"}, "bone_count": {"type": "integer"},
          "pose": array({"type": "object"})},
         completed_required=("frame", "unit", "seconds", "fps", "finite", "bone_count")),
    tool("mmdtool_operation_status", "Query a retained operation ID after a timeout; never repeat an uncertain mutation.",
         input_schema(document=False, properties={"query_operation_id": OPERATION_ID},
                      required=("query_operation_id",)),
         {"operation": output_schema({})}, read_only=True),
]
TOOL_BY_NAME = {item["name"]: item for item in TOOLS}


def validate(value: Any, schema: dict[str, Any], field: str = "arguments") -> None:
    """Validate exactly the subset advertised by the maintained tool schemas."""
    expected = schema.get("type")
    accepted = expected if isinstance(expected, list) else [expected]
    matches = {"object": isinstance(value, dict), "array": isinstance(value, list),
               "string": isinstance(value, str), "boolean": isinstance(value, bool),
               "integer": isinstance(value, int) and not isinstance(value, bool),
               "number": isinstance(value, (int, float)) and not isinstance(value, bool),
               "null": value is None}
    if expected and not any(matches.get(kind, False) for kind in accepted):
        raise ValidationError(f"{field}: expected {expected}")
    if isinstance(value, (int, float)) and not isinstance(value, bool):
        if not math.isfinite(value):
            raise ValidationError(f"{field}: must be finite")
        for key, compare in (("minimum", lambda a, b: a < b),
                             ("maximum", lambda a, b: a > b),
                             ("exclusiveMinimum", lambda a, b: a <= b)):
            if key in schema and compare(value, schema[key]):
                raise ValidationError(f"{field}: violates {key} {schema[key]}")
    if "enum" in schema and value not in schema["enum"]:
        raise ValidationError(f"{field}: unsupported value")
    if "const" in schema and value != schema["const"]:
        raise ValidationError(f"{field}: unexpected constant")
    if isinstance(value, str):
        if "\x00" in value:
            raise ValidationError(f"{field}: NUL is not allowed")
        for bound, invalid in (("minLength", len(value) < schema.get("minLength", 0)),
                               ("maxLength", len(value) > schema.get("maxLength", 2**31))):
            if invalid:
                raise ValidationError(f"{field}: violates {bound}")
        if "pattern" in schema and not re.fullmatch(schema["pattern"], value):
            raise ValidationError(f"{field}: invalid format")
        if schema.get("format") == "uuid" and not re.fullmatch(
                r"[0-9a-fA-F]{8}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{4}-[0-9a-fA-F]{12}", value):
            raise ValidationError(f"{field}: expected UUID")
    if isinstance(value, dict):
        properties = schema.get("properties", {})
        for name in schema.get("required", []):
            if name not in value:
                raise ValidationError(f"{field}.{name}: required")
        for name, item in value.items():
            if name in properties:
                validate(item, properties[name], f"{field}.{name}")
            elif schema.get("additionalProperties") is False:
                raise ValidationError(f"{field}.{name}: unknown option")
    if isinstance(value, list) and "items" in schema:
        for index, item in enumerate(value):
            validate(item, schema["items"], f"{field}[{index}]")
    if "anyOf" in schema:
        for alternative in schema["anyOf"]:
            try:
                validate(value, alternative, field)
                break
            except ValidationError:
                continue
        else:
            raise ValidationError(f"{field}: does not match a documented result shape")
    if "if" in schema:
        try:
            validate(value, schema["if"], field)
        except ValidationError:
            conditional = schema.get("else")
        else:
            conditional = schema.get("then")
        if conditional is not None:
            validate(value, conditional, field)


def validated_arguments(name: str, arguments: Any) -> dict[str, Any]:
    if name not in TOOL_BY_NAME:
        raise ValidationError("name: unknown tool")
    definition = TOOL_BY_NAME[name]["inputSchema"]
    validate(arguments, definition)
    if "path" in arguments and not (ntpath.isabs(arguments["path"]) or posixpath.isabs(arguments["path"])):
        raise ValidationError("arguments.path: expected an absolute local file path")
    result = copy.deepcopy(arguments)
    for key, definition in definition["properties"].items():
        if key not in result and "default" in definition:
            result[key] = copy.deepcopy(definition["default"])
    if name in ("mmdtool_import_pmx", "mmdtool_export_pmx"):
        if result["weights"] and (not result["polygon"] or not result["bones"]):
            raise ValidationError("arguments.weights: requires polygon=true and bones=true")
        if not result["bones"] and (result["ik"] or result["inherit"]):
            raise ValidationError("arguments.ik/inherit: require bones=true")
        if not result["polygon"] and (result["normals"] or result["uv"] or result["materials"]):
            raise ValidationError("arguments.normals/uv/materials: require polygon=true")
        if name == "mmdtool_import_pmx" and result["multipart"] and not result["polygon"]:
            raise ValidationError("arguments.multipart: requires polygon=true")
    return result
