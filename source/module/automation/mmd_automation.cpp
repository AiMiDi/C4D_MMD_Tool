#include "module/core/cmt_old_sdk_stl_preload.h"
#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <limits>
#include <memory>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

#include "mmd_automation.h"
#include "module/tools/sizing/sizing_session.h"
#include "CMTSceneManager.h"
#include "plugin_resource.h"
#include "module/tools/object/mmd_bone_manager.h"
#include "module/tools/object/mmd_camera.h"
#include "module/tools/object/mmd_model_manager.h"
#include "module/tools/object/mmd_morph.h"
#include "module/tools/material/mmd_material.h"
#include "module/tools/material/mmd_redshift_toon_material.h"
#include "utils/cmt_automation_protocol.hpp"
#include "utils/cmt_motion_validation.hpp"
#include "utils/filename_util.hpp"
#include "utils/string_util.hpp"
#include "libMMD/Base/UnicodeUtil.h"

#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#else
#include <unistd.h>
#endif

namespace cmt { namespace automation
{
namespace
{

// Small JSON writer: all strings are escaped; SDK/container data never becomes
// executable code. The response is serialized once for the fixed Python call.
struct Json
{
	std::string text;
	explicit Json(std::string value = "{}") : text(std::move(value)) {}
	static Json StringValue(const std::string& value)
	{
		std::ostringstream out;
		out << '"';
		for (const unsigned char character : value)
		{
			if (character == '"' || character == '\\')
				out << '\\' << static_cast<char>(character);
			else if (character < 32)
				out << "\\u" << std::hex << std::setw(4) << std::setfill('0') << static_cast<int>(character) << std::dec;
			else
				out << static_cast<char>(character);
		}
		out << '"';
		return Json(out.str());
	}
	static Json StringValue(const String& value) { return StringValue(string_util::GetStdString(value)); }
	static Json Number(double value)
	{
		if (!std::isfinite(value))
			return Json("null");
		std::ostringstream out;
		out << std::setprecision(17) << value;
		return Json(out.str());
	}
	static Json Integer(UInt64 value) { return Json(std::to_string(value)); }
	static Json Boolean(Bool value) { return Json(value ? "true" : "false"); }
	static Json Object(const std::vector<std::pair<std::string, Json>>& values)
	{
		std::string out = "{";
		for (const auto& value : values)
		{
			if (out.size() != 1) out += ',';
			out += StringValue(value.first).text + ':' + value.second.text;
		}
		return Json(out + '}');
	}
	static Json Array(const std::vector<Json>& values)
	{
		std::string out = "[";
		for (const Json& value : values)
		{
			if (out.size() != 1) out += ',';
			out += value.text;
		}
		return Json(out + ']');
	}
};

enum class Operation
{
	Capabilities, ListModels, InspectModel, ImportPmx, ExportPmx,
	ImportMotion, ExportMotion, ImportCamera, ExportCamera,
	ListSlots, SelectSlot, SetMode, SetPhysics, SetMorph, Evaluate, Status,
    SizingStart, SizingStatus, SizingResult, SizingCancel, SizingPreview, SizingClosePreview,
    SizingApply, SizingExport, SizingApplyCamera, SizingExportCamera, SizingRelease, Invalid
};

const char* const kOperationNames[] = {
	"mmdtool_capabilities", "mmdtool_list_models", "mmdtool_inspect_model",
	"mmdtool_import_pmx", "mmdtool_export_pmx", "mmdtool_import_motion",
	"mmdtool_export_motion", "mmdtool_import_camera", "mmdtool_export_camera",
	"mmdtool_list_animation_slots", "mmdtool_select_animation_slot",
	"mmdtool_set_mode", "mmdtool_set_physics_enabled", "mmdtool_set_morph_strength",
	"mmdtool_evaluate_frame", "mmdtool_operation_status",
    "mmdtool_sizing_start", "mmdtool_sizing_status", "mmdtool_sizing_result", "mmdtool_sizing_cancel",
    "mmdtool_sizing_preview", "mmdtool_sizing_close_preview", "mmdtool_sizing_apply", "mmdtool_sizing_export",
    "mmdtool_sizing_apply_camera", "mmdtool_sizing_export_camera", "mmdtool_sizing_release"
};

Operation ParseOperation(const std::string& name)
{
	for (Int32 index = 0; index < static_cast<Int32>(Operation::Invalid); ++index)
		if (name == kOperationNames[index]) return static_cast<Operation>(index);
	return Operation::Invalid;
}

std::vector<Int32> AllowedOptions(Operation operation)
{
	switch (operation)
	{
		case Operation::Capabilities: return {};
		case Operation::ListModels: case Operation::ListSlots: return {Offset, Limit};
		case Operation::InspectModel: return {Offset, Limit, Section};
		case Operation::ImportPmx: return {Path, PositionMultiple, Polygon, Normals, UV, Materials, Bones,
			Weights, IK, Inherit, Expressions, Multipart, English, EnglishCheck, MaterialType};
		case Operation::ExportPmx: return {Path, PositionMultiple, Polygon, Normals, UV, Materials, Bones,
			Weights, IK, Inherit, Expressions, Overwrite};
		case Operation::ImportMotion: return {Path, PositionMultiple, Strategy, Motion, Morph, ModelInfo,
			TimeOffset, IgnorePhysics, LocalNames};
		case Operation::ExportMotion: return {Path, PositionMultiple, Motion, Morph, ModelInfo,
			TimeOffset, Bake, Rotation, Overwrite};
		case Operation::ImportCamera: return {Path, PositionMultiple, TimeOffset};
		case Operation::ExportCamera: return {Path, PositionMultiple, TimeOffset, Bake, Rotation, Overwrite};
		case Operation::SelectSlot: return {Slot};
		case Operation::SetMode: return {Mode};
		case Operation::SetPhysics: return {Enabled};
		case Operation::SetMorph: return {MorphHandle, Strength};
		case Operation::Evaluate: return {Frame, Unit, SetPlayhead};
		case Operation::Status: return {QueryOperationId};
        case Operation::SizingStart: return {SizingCharacters, SizingOptions, SizingCameraPath, SizingCameraRatio};
        case Operation::SizingStatus: case Operation::SizingCancel: case Operation::SizingClosePreview:
        case Operation::SizingApplyCamera: case Operation::SizingRelease: return {SizingJob};
        case Operation::SizingResult: return {SizingJob, SizingMember, Section, Offset, Limit};
        case Operation::SizingPreview: return {SizingJob, SizingMember, SizingStage, SizingOverlay};
        case Operation::SizingApply: return {SizingJob, SizingMember, SizingStage};
        case Operation::SizingExport: return {SizingJob, SizingMember, SizingStage, Path, Overwrite};
        case Operation::SizingExportCamera: return {SizingJob, Path, Overwrite};
		default: return {};
	}
}

Bool Has(const BaseContainer& container, Int32 field) { return container.GetData(field).GetType() != DA_NIL; }
Bool IsUuid(const std::string& value)
{
	if (value.size() != 36) return false;
	for (size_t index = 0; index < value.size(); ++index)
	{
		const char character = value[index];
		if (index == 8 || index == 13 || index == 18 || index == 23)
		{ if (character != '-') return false; }
		else if (!((character >= '0' && character <= '9') || (character >= 'a' && character <= 'f') ||
			(character >= 'A' && character <= 'F'))) return false;
	}
	return true;
}

std::string Text(const BaseContainer& container, Int32 field, const char* fallback = "")
{
	return Has(container, field) ? string_util::GetStdString(container.GetString(field)) : std::string(fallback);
}

double Number(const BaseContainer& container, Int32 field, double fallback = 0)
{
	if (!Has(container, field)) return fallback;
	return container.GetData(field).GetType() == DA_LONG ? container.GetInt32(field) : container.GetFloat(field);
}

Bool TryEvaluationTime(double value, Int32 rate, BaseTime& time)
{
	if (rate < 1 || !std::isfinite(value))
		return false;
	// Both BaseTime constructors and SDK time copies expect integer fraction
	// components. Decimal scaling retains subframe/second precision before GCD
	// reduction; lower the scale for large inputs to keep Int64 conversion safe.
	Int64 scale = 1000000000000LL;
	const double magnitude = std::max(std::abs(value), static_cast<double>(rate));
	while (magnitude > 1.0e18 / static_cast<double>(scale))
		scale /= 10;
	const Int64 numerator = static_cast<Int64>(std::round(value * static_cast<double>(scale)));
	const Int64 denominator = static_cast<Int64>(rate) * scale;
	if (value != 0.0 && numerator == 0)
		return false;
	const Int64 divisor = std::gcd(numerator, denominator);
	time = BaseTime(static_cast<Float>(numerator / divisor), static_cast<Float>(denominator / divisor));
	return std::isfinite(time.Get());
}

Bool IsBooleanOption(Int32 field)
{
	return field == Motion || field == Morph || field == ModelInfo || field == IgnorePhysics ||
		field == LocalNames || field == Bake || field == Overwrite || field == Enabled ||
		field == SetPlayhead || (field >= Polygon && field <= EnglishCheck);
}

Bool ValidateSizingOptions(const BaseContainer& options, std::string& error)
{
    for (Int32 i = 0, field; (field = options.GetIndexId(i)) != NOTOK; ++i)
    {
        const Int32 type = options.GetData(field).GetType();
        if (field >= SizingCenterOffsets && field <= SizingMultiContact)
        {
            if (type != DA_LONG || (options.GetInt32(field) != 0 && options.GetInt32(field) != 1))
            { error = "Sizing switch must be boolean"; return false; }
        }
        else if (field == SizingAvoidanceBodies)
        {
            const auto* bodies = options.GetContainerInstance(field);
            if (!bodies) { error = "avoidance_bodies must be a container"; return false; }
            for (Int32 j = 0, key; (key = bodies->GetIndexId(j)) != NOTOK; ++j)
                if (key != j || j >= 256 || bodies->GetData(key).GetType() != DA_STRING ||
                    Text(*bodies, key).empty() || Text(*bodies, key).size() > 1024)
                { error = "Invalid avoidance body list"; return false; }
        }
        else if (field >= SizingIterations && field <= SizingMaxDiagnostics)
        {
            const Int32 upper = field == SizingIterations ? 1000 : field == SizingMaxFrames ? 18000 :
                field == SizingMaxKeys ? 2000000 : 20000;
            if (type != DA_LONG || options.GetInt32(field) < (field == SizingMaxDiagnostics ? 0 : 1) || options.GetInt32(field) > upper)
            { error = "Sizing integer budget exceeds bounds"; return false; }
        }
        else if (field == SizingMovement || field == SizingLegOffset ||
                 (field >= SizingContactDistance && field <= SizingTolerance))
        {
            const double value = Number(options, field);
            const double maximum = field == SizingMovement || field == SizingTolerance ? 1000 : 10000;
            const double minimum = field == SizingLegOffset || field == SizingFloorHeight ? -10000 : 0;
            if ((type != DA_REAL && type != DA_LONG) || !std::isfinite(value) || value < minimum || value > maximum ||
                ((field == SizingMovement || field == SizingContactDistance || field == SizingTolerance) && value == 0))
            { error = "Sizing numeric option exceeds bounds"; return false; }
        }
        else { error = "Unknown sizing option"; return false; }
    }
    return true;
}

Bool ValidateSizingCharacters(const BaseContainer& characters, std::string& error)
{
    Int32 count = 0;
    for (Int32 key; (key = characters.GetIndexId(count)) != NOTOK; ++count)
    {
        const auto* input = characters.GetContainerInstance(key);
        if (key != count || count >= 16 || !input)
        { error = "Expected 1-16 ordered character containers"; return false; }
        for (Int32 j = 0, field; (field = input->GetIndexId(j)) != NOTOK; ++j)
        {
            if (field == SizingOptions)
            {
                const auto* values = input->GetContainerInstance(field);
                if (!values || !ValidateSizingOptions(*values, error)) return false;
            }
            else if (field == SizingModel || field == SizingSource || field == Path || field == Slot)
            {
                if (input->GetData(field).GetType() != DA_STRING || Text(*input, field).empty() ||
                    Text(*input, field).size() > (field == Path || field == SizingSource ? 4096u : 1024u))
                { error = "Invalid character handle or path"; return false; }
            }
            else { error = "Unknown character field"; return false; }
        }
        if (!Has(*input, SizingModel) || !Has(*input, SizingSource) || Has(*input, Path) == Has(*input, Slot))
        { error = "Each character requires model, source_pmx and exactly one of path/slot"; return false; }
    }
    if (count == 0) { error = "At least one character is required"; return false; }
    return true;
}

const char* const kSizingStages[] = {"original", "scale", "offset", "stance", "twist", "avoidance", "contact", "multi_character"};
size_t SizingStageIndex(const BaseContainer& options)
{
    const std::string name = Text(options, SizingStage, "multi_character");
    for (size_t i = 0; i < static_cast<size_t>(libmmd::sizing::Stage::Count); ++i)
        if (name == kSizingStages[i]) return i;
    return static_cast<size_t>(libmmd::sizing::Stage::Count);
}

Bool ValidateRequest(const BaseContainer& request, Operation operation, std::string& error)
{
	for (Int32 index = 0, field; (field = request.GetIndexId(index)) != NOTOK; ++index)
		if (field < Protocol || field > Options) { error = "Unknown request field"; return false; }
	if (request.GetData(Protocol).GetType() != DA_LONG || request.GetInt32(Protocol) != kProtocolVersion)
	{ error = "Protocol version mismatch"; return false; }
	for (Int32 field : {OperationName, OperationId, DocumentHandle, TargetHandle})
		if (request.GetData(field).GetType() != DA_STRING || Text(request, field).size() > 1024)
		{ error = "Missing or invalid request string"; return false; }
	if (!IsUuid(Text(request, OperationId))) { error = "operation_id must be a UUID"; return false; }
	if (operation == Operation::Invalid) { error = "Unknown operation"; return false; }
	const BaseContainer* options = request.GetContainerInstance(Options);
	if (!options) { error = "Missing options container"; return false; }
	const auto allowed = AllowedOptions(operation);
	for (Int32 index = 0, field; (field = options->GetIndexId(index)) != NOTOK; ++index)
	{
		if (std::find(allowed.begin(), allowed.end(), field) == allowed.end())
		{ error = "Unknown option for this operation"; return false; }
		const Int32 type = options->GetData(field).GetType();
		if (field == SizingOptions || field == SizingCharacters)
        {
            const auto* values = options->GetContainerInstance(field);
            if (!values || !(field == SizingOptions ? ValidateSizingOptions(*values, error) : ValidateSizingCharacters(*values, error)))
                return false;
        }
        else if (IsBooleanOption(field) || field == SizingOverlay)
		{
			if (type != DA_LONG || (options->GetInt32(field) != 0 && options->GetInt32(field) != 1))
			{ error = "Boolean option must be true or false"; return false; }
		}
		else if (field == PositionMultiple || field == Strength || field == Frame || field == SizingCameraRatio)
		{
			if ((type != DA_REAL && type != DA_LONG) || !std::isfinite(Number(*options, field)))
			{ error = "Numeric option must be finite"; return false; }
		}
		else if (field == TimeOffset || field == Offset || field == Limit || field == SizingMember)
		{
			if (type != DA_LONG) { error = "Frame offset and paging require integer values"; return false; }
		}
		else if (type != DA_STRING || Text(*options, field).empty() ||
			Text(*options, field).size() > (field == Path || field == SizingCameraPath ? 4096u : 1024u))
		{ error = "String option is missing or too long"; return false; }
	}
    if (Has(*options, SizingCameraRatio) && (Number(*options, SizingCameraRatio) < 1 || Number(*options, SizingCameraRatio) > 100))
    { error = "Invalid camera distance ratio"; return false; }
    if (options->GetInt32(SizingMember, 0) < 0 || options->GetInt32(SizingMember, 0) > 15)
    { error = "Invalid character member"; return false; }
    if (Has(*options, SizingStage) && SizingStageIndex(*options) == static_cast<size_t>(libmmd::sizing::Stage::Count))
    { error = "Unknown sizing stage"; return false; }
	if (Has(*options, PositionMultiple) && (Number(*options, PositionMultiple) <= 0 || Number(*options, PositionMultiple) > 1000000))
	{ error = "position_multiple must be positive and bounded"; return false; }
	if (Has(*options, Strength) && std::abs(Number(*options, Strength)) > 1000000)
	{ error = "strength exceeds the supported bound"; return false; }
	if (Has(*options, Frame) && std::abs(Number(*options, Frame)) > 100000000)
	{ error = "frame exceeds the supported bound"; return false; }
	if (Has(*options, TimeOffset) && std::abs(Number(*options, TimeOffset)) > 100000000)
	{ error = "time_offset exceeds the supported bound"; return false; }
	if (options->GetInt32(Offset, 0) < 0 || options->GetInt32(Offset, 0) > 100000000 ||
		options->GetInt32(Limit, 64) < 1 || options->GetInt32(Limit, 64) > kMaxPageSize)
	{ error = "Invalid paging range"; return false; }
	for (const auto& item : std::vector<std::pair<Int32, std::vector<std::string>>>{
		{Strategy, {"append", "replace", "merge"}}, {Rotation, {"quaternion", "euler"}},
		{Mode, {"edit", "anim"}}, {Unit, {"vmd_frames", "document_frames", "seconds"}},
		{Section, operation == Operation::SizingResult ? std::vector<std::string>{"summary", "stages", "warnings", "constraints"} : std::vector<std::string>{"summary", "bones", "morphs", "slots"}},
		{MaterialType, {"standard", "redshift", "octane", "corona", "redshift_toon"}}})
		if (Has(*options, item.first) && std::find(item.second.begin(), item.second.end(), Text(*options, item.first)) == item.second.end())
		{ error = "Unsupported enumeration value"; return false; }
	std::vector<Int32> required;
	switch (operation)
	{
		case Operation::ImportPmx: case Operation::ExportPmx: case Operation::ImportMotion:
		case Operation::ExportMotion: case Operation::ImportCamera: case Operation::ExportCamera: required = {Path}; break;
		case Operation::SelectSlot: required = {Slot}; break;
		case Operation::SetMode: required = {Mode}; break;
		case Operation::SetPhysics: required = {Enabled}; break;
		case Operation::SetMorph: required = {MorphHandle, Strength}; break;
		case Operation::Evaluate: required = {Frame, Unit}; break;
		case Operation::Status: required = {QueryOperationId}; break;
        case Operation::SizingStart: required = {SizingCharacters}; break;
        case Operation::SizingExport: case Operation::SizingExportCamera: required = {SizingJob, Path}; break;
        case Operation::SizingStatus: case Operation::SizingResult: case Operation::SizingCancel:
        case Operation::SizingPreview: case Operation::SizingClosePreview: case Operation::SizingApply:
        case Operation::SizingApplyCamera: case Operation::SizingRelease: required = {SizingJob}; break;
		default: break;
	}
	for (Int32 field : required)
		if (!Has(*options, field)) { error = "Required operation option is missing"; return false; }
	if (operation == Operation::Status && !IsUuid(Text(*options, QueryOperationId)))
	{ error = "query_operation_id must be a UUID"; return false; }
	if (operation == Operation::ImportPmx || operation == Operation::ExportPmx)
	{
		const Bool polygon = options->GetBool(Polygon, true), bones = options->GetBool(Bones, true);
		if (options->GetBool(Weights, true) && (!polygon || !bones))
		{ error = "weights=true requires polygon=true and bones=true"; return false; }
		if (!bones && (options->GetBool(IK, true) || options->GetBool(Inherit, true)))
		{ error = "ik/inherit require bones=true"; return false; }
		if (!polygon && (options->GetBool(Normals, true) || options->GetBool(UV, true) || options->GetBool(Materials, true)))
		{ error = "normals/uv/materials require polygon=true"; return false; }
		if (operation == Operation::ImportPmx && options->GetBool(Multipart, false) && !polygon)
		{ error = "multipart=true requires polygon=true"; return false; }
	}
	return true;
}

struct HandleEntry
{
	std::string handle;
	std::string document;
	std::unique_ptr<BaseLink, void(*)(BaseLink*)> link{nullptr, [](BaseLink* value) { BaseLink::Free(value); }};
	Bool is_document = false;
};

struct Record
{
	std::string id;
	std::string fingerprint;
	Json result;
	double accepted_at = 0;
};

struct SizingJobEntry
{
    std::string handle;
    std::string document;
    std::vector<std::string> models;
    std::shared_ptr<sizing::HostSession> session;
    std::shared_ptr<sizing::PanelState> panel;
    double last_access = 0;
};

struct State
{
	std::string session;
	UInt64 sequence = 0;
	std::vector<HandleEntry> handles;
	std::vector<Record> records;
    std::vector<SizingJobEntry> sizing_jobs;
	Bool executing = false;
	Bool rollback_failed = false;
	State()
	{
		// Session identity is a lifecycle nonce, not an authentication credential.
		std::ostringstream out;
		out << std::hex << std::chrono::high_resolution_clock::now().time_since_epoch().count()
			<< static_cast<UInt64>(GeGetMilliSeconds() * 1000.0);
		session = out.str();
	}
};

State& GetState() { static State state; return state; }

Bool IsOpenDocument(BaseDocument* candidate)
{
	for (BaseDocument* document = GetFirstDocument(); document; document = document->GetNext())
		if (document == candidate) return true;
	return false;
}

BaseDocument* ResolveDocument(const std::string& handle)
{
	for (auto& entry : GetState().handles)
		if (entry.handle == handle && entry.is_document)
		{
			auto* document = static_cast<BaseDocument*>(entry.link->ForceGetLink());
			return IsOpenDocument(document) ? document : nullptr;
		}
	return nullptr;
}

std::string RegisterHandle(BaseDocument* document, BaseList2D* object, Bool is_document = false)
{
	State& state = GetState();
	state.handles.erase(std::remove_if(state.handles.begin(), state.handles.end(), [](const HandleEntry& entry)
		{ return !entry.link || !entry.link->ForceGetLink(); }), state.handles.end());
	const std::string document_handle = is_document ? "" : RegisterHandle(document, document, true);
	for (const auto& entry : state.handles)
		if (entry.is_document == is_document && entry.document == document_handle && entry.link->ForceGetLink() == object)
			return entry.handle;
	if (state.handles.size() >= 65536)
		return "";
	HandleEntry entry;
	entry.handle = state.session + (is_document ? ":document:" : ":object:") + std::to_string(++state.sequence);
	entry.document = document_handle;
	entry.is_document = is_document;
	entry.link.reset(BaseLink::Alloc());
	if (!entry.link) return "";
	entry.link->SetLink(object);
	const std::string result = entry.handle;
	state.handles.push_back(std::move(entry));
	return result;
}

BaseObject* ResolveObject(BaseDocument* document, const std::string& document_handle, const std::string& handle)
{
	if (!document || !IsOpenDocument(document)) return nullptr;
	for (auto& entry : GetState().handles)
		if (!entry.is_document && entry.handle == handle && entry.document == document_handle)
		{
			auto* object = static_cast<BaseObject*>(entry.link->GetLink(document));
			return object && object->GetDocument() == document ? object : nullptr;
		}
	return nullptr;
}

Json Envelope(const std::string& id, Bool success, const char* code, const std::string& message,
	const Json& data = Json(), const char* state = nullptr, const std::vector<Json>& warnings = {})
{
	return Json::Object({{"success", Json::Boolean(success)}, {"code", Json::StringValue(std::string(code))},
		{"message", Json::StringValue(message)}, {"operation_id", Json::StringValue(id)},
		{"state", Json::StringValue(std::string(state ? state : success ? "completed" : "failed"))},
		{"host_session", Json::StringValue(GetState().session)}, {"data", data}, {"warnings", Json::Array(warnings)}});
}

void CollectObjects(BaseObject* first, std::vector<BaseObject*>& objects)
{
	for (BaseObject* object = first; object; object = object->GetNext())
	{
		objects.push_back(object);
		CollectObjects(object->GetDown(), objects);
	}
}

std::vector<BaseObject*> BoneObjects(MMDModelManagerObject* model)
{
	std::vector<BaseObject*> result;
	if (auto* bones = model ? model->GetBoneManagerData() : nullptr)
	{
		maxon::BaseArray<BaseObject*> ordered;
		bones->BuildOrderedBoneObjectList(ordered);
		for (BaseObject* bone : ordered) result.push_back(bone);
	}
	return result;
}

Json ModelSummary(BaseDocument* document, BaseObject* object)
{
	auto* model = object->GetNodeData<MMDModelManagerObject>();
	const auto* container = object->GetDataInstance();
	return Json::Object({{"handle", Json::StringValue(RegisterHandle(document, object))},
		{"name", Json::StringValue(object->GetName())},
		{"mode", Json::StringValue(std::string(container->GetInt32(MODEL_MODE) == MODEL_MODE_ANIM ? "anim" : "edit"))},
		{"physics_enabled", Json::Boolean(container->GetBool(MODEL_PHYSICS_ENABLED, true))},
		{"bone_count", Json::Integer(BoneObjects(model).size())},
		{"morph_count", Json::Integer(model->GetMorphNum())},
		{"slot_count", Json::Integer(model->GetAutomationAnimationSlots().GetCount())}});
}

std::string DerivedHandle(const std::string& model, const char* kind, UInt64 identity)
{
	return model + ':' + kind + ':' + std::to_string(identity);
}

UInt64 ResolveDerived(const std::string& model, const char* kind, const std::string& handle)
{
	const std::string prefix = model + ':' + kind + ':';
	if (handle.compare(0, prefix.size(), prefix) != 0) return 0;
	const std::string suffix = handle.substr(prefix.size());
	if (suffix.empty() || suffix.size() > 20) return 0;
	UInt64 value = 0;
	for (char digit : suffix)
	{
		if (digit < '0' || digit > '9' || value > (std::numeric_limits<UInt64>::max() - 9) / 10) return 0;
		value = value * 10 + static_cast<UInt64>(digit - '0');
	}
	return value;
}

Json Slots(MMDModelManagerObject* model, const std::string& model_handle, const BaseContainer& options)
{
	std::vector<Json> values;
	const auto& slots = model->GetAutomationAnimationSlots();
	const Int32 offset = options.GetInt32(Offset, 0), limit = options.GetInt32(Limit, 64);
	for (Int32 index = offset; index < slots.GetCount() && index < offset + limit; ++index)
		values.push_back(Json::Object({{"handle", Json::StringValue(DerivedHandle(model_handle, "slot", slots[index].runtime_identity))},
			{"name", Json::StringValue(slots[index].name)}, {"max_frame", Json::Integer(slots[index].max_frame)},
			{"active", Json::Boolean(index == model->GetAutomationActiveAnimationSlot())}}));
	const Int32 active = model->GetAutomationActiveAnimationSlot();
	return Json::Object({{"slots", Json::Array(values)}, {"total", Json::Integer(slots.GetCount())},
		{"next_offset", Json::Number(offset + static_cast<Int32>(values.size()) < slots.GetCount() ? offset + static_cast<Int32>(values.size()) : -1)},
		{"active_slot", Json::StringValue(active >= 0 && active < slots.GetCount()
			? DerivedHandle(model_handle, "slot", slots[active].runtime_identity) : std::string{})}});
}

// Copy an entire document with AliasTrans before evaluating or preparing an
// export, then locate the same structural path. User material links stay live.
class SceneCopy
{
	std::unique_ptr<BaseDocument, void(*)(BaseDocument*)> document_{nullptr, [](BaseDocument* value) { BaseDocument::Free(value); }};
public:
	BaseObject* object = nullptr;
	BaseDocument* document() const { return document_.get(); }
	Bool Init(BaseDocument* source, BaseObject* target)
	{
		std::vector<Int32> path;
		for (BaseObject* node = target; node; node = node->GetUp())
		{
			Int32 index = 0;
			for (auto* previous = node->GetPred(); previous; previous = previous->GetPred()) ++index;
			path.push_back(index);
		}
		AutoAlloc<AliasTrans> translator;
		if (!translator || !translator->Init(source)) return false;
		document_.reset(static_cast<BaseDocument*>(source->GetClone(COPYFLAGS::NONE, translator)));
		if (!document_) return false;
		translator->Translate(true);
		object = document_->GetFirstObject();
		for (auto part = path.rbegin(); part != path.rend(); ++part)
		{
			for (Int32 index = 0; object && index < *part; ++index) object = object->GetNext();
			if (!object) return false;
			if (std::next(part) != path.rend()) object = object->GetDown();
		}
		return object != nullptr;
	}
};

class UndoAction
{
	BaseDocument* document_;
	BaseTime previous_time_, previous_min_, previous_max_, previous_loop_min_, previous_loop_max_;
	Bool opened_ = false;
	Bool recorded_ = false;
	Bool committed_ = false;
public:
	explicit UndoAction(BaseDocument* document) : document_(document),
		previous_time_(document->GetTime()), previous_min_(document->GetMinTime()), previous_max_(document->GetMaxTime()),
		previous_loop_min_(document->GetLoopMinTime()), previous_loop_max_(document->GetLoopMaxTime())
	{ opened_ = document_->StartUndo(); }
	~UndoAction()
	{
		if (!opened_) return;
		if (!committed_ && recorded_)
		{
			// DoUndo(true) closes the active Undo group internally (SDK contract).
			const Bool restored = document_->DoUndo(true);
			document_->SetMinTime(previous_min_); document_->SetMaxTime(previous_max_);
			document_->SetLoopMinTime(previous_loop_min_); document_->SetLoopMaxTime(previous_loop_max_);
			document_->SetTime(previous_time_);
			if (!restored)
			{
				GetState().rollback_failed = true;
				DebugOutput(maxon::OUTPUT::DIAGNOSTIC, "[CMT][Automation] Undo rollback failed; outcome requires inspection");
			}
		}
		else if (!document_->EndUndo()) GetState().rollback_failed = true;
	}
	Bool Change(BaseList2D* node)
	{
		const Bool added = opened_ && document_->AddUndo(UNDOTYPE::CHANGE, node);
		recorded_ = recorded_ || added;
		return added;
	}
	Bool DocumentSettings()
	{
		const Bool added = opened_ && document_->AddUndo(UNDOTYPE::CHANGE_SMALL, document_);
		recorded_ = recorded_ || added;
		return added;
	}
	Bool Created(BaseList2D* node)
	{
		const Bool added = opened_ && document_->AddUndo(UNDOTYPE::NEWOBJ, node);
		recorded_ = recorded_ || added;
		return added;
	}
	void Commit() { committed_ = true; }
	Bool Opened() const { return opened_; }
};

// Allocate this before UndoAction so its cleanup runs after Undo rollback. The
// SDK inserts materials at the head by default; a previous-last marker cannot
// identify new materials in a document that already has user-owned materials.
class ImportDelta
{
	BaseDocument* document_;
	std::vector<BaseMaterial*> materials_;
	std::vector<BaseObject*> roots_;
	Bool committed_ = false;
public:
	explicit ImportDelta(BaseDocument* document) : document_(document)
	{
		for (BaseMaterial* material = document->GetFirstMaterial(); material; material = static_cast<BaseMaterial*>(material->GetNext()))
			materials_.push_back(material);
		for (BaseObject* object = document->GetFirstObject(); object; object = object->GetNext()) roots_.push_back(object);
	}
	~ImportDelta()
	{
		if (committed_) return;
		for (BaseObject* object = document_->GetFirstObject(); object;)
		{
			BaseObject* next = object->GetNext();
			if (std::find(roots_.begin(), roots_.end(), object) == roots_.end())
			{ object->Remove(); BaseObject::Free(object); }
			object = next;
		}
		for (BaseMaterial* material = document_->GetFirstMaterial(); material;)
		{
			BaseMaterial* next = static_cast<BaseMaterial*>(material->GetNext());
			if (IsNewMaterial(material)) { material->Remove(); BaseMaterial::Free(material); }
			material = next;
		}
	}
	Bool IsNewMaterial(BaseMaterial* material) const
	{ return std::find(materials_.begin(), materials_.end(), material) == materials_.end(); }
	void Commit() { committed_ = true; }
};

Bool ReadInput(const Filename& filename, std::vector<uint8_t>& bytes)
{
	AutoAlloc<BaseFile> file;
	if (!file || !file->Open(filename, FILEOPEN::READ, FILEDIALOG::NONE, BYTEORDER::V_INTEL)) return false;
	const Int64 length = file->GetLength();
	if (length < 1 || length > kMaxInputBytes) return false;
	bytes.resize(static_cast<size_t>(length));
	return file->ReadBytes(bytes.data(), length) == length;
}

Bool PmxInputFinite(const libmmd::PMXFile& pmx)
{
	for (const auto& vertex : pmx.m_vertices)
		if (!vertex.m_position.allFinite() || !vertex.m_normal.allFinite()) return false;
	for (const auto& bone : pmx.m_bones)
		if (!bone.m_position.allFinite()) return false;
	for (const auto& material : pmx.m_materials)
		if (!material.m_diffuse.allFinite() || !material.m_specular.allFinite() ||
			!material.m_ambient.allFinite() || !std::isfinite(material.m_specularPower)) return false;
	return true;
}

Bool CameraInputFinite(const libmmd::VMDFile& vmd, const BaseContainer& options)
{
	for (const auto& camera : vmd.m_cameras)
	{
		std::int32_t shifted_frame = 0;
		if (!camera.m_interest.allFinite() || !camera.m_rotate.allFinite() || !std::isfinite(camera.m_distance) ||
			camera.m_viewAngle < 1 || camera.m_viewAngle >= 180 || camera.m_isPerspective > 1 ||
			!cmt_motion_validation::TryAnimationFrame(camera.m_frame, options.GetInt32(TimeOffset, 0), shifted_frame)) return false;
	}
	return true;
}

Bool IsAbsolutePath(const std::string& path)
{
	return !path.empty() && (path[0] == '/' || (path.size() > 2 && path[1] == ':' && (path[2] == '\\' || path[2] == '/')) ||
		(path.size() > 2 && path[0] == '\\' && path[1] == '\\'));
}

Bool RendererAvailable(const std::string& name)
{
	if (name == "standard") return true;
	if (name == "redshift_toon")
	{
		String reason;
		return MMDRedShiftToonMaterialAdapter::IsAvailable(reason);
	}
	if (name == "octane" && (!FindPlugin(1029501, PLUGINTYPE::MATERIAL) ||
		!FindPlugin(1029508, PLUGINTYPE::SHADER) || !FindPlugin(1029504, PLUGINTYPE::SHADER) ||
		!FindPlugin(1029506, PLUGINTYPE::SHADER))) return false;
	if (name == "corona" && (!FindPlugin(1032100, PLUGINTYPE::MATERIAL) || !FindPlugin(1036473, PLUGINTYPE::SHADER))) return false;
	const MMDRendererMaterialType type = name == "redshift" ? MMDRendererMaterialType::RedShift :
		name == "octane" ? MMDRendererMaterialType::Octane : MMDRendererMaterialType::Corona;
	// Exercise the same detached factory as import; modern Redshift is a node
	// space on Mmaterial, so checking only its legacy plugin ID is insufficient.
	BaseMaterial* material = CreateMaterialFromData(MMDMaterialData{}, type);
	const Bool available = material && MMDMaterialAdapter::DetectType(material) == type;
	if (material) BaseMaterial::Free(material);
	return available;
}

Bool CommitFile(const Filename& staged, const Filename& destination, Bool overwrite)
{
#if defined(_WIN32)
	std::wstring source, target;
	if (!libmmd::TryToWString(string_util::GetStdString(staged.GetString()), source) ||
		!libmmd::TryToWString(string_util::GetStdString(destination.GetString()), target)) return false;
	return MoveFileExW(source.c_str(), target.c_str(), MOVEFILE_WRITE_THROUGH | (overwrite ? MOVEFILE_REPLACE_EXISTING : 0)) != 0;
#else
	const std::string source = string_util::GetStdString(staged.GetString()), target = string_util::GetStdString(destination.GetString());
	if (overwrite) return std::rename(source.c_str(), target.c_str()) == 0;
	if (::link(source.c_str(), target.c_str()) != 0) return false;
	::unlink(source.c_str());
	return true;
#endif
}

template <typename Writer>
Json WriteExport(const std::string& operation_id, const BaseContainer& options, const char* suffix, Writer writer)
{
	const Filename destination(options.GetString(Path));
	const std::string path = string_util::GetStdString(destination.GetString());
	if (!IsAbsolutePath(path) || !filename_util::CheckSuffix(destination, String(suffix)))
		return Envelope(operation_id, false, "invalid_argument", "Export requires an absolute path with the expected suffix.");
	const Bool overwrite = options.GetBool(Overwrite, false);
	if (GeFExist(destination) && !overwrite)
		return Envelope(operation_id, false, "destination_exists", "Existing destination requires overwrite=true.");
	Filename staged = destination;
	staged.SetFile(Filename(String((".cmt-" + GetState().session + '-' + operation_id + ".tmp").c_str())));
	const std::string staged_path = string_util::GetStdString(staged.GetString());
	if (GeFExist(staged)) return Envelope(operation_id, false, "write_failed", "Export staging destination already exists.");
	struct Cleanup { Filename filename; ~Cleanup() { if (GeFExist(filename)) GeFKill(filename); } } cleanup{staged};
	if (!writer(staged_path)) return Envelope(operation_id, false, "write_failed", "Export serialization or staging write failed.");
	AutoAlloc<BaseFile> file;
	if (!file || !file->Open(staged, FILEOPEN::READ, FILEDIALOG::NONE, BYTEORDER::V_INTEL))
		return Envelope(operation_id, false, "write_failed", "Cannot verify staged export.");
	const Int64 bytes = file->GetLength();
	file->Close();
	if (bytes <= 0 || !CommitFile(staged, destination, overwrite))
		return Envelope(operation_id, false, "write_failed", "Final export commit failed; previous destination was preserved.");
	return Envelope(operation_id, true, "ok", "", Json::Object({{"path", Json::StringValue(path)}, {"bytes", Json::Integer(bytes)}}));
}

Json ContainerFingerprint(const BaseContainer& container)
{
    std::vector<Int32> ids;
    for (Int32 i = 0, field; (field = container.GetIndexId(i)) != NOTOK; ++i) ids.push_back(field);
    std::sort(ids.begin(), ids.end());
    std::vector<std::pair<std::string, Json>> fields;
    for (Int32 field : ids)
    {
        const auto* nested = container.GetContainerInstance(field);
        const Json value = nested ? ContainerFingerprint(*nested) : container.GetData(field).GetType() == DA_STRING ?
            Json::StringValue(container.GetString(field)) : Json::Number(Number(container, field));
        fields.push_back({std::to_string(field), value});
    }
    return Json::Object(fields);
}

std::string Fingerprint(const BaseContainer& request)
{
    return Json::Object({{"operation", Json::StringValue(request.GetString(OperationName))},
        {"document", Json::StringValue(request.GetString(DocumentHandle))},
        {"target", Json::StringValue(request.GetString(TargetHandle))},
        {"options", ContainerFingerprint(request.GetContainer(Options))}}).text;
}

// Production sizing operations share the serial dispatcher and its handle registry.
// Worker state is owned by HostSession; no worker callback touches C4D objects.
void ApplySizingOptions(const BaseContainer& values, libmmd::sizing::Options& options)
{
    options.movementMultiplier = Number(values, SizingMovement, options.movementMultiplier);
    options.legOffset = Number(values, SizingLegOffset, options.legOffset);
    options.centerOffsets = values.GetBool(SizingCenterOffsets, options.centerOffsets);
    options.legOffsets = values.GetBool(SizingLegOffsets, options.legOffsets);
    options.stance = values.GetBool(SizingStance, options.stance);
    options.twist = values.GetBool(SizingTwist, options.twist);
    options.avoidance = values.GetBool(SizingAvoidance, options.avoidance);
    options.wristContact = values.GetBool(SizingWristContact, options.wristContact);
    options.fingerContact = values.GetBool(SizingFingerContact, options.fingerContact);
    options.floorContact = values.GetBool(SizingFloorContact, options.floorContact);
    options.multiContact = values.GetBool(SizingMultiContact, options.multiContact);
    options.contactDistance = Number(values, SizingContactDistance, options.contactDistance);
    options.floorHeight = Number(values, SizingFloorHeight, options.floorHeight);
    options.collisionMargin = Number(values, SizingCollisionMargin, options.collisionMargin);
    options.tolerance = Number(values, SizingTolerance, options.tolerance);
    options.iterations = static_cast<unsigned>(values.GetInt32(SizingIterations, options.iterations));
    options.maxBakeFrames = static_cast<uint32_t>(values.GetInt32(SizingMaxFrames, options.maxBakeFrames));
    options.maxBakedKeys = static_cast<size_t>(values.GetInt32(SizingMaxKeys, static_cast<Int32>(options.maxBakedKeys)));
    options.maxDiagnostics = static_cast<size_t>(values.GetInt32(SizingMaxDiagnostics, static_cast<Int32>(options.maxDiagnostics)));
    if (const auto* bodies = values.GetContainerInstance(SizingAvoidanceBodies))
    {
        options.avoidanceBodies.clear();
        for (Int32 i = 0, field; (field = bodies->GetIndexId(i)) != NOTOK; ++i)
            options.avoidanceBodies.push_back(Text(*bodies, field));
    }
}

bool SizingInputFile(const std::string& path, const char* suffix)
{
    const Filename filename(String(path.c_str()));
    if (!IsAbsolutePath(path) || !filename_util::CheckSuffix(filename, String(suffix))) return false;
    AutoAlloc<BaseFile> file;
    if (!file || !file->Open(filename, FILEOPEN::READ, FILEDIALOG::NONE, BYTEORDER::V_INTEL)) return false;
    return file->GetLength() > 0 && file->GetLength() <= kMaxInputBytes;
}

const char* SizingState(const SizingJobEntry& entry)
{
    const auto& batch = entry.session->GetBatchResult();
    if (entry.session->IsRunning()) return entry.session->IsCancelling() ? "cancelling" : "running";
    if (batch.cancelled) return "cancelled";
    return batch.success ? "completed" : "failed";
}

Json SizingJobData(const SizingJobEntry& entry, const std::vector<std::pair<std::string, Json>>& extra = {})
{
    BaseDocument* preview = entry.session->GetPreviewDocument();
    std::vector<std::pair<std::string, Json>> fields{{"job", Json::StringValue(entry.handle)},
        {"job_state", Json::StringValue(std::string(SizingState(entry)))},
        {"character_count", Json::Integer(entry.models.size())},
        {"has_camera", Json::Boolean(entry.session->HasCamera())},
        {"preview_document", Json::StringValue(preview ? RegisterHandle(preview, preview, true) : std::string())},
        {"error", Json::StringValue(entry.session->GetError())}};
    fields.insert(fields.end(), extra.begin(), extra.end());
    return Json::Object(fields);
}

void PruneSizingJobs()
{
    const double now = GeGetMilliSeconds() / 1000.;
    auto& jobs = GetState().sizing_jobs;
    for (auto it = jobs.begin(); it != jobs.end();)
    {
        it->session->Poll();
        const bool expired = now - it->last_access > kRetentionSeconds || !ResolveDocument(it->document);
        if (expired && it->session->IsRunning())
        {
            it->session->Cancel();
        }
        // Destroy only completed workers; never wait on the main thread.
        if (expired && !it->session->IsRunning())
        {
            sizing::WithdrawPanelState(it->panel);
            it = jobs.erase(it);
        }
        else ++it;
    }
}

Json SizingVector(const Eigen::Vector3d& value)
{
    return Json::Array({Json::Number(value.x()), Json::Number(value.y()), Json::Number(value.z())});
}

Json SizingResultData(const SizingJobEntry& entry, size_t member, const BaseContainer& options)
{
    const auto& result = entry.session->GetBatchResult().characters[member];
    const auto& analysis = result.analysis;
    std::vector<Json> offsets;
    for (const auto& offset : analysis.localOffsets)
        offsets.push_back(Json::Object({{"bone", Json::StringValue(offset.first)}, {"offset", SizingVector(offset.second)}}));
    const Json summary = Json::Object({{"horizontal_ratio", Json::Number(analysis.horizontalRatio)},
        {"vertical_ratio", Json::Number(analysis.verticalRatio)}, {"local_offsets", Json::Array(offsets)},
        {"matched_tracks", Json::Integer(analysis.matchedTracks)}, {"modified_keys", Json::Integer(analysis.modifiedKeys)},
        {"constraints", Json::Integer(analysis.constraints)}, {"unresolved", Json::Integer(analysis.unresolved)},
        {"max_residual", Json::Number(analysis.maxResidual)}, {"warning_count", Json::Integer(analysis.warnings.size())},
        {"stored_samples", Json::Integer(analysis.samples.size())}, {"elapsed_ms", Json::Number(result.elapsedMilliseconds)}});
    const std::string section = Text(options, Section, "summary");
    const size_t offset = static_cast<size_t>(options.GetInt32(Offset, 0)), limit = static_cast<size_t>(options.GetInt32(Limit, 64));
    size_t total = 0;
    std::vector<Json> items;
    if (section == "warnings")
    {
        total = analysis.warnings.size();
        for (size_t i = offset; i < std::min(total, offset + limit); ++i) items.push_back(Json::StringValue(analysis.warnings[i]));
    }
    else if (section == "constraints")
    {
        total = analysis.samples.size();
        for (size_t i = offset; i < std::min(total, offset + limit); ++i)
        {
            const auto& sample = analysis.samples[i];
            items.push_back(Json::Object({{"stage", Json::StringValue(std::string(kSizingStages[static_cast<size_t>(sample.stage)]))},
                {"frame", Json::Integer(sample.frame)}, {"bone", Json::StringValue(sample.bone)},
                {"target", SizingVector(sample.target)}, {"actual", SizingVector(sample.actual)}, {"error", Json::Number(sample.error)}}));
        }
    }
    else if (section == "stages")
    {
        total = result.stages.size();
        for (size_t i = offset; i < std::min(total, offset + limit); ++i)
        {
            const auto& motion = result.stages[i];
            uint32_t maxFrame = 0;
            for (const auto& key : motion.m_motions) maxFrame = std::max(maxFrame, key.m_frame);
            for (const auto& key : motion.m_morphs) maxFrame = std::max(maxFrame, key.m_frame);
            items.push_back(Json::Object({{"stage", Json::StringValue(std::string(kSizingStages[i]))},
                {"bone_keys", Json::Integer(motion.m_motions.size())}, {"morph_keys", Json::Integer(motion.m_morphs.size())},
                {"max_frame", Json::Integer(maxFrame)}}));
        }
    }
    return Json::Object({{"job", Json::StringValue(entry.handle)}, {"member", Json::Integer(member)},
        {"section", Json::StringValue(section)}, {"summary", summary}, {"items", Json::Array(items)},
        {"total", Json::Integer(total)}, {"next_offset", Json::Number(offset + items.size() < total ? static_cast<double>(offset + items.size()) : -1)}});
}

Json ExecuteSizing(Operation operation, BaseDocument* document, const std::string& documentHandle,
                   const std::string& id, const BaseContainer& options)
{
    PruneSizingJobs();
    auto& jobs = GetState().sizing_jobs;
    if (operation == Operation::SizingStart)
    {
        if (jobs.size() >= 4) return Envelope(id, false, "sizing_capacity", "Release finished sizing jobs; at most four jobs are retained.");
        std::vector<sizing::HostInput> inputs;
        std::vector<std::string> modelHandles;
        const auto* characters = options.GetContainerInstance(SizingCharacters);
        for (Int32 i = 0, field; (field = characters->GetIndexId(i)) != NOTOK; ++i)
        {
            const auto& character = *characters->GetContainerInstance(field);
            const std::string handle = Text(character, SizingModel);
            BaseObject* target = ResolveObject(document, documentHandle, handle);
            if (!target || !target->IsInstanceOf(g_mmd_model_manager_object_id))
                return Envelope(id, false, "stale_handle", "Sizing target is not a live MMD model in the selected document.");
            if (std::find(modelHandles.begin(), modelHandles.end(), handle) != modelHandles.end())
                return Envelope(id, false, "invalid_argument", "Sizing targets must be unique.");
            auto* model = target->GetNodeData<MMDModelManagerObject>();
            if (!model) return Envelope(id, false, "invalid_target", "Sizing model runtime is unavailable.");
            const std::string source = Text(character, SizingSource), motion = Text(character, Path);
            if (!SizingInputFile(source, "pmx") || (Has(character, Path) && !SizingInputFile(motion, "vmd")))
                return Envelope(id, false, "invalid_file", "Sizing input must be an absolute, readable PMX/VMD within the input size limit.");
            UInt64 slotIdentity = 0;
            if (Has(character, Slot))
            {
                slotIdentity = ResolveDerived(handle, "slot", Text(character, Slot));
                bool exists = false;
                for (const auto& slot : model->GetAutomationAnimationSlots()) exists = exists || (slotIdentity != 0 && slot.runtime_identity == slotIdentity);
                if (!exists) return Envelope(id, false, "stale_handle", "Sizing animation slot no longer exists on its target model.");
            }
            libmmd::sizing::Options solverOptions;
            if (const auto* shared = options.GetContainerInstance(SizingOptions)) ApplySizingOptions(*shared, solverOptions);
            if (const auto* local = character.GetContainerInstance(SizingOptions)) ApplySizingOptions(*local, solverOptions);
            inputs.push_back({target, Filename(String(source.c_str())), Filename(String(motion.c_str())), solverOptions, slotIdentity});
            modelHandles.push_back(handle);
        }
        const std::string cameraPath = Text(options, SizingCameraPath);
        if (!cameraPath.empty() && !SizingInputFile(cameraPath, "vmd"))
            return Envelope(id, false, "invalid_file", "Sizing camera input is not a readable bounded VMD.");
        libmmd::sizing::CameraOptions cameraOptions;
        cameraOptions.enabled = !cameraPath.empty();
        cameraOptions.maxDistanceRatio = Number(options, SizingCameraRatio, 5.);
        SizingJobEntry entry;
        entry.handle = GetState().session + ":sizing:" + std::to_string(++GetState().sequence);
        entry.document = documentHandle;
        entry.models = std::move(modelHandles);
        entry.last_access = GeGetMilliSeconds() / 1000.;
        entry.session = std::make_shared<sizing::HostSession>();
        entry.panel = sizing::MakePanelState(entry.session, inputs, Filename(String(cameraPath.c_str())), cameraOptions);
        if (!entry.session->StartBatch(inputs, Filename(String(cameraPath.c_str())), cameraOptions))
            return Envelope(id, false, "sizing_input_failed", string_util::GetStdString(entry.session->GetError()));
        jobs.push_back(std::move(entry));
        sizing::PublishPanelState(jobs.back().panel);
        return Envelope(id, true, "ok", "Sizing started; query the job handle for completion.", SizingJobData(jobs.back()));
    }
    const std::string handle = Text(options, SizingJob);
    auto found = std::find_if(jobs.begin(), jobs.end(), [&handle, &documentHandle](const SizingJobEntry& entry)
        { return entry.handle == handle && entry.document == documentHandle; });
    if (found == jobs.end()) return Envelope(id, false, "stale_handle", "Sizing job is released, expired or belongs to another document/host session.");
    auto& entry = *found;
    auto& session = *entry.session;
    entry.last_access = GeGetMilliSeconds() / 1000.;
    session.Poll();
    if (operation == Operation::SizingStatus) return Envelope(id, true, "ok", "", SizingJobData(entry));
    if (operation == Operation::SizingCancel)
    {
        if (session.IsRunning()) session.Cancel();
        sizing::PublishPanelState(entry.panel);
        return Envelope(id, true, "ok", "", SizingJobData(entry));
    }
    if (operation == Operation::SizingClosePreview)
    {
        session.ClosePreview();
        sizing::PublishPanelState(entry.panel);
        return Envelope(id, true, "ok", "", SizingJobData(entry));
    }
    if (operation == Operation::SizingRelease)
    {
        if (session.IsRunning()) return Envelope(id, false, "sizing_busy", "Cancel and poll until the worker finishes before releasing its job.");
        sizing::WithdrawPanelState(entry.panel);
        jobs.erase(found);
        return Envelope(id, true, "ok", "", Json::Object({{"job", Json::StringValue(handle)}, {"released", Json::Boolean(true)}}));
    }
    if (session.IsRunning() || !session.GetBatchResult().success)
        return Envelope(id, false, "sizing_not_ready", "Sizing has no completed successful result.", SizingJobData(entry));
    const size_t member = static_cast<size_t>(options.GetInt32(SizingMember, 0));
    if (member >= session.CharacterCount()) return Envelope(id, false, "invalid_argument", "Sizing member is out of range.");
    session.SelectCharacter(member);
    const size_t stage = SizingStageIndex(options);
    if (operation == Operation::SizingResult)
        return Envelope(id, true, "ok", "", SizingResultData(entry, member, options));
    if (operation == Operation::SizingPreview)
    {
        if (!session.Preview(stage, options.GetBool(SizingOverlay, false)))
            return Envelope(id, false, "sizing_preview_failed", string_util::GetStdString(session.GetError()));
        entry.panel->member = member;
        entry.panel->stage = stage;
        entry.panel->overlay = options.GetBool(SizingOverlay, false);
        sizing::PublishPanelState(entry.panel);
        return Envelope(id, true, "ok", "", SizingJobData(entry, {
            {"stage", Json::StringValue(std::string(kSizingStages[stage]))}, {"member", Json::Integer(member)}}));
    }
    if (operation == Operation::SizingExport || operation == Operation::SizingExportCamera)
    {
        if (operation == Operation::SizingExportCamera && !session.HasCamera())
            return Envelope(id, false, "sizing_no_camera", "This job has no adapted camera.");
        const auto& motion = operation == Operation::SizingExport ? session.GetResult().stages[stage] : session.GetBatchResult().camera;
        return WriteExport(id, options, "vmd", [&motion](const std::string& path) { return libmmd::WriteVMDFile(&motion, path.c_str()); });
    }
    // Resolve every batch member again before host application, then let
    // HostSession validate the immutable binding signature of every target.
    for (const auto& modelHandle : entry.models)
        if (!ResolveObject(document, documentHandle, modelHandle))
            return Envelope(id, false, "stale_handle", "A sizing target was deleted or moved out of the source document.");
    if (operation == Operation::SizingApplyCamera)
    {
        if (!session.HasCamera()) return Envelope(id, false, "sizing_no_camera", "This job has no adapted camera.");
        if (!session.ApplyCamera()) return Envelope(id, false, "sizing_apply_failed", string_util::GetStdString(session.GetError()));
        sizing::PublishPanelState(entry.panel);
        auto* camera = document->GetActiveObject();
        return Envelope(id, true, "ok", "", Json::Object({{"job", Json::StringValue(handle)}, {"camera", Json::StringValue(RegisterHandle(document, camera))}}));
    }
    if (operation == Operation::SizingApply)
    {
        if (!session.Apply(stage)) return Envelope(id, false, "sizing_apply_failed", string_util::GetStdString(session.GetError()));
        entry.panel->member = member;
        entry.panel->stage = stage;
        sizing::PublishPanelState(entry.panel);
        auto* target = ResolveObject(document, documentHandle, entry.models[member]);
        auto* model = target->GetNodeData<MMDModelManagerObject>();
        const auto& slots = model->GetAutomationAnimationSlots();
        const Int32 active = model->GetAutomationActiveAnimationSlot();
        if (active < 0 || active >= slots.GetCount())
            return Envelope(id, false, "sizing_apply_failed", "Applied result slot could not be identified.", Json(), "outcome_unknown");
        return Envelope(id, true, "ok", "", Json::Object({{"job", Json::StringValue(handle)},
            {"model", Json::StringValue(entry.models[member])}, {"slot", Json::StringValue(DerivedHandle(entry.models[member], "slot", slots[active].runtime_identity))},
            {"member", Json::Integer(member)}, {"stage", Json::StringValue(std::string(kSizingStages[stage]))}}));
    }
    return Envelope(id, false, "unsupported_operation", "Unknown sizing operation.");
}

Json Execute(Operation operation, const BaseContainer& request);

} // namespace

Bool Dispatch(BaseDocument* owner, BaseContainer* storage)
{
	if (!owner || !storage || storage->GetId() != kContainerId ||
		!storage->GetContainerInstance(kRequestContainer)) return false;
	const BaseContainer request = storage->GetContainer(kRequestContainer);
	const std::string id = Text(request, OperationId);
	const Operation operation = ParseOperation(Text(request, OperationName));
	Json result;
	std::string validation_error;
	if (!GeIsMainThread()) result = Envelope(id, false, "main_thread_required", "Production scene access requires the Cinema 4D main thread.");
	else if (!ValidateRequest(request, operation, validation_error)) result = Envelope(id, false, "invalid_argument", validation_error);
	else
	{
		State& state = GetState();
		const double now = GeGetMilliSeconds() / 1000.0;
		state.records.erase(std::remove_if(state.records.begin(), state.records.end(), [now](const Record& record)
			{ return now - record.accepted_at > kRetentionSeconds; }), state.records.end());
		const std::string fingerprint = Fingerprint(request);
		auto found = std::find_if(state.records.begin(), state.records.end(), [&id](const Record& record) { return record.id == id; });
		if (found != state.records.end())
			result = found->fingerprint == fingerprint ? found->result : Envelope(id, false, "operation_id_conflict", "Operation ID already has different arguments.");
		else if (state.executing) result = Envelope(id, false, "dispatcher_busy", "The serial dispatcher is already executing an operation.");
		else
		{
			if (state.records.size() >= kRecordCapacity) state.records.erase(state.records.begin());
			state.records.push_back({id, fingerprint, Envelope(id, true, "accepted", "", Json(), "running"), now});
			state.executing = true;
			state.rollback_failed = false;
			try { result = Execute(operation, request); }
			catch (...) { result = Envelope(id, false, "operation_failed", "Production operation raised an exception; its final scene/file outcome requires inspection before retrying.", Json(), "outcome_unknown"); }
			if (state.rollback_failed)
				result = Envelope(id, false, "undo_failed", "Undo recording or rollback failed; inspect the actual scene outcome before retrying.", Json(), "outcome_unknown");
			state.executing = false;
			state.records.back().result = result;
		}
	}
	storage->SetString(kResponseJson, String(result.text.c_str()));
	return true;
}

namespace
{

Json Execute(Operation operation, const BaseContainer& request)
{
	const std::string id = Text(request, OperationId), document_handle = Text(request, DocumentHandle), target_handle = Text(request, TargetHandle);
	const BaseContainer options = request.GetContainer(Options);
	if (operation == Operation::Capabilities)
	{
		std::vector<Json> documents, supported, cameras, material_types;
		for (BaseDocument* document = GetFirstDocument(); document; document = document->GetNext())
		{
			const std::string handle = RegisterHandle(document, document, true);
			documents.push_back(Json::Object({{"handle", Json::StringValue(RegisterHandle(document, document, true))},
				{"name", Json::StringValue(document->GetDocumentName().GetString())}, {"active", Json::Boolean(document == GetActiveDocument())}}));
			std::vector<BaseObject*> objects;
			CollectObjects(document->GetFirstObject(), objects);
			for (BaseObject* object : objects)
				if (object->IsInstanceOf(Ocamera) || object->IsInstanceOf(g_mmd_camera_object_id))
					cameras.push_back(Json::Object({{"handle", Json::StringValue(RegisterHandle(document, object))},
						{"document", Json::StringValue(handle)}, {"name", Json::StringValue(object->GetName())},
						{"type", Json::StringValue(std::string(object->IsInstanceOf(Ocamera) ? "ordinary" : "mmd"))}}));
		}
		for (const char* name : kOperationNames) supported.push_back(Json::StringValue(std::string(name)));
		for (const std::string& type : {std::string("standard"), std::string("redshift"), std::string("octane"), std::string("corona"), std::string("redshift_toon")})
			if (RendererAvailable(type)) material_types.push_back(Json::StringValue(type));
		return Envelope(id, true, "ok", "", Json::Object({{"protocol_version", Json::Integer(kProtocolVersion)},
			{"plugin_version", Json::StringValue(std::string("production-api-1"))}, {"host_version", Json::Integer(GetC4DVersion())},
			{"host_session", Json::StringValue(GetState().session)}, {"supported_operations", Json::Array(supported)},
			{"documents", Json::Array(documents)}, {"cameras", Json::Array(cameras)}, {"retention_seconds", Json::Integer(kRetentionSeconds)},
			{"record_capacity", Json::Integer(kRecordCapacity)}, {"max_page_size", Json::Integer(kMaxPageSize)},
			{"max_input_bytes", Json::Integer(kMaxInputBytes)}, {"transport_supported", Json::Boolean(GetC4DVersion() >= 2026400)},
			{"material_types", Json::Array(material_types)},
			{"sizing_job_capacity", Json::Integer(4)}, {"sizing_execution", Json::StringValue(std::string("main-thread-snapshot-background-solve"))},
			{"execution", Json::StringValue(std::string("synchronous-main-thread"))}}));
	}
	if (operation == Operation::Status)
	{
		const std::string query = Text(options, QueryOperationId);
		for (const auto& record : GetState().records)
			if (record.id == query) return Envelope(id, true, "ok", "", Json::Object({{"operation", record.result}}));
		return Envelope(id, false, "outcome_unknown", "Operation record is unavailable in the current host session.", Json(), "outcome_unknown");
	}
	BaseDocument* document = ResolveDocument(document_handle);
	if (!document) return Envelope(id, false, "stale_handle", "The target document is closed or belongs to another host session.");
    if (operation >= Operation::SizingStart && operation <= Operation::SizingRelease)
        return ExecuteSizing(operation, document, document_handle, id, options);
	if (operation == Operation::ListModels)
	{
		std::vector<BaseObject*> objects;
		CollectObjects(document->GetFirstObject(), objects);
		std::vector<Json> models;
		Int32 total = 0, offset = options.GetInt32(Offset, 0), limit = options.GetInt32(Limit, 64);
		for (BaseObject* object : objects)
			if (object->IsInstanceOf(g_mmd_model_manager_object_id))
			{
				if (total >= offset && total < offset + limit) models.push_back(ModelSummary(document, object));
				++total;
			}
		return Envelope(id, true, "ok", "", Json::Object({{"models", Json::Array(models)}, {"total", Json::Integer(total)},
			{"next_offset", Json::Number(offset + static_cast<Int32>(models.size()) < total ? offset + static_cast<Int32>(models.size()) : -1)}}));
	}
	if (operation == Operation::ImportPmx || operation == Operation::ImportCamera)
	{
		const Filename filename(options.GetString(Path));
		if (!IsAbsolutePath(Text(options, Path)) || !filename_util::CheckSuffix(filename, String(operation == Operation::ImportPmx ? "pmx" : "vmd")))
			return Envelope(id, false, "invalid_argument", "Import requires an absolute path with the expected suffix.");
		std::vector<uint8_t> bytes;
		if (!ReadInput(filename, bytes)) return Envelope(id, false, "read_failed", "Input is unavailable or exceeds the input byte limit.");
		libmmd::PMXFile pmx;
		libmmd::VMDFile vmd;
		std::unique_ptr<libmmd::VMDCameraAnimation> animation;
		if (operation == Operation::ImportPmx)
		{
			if (options.GetBool(Materials, true) && Text(options, MaterialType, "standard") == "redshift_toon")
			{
				String diagnostic;
				if (!MMDRedShiftToonMaterialAdapter::IsAvailable(diagnostic))
					return Envelope(id, false, "unsupported_renderer", string_util::GetStdString(diagnostic));
			}
			if (options.GetBool(Materials, true) && !RendererAvailable(Text(options, MaterialType, "standard")))
				return Envelope(id, false, "unsupported_renderer", "Requested material renderer or its required shaders are unavailable; no fallback was applied.");
			std::string error;
			if (!libmmd::ReadPMXFile(&pmx, bytes.data(), bytes.size(), &error) || !PmxInputFinite(pmx)) return Envelope(id, false, "invalid_file", "PMX parsing failed or includes nonfinite geometry/material data.");
		}
		else
		{
			animation = std::make_unique<libmmd::VMDCameraAnimation>();
			if (!libmmd::ReadVMDFile(&vmd, bytes.data(), bytes.size()) || vmd.m_cameras.empty() || !CameraInputFinite(vmd, options) || !animation->Create(vmd))
				return Envelope(id, false, "invalid_file", "VMD contains no valid camera animation.");
		}
		ImportDelta delta(document);
		// PMX initialization creates only new scene content, which ImportDelta
		// cleans up on failure. Camera import also changes existing time ranges,
		// so its document snapshot must precede initialization.
		std::unique_ptr<UndoAction> undo;
		if (operation == Operation::ImportCamera)
		{
			undo = std::make_unique<UndoAction>(document);
			if (!undo->Opened() || !undo->DocumentSettings())
				return Envelope(id, false, "undo_failed", "Could not record document settings before camera import.");
		}
		BaseObject* imported = nullptr;
		if (operation == Operation::ImportPmx)
		{
			CMTToolsSetting::ModelImport setting(document);
			setting.fn = filename; setting.position_multiple = Number(options, PositionMultiple, 8.5);
			setting.suppress_dialogs = true;
			setting.import_polygon = options.GetBool(Polygon, true); setting.import_normal = options.GetBool(Normals, true);
			setting.import_uv = options.GetBool(UV, true); setting.import_material = options.GetBool(Materials, true);
			setting.import_bone = options.GetBool(Bones, true); setting.import_weights = options.GetBool(Weights, true);
			setting.import_ik = options.GetBool(IK, true); setting.import_inherit = options.GetBool(Inherit, true);
			setting.import_expression = options.GetBool(Expressions, true); setting.import_multipart = options.GetBool(Multipart, false);
			setting.import_english = options.GetBool(English, false); setting.import_english_check = options.GetBool(EnglishCheck, false);
			const std::string type = Text(options, MaterialType, "standard");
			setting.import_material_type = type == "redshift_toon" ? CMTToolsSetting::ModelImport::material_type::RedShiftToon :
				type == "redshift" ? CMTToolsSetting::ModelImport::material_type::RedShift :
				type == "octane" ? CMTToolsSetting::ModelImport::material_type::Octane : type == "corona" ?
				CMTToolsSetting::ModelImport::material_type::Corona : CMTToolsSetting::ModelImport::material_type::Standard;
			imported = CMTSceneManager::LoadPMXModel(pmx, setting);
		}
		else
		{
			CMTToolsSetting::CameraImport setting(document);
			setting.fn = filename; setting.position_multiple = Number(options, PositionMultiple, 8.5);
			setting.time_offset = options.GetInt32(TimeOffset, 0);
			imported = CMTSceneManager::LoadVMDCamera(setting, std::move(animation));
		}
		if (!imported) return Envelope(id, false, "import_failed", "Native import failed without a modal dialog.");
		// Finish runtime inspection and BaseLink registration before recording the
		// imported hierarchy. NEWOBJ must capture the fully initialized object.
		Json result = operation == Operation::ImportPmx ?
			Envelope(id, true, "ok", "", Json::Object({{"model", ModelSummary(document, imported)}})) :
			Envelope(id, true, "ok", "", Json::Object({{"camera", Json::StringValue(RegisterHandle(document, imported))}, {"frame_count", Json::Integer(vmd.m_cameras.size())}}));
		if (!undo)
		{
			// Record PMX creation in one group after the complete hierarchy and its
			// materials are initialized. NEWOBJ is recorded after insertion.
			undo = std::make_unique<UndoAction>(document);
			if (!undo->Opened()) return Envelope(id, false, "undo_failed", "Could not open the import Undo transaction.");
		}
		// Record dependencies first: Undo removes the hierarchy before materials,
		// and Redo restores materials before the hierarchy and its material links.
		for (BaseMaterial* material = document->GetFirstMaterial(); material; material = static_cast<BaseMaterial*>(material->GetNext()))
			if (delta.IsNewMaterial(material) && !undo->Created(material)) return Envelope(id, false, "undo_failed", "Could not record imported material.");
		if (!undo->Created(imported)) return Envelope(id, false, "undo_failed", "Could not record imported object.");
		undo->Commit();
		delta.Commit();
		return result;
	}

	BaseObject* target = ResolveObject(document, document_handle, target_handle);
	if (!target) return Envelope(id, false, "stale_handle", "Target object was deleted, replaced or belongs to another document.");
	const Bool camera_operation = operation == Operation::ExportCamera;
	if (camera_operation && !(target->IsInstanceOf(Ocamera) || target->IsInstanceOf(g_mmd_camera_object_id)))
		return Envelope(id, false, "invalid_target", "Target is not an ordinary or MMD camera.");
	if (!camera_operation && !target->IsInstanceOf(g_mmd_model_manager_object_id))
		return Envelope(id, false, "invalid_target", "Target is not an MMD model.");
	auto* model = camera_operation ? nullptr : target->GetNodeData<MMDModelManagerObject>();
	if (!camera_operation && !model) return Envelope(id, false, "invalid_target", "Model runtime data is unavailable.");
	if (operation == Operation::ListSlots) return Envelope(id, true, "ok", "", Slots(model, target_handle, options));
	if (operation == Operation::InspectModel)
	{
		const std::string section = Text(options, Section, "summary");
		if (section == "slots") return Envelope(id, true, "ok", "", Slots(model, target_handle, options));
		std::vector<Json> items;
		Int32 total = 0, offset = options.GetInt32(Offset, 0), limit = options.GetInt32(Limit, 64);
		if (section == "morphs")
		{
			for (auto& morph : model->GetMorphData())
			{
				if (total >= offset && total < offset + limit) items.push_back(Json::Object({
					{"handle", Json::StringValue(DerivedHandle(target_handle, "morph", morph.GetRuntimeIdentity()))},
					{"name", Json::StringValue(morph.GetName())}, {"strength", Json::Number(morph.GetStrength(target))},
					{"type", Json::Integer(static_cast<UInt64>(morph.GetType()))}}));
				++total;
			}
		}
		else if (section == "bones")
		{
			for (BaseObject* bone : BoneObjects(model))
			{
				if (total >= offset && total < offset + limit) items.push_back(Json::Object({{"handle", Json::StringValue(RegisterHandle(document, bone))}, {"name", Json::StringValue(bone->GetName())}}));
				++total;
			}
		}
		return Envelope(id, true, "ok", "", Json::Object({{"model", ModelSummary(document, target)}, {"items", Json::Array(items)},
			{"total", Json::Integer(total)}, {"next_offset", Json::Number(offset + static_cast<Int32>(items.size()) < total ? offset + static_cast<Int32>(items.size()) : -1)}}));
	}
	if (operation == Operation::ExportPmx || operation == Operation::ExportMotion || operation == Operation::ExportCamera)
	{
		SceneCopy copy;
		if (!copy.Init(document, target)) return Envelope(id, false, "copy_failed", "Could not isolate the source document for export.");
		if (operation == Operation::ExportPmx)
		{
			CMTToolsSetting::ModelExport setting(copy.document());
			setting.fn = Filename(options.GetString(Path)); setting.position_multiple = Number(options, PositionMultiple, 8.5);
			setting.export_polygon = options.GetBool(Polygon, true); setting.export_normal = options.GetBool(Normals, true);
			setting.export_uv = options.GetBool(UV, true); setting.export_material = options.GetBool(Materials, true);
			setting.export_bone = options.GetBool(Bones, true); setting.export_weights = options.GetBool(Weights, true);
			setting.export_ik = options.GetBool(IK, true); setting.export_inherit = options.GetBool(Inherit, true);
			setting.export_expression = options.GetBool(Expressions, true);
			auto* cloned_model = copy.object->GetNodeData<MMDModelManagerObject>();
			libmmd::PMXFile pmx;
			cloned_model->PreparePMXExportState(copy.document());
			if (!cloned_model->SavePMX(pmx, setting)) return Envelope(id, false, "export_failed", "Native PMX serialization failed.");
			return WriteExport(id, options, "pmx", [&pmx](const std::string& path) { return libmmd::WritePMXFile(&pmx, path.c_str()); });
		}
		libmmd::VMDFile vmd;
		if (operation == Operation::ExportMotion)
		{
			CMTToolsSetting::MotionExport setting(copy.document());
			setting.fn = Filename(options.GetString(Path)); setting.position_multiple = Number(options, PositionMultiple, 8.5);
			setting.time_offset = options.GetInt32(TimeOffset, 0); setting.export_motion = options.GetBool(Motion, true);
			setting.export_morph = options.GetBool(Morph, true); setting.export_model_info = options.GetBool(ModelInfo, true);
			setting.use_bake = options.GetBool(Bake, true); setting.use_rotation = Text(options, Rotation, "quaternion") == "euler" ? 1 : 0;
			if (!copy.object->GetNodeData<MMDModelManagerObject>()->SaveVMDMotion(vmd, setting)) return Envelope(id, false, "export_failed", "Native motion serialization failed.");
		}
		else
		{
			CMTToolsSetting::CameraExport setting(copy.document());
			setting.fn = Filename(options.GetString(Path));
			// The public scale is C4D units per VMD unit, matching the UI.
			// Camera serialization multiplies by its internal conversion factor.
			setting.position_multiple = 1.0 / Number(options, PositionMultiple, 8.5);
			if (!std::isfinite(setting.position_multiple))
				return Envelope(id, false, "invalid_argument", "Camera export scale cannot be represented as a finite conversion factor.");
			setting.time_offset = options.GetInt32(TimeOffset, 0); setting.use_bake = options.GetBool(Bake, true);
			setting.use_rotation = Text(options, Rotation, "quaternion") == "euler" ? 1 : 0;
			BaseObject* camera = copy.object;
			AutoFree<BaseObject> converted;
			if (camera->IsInstanceOf(Ocamera))
			{
				converted.Set(BaseObject::Alloc(g_mmd_camera_object_id)); camera = converted;
				if (!camera || !camera->GetNodeData<MMDCamera>()->ConversionCamera(CMTToolsSetting::CameraConversion{copy.document(), 0., setting.use_rotation, copy.object}))
					return Envelope(id, false, "export_failed", "Detached camera conversion failed.");
			}
			if (!camera->GetNodeData<MMDCamera>()->InitCamera() || !camera->GetNodeData<MMDCamera>()->SaveVMDCamera(vmd, setting))
				return Envelope(id, false, "export_failed", "Native camera serialization failed.");
		}
		return WriteExport(id, options, "vmd", [&vmd](const std::string& path) { return libmmd::WriteVMDFile(&vmd, path.c_str()); });
	}
	if (operation == Operation::ImportMotion)
	{
		const Filename filename(options.GetString(Path));
		std::vector<uint8_t> bytes;
		libmmd::VMDFile vmd;
		if (!IsAbsolutePath(Text(options, Path)) || !filename_util::CheckSuffix(filename, "vmd"_s))
			return Envelope(id, false, "invalid_argument", "Motion import requires an absolute VMD path.");
		if (!ReadInput(filename, bytes) || !libmmd::ReadVMDFile(&vmd, bytes.data(), bytes.size()))
			return Envelope(id, false, "invalid_file", "VMD motion parsing failed.");
		CMTToolsSetting::MotionImport setting(document);
		setting.fn = filename; setting.position_multiple = Number(options, PositionMultiple, 8.5);
		setting.time_offset = options.GetInt32(TimeOffset, 0); setting.import_motion = options.GetBool(Motion, true);
		setting.import_morph = options.GetBool(Morph, true); setting.import_model_info = options.GetBool(ModelInfo, true);
		setting.ignore_physical = options.GetBool(IgnorePhysics, true); setting.import_by_local_name = options.GetBool(LocalNames, true);
		const std::string strategy = Text(options, Strategy, "append");
		setting.delete_previous_animation = strategy == "replace";
		const BaseTime time = document->GetTime();
		LoadVmdMotionLog log;
		UndoAction undo(document);
		if (!undo.DocumentSettings() || !undo.Change(target))
			return Envelope(id, false, "undo_failed", "Could not record document and model before motion import.");
		const Bool imported = model->LoadVMDMotion(vmd, setting, log, strategy == "merge");
		document->SetTime(time);
		if (!imported) return Envelope(id, false, "import_failed", "Native motion import failed and restored its transaction.");
		undo.Commit();
		std::vector<Json> unmatched_bones, unmatched_morphs;
		for (const String& name : log.not_find_bone_name_list) unmatched_bones.push_back(Json::StringValue(name));
		for (const String& name : log.not_find_morph_name_list) unmatched_morphs.push_back(Json::StringValue(name));
		const Int32 active = model->GetAutomationActiveAnimationSlot();
		const auto& slots = model->GetAutomationAnimationSlots();
		return Envelope(id, true, "ok", "", Json::Object({{"bone_count", Json::Integer(log.imported_bone_count)},
			{"morph_count", Json::Integer(log.imported_morph_count)}, {"frame_count", Json::Integer(log.imported_motion_count)},
			{"slot", Json::StringValue(active >= 0 && active < slots.GetCount() ? DerivedHandle(target_handle, "slot", slots[active].runtime_identity) : std::string{})},
			{"unmatched_bones", Json::Array(unmatched_bones)}, {"unmatched_morphs", Json::Array(unmatched_morphs)}}));
	}
	if (operation == Operation::Evaluate)
	{
		const std::string unit = Text(options, Unit);
		const double frame = Number(options, Frame);
		const Int32 time_rate = unit == "seconds" ? 1 : unit == "vmd_frames" ? 30 : document->GetFps();
		BaseTime evaluation_time;
		if (!TryEvaluationTime(frame, time_rate, evaluation_time))
			return Envelope(id, false, "invalid_time_precision", "The requested time cannot be represented at the supported precision and document frame rate.");
		const double seconds = evaluation_time.Get();
		SceneCopy copy;
		std::unique_ptr<UndoAction> playhead_undo;
		BaseDocument* evaluated_document = document;
		MMDModelManagerObject* evaluated_model = model;
		if (!options.GetBool(SetPlayhead, false))
		{
			if (!copy.Init(document, target)) return Envelope(id, false, "copy_failed", "Could not isolate frame evaluation.");
			evaluated_document = copy.document(); evaluated_model = copy.object->GetNodeData<MMDModelManagerObject>();
		}
		else
		{
			playhead_undo = std::make_unique<UndoAction>(document);
			if (!playhead_undo->DocumentSettings()) return Envelope(id, false, "undo_failed", "Could not record document time before frame evaluation.");
		}
		evaluated_document->SetTime(evaluation_time);
		if (!evaluated_document->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE))
			return Envelope(id, false, "evaluation_failed", "Document evaluation failed.");
		Bool finite = true;
		const auto bones = BoneObjects(evaluated_model);
		for (BaseObject* bone : bones)
		{
			const Matrix matrix = bone->GetMg();
			for (const Vector vector : {matrix.off, matrix.sqmat.v1, matrix.sqmat.v2, matrix.sqmat.v3})
				finite = finite && std::isfinite(vector.x) && std::isfinite(vector.y) && std::isfinite(vector.z);
		}
		if (finite && playhead_undo) { playhead_undo->Commit(); EventAdd(); }
		return Envelope(id, finite, finite ? "ok" : "nonfinite_pose", finite ? "" : "Evaluated pose contains nonfinite values.",
			Json::Object({{"frame", Json::Number(frame)}, {"unit", Json::StringValue(unit)}, {"seconds", Json::Number(seconds)},
				{"fps", Json::Integer(document->GetFps())}, {"finite", Json::Boolean(finite)}, {"bone_count", Json::Integer(bones.size())}}));
	}
	// Reject stale derived identities before opening Undo: an invalid handle must
	// not trigger a restore/copy of an otherwise unchanged model subtree.
	if (operation == Operation::SelectSlot)
	{
		const UInt64 identity = ResolveDerived(target_handle, "slot", Text(options, Slot));
		Bool exists = false;
		for (const auto& slot : model->GetAutomationAnimationSlots()) exists = exists || (identity != 0 && slot.runtime_identity == identity);
		if (!exists) return Envelope(id, false, "stale_handle", "Animation slot identity is stale or belongs to another model.");
	}
	if (operation == Operation::SetMorph)
	{
		const UInt64 identity = ResolveDerived(target_handle, "morph", Text(options, MorphHandle));
		Bool exists = false;
		for (const auto& morph : model->GetMorphData()) exists = exists || (identity != 0 && morph.GetRuntimeIdentity() == identity);
		if (!exists) return Envelope(id, false, "stale_handle", "Morph identity is stale or belongs to another model.");
	}
	UndoAction undo(document);
	if (operation == Operation::SelectSlot && !undo.DocumentSettings())
		return Envelope(id, false, "undo_failed", "Could not record document time and ranges before selecting the animation slot.");
	if (!undo.Change(target)) return Envelope(id, false, "undo_failed", "Could not record the target before mutation.");
	Bool changed = false;
	Json data;
	if (operation == Operation::SetMode)
	{
		const std::string mode = Text(options, Mode);
		changed = target->SetParameter(ConstDescID(DescLevel(MODEL_MODE)), GeData(mode == "anim" ? MODEL_MODE_ANIM : MODEL_MODE_EDIT), DESCFLAGS_SET::NONE);
		data = Json::Object({{"mode", Json::StringValue(mode)}});
	}
	else if (operation == Operation::SetPhysics)
	{
		changed = target->SetParameter(ConstDescID(DescLevel(MODEL_PHYSICS_ENABLED)), GeData(options.GetBool(Enabled)), DESCFLAGS_SET::NONE);
		data = Json::Object({{"physics_enabled", Json::Boolean(options.GetBool(Enabled))}});
	}
	else if (operation == Operation::SelectSlot)
	{
		const UInt64 identity = ResolveDerived(target_handle, "slot", Text(options, Slot));
		changed = identity != 0 && model->SelectAutomationAnimationSlot(identity);
		data = Json::Object({{"active_slot", Json::StringValue(options.GetString(Slot))}});
	}
	else if (operation == Operation::SetMorph)
	{
		const UInt64 identity = ResolveDerived(target_handle, "morph", Text(options, MorphHandle));
		changed = identity != 0 && model->SetAutomationMorphStrength(identity, Number(options, Strength));
		data = Json::Object({{"morph_handle", Json::StringValue(options.GetString(MorphHandle))}, {"strength", Json::Number(Number(options, Strength))}});
	}
	if (!changed) return Envelope(id, false, operation == Operation::SelectSlot || operation == Operation::SetMorph ? "stale_handle" : "mutation_failed",
		"Native mutation failed; the Undo transaction restored its prior state.");
	undo.Commit();
	EventAdd();
	return Envelope(id, true, "ok", "", data);
}

} // namespace
} }
