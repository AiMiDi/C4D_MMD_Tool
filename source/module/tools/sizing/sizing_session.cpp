#include "sizing_session.h"
#include "CMTSceneManager.h"
#include "plugin_resource.h"
#include "module/tools/object/mmd_model_manager.h"
#include "description/OMMDModelManager.h"
#include "description/tdisplay.h"
#include "utils/filename_util.hpp"
#include "utils/string_util.hpp"
#include <c4d_symbols.h>
#include <set>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <mutex>
#include "maxon/job.h"

namespace cmt { namespace sizing
{
namespace { std::weak_ptr<StatusProgress> statusOwner; }

// The solver owns no SDK objects. Coalesced, asynchronous main-thread jobs
// present its latest progress even when the dialog and MCP polling are idle.
// Queued jobs hold weak references, never a HostSession or document pointer.
class StatusProgress : public std::enable_shared_from_this<StatusProgress>
{
public:
    static std::shared_ptr<StatusProgress> Begin(Int32 label)
    {
        auto status = std::make_shared<StatusProgress>();
        status->label_ = label;
        statusOwner = status; // Main-thread-only ownership of C4D's shared bar.
        status->Draw();
        return status;
    }

    void SetLabel(Int32 label)
    {
        { std::lock_guard<std::mutex> lock(mutex_); label_ = label; }
        Schedule();
    }

    void Publish(const libmmd::sizing::Progress& value)
    {
        { std::lock_guard<std::mutex> lock(mutex_); value_ = value; label_ = 0; }
        const auto now = std::chrono::steady_clock::now();
        // Only the worker calls Publish. Bound UI queue traffic, not solver work.
        if (now - lastPublished_ >= std::chrono::milliseconds(100))
        { lastPublished_ = now; Schedule(); }
    }

    void Cancel() { cancelling_.store(true); Schedule(); }
    void Finish() { finished_.store(true); Schedule(); }
    libmmd::sizing::Progress Snapshot()
    {
        std::lock_guard<std::mutex> lock(mutex_);
        return value_;
    }

private:
    void Schedule()
    {
        if (GeIsMainThread()) { Draw(); return; }
        if (queued_.exchange(true)) return;
        const std::weak_ptr<StatusProgress> weak = shared_from_this();
        iferr (maxon::JobRef::Enqueue([weak]() {
            if (const auto status = weak.lock())
            {
                status->queued_.store(false);
                status->Draw();
            }
        }, maxon::JobQueueInterface::GetMainThreadQueue()))
        {
            // Presentation allocation must not fail or block a calculation.
            // Poll()/destruction still clears the bar on the main thread.
            queued_.store(false);
        }
    }

    void Draw()
    {
        if (!GeIsMainThread()) return;
        if (finished_.load())
        {
            if (statusOwner.lock().get() == this) { StatusClear(); statusOwner.reset(); }
            return;
        }
        if (statusOwner.expired()) statusOwner = shared_from_this();
        if (statusOwner.lock().get() != this) return;
        libmmd::sizing::Progress value;
        Int32 label = 0;
        { std::lock_guard<std::mutex> lock(mutex_); value = value_; label = label_; }
        if (cancelling_.load()) label = IDS_SIZING_PROGRESS_CANCELLING;
        const Int32 phaseLabels[] = {IDS_SIZING_PROGRESS_VALIDATION, IDS_SIZING_PROGRESS_MOVEMENT,
            IDS_SIZING_STAGE_STANCE, IDS_SIZING_STAGE_TWIST, IDS_SIZING_STAGE_AVOIDANCE,
            IDS_SIZING_STAGE_CONTACT, IDS_SIZING_STAGE_MULTI, IDS_SIZING_CAMERA, IDS_SIZING_LEG_AVOIDANCE};
        String text = GeLoadString(IDS_SIZING_TITLE) + String(" | ") +
            GeLoadString(label ? label : phaseLabels[static_cast<size_t>(value.phase)]);
        if (!label)
        {
            if (value.characterIndex)
                text += String(" | ") + String::IntToString(static_cast<Int32>(value.characterIndex)) +
                    String(" / ") + String::IntToString(static_cast<Int32>(value.characterCount));
            if (value.total)
                text += String(" | ") + String::UIntToString(value.completed) + String(" / ") + String::UIntToString(value.total);
        }
        StatusSetText(text);
        if (label || !value.total) StatusSetSpin();
        else StatusSetBar(static_cast<Int32>(100. * std::min(value.completed, value.total) / value.total));
    }

    std::mutex mutex_;
    libmmd::sizing::Progress value_;
    Int32 label_ = 0;
    std::atomic_bool queued_{false};
    std::atomic_bool finished_{false};
    std::atomic_bool cancelling_{false};
    std::chrono::steady_clock::time_point lastPublished_{};
};

namespace
{
class ScopedStatus
{
public:
    explicit ScopedStatus(Int32 label) : status_(StatusProgress::Begin(label)) {}
    explicit ScopedStatus(std::shared_ptr<StatusProgress> status) : status_(std::move(status)) {}
    ~ScopedStatus() { status_->Finish(); }
    void SetLabel(Int32 label) { status_->SetLabel(label); }
private:
    std::shared_ptr<StatusProgress> status_;
};
}

namespace
{
std::weak_ptr<PanelState> publishedPanel;
UInt64 panelRevision = 0;
using DocumentOwner = std::unique_ptr<BaseDocument, void(*)(BaseDocument*)>;

bool Snapshot(BaseObject* target, libmmd::PMXFile& output, Float& scale,
              libmmd::VMDFile* motion = nullptr, UInt64 slotIdentity = 0)
{
    if (!target || !target->IsInstanceOf(g_mmd_model_manager_object_id) || !target->GetDocument()) return false;
    scale = target->GetDataInstance()->GetFloat(MODEL_POSITION_MULTIPLE, 8.5);
    if (!std::isfinite(scale) || scale <= 0) return false;
    // Export only in an isolated translated document: SavePMX synchronizes
    // hierarchy and metadata and must not mutate the artist's document.
    std::vector<Int32> path;
    for (BaseObject* node = target; node; node = node->GetUp())
    {
        Int32 index = 0;
        for (BaseObject* previous = node->GetPred(); previous; previous = previous->GetPred()) ++index;
        path.push_back(index);
    }
    AutoAlloc<AliasTrans> translator;
    if (!translator || !translator->Init(target->GetDocument())) return false;
    DocumentOwner copy(static_cast<BaseDocument*>(target->GetDocument()->GetClone(COPYFLAGS::NONE, translator)),
                       [](BaseDocument* doc) { BaseDocument::Free(doc); });
    if (!copy) return false;
    translator->Translate(true);
    BaseObject* node = copy->GetFirstObject();
    for (auto item = path.rbegin(); item != path.rend(); ++item)
    {
        for (Int32 i = 0; node && i < *item; ++i) node = node->GetNext();
        if (!node) return false;
        if (std::next(item) != path.rend()) node = node->GetDown();
    }
    auto* model = node->GetNodeData<MMDModelManagerObject>();
    if (!model) return false;
    if (motion)
    {
        // Clones get new runtime identities. Resolve the original identity to
        // an index before selecting that index exclusively in the clone.
        const auto* original = target->GetNodeData<MMDModelManagerObject>();
        const auto& slots = original->GetAutomationAnimationSlots();
        Int32 selected = -1;
        for (Int32 i = 0; i < slots.GetCount(); ++i)
            if (slots[i].runtime_identity == slotIdentity) selected = i;
        if (selected < 0 || !node->SetParameter(ConstDescID(DescLevel(MODEL_ANIM_LIST)), GeData(selected), DESCFLAGS_SET::NONE))
            return false;
        CMTToolsSetting::MotionExport exportMotion(copy.get());
        exportMotion.position_multiple = scale;
        exportMotion.use_bake = false;
        if (!model->SaveVMDMotion(*motion, exportMotion)) return false;
    }
    CMTToolsSetting::ModelExport setting(copy.get());
    setting.position_multiple = scale;
    setting.export_polygon = setting.export_normal = setting.export_uv = true;
    setting.export_bone = setting.export_weights = setting.export_ik = setting.export_inherit = true;
    setting.export_material = true;
    setting.export_expression = true;
    return model->SavePMX(output, setting);
}

std::string Signature(const libmmd::PMXFile& model, Float scale)
{
    // Exact textual signature over all inputs used by the solver. Names are
    // length-prefixed; float values round-trip. No object dirty counter is used:
    // ordinary animation playback must not spuriously invalidate bind data.
    std::ostringstream out;
    out.imbue(std::locale::classic());
    out << std::setprecision(17) << scale << ' ' << model.m_bones.size() << ' ' << model.m_vertices.size() << '\n';
    for (const auto& bone : model.m_bones)
    {
        out << bone.m_name.size() << ':' << bone.m_name << ' ' << bone.m_position.transpose() << ' '
            << bone.m_parentBoneIndex << ' ' << static_cast<uint16_t>(bone.m_boneFlag);
        if ((static_cast<uint16_t>(bone.m_boneFlag) & 0x400u) != 0) out << ' ' << bone.m_fixedAxis.transpose();
        if ((static_cast<uint16_t>(bone.m_boneFlag) & 0x300u) != 0)
            out << ' ' << bone.m_appendBoneIndex << ' ' << bone.m_appendWeight;
        out << '\n';
    }
    for (const auto& vertex : model.m_vertices)
    {
        out << vertex.m_position.transpose() << ' ' << static_cast<int>(vertex.m_weightType);
        const int count = vertex.m_weightType == libmmd::PMXVertexWeight::BDEF1 ? 1 :
            (vertex.m_weightType == libmmd::PMXVertexWeight::BDEF2 || vertex.m_weightType == libmmd::PMXVertexWeight::SDEF ? 2 : 4);
        for (int i = 0; i < count; ++i) out << ' ' << vertex.m_boneIndices[i] << ':' << vertex.m_boneWeights[i];
        out << '\n';
    }
    for (const auto& body : model.m_rigidbodies)
        out << body.m_name.size() << ':' << body.m_name << ' ' << body.m_boneIndex << ' '
            << static_cast<int>(body.m_shape) << ' ' << static_cast<int>(body.m_op) << ' '
            << body.m_shapeSize.transpose() << ' ' << body.m_translate.transpose() << ' ' << body.m_rotate.transpose() << '\n';
    return out.str();
}

bool ImportStage(BaseDocument* doc, BaseObject* target, const libmmd::VMDFile& motion,
                 Float scale, bool replace, const String& name)
{
    CMTToolsSetting::MotionImport setting(doc);
    setting.fn = Filename(name + String(".vmd"));
    setting.position_multiple = scale;
    setting.delete_previous_animation = replace;
    setting.ignore_physical = false;
    LoadVmdMotionLog log;
    return CMTSceneManager::LoadVMDMotion(setting, motion, log, target);
}

void StylePreview(BaseObject* root, const Vector& color, bool ghost)
{
    std::vector<BaseObject*> pending{root};
    while (!pending.empty())
    {
        BaseObject* object = pending.back();
        pending.pop_back();
        auto properties = MakeObjectColorProperties(color, ID_BASEOBJECT_USECOLOR_ALWAYS, false);
        object->SetColorProperties(&properties);
        object->SetParameter(ConstDescID(DescLevel(ID_BASEOBJECT_XRAY)), GeData(ghost), DESCFLAGS_SET::NONE);
        if (object->IsInstanceOf(Opolygon))
        {
            BaseTag* display = object->GetTag(Tdisplay);
            if (!display) display = object->MakeTag(Tdisplay);
            if (display)
            {
                display->GetDataInstance()->SetBool(DISPLAYTAG_AFFECT_DISPLAYMODE, true);
                display->GetDataInstance()->SetInt32(DISPLAYTAG_SDISPLAYMODE,
                    ghost ? DISPLAYTAG_SDISPLAY_NOSHADING : DISPLAYTAG_SDISPLAY_GOURAUD);
            }
        }
        for (BaseObject* child = object->GetDown(); child; child = child->GetNext()) pending.push_back(child);
    }
}
}

std::shared_ptr<PanelState> MakePanelState(const std::shared_ptr<HostSession>& session,
    const std::vector<HostInput>& inputs, const Filename& camera, const libmmd::sizing::CameraOptions& options)
{
    auto state = std::make_shared<PanelState>();
    state->session = session;
    state->camera = camera;
    state->cameraOptions = options;
    for (const auto& input : inputs)
    {
        auto entry = std::make_unique<PanelInput>();
        entry->target->SetLink(input.target);
        entry->source = input.source;
        entry->motion = input.motion;
        entry->options = input.options;
        entry->motionSlotIdentity = input.motionSlotIdentity;
        state->inputs.push_back(std::move(entry));
    }
    return state;
}

void PublishPanelState(const std::shared_ptr<PanelState>& state)
{
    publishedPanel = state;
    ++panelRevision;
}

void WithdrawPanelState(const std::shared_ptr<PanelState>& state)
{
    if (publishedPanel.lock() == state)
    {
        publishedPanel.reset();
        ++panelRevision;
    }
}

std::shared_ptr<const PanelState> GetPanelState(UInt64& revision)
{
    revision = panelRevision;
    return publishedPanel.lock();
}

HostSession::~HostSession()
{
    Cancel();
    if (job_.valid()) job_.wait();
    if (progress_) progress_->Finish();
    ClosePreview();
}

bool HostSession::Start(BaseObject* target, const Filename& source, const Filename& motion, const libmmd::sizing::Options& options)
{
    return StartBatch({HostInput{target, source, motion, options}}, Filename(), libmmd::sizing::CameraOptions());
}

bool HostSession::StartBatch(const std::vector<HostInput>& inputs, const Filename& cameraPath, const libmmd::sizing::CameraOptions& options)
{
    if (!GeIsMainThread() || running_) return false;
    ScopedStatus preparing(IDS_SIZING_PROGRESS_READING);
    error_ = String();
    ClosePreview();
    batch_ = libmmd::sizing::BatchResult();
    targets_.clear();
    selected_ = 0;
    cameraEnabled_ = options.enabled;
    if (inputs.empty() || inputs.size() > 16 || !preview_ || !previewCamera_)
    { error_ = GeLoadString(IDS_SIZING_ERR_BATCH); return false; }
    std::vector<libmmd::sizing::CharacterInput> characters;
    std::set<BaseObject*> unique;
    BaseDocument* document = nullptr;
    for (const auto& input : inputs)
    {
        preparing.SetLabel(IDS_SIZING_PROGRESS_READING);
        if (!input.target || !input.target->GetDocument() || !unique.insert(input.target).second ||
            (document && document != input.target->GetDocument()))
        { error_ = GeLoadString(IDS_SIZING_ERR_TARGETS); return false; }
        document = input.target->GetDocument();
        libmmd::sizing::CharacterInput character;
        character.options = input.options;
        std::vector<uint8_t> bytes;
        if (!filename_util::ReadFileData(input.source, bytes) || !libmmd::ReadPMXFile(&character.source, bytes.data(), bytes.size()))
        { error_ = GeLoadString(IDS_SIZING_ERR_SOURCE); return false; }
        if (!input.motionSlotIdentity &&
            (!filename_util::ReadFileData(input.motion, bytes) || !libmmd::ReadVMDFile(&character.motion, bytes.data(), bytes.size())))
        { error_ = GeLoadString(IDS_SIZING_ERR_MOTION); return false; }
        auto target = std::make_unique<Target>();
        preparing.SetLabel(IDS_SIZING_PROGRESS_SNAPSHOT);
        if (!target->object || !target->document || !target->before || !target->after ||
            !Snapshot(input.target, target->snapshot, target->scale,
                      input.motionSlotIdentity ? &character.motion : nullptr, input.motionSlotIdentity))
        { error_ = GeLoadString(IDS_SIZING_ERR_SNAPSHOT); return false; }
        if (!targets_.empty() && std::abs(target->scale - targets_.front()->scale) > 1.e-8)
        { error_ = GeLoadString(IDS_SIZING_ERR_SCALE); return false; }
        target->object->SetLink(input.target);
        target->document->SetLink(document);
        target->signature = Signature(target->snapshot, target->scale);
        character.target = target->snapshot;
        targets_.push_back(std::move(target));
        characters.push_back(std::move(character));
    }
    libmmd::VMDFile camera;
    if (options.enabled)
    {
        preparing.SetLabel(IDS_SIZING_PROGRESS_READING);
        std::vector<uint8_t> bytes;
        if (!filename_util::ReadFileData(cameraPath, bytes) || !libmmd::ReadVMDFile(&camera, bytes.data(), bytes.size()) || camera.m_cameras.empty())
        { error_ = GeLoadString(IDS_SIZING_ERR_CAMERA); return false; }
    }
    cancel_.store(false);
    progress_ = StatusProgress::Begin(IDS_SIZING_RUNNING);
    try
    {
        job_ = std::async(std::launch::async, [characters = std::move(characters), camera = std::move(camera), options, this, status = progress_]() {
            ScopedStatus completion(status);
            return libmmd::sizing::RunBatch(characters, camera, options, &cancel_,
                [status](const libmmd::sizing::Progress& progress) { status->Publish(progress); });
        });
    }
    catch (const std::exception& error)
    {
        progress_->Finish();
        error_ = GeLoadString(IDS_SIZING_ERR_SOLVE) + String("\n") + String(error.what());
        return false;
    }
    running_ = true;
    return true;
}

bool HostSession::Poll()
{
    if (!running_ || job_.wait_for(std::chrono::milliseconds(0)) != std::future_status::ready) return false;
    try { batch_ = job_.get(); }
    catch (const std::exception& error) { batch_ = libmmd::sizing::BatchResult(); batch_.error = error.what(); }
    running_ = false;
    if (progress_) progress_->Finish();
    if (cancel_.load()) { batch_ = libmmd::sizing::BatchResult(); batch_.cancelled = true; }
    if (!batch_.error.empty()) error_ = GeLoadString(IDS_SIZING_ERR_SOLVE) + String("\n") + String(batch_.error.c_str());
    return true;
}

void HostSession::Cancel()
{
    cancel_.store(true);
    if (running_ && progress_) progress_->Cancel();
}

libmmd::sizing::Progress HostSession::GetProgress() const
{
    return progress_ ? progress_->Snapshot() : libmmd::sizing::Progress();
}

bool HostSession::SelectCharacter(size_t index)
{
    if (running_ || index >= batch_.characters.size()) return false;
    selected_ = index;
    return true;
}

BaseDocument* HostSession::GetPreviewDocument() const
{
    return preview_ ? static_cast<BaseDocument*>(preview_->GetLink(nullptr, Tbasedocument)) : nullptr;
}

void HostSession::ClosePreview()
{
    if (BaseDocument* preview = GetPreviewDocument())
    {
        if (GetActiveDocument() == preview && !targets_.empty())
            if (auto* source = static_cast<BaseDocument*>(targets_.front()->document->GetLink(nullptr, Tbasedocument))) SetActiveDocument(source);
        KillDocument(preview);
    }
    if (preview_) preview_->SetLink(nullptr);
    if (previewCamera_) previewCamera_->SetLink(nullptr);
    for (auto& target : targets_) { target->before->SetLink(nullptr); target->after->SetLink(nullptr); }
}

bool HostSession::ValidStage(size_t stage)
{
    error_ = String();
    if (running_ || !batch_.success || stage >= static_cast<size_t>(libmmd::sizing::Stage::Count))
    { error_ = GeLoadString(IDS_SIZING_ERR_RESULT); return false; }
    return true;
}

bool HostSession::CheckTarget(size_t index)
{
    if (index >= targets_.size()) return false;
    auto& entry = *targets_[index];
    auto* document = static_cast<BaseDocument*>(entry.document->GetLink(nullptr, Tbasedocument));
    auto* target = static_cast<BaseObject*>(entry.object->GetLink(document, Obase));
    if (!document || !target || target->GetDocument() != document)
    { error_ = GeLoadString(IDS_SIZING_ERR_REMOVED); return false; }
    libmmd::PMXFile current;
    Float scale = 0;
    if (!Snapshot(target, current, scale) || Signature(current, scale) != entry.signature)
    { error_ = GeLoadString(IDS_SIZING_ERR_STALE); return false; }
    return true;
}

namespace
{
BaseObject* ImportCamera(BaseDocument* document, const libmmd::VMDFile& data, Float scale)
{
    auto animation = std::make_unique<libmmd::VMDCameraAnimation>();
    if (!animation->Create(data)) return nullptr;
    CMTToolsSetting::CameraImport setting(document);
    setting.position_multiple = scale;
    setting.fn = Filename(GeLoadString(IDS_SIZING_CAMERA_RESULT));
    return CMTSceneManager::LoadVMDCamera(setting, std::move(animation));
}
}

bool HostSession::Preview(size_t stage, bool overlay)
{
    if (!GeIsMainThread() || !ValidStage(stage)) return false;
    ScopedStatus status(IDS_SIZING_PROGRESS_PREVIEW);
    BaseDocument* preview = GetPreviewDocument();
    bool valid = preview != nullptr;
    for (const auto& target : targets_)
        valid = valid && target->before->GetLink(preview, Obase) && target->after->GetLink(preview, Obase);
    if (!valid)
    {
        ClosePreview();
        DocumentOwner owned(BaseDocument::Alloc(), [](BaseDocument* doc) { BaseDocument::Free(doc); });
        if (!owned) { error_ = GeLoadString(IDS_SIZING_ERR_PREVIEW); return false; }
        BaseObject* previous = nullptr;
        for (size_t i = 0; i < targets_.size(); ++i)
        {
            auto& entry = *targets_[i];
            CMTToolsSetting::ModelImport setting(owned.get());
            setting.position_multiple = entry.scale;
            setting.import_polygon = setting.import_bone = setting.import_weights = true;
            setting.import_ik = setting.import_inherit = setting.import_expression = true;
            setting.suppress_dialogs = true;
            auto* before = CMTSceneManager::LoadPMXModel(entry.snapshot, setting);
            auto* after = CMTSceneManager::LoadPMXModel(entry.snapshot, setting);
            if (!before || !after) { error_ = GeLoadString(IDS_SIZING_ERR_PREVIEW); return false; }
            before->Remove(); after->Remove();
            owned->InsertObject(before, nullptr, previous);
            owned->InsertObject(after, nullptr, before);
            previous = after;
            before->SetName(GeLoadString(IDS_SIZING_BEFORE) + String::IntToString(static_cast<Int32>(i + 1)));
            after->SetName(GeLoadString(IDS_SIZING_AFTER) + String::IntToString(static_cast<Int32>(i + 1)));
            before->GetDataInstance()->SetBool(MODEL_PHYSICS_ENABLED, false);
            after->GetDataInstance()->SetBool(MODEL_PHYSICS_ENABLED, false);
            if (!ImportStage(owned.get(), before, batch_.characters[i].stages[0], entry.scale, true, GeLoadString(IDS_SIZING_BEFORE)))
            { error_ = GeLoadString(IDS_SIZING_ERR_PREVIEW); return false; }
            entry.before->SetLink(before); entry.after->SetLink(after);
        }
        owned->SetDocumentName(GeLoadString(IDS_SIZING_PREVIEW_DOCUMENT));
        owned->SetFps(30);
        preview = owned.release();
        InsertBaseDocument(preview);
        preview_->SetLink(preview);
    }
    const BaseTime time = preview->GetTime();
    double extent = 1.;
    for (const auto& target : targets_)
        for (const auto& bone : target->snapshot.m_bones) extent = std::max(extent, std::abs(static_cast<double>(bone.m_position.x())));
    for (size_t i = 0; i < targets_.size(); ++i)
    {
        auto& entry = *targets_[i];
        auto* before = static_cast<BaseObject*>(entry.before->GetLink(preview, Obase));
        auto* after = static_cast<BaseObject*>(entry.after->GetLink(preview, Obase));
        if (!ImportStage(preview, after, batch_.characters[i].stages[stage], entry.scale, true, GeLoadString(IDS_SIZING_AFTER)))
        { error_ = GeLoadString(IDS_SIZING_ERR_PREVIEW); return false; }
        before->SetRelPos(Vector(overlay ? 0. : -extent * entry.scale * 1.3, 0, 0));
        after->SetRelPos(Vector(overlay ? 0. : extent * entry.scale * 1.3, 0, 0));
        StylePreview(before, Vector(.15, .45, 1.), overlay);
        StylePreview(after, Vector(1., .5, .1), false);
    }
    if (HasCamera())
    {
        auto* oldCamera = static_cast<BaseObject*>(previewCamera_->GetLink(preview, Obase));
        auto cameraMotion = stage == static_cast<size_t>(libmmd::sizing::Stage::MultiCharacter) ? batch_.camera : batch_.originalCamera;
        // The camera follows the adjusted group when comparing side by side.
        if (!overlay) for (auto& key : cameraMotion.m_cameras) key.m_interest.x() += static_cast<float>(extent * 1.3);
        auto* camera = ImportCamera(preview, cameraMotion, targets_.front()->scale);
        if (!camera) { error_ = GeLoadString(IDS_SIZING_ERR_CAMERA); return false; }
        if (oldCamera) { oldCamera->Remove(); BaseObject::Free(oldCamera); }
        previewCamera_->SetLink(camera);
    }
    preview->FlushUndoBuffer();
    preview->SetTime(time);
    preview->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE);
    SetActiveDocument(preview);
    preview->SetActiveObject(static_cast<BaseObject*>(targets_[selected_]->after->GetLink(preview, Obase)), SELECTION_NEW);
    EventAdd();
    return true;
}

bool HostSession::Apply(size_t stage)
{
    if (!GeIsMainThread() || !ValidStage(stage)) return false;
    ScopedStatus status(IDS_SIZING_PROGRESS_APPLY);
    // A batch result depends on every member, even when applying one slot.
    for (size_t i = 0; i < targets_.size(); ++i) if (!CheckTarget(i)) return false;
    auto& entry = *targets_[selected_];
    auto* document = static_cast<BaseDocument*>(entry.document->GetLink(nullptr, Tbasedocument));
    auto* target = static_cast<BaseObject*>(entry.object->GetLink(document, Obase));
    // C4D records selection changes as undo steps. Select before the motion
    // transaction so the first Undo always restores the previous motion slot.
    SetActiveDocument(document);
    document->SetActiveObject(target, SELECTION_NEW);
    if (!ImportStage(document, target, GetResult().stages[stage], entry.scale, false,
                     GeLoadString(IDS_SIZING_SLOT) + String::IntToString(static_cast<Int32>(stage))))
    { error_ = GeLoadString(IDS_SIZING_ERR_APPLY); return false; }
    EventAdd();
    return true;
}

bool HostSession::Export(size_t stage, const Filename& path)
{
    if (!GeIsMainThread() || !ValidStage(stage)) return false;
    ScopedStatus status(IDS_SIZING_PROGRESS_EXPORT);
    if (!libmmd::WriteVMDFile(&GetResult().stages[stage], string_util::GetStdString(path.GetString()).c_str()))
    { error_ = GeLoadString(IDS_SIZING_ERR_EXPORT); return false; }
    return true;
}

bool HostSession::ExportCamera(const Filename& path)
{
    if (!GeIsMainThread()) return false;
    if (running_ || !HasCamera()) { error_ = GeLoadString(IDS_SIZING_ERR_CAMERA); return false; }
    ScopedStatus status(IDS_SIZING_PROGRESS_EXPORT);
    if (!libmmd::WriteVMDFile(&batch_.camera, string_util::GetStdString(path.GetString()).c_str()))
    { error_ = GeLoadString(IDS_SIZING_ERR_EXPORT); return false; }
    return true;
}

bool HostSession::ApplyCamera()
{
    if (!GeIsMainThread() || running_ || !HasCamera()) return false;
    ScopedStatus status(IDS_SIZING_PROGRESS_APPLY);
    for (size_t i = 0; i < targets_.size(); ++i) if (!CheckTarget(i)) return false;
    auto* document = static_cast<BaseDocument*>(targets_.front()->document->GetLink(nullptr, Tbasedocument));
    document->StartUndo();
    auto* camera = ImportCamera(document, batch_.camera, targets_.front()->scale);
    if (camera)
    {
        document->AddUndo(UNDOTYPE::NEWOBJ, camera);
        document->SetActiveObject(camera, SELECTION_NEW);
    }
    document->EndUndo();
    if (!camera) { error_ = GeLoadString(IDS_SIZING_ERR_CAMERA); return false; }
    SetActiveDocument(document);
    EventAdd();
    return true;
}

String HostSession::Summary() const
{
    if (running_) return GeLoadString(IDS_SIZING_RUNNING);
    if (batch_.cancelled) return GeLoadString(IDS_SIZING_CANCELLED);
    if (!batch_.success) return error_;
    const auto& result = GetResult();
    std::ostringstream values;
    values << selected_ + 1 << " / " << batch_.characters.size() << " | XZ " << result.analysis.horizontalRatio
           << " | Y " << result.analysis.verticalRatio << " | " << result.elapsedMilliseconds << " ms\n";
    String report = GeLoadString(IDS_SIZING_COMPLETE) + String(" ") + String(values.str().c_str());
    report += GeLoadString(IDS_SIZING_RESIDUAL) + String(" ") + String::FloatToString(result.analysis.maxResidual) +
        String(" | ") + String::IntToString(static_cast<Int32>(result.analysis.unresolved)) + String(" / ") +
        String::IntToString(static_cast<Int32>(result.analysis.constraints)) + String("\n");
    for (const auto& warning : result.analysis.warnings) report += String(warning.c_str()) + String("\n");
    return report;
}
} }
