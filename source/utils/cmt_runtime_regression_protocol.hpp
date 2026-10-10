#pragma once

// Test-only SceneHook protocol. No pointer payload crosses the Python boundary:
// the request and result live in the hook's BaseContainer, and Message has no data.
// This header is included only when CMT_ENABLE_RUNTIME_REGRESSION is enabled.
namespace cmt_regression
{
	constexpr Int32 kProtocolVersion = 1;
	constexpr Int32 kMessage = 1057017; // CMTSceneManager's registered plugin ID.
	enum Field : Int32
	{
		Protocol = 1000000,
		Action,
		Path,
		Motion,
		Morph,
		ModelInfo,
		ReplaceAnimation,
		Bake,
		TimeOffset,
		IgnorePhysics,
		MorphIndex,
		MorphStrength,
		SizingSourcePath = 1000020,
		SizingStage,
		SizingOverlay,
		SizingRunning,
		SizingReady,
		SizingSummary,
		ImportScale,
		HoverX = 1000030,
		HoverY,
		HoverName,
		SizingFlags = 1000040,
		SizingCameraPath,
		SizingMember,
		Success = 1000100,
		Error,
		BoneCount,
		MorphCount,
		FrameCount,
		CameraCount
	};
	enum class Operation : Int32
	{
		Handshake = 0,
		ImportModel,
		ImportMotion,
		ExportModel,
		ExportMotion,
		ImportCamera,
		ExportCamera,
		DeleteMorph,
		SetMorphStrength,
		SizingStart = 20,
		SizingPoll,
		SizingPreview,
		SizingApply,
		SizingExport,
		SizingCancel,
        SizingClose,
        SizingDialogOpen,
        SizingDialogClose,
		ControlHover = 30,
        SizingBatchStart = 40,
        SizingSelectCharacter,
        SizingExportCamera,
        SizingApplyCamera,
        SizingSceneSlotStart,
	};
}
