#pragma once

// Versioned production SceneHook protocol. Independent of the test-only bridge.
namespace cmt { namespace automation
{

constexpr Int32 kProtocolVersion = 1;
// Use the SDK's supported message data route. The qualifier and request/result
// fields live in the caller-owned packet, never in persistent SceneHook data.
constexpr Int32 kTransportMessage = MSG_BASECONTAINER;
constexpr Int32 kContainerId = 1057017;
constexpr Int32 kMessage = kContainerId; // Reserved qualifier; not a message type.
constexpr Int32 kRequestContainer = 2000000;
constexpr Int32 kResponseJson = 2000001;
constexpr Int32 kRetentionSeconds = 900;
constexpr Int32 kRecordCapacity = 256;
constexpr Int32 kMaxPageSize = 256;
constexpr Int64 kMaxInputBytes = 256 * 1024 * 1024;

enum RequestField : Int32
{
	Protocol = 0, OperationName = 1, OperationId = 2,
	DocumentHandle = 3, TargetHandle = 4, Options = 5
};

enum Option : Int32
{
	Path = 100, PositionMultiple = 101, Strategy = 102,
	Motion = 103, Morph = 104, ModelInfo = 105, TimeOffset = 106,
	IgnorePhysics = 107, LocalNames = 108, Bake = 109,
	Rotation = 110, Overwrite = 111, Slot = 112, Mode = 113,
	Enabled = 114, MorphHandle = 115, Strength = 116, Frame = 117,
	Unit = 118, SetPlayhead = 119, Offset = 120, Limit = 121,
	Section = 122, Polygon = 123, Normals = 124, UV = 125,
	Materials = 126, Bones = 127, Weights = 128, IK = 129,
	Inherit = 130, Expressions = 131, Multipart = 132,
	English = 133, EnglishCheck = 134, MaterialType = 135,
	QueryOperationId = 136
};

} }
