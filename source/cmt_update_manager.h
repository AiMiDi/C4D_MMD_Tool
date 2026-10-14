#pragma once

#include <c4d.h>
#include "module/core/cmt_marco.h"
#include "utils/cmt_update_policy.hpp"
#include "utils/cmt_release_json.hpp"
#include <atomic>
#include <mutex>
#include <thread>

class CMTUpdateManager final
{
public:
	enum class Status { Idle, Checking, Ready, Failed };
	static CMTUpdateManager& GetInstance();
	// All public operations, preferences and UI reads belong to the main thread.
	void Init();
	void Shutdown();
	void Poll();
	void Check(bool manual);
	void SetAutomatic(bool enabled);
	void IgnoreVersion(const std::string& version);
	void OnToolUse();
	bool TakeNotification();
	bool Automatic() const { return automatic_; }
	bool Remind() const;
	Status GetStatus() const { return status_; }
	const std::string& Installed() const { return installed_; }
	const std::string& Latest() const { return latest_; }
	const std::string& Notes() const { return notes_; }
	bool OpenReleasePage() const;

private:
	CMTUpdateManager() = default;
	~CMTUpdateManager() { Shutdown(); }
	CMTUpdateManager(const CMTUpdateManager&) = delete;
	CMTUpdateManager& operator=(const CMTUpdateManager&) = delete;
	void SavePreferences() const;
	void RunCheck();

	std::string installed_, latest_, ignored_, notes_, notified_;
	std::int64_t lastAttempt_ = 0;
	bool automatic_ = true, manual_ = false;
	bool notificationRequested_ = false;
	Status status_ = Status::Idle;
	std::thread worker_;
	std::atomic<bool> cancel_{false};
	std::mutex resultMutex_;
	bool resultReady_ = false;
	std::optional<cmt_update::Release> result_;
};
