#include "motion_sizing_dialog.h"
#include "plugin_resource.h"
#include "utils/filename_util.hpp"
#include <c4d_symbols.h>
#include "module/tools/object/mmd_model_manager.h"
#include <algorithm>
#include <iterator>

namespace
{
enum : Int32
{
    SourcePath = 2000, SourceBrowse, MotionPath, MotionBrowse, TargetPick, TargetName,
    Movement, LegOffset, CenterOffsets, LegOffsets, Calculate, Cancel, Stage,
    Overlay, Preview, ClosePreview, Apply, Export, Report,
    Stance = 2200, Twist, Avoidance, Wrist, Finger, FloorContact, Multi, Distance, Margin,
    FloorHeight, CameraPath, CameraBrowse, CameraEnabled, CameraLimit, CameraApply, CameraExport,
    Queue, QueueAdd, QueueRemove, MotionSlot, LivePreview, LegAvoidance
};
const Int32 Editable[] = {SourcePath, SourceBrowse, MotionPath, MotionBrowse, TargetPick, Movement,
    LegOffset, CenterOffsets, LegOffsets, Calculate, Stance, Twist, Avoidance, LegAvoidance, Wrist, Finger, FloorContact,
    Multi, Distance, Margin, FloorHeight, CameraPath, CameraBrowse, CameraEnabled, CameraLimit, QueueAdd, QueueRemove, TargetName, MotionSlot};
String Text(Int32 id) { return GeLoadString(id); }
}

Bool MotionSizingDialog::CreateLayout()
{
    SetTitle(Text(IDS_SIZING_TITLE));
    ScrollGroupBegin(99, BFH_SCALEFIT | BFV_SCALEFIT, SCROLLGROUP_VERT | SCROLLGROUP_BORDERIN, 0, 0);
    GroupBegin(100, BFH_SCALEFIT | BFV_SCALEFIT, 1, 0, String(), 0);
    GroupBorderSpace(12, 12, 12, 12);
    AddUserArea(121, BFH_CENTER, SizePix(300), SizePix(95));
    AttachUserArea(logo_, 121);
    AddStaticText(101, BFH_LEFT, 0, 0, Text(IDS_SIZING_INPUT_HINT), 0);
    GroupBegin(102, BFH_SCALEFIT, 3, 0, String(), 0);
    AddStaticText(103, BFH_LEFT, 0, 0, Text(IDS_SIZING_SOURCE), 0);
    AddEditText(SourcePath, BFH_SCALEFIT, SizePix(340), 0);
    AddButton(SourceBrowse, BFH_RIGHT, 0, 0, Text(IDS_SIZING_BROWSE));
    AddStaticText(104, BFH_LEFT, 0, 0, Text(IDS_SIZING_MOTION), 0);
    AddEditText(MotionPath, BFH_SCALEFIT, SizePix(340), 0);
    AddButton(MotionBrowse, BFH_RIGHT, 0, 0, Text(IDS_SIZING_BROWSE));
    AddStaticText(105, BFH_LEFT, 0, 0, Text(IDS_SIZING_TARGET), 0);
    BaseContainer linkSettings;
#if CMT_SDK_HAS_LINKBOX_EMPTY_TEXT
    linkSettings.SetString(LINKBOX_EMPTY_TEXT, Text(IDS_SIZING_DROP_MODEL));
#endif
    targetBox_ = static_cast<LinkBoxGui*>(AddCustomGui(TargetName, CUSTOMGUI_LINKBOX, String(), BFH_SCALEFIT, SizePix(260), 0, linkSettings));
    AddButton(TargetPick, BFH_RIGHT, 0, 0, Text(IDS_SIZING_PICK));
    AddStaticText(122, BFH_LEFT, 0, 0, Text(IDS_SIZING_MOTION_SLOT), 0);
    AddComboBox(MotionSlot, BFH_SCALEFIT, SizePix(260), 0);
    AddStaticText(123, BFH_LEFT, 0, 0, String(), 0);
    AddComboBox(Queue, BFH_SCALEFIT, SizePix(160), 0);
    AddButton(QueueAdd, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_QUEUE_ADD));
    AddButton(QueueRemove, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_QUEUE_REMOVE));
    GroupEnd();
    AddStaticText(113, BFH_LEFT, 0, 0, Text(IDS_SIZING_QUEUE_HINT), 0);
    GroupBegin(106, BFH_SCALEFIT, 4, 0, String(), 0);
    AddStaticText(107, BFH_LEFT, 0, 0, Text(IDS_SIZING_MOVEMENT), 0); AddEditNumberArrows(Movement, BFH_SCALEFIT);
    AddStaticText(108, BFH_LEFT, 0, 0, Text(IDS_SIZING_LEG_OFFSET), 0); AddEditNumberArrows(LegOffset, BFH_SCALEFIT);
    AddCheckbox(CenterOffsets, BFH_LEFT, 0, 0, Text(IDS_SIZING_CENTER));
    AddCheckbox(LegOffsets, BFH_LEFT, 0, 0, Text(IDS_SIZING_LEG));
    AddCheckbox(Stance, BFH_LEFT, 0, 0, Text(IDS_SIZING_STANCE));
    AddCheckbox(Twist, BFH_LEFT, 0, 0, Text(IDS_SIZING_TWIST));
    AddCheckbox(Avoidance, BFH_LEFT, 0, 0, Text(IDS_SIZING_AVOIDANCE));
    AddCheckbox(Wrist, BFH_LEFT, 0, 0, Text(IDS_SIZING_WRIST));
    AddCheckbox(Finger, BFH_LEFT, 0, 0, Text(IDS_SIZING_FINGER));
    AddCheckbox(FloorContact, BFH_LEFT, 0, 0, Text(IDS_SIZING_FLOOR));
    AddCheckbox(LegAvoidance, BFH_LEFT, 0, 0, Text(IDS_SIZING_LEG_AVOIDANCE));
    AddStaticText(124, BFH_LEFT, 0, 0, String(), 0);
    AddStaticText(125, BFH_LEFT, 0, 0, String(), 0);
    AddStaticText(126, BFH_LEFT, 0, 0, String(), 0);
    AddStaticText(114, BFH_LEFT, 0, 0, Text(IDS_SIZING_DISTANCE), 0); AddEditNumberArrows(Distance, BFH_SCALEFIT);
    AddStaticText(115, BFH_LEFT, 0, 0, Text(IDS_SIZING_MARGIN), 0); AddEditNumberArrows(Margin, BFH_SCALEFIT);
    AddStaticText(116, BFH_LEFT, 0, 0, Text(IDS_SIZING_FLOOR_HEIGHT), 0); AddEditNumberArrows(FloorHeight, BFH_SCALEFIT);
    AddCheckbox(Multi, BFH_LEFT, 0, 0, Text(IDS_SIZING_MULTI));
    AddStaticText(117, BFH_LEFT, 0, 0, Text(IDS_SIZING_UNITS), 0);
    GroupEnd();
    GroupBegin(118, BFH_SCALEFIT, 3, 0, String(), 0);
    AddCheckbox(CameraEnabled, BFH_LEFT, 0, 0, Text(IDS_SIZING_CAMERA));
    AddEditText(CameraPath, BFH_SCALEFIT, SizePix(340), 0);
    AddButton(CameraBrowse, BFH_RIGHT, 0, 0, Text(IDS_SIZING_BROWSE));
    AddStaticText(119, BFH_LEFT, 0, 0, Text(IDS_SIZING_CAMERA_LIMIT), 0);
    AddEditNumberArrows(CameraLimit, BFH_SCALEFIT);
    AddStaticText(120, BFH_LEFT, 0, 0, String(), 0);
    GroupEnd();
    GroupBegin(109, BFH_SCALEFIT, 2, 0, String(), 0);
    AddButton(Calculate, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_CALCULATE));
    AddButton(Cancel, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_CANCEL));
    GroupEnd();
    AddCheckbox(LivePreview, BFH_LEFT, 0, 0, Text(IDS_SIZING_LIVE_PREVIEW));
    AddMultiLineEditText(Report, BFH_SCALEFIT, SizePix(620), SizePix(100), DR_MULTILINE_READONLY | DR_MULTILINE_WORDWRAP);
    GroupBegin(110, BFH_SCALEFIT, 2, 0, String(), 0);
    AddComboBox(Stage, BFH_SCALEFIT);
    for (Int32 i = 0; i < static_cast<Int32>(libmmd::sizing::Stage::Count); ++i)
        AddChild(Stage, i, Text(IDS_SIZING_STAGE_ORIGINAL + i));
    AddCheckbox(Overlay, BFH_LEFT, 0, 0, Text(IDS_SIZING_OVERLAY));
    AddButton(Preview, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_PREVIEW));
    AddButton(ClosePreview, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_CLOSE_PREVIEW));
    AddButton(Apply, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_APPLY));
    AddButton(Export, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_EXPORT));
    AddButton(CameraApply, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_CAMERA_APPLY));
    AddButton(CameraExport, BFH_SCALEFIT, 0, 0, Text(IDS_SIZING_CAMERA_EXPORT));
    GroupEnd();
    AddStaticText(111, BFH_LEFT, 0, 0, Text(IDS_SIZING_PREVIEW_HINT), 0);
    AddStaticText(112, BFH_LEFT, 0, 0, Text(IDS_SIZING_BOUNDARY), 0);
    GroupEnd();
    GroupEnd();
    return true;
}

Bool MotionSizingDialog::InitValues()
{
    inputsDirty_ = true;
    SetFloat(Movement, 1., 0., 1000., .01);
    SetFloat(LegOffset, 0., -10000., 10000., .01);
    SetFloat(Distance, .3, 0., 10000., .01);
    SetFloat(Margin, .05, 0., 10000., .01);
    SetFloat(FloorHeight, 0., -10000., 10000., .01);
    SetFloat(CameraLimit, 5., 1., 100., .1);
    for (Int32 id : {CenterOffsets, LegOffsets, Stance, Twist}) SetBool(id, true);
    for (Int32 id : {Avoidance, LegAvoidance, Wrist, Finger, FloorContact, Multi, CameraEnabled, Overlay}) SetBool(id, false);
    SetInt32(Stage, 7);
    SetBool(LivePreview, true);
    pendingCalculation_ = false;
    RefreshQueue();
    RefreshMotionSlots();
    if (targetBox_) targetBox_->SetLink(target_->GetLink(nullptr, Obase));
    SetTimer(100);
    SyncFromMcp(true);
    Refresh();
    return true;
}

cmt::sizing::HostSession& MotionSizingDialog::ActiveSession()
{
    // Both dispatcher and dialog run on the main thread. The registry owns
    // this session throughout the call; the dialog keeps only a weak link.
    if (auto external = externalSession_.lock()) return *external;
    return session_;
}

void MotionSizingDialog::WriteOptions(const libmmd::sizing::Options& options)
{
    retainedOptions_ = options;
    SetFloat(Movement, options.movementMultiplier);
    SetFloat(LegOffset, options.legOffset);
    SetBool(CenterOffsets, options.centerOffsets); SetBool(LegOffsets, options.legOffsets);
    SetBool(Stance, options.stance); SetBool(Twist, options.twist);
    SetBool(Avoidance, options.avoidance); SetBool(Wrist, options.wristContact);
    SetBool(Finger, options.fingerContact); SetBool(FloorContact, options.floorContact);
    SetBool(LegAvoidance, options.legAvoidance);
    SetBool(Multi, options.multiContact); SetFloat(Distance, options.contactDistance);
    SetFloat(Margin, options.collisionMargin); SetFloat(FloorHeight, options.floorHeight);
}

void MotionSizingDialog::LoadEntry(size_t index)
{
    if (index >= entries_.size()) return;
    const auto& entry = *entries_[index];
    auto* object = entry.target->GetLink(nullptr, Obase);
    target_->SetLink(object);
    if (targetBox_) targetBox_->SetLink(object);
    SetString(SourcePath, entry.source.GetString());
    SetString(MotionPath, entry.motion.GetString());
    RefreshMotionSlots(entry.motionSlotIdentity);
    WriteOptions(entry.options);
}

void MotionSizingDialog::SyncFromMcp(bool force)
{
    UInt64 revision = 0;
    const auto state = cmt::sizing::GetPanelState(revision);
    if (!force && panelRevision_ == revision) return;
    panelRevision_ = revision;
    if (!state || state->session.expired())
    {
        if (externalJob_)
        {
            externalSession_.reset(); externalJob_ = false;
            pendingCalculation_ = false; automaticJob_ = false; inputsDirty_ = true;
            Refresh();
        }
        return;
    }
    // Programmatic field changes do not enqueue a live recalculation. A new
    // MCP request replaces the displayed job only when explicitly published.
    session_.Cancel();
    externalSession_ = state->session;
    externalJob_ = true;
    inputsDirty_ = false; pendingCalculation_ = false; automaticJob_ = false;
    SetBool(LivePreview, false);
    entries_.clear();
    for (const auto& input : state->inputs)
    {
        auto entry = std::make_unique<Entry>();
        auto* object = input->target->GetLink(nullptr, Obase);
        entry->target->SetLink(object);
        entry->name = object ? object->GetName() : String();
        entry->source = input->source; entry->motion = input->motion;
        entry->motionSlotIdentity = input->motionSlotIdentity;
        entry->options = input->options;
        entries_.push_back(std::move(entry));
    }
    RefreshQueue();
    SetInt32(Queue, static_cast<Int32>(state->member));
    LoadEntry(state->member);
    SetString(CameraPath, state->camera.GetString());
    SetBool(CameraEnabled, state->cameraOptions.enabled);
    SetFloat(CameraLimit, state->cameraOptions.maxDistanceRatio);
    SetInt32(Stage, static_cast<Int32>(state->stage));
    SetBool(Overlay, state->overlay);
    Refresh();
}

void MotionSizingDialog::RefreshQueue()
{
    FreeChildren(Queue);
    if (!entries_.empty()) AddChild(Queue, -1, Text(IDS_SIZING_QUEUE_DRAFT));
    if (entries_.empty()) AddChild(Queue, 0, Text(IDS_SIZING_SINGLE));
    for (size_t i = 0; i < entries_.size(); ++i)
        AddChild(Queue, static_cast<Int32>(i), String::IntToString(static_cast<Int32>(i + 1)) + String(" · ") + entries_[i]->name);
    SetInt32(Queue, entries_.empty() ? 0 : static_cast<Int32>(entries_.size() - 1));
}

void MotionSizingDialog::SelectQueueEntry(Int32 member)
{
    SetInt32(Queue, member);
    if (member >= 0 && static_cast<size_t>(member) < entries_.size())
        LoadEntry(static_cast<size_t>(member));
}

bool MotionSizingDialog::HasPendingQueueInput() const
{
    Int32 member = -1; GetInt32(Queue, member);
    return !entries_.empty() && (member < 0 || static_cast<size_t>(member) >= entries_.size() ||
        entries_[static_cast<size_t>(member)]->target->GetLink(nullptr, Obase) != target_->GetLink(nullptr, Obase));
}

libmmd::sizing::Options MotionSizingDialog::ReadOptions() const
{
    libmmd::sizing::Options options = retainedOptions_;
    const auto number = [&](Int32 id) { Float value = 0.; GetFloat(id, value); return value; };
    const auto flag = [&](Int32 id) { Bool value = false; GetBool(id, value); return value != false; };
    options.movementMultiplier = number(Movement); options.legOffset = number(LegOffset);
    options.centerOffsets = flag(CenterOffsets); options.legOffsets = flag(LegOffsets);
    options.stance = flag(Stance); options.twist = flag(Twist); options.avoidance = flag(Avoidance);
    options.legAvoidance = flag(LegAvoidance);
    options.wristContact = flag(Wrist); options.fingerContact = flag(Finger); options.floorContact = flag(FloorContact);
    options.multiContact = flag(Multi); options.contactDistance = number(Distance);
    options.collisionMargin = number(Margin); options.floorHeight = number(FloorHeight);
    return options;
}

void MotionSizingDialog::Refresh()
{
    const bool running = ActiveSession().IsRunning();
    lastRunning_ = running;
    Int32 member = 0; GetInt32(Queue, member);
    if (!running) ActiveSession().SelectCharacter(static_cast<size_t>(member));
    for (Int32 id : Editable) Enable(id, !running);
    Enable(Calculate, !running && !HasPendingQueueInput());
    Enable(QueueRemove, !running && member >= 0 && static_cast<size_t>(member) < entries_.size());
    // Solver options stay editable while a job runs; a newer change cancels
    // that job and is debounced into one replacement request.
    for (Int32 id : {Movement, LegOffset, CenterOffsets, LegOffsets, Stance, Twist, Avoidance,
                     LegAvoidance, Wrist, Finger, FloorContact, Multi, Distance, Margin, FloorHeight}) Enable(id, true);
    const bool fileMotion = SelectedMotionSlot() == 0;
    Enable(MotionPath, !running && fileMotion); Enable(MotionBrowse, !running && fileMotion);
    Enable(Queue, !running);
    Enable(Cancel, running);
    const bool ready = !running && !inputsDirty_ && !HasPendingQueueInput() && ActiveSession().GetResult().success;
    for (Int32 id : {Stage, Overlay, Preview, Apply, Export}) Enable(id, ready);
    for (Int32 id : {CameraApply, CameraExport}) Enable(id, ready && ActiveSession().HasCamera());
    Enable(ClosePreview, ActiveSession().GetPreviewDocument() != nullptr);
    SetString(Report, HasPendingQueueInput() ? Text(IDS_SIZING_QUEUE_DRAFT) :
        !running && inputsDirty_ && ActiveSession().GetResult().success ? Text(IDS_SIZING_DIRTY) : ActiveSession().Summary());
}

Bool MotionSizingDialog::Command(Int32 id, const BaseContainer&)
{
    try
    {
        Int32 stage = 7, member = 0;
        Bool overlay = false;
        GetInt32(Stage, stage); GetInt32(Queue, member); GetBool(Overlay, overlay);
        if (!ActiveSession().IsRunning() && !inputsDirty_)
            ActiveSession().SelectCharacter(static_cast<size_t>(member));
        bool success = true;
        if (id == SourceBrowse || id == MotionBrowse || id == CameraBrowse)
        {
            Filename path;
            if (filename_util::SelectSuffixImportFile(path, id == SourceBrowse ? "pmx"_s : "vmd"_s))
            {
                SetString(id == SourceBrowse ? SourcePath : id == MotionBrowse ? MotionPath : CameraPath, path.GetString());
                MarkDirty();
            }
        }
        else if (id == TargetPick || id == TargetName)
        {
            BaseDocument* doc = GetActiveDocument();
            auto* object = id == TargetPick ? (doc ? doc->GetActiveObject() : nullptr) :
                static_cast<BaseObject*>(targetBox_ ? targetBox_->GetLink(nullptr, Obase) : nullptr);
            if (object && (!object->IsInstanceOf(g_mmd_model_manager_object_id) || object->GetDocument() == ActiveSession().GetPreviewDocument()))
            {
                if (targetBox_) targetBox_->SetLink(target_->GetLink(nullptr, Obase));
                SetString(Report, Text(IDS_SIZING_PICK_HINT)); return true;
            }
            target_->SetLink(object);
            if (targetBox_) targetBox_->SetLink(object);
            // Choosing another model edits a draft, not the selected member.
            // An existing queued model restores its own paths and options.
            Int32 queued = -1;
            for (size_t i = 0; i < entries_.size(); ++i)
                if (entries_[i]->target->GetLink(nullptr, Obase) == object)
                    queued = static_cast<Int32>(i);
            RefreshMotionSlots();
            if (!entries_.empty()) SelectQueueEntry(queued);
            MarkDirty(false);
        }
        else if (id == QueueAdd)
        {
            auto* target = static_cast<BaseObject*>(target_->GetLink(nullptr, Obase));
            if (!target) { SetString(Report, Text(IDS_SIZING_PICK_HINT)); return true; }
            String source, motion; GetString(SourcePath, source); GetString(MotionPath, motion);
            Entry* entry = nullptr;
            for (const auto& existing : entries_)
                if (existing->target->GetLink(nullptr, Obase) == target) entry = existing.get();
            if (!entry)
            {
                if (entries_.size() >= 16) { SetString(Report, Text(IDS_SIZING_ERR_BATCH)); return true; }
                entries_.push_back(std::make_unique<Entry>()); entry = entries_.back().get();
            }
            entry->target->SetLink(target); entry->source = Filename(source); entry->motion = Filename(motion); entry->name = target->GetName();
            entry->motionSlotIdentity = SelectedMotionSlot();
            entry->options = ReadOptions();
            const auto selected = static_cast<Int32>(std::distance(entries_.begin(),
                std::find_if(entries_.begin(), entries_.end(), [entry](const auto& item) { return item.get() == entry; })));
            RefreshQueue(); SelectQueueEntry(selected); MarkDirty(false);
        }
        else if (id == QueueRemove)
        {
            if (member < 0 || static_cast<size_t>(member) >= entries_.size()) return true;
            entries_.erase(entries_.begin() + member);
            RefreshQueue();
            if (!entries_.empty())
            {
                SelectQueueEntry(std::min(member, static_cast<Int32>(entries_.size() - 1)));
                MarkDirty(false);
            }
            else
            {
                target_->SetLink(nullptr);
                if (targetBox_) targetBox_->SetLink(nullptr);
                SetString(SourcePath, String()); SetString(MotionPath, String());
                RefreshMotionSlots();
                MarkDirty(false);
                pendingCalculation_ = false;
            }
        }
        else if (id == Queue)
        {
            if (!inputsDirty_) ActiveSession().SelectCharacter(static_cast<size_t>(member));
            SelectQueueEntry(member);
        }
        else if (id == Calculate) success = StartCalculation();
        else if (id == Cancel)
        {
            pendingCalculation_ = false; automaticJob_ = false; ActiveSession().Cancel();
        }
        else if (id == LivePreview)
        {
            Bool live = false; GetBool(LivePreview, live);
            if (live) MarkDirty();
            else { pendingCalculation_ = false; automaticJob_ = false; }
        }
        else if (id == ClosePreview)
        { SetBool(LivePreview, false); pendingCalculation_ = false; automaticJob_ = false; ActiveSession().ClosePreview(); }
        else if (id == Preview || ((id == Stage || id == Overlay) && ActiveSession().GetPreviewDocument()))
            success = ActiveSession().Preview(static_cast<size_t>(stage), overlay);
        else if (id == Apply) success = ActiveSession().Apply(static_cast<size_t>(stage));
        else if (id == CameraApply) success = ActiveSession().ApplyCamera();
        else if (id == Export || id == CameraExport)
        {
            Filename output;
            if (filename_util::SelectSuffixExportFile(output, "vmd"_s))
                success = id == CameraExport ? ActiveSession().ExportCamera(output) : ActiveSession().Export(static_cast<size_t>(stage), output);
        }
        else for (Int32 editable : Editable) if (id == editable) MarkDirty();
        Refresh();
        if (!success) SetString(Report, ActiveSession().GetError());
    }
    catch (const std::exception& error) { SetString(Report, Text(IDS_SIZING_ERR_SOLVE) + String("\n") + String(error.what())); }
    return true;
}

void MotionSizingDialog::RefreshMotionSlots(UInt64 selected)
{
    FreeChildren(MotionSlot);
    motionSlots_.clear();
    AddChild(MotionSlot, 0, Text(IDS_SIZING_FILE_MOTION));
    Int32 selection = 0;
    auto* object = static_cast<BaseObject*>(target_->GetLink(nullptr, Obase));
    auto* model = object ? object->GetNodeData<MMDModelManagerObject>() : nullptr;
    if (model)
    {
        const auto& slots = model->GetAutomationAnimationSlots();
        for (const auto& slot : slots)
        {
            motionSlots_.push_back(slot.runtime_identity);
            const Int32 index = static_cast<Int32>(motionSlots_.size());
            AddChild(MotionSlot, index, String::IntToString(index) + String(" : ") + slot.name);
            if (slot.runtime_identity == selected) selection = index;
        }
    }
    SetInt32(MotionSlot, selection);
}

UInt64 MotionSizingDialog::SelectedMotionSlot() const
{
    Int32 index = 0; GetInt32(MotionSlot, index);
    return index > 0 && static_cast<size_t>(index) <= motionSlots_.size() ? motionSlots_[index - 1] : 0;
}

void MotionSizingDialog::MarkDirty(bool updateEntry)
{
    // A UI edit starts a separate calculation. Never overwrite or implicitly
    // cancel the immutable job referenced by an MCP handle.
    if (externalJob_)
        if (auto* preview = ActiveSession().GetPreviewDocument())
        { previewTime_ = preview->GetTime(); preservePreviewTime_ = true; }
    externalSession_.reset();
    externalJob_ = false;
    if (updateEntry && !HasPendingQueueInput())
    {
        Int32 member = 0; GetInt32(Queue, member);
        if (member >= 0 && static_cast<size_t>(member) < entries_.size())
        {
            auto& entry = *entries_[static_cast<size_t>(member)];
            String source, motion; GetString(SourcePath, source); GetString(MotionPath, motion);
            entry.source = Filename(source); entry.motion = Filename(motion);
            entry.target->SetLink(target_->GetLink(nullptr, Obase));
            entry.motionSlotIdentity = SelectedMotionSlot();
            entry.options = ReadOptions();
        }
    }
    inputsDirty_ = true;
    Bool live = false; GetBool(LivePreview, live);
    pendingCalculation_ = live && !HasPendingQueueInput();
    changedAt_ = std::chrono::steady_clock::now();
    if (pendingCalculation_ && ActiveSession().IsRunning()) ActiveSession().Cancel();
}

bool MotionSizingDialog::StartCalculation()
{
    if (HasPendingQueueInput()) return false;
    externalSession_.reset();
    externalJob_ = false;
    pendingCalculation_ = false;
    const auto options = ReadOptions();
    std::vector<cmt::sizing::HostInput> inputs;
    if (entries_.empty())
    {
        String source, motion; GetString(SourcePath, source); GetString(MotionPath, motion);
        inputs.push_back({static_cast<BaseObject*>(target_->GetLink(nullptr, Obase)), Filename(source),
                          Filename(motion), options, SelectedMotionSlot()});
    }
    else for (const auto& entry : entries_)
        inputs.push_back({static_cast<BaseObject*>(entry->target->GetLink(nullptr, Obase)), entry->source,
                          entry->motion, entry->options, entry->motionSlotIdentity});
    Bool enabled = false, live = false; Float limit = 5.; String path;
    GetBool(CameraEnabled, enabled); GetFloat(CameraLimit, limit); GetString(CameraPath, path);
    GetBool(LivePreview, live);
    if (auto* preview = ActiveSession().GetPreviewDocument()) previewTime_ = preview->GetTime();
    else if (!preservePreviewTime_ && !inputs.empty() && inputs.front().target && inputs.front().target->GetDocument())
        previewTime_ = inputs.front().target->GetDocument()->GetTime();
    preservePreviewTime_ = false;
    automaticJob_ = live;
    const bool success = ActiveSession().StartBatch(inputs, Filename(path), {enabled != false, limit});
    inputsDirty_ = !success;
    return success;
}

void MotionSizingDialog::Timer(const BaseContainer&)
{
    SyncFromMcp();
    if (externalJob_) session_.Poll(); // Reap a cancelled previous UI worker.
    if (ActiveSession().Poll() || lastRunning_ != ActiveSession().IsRunning())
    {
        Int32 member = 0; GetInt32(Queue, member);
        ActiveSession().SelectCharacter(static_cast<size_t>(member));
        if (automaticJob_ && !pendingCalculation_ && ActiveSession().GetResult().success)
        {
            Int32 stage = 7; Bool overlay = false;
            GetInt32(Stage, stage); GetBool(Overlay, overlay);
            if (ActiveSession().Preview(static_cast<size_t>(stage), overlay))
            {
                auto* preview = ActiveSession().GetPreviewDocument();
                preview->SetTime(previewTime_);
                preview->ExecutePasses(nullptr, true, true, true, BUILDFLAGS::NONE);
                EventAdd();
            }
        }
        Refresh();
    }
    if (pendingCalculation_ && !ActiveSession().IsRunning() &&
        std::chrono::steady_clock::now() - changedAt_ >= std::chrono::milliseconds(350))
    {
        StartCalculation();
        Refresh();
        if (!ActiveSession().GetError().IsEmpty()) SetString(Report, ActiveSession().GetError());
    }
}

Bool MotionSizingDialog::AskClose()
{
    pendingCalculation_ = false; automaticJob_ = false;
    // The panel observes MCP jobs; only an explicit Cancel/Close Preview
    // command is allowed to affect them.
    if (!externalJob_) { session_.Cancel(); session_.ClosePreview(); }
    return false;
}
