#pragma once
#include <c4d.h>
#include "module/tools/sizing/sizing_session.h"
#include "utils/images_user_area_util.hpp"
#include <customgui_linkbox.h>
#include <chrono>

class MotionSizingDialog final : public GeDialog
{
public:
    Bool CreateLayout() override;
    Bool InitValues() override;
    Bool Command(Int32 id, const BaseContainer& msg) override;
    void Timer(const BaseContainer& msg) override;
    Bool AskClose() override;
private:
    void Refresh();
    void RefreshQueue();
    void SelectQueueEntry(Int32 member);
    bool HasPendingQueueInput() const;
    void RefreshMotionSlots(UInt64 selected = 0);
    UInt64 SelectedMotionSlot() const;
    bool StartCalculation();
    void MarkDirty(bool updateEntry = true);
    void SyncFromMcp(bool force = false);
    void LoadEntry(size_t index);
    void WriteOptions(const libmmd::sizing::Options& options);
    cmt::sizing::HostSession& ActiveSession();
    libmmd::sizing::Options ReadOptions() const;
    struct Entry
    {
        AutoAlloc<BaseLink> target;
        Filename source;
        Filename motion;
        String name;
        UInt64 motionSlotIdentity = 0;
        libmmd::sizing::Options options;
    };
    std::vector<std::unique_ptr<Entry>> entries_;
    cmt::sizing::HostSession session_;
    std::weak_ptr<cmt::sizing::HostSession> externalSession_;
    libmmd::sizing::Options retainedOptions_; // Preserve MCP options without UI controls.
    UInt64 panelRevision_ = 0;
    bool externalJob_ = false;
    bool lastRunning_ = false;
    AutoAlloc<BaseLink> target_;
    bool inputsDirty_ = true;
    ImagesUserArea logo_{"mmd_tool_title.png"_s, 300, 95, true};
    LinkBoxGui* targetBox_ = nullptr; // Owned by the dialog.
    std::vector<UInt64> motionSlots_;
    bool pendingCalculation_ = false;
    bool automaticJob_ = false;
    BaseTime previewTime_;
    bool preservePreviewTime_ = false;
    std::chrono::steady_clock::time_point changedAt_;
};
