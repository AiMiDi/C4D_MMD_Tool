#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "libMMD/Model/MMD/MMDMotionSizing.h"
#include <future>
#include <memory>

namespace cmt { namespace sizing
{
struct HostInput
{
    BaseObject* target = nullptr;
    Filename source;
    Filename motion;
    libmmd::sizing::Options options;
    UInt64 motionSlotIdentity = 0; // Zero selects the VMD file; otherwise a stable model slot identity.
};

// Main-thread owner. Worker input contains no BaseDocument/BaseObject pointers.
class HostSession
{
public:
    HostSession() = default;
    ~HostSession();
    HostSession(const HostSession&) = delete;
    HostSession& operator=(const HostSession&) = delete;

    bool Start(BaseObject* target, const Filename& source, const Filename& motion, const libmmd::sizing::Options& options);
    bool StartBatch(const std::vector<HostInput>& inputs, const Filename& camera, const libmmd::sizing::CameraOptions& options);
    bool Poll();
    void Cancel();
    bool Preview(size_t stage, bool overlay);
    void ClosePreview();
    bool Apply(size_t stage);
    bool Export(size_t stage, const Filename& path);
    bool ApplyCamera();
    bool ExportCamera(const Filename& path);
    bool SelectCharacter(size_t index);
    size_t CharacterCount() const { return batch_.characters.size(); }
    bool HasCamera() const { return batch_.success && cameraEnabled_ && !batch_.camera.m_cameras.empty(); }
    bool IsRunning() const { return running_; }
    bool IsCancelling() const { return running_ && cancel_.load(); }
    const libmmd::sizing::Result& GetResult() const { return selected_ < batch_.characters.size() ? batch_.characters[selected_] : emptyResult_; }
    const libmmd::sizing::BatchResult& GetBatchResult() const { return batch_; }
    const String& GetError() const { return error_; }
    BaseDocument* GetPreviewDocument() const;
    String Summary() const;

private:
    bool CheckTarget(size_t index);
    bool ValidStage(size_t stage);
    struct Target
    {
        AutoAlloc<BaseLink> object;
        AutoAlloc<BaseLink> document;
        AutoAlloc<BaseLink> before;
        AutoAlloc<BaseLink> after;
        libmmd::PMXFile snapshot;
        std::string signature;
        Float scale = 1.;
    };
    std::vector<std::unique_ptr<Target>> targets_;
    AutoAlloc<BaseLink> preview_;
    AutoAlloc<BaseLink> previewCamera_;
    std::future<libmmd::sizing::BatchResult> job_;
    std::atomic_bool cancel_{false};
    bool running_ = false;
    libmmd::sizing::BatchResult batch_;
    libmmd::sizing::Result emptyResult_;
    size_t selected_ = 0;
    bool cameraEnabled_ = false;
    String error_;
};

// Main-thread presentation of a production MCP job. Links, not raw scene
// pointers, survive document closure. The dispatcher remains the sole owner
// of the job; a dialog must not prolong its lifetime after release/expiry.
struct PanelInput
{
    AutoAlloc<BaseLink> target;
    Filename source;
    Filename motion;
    libmmd::sizing::Options options;
    UInt64 motionSlotIdentity = 0;
};

struct PanelState
{
    std::weak_ptr<HostSession> session;
    std::vector<std::unique_ptr<PanelInput>> inputs;
    Filename camera;
    libmmd::sizing::CameraOptions cameraOptions;
    size_t member = 0;
    size_t stage = static_cast<size_t>(libmmd::sizing::Stage::Count) - 1;
    bool overlay = false;
};

std::shared_ptr<PanelState> MakePanelState(const std::shared_ptr<HostSession>& session,
    const std::vector<HostInput>& inputs, const Filename& camera, const libmmd::sizing::CameraOptions& options);
void PublishPanelState(const std::shared_ptr<PanelState>& state);
void WithdrawPanelState(const std::shared_ptr<PanelState>& state);
std::shared_ptr<const PanelState> GetPanelState(UInt64& revision);
} }
