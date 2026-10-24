#include "cmt_update_manager.h"
#include "plugin_resource.h"
#include "utils/cmt_release_json.hpp"
#include "maxon/datadictionary.h"
#include "maxon/iostreams.h"
#include "maxon/url.h"
#if CMT_SDK_HAS_NETWORK_URL_HEADER
#include "maxon/network_url.h"
#endif
#include <chrono>
#include <ctime>

namespace
{
// Keep these outside dialog/config parameter IDs; merge into the existing
// command preference container so other command-owned data remains intact.
enum : Int32 { PrefAutomatic = 2000000, PrefIgnored, PrefLastAttempt, PrefLatest, PrefNotes };

std::string Utf8(const String& text)
{
	maxon::AutoMem<Char> bytes(text.GetCStringCopy(STRINGENCODING::UTF8));
	return bytes ? std::string(static_cast<const Char*>(bytes)) : std::string();
}

std::string InstalledVersion()
{
	AutoAlloc<BaseFile> file;
	if (!file || !file->Open(GeGetPluginResourcePath() + Filename("cmt_version.txt"),
		FILEOPEN::READ, FILEDIALOG::NONE, BYTEORDER::V_INTEL)) return {};
	const Int64 length = file->GetLength();
	if (length <= 0 || length > 64) return {};
	std::string text(static_cast<std::size_t>(length), '\0');
	if (file->ReadBytes(text.data(), length) != length) return {};
	while (!text.empty() && (text.back() == '\r' || text.back() == '\n' || text.back() == ' ')) text.pop_back();
	return cmt_update::ParseVersion(text) ? text : std::string();
}

maxon::Result<std::string> FetchRelease(const std::atomic<bool>& cancel)
{
#if !CMT_SDK_HAS_NETWORK_URL_HEADER
	// R21–2023 的 SDK 树没有配置 network.framework，URLFLAGS 里的网络标志（超时、跳转、
	// 请求头）不可用，缺 User-Agent 的请求也会被 GitHub 拒绝。
	// 这些版本不做 HTTP 更新检查，直接返回空响应，由 ParseStableRelease 判为「无新版本」。
	(void)cancel;
	return std::string();
#else
	iferr_scope;
	maxon::Url url("https://api.github.com/repos/AiMiDi/C4D_MMD_Tool/releases/latest"_s);
	url.Set(maxon::URLFLAGS::NETWORK_CONNECTTIMEOUT, maxon::Seconds(5)) iferr_return;
	url.Set(maxon::URLFLAGS::NETWORK_SESSIONTIMEOUT, maxon::Seconds(5)) iferr_return;
	// TLS verification stays at the SDK default. Do not accept certificate bypasses.
	url.Set(maxon::URLFLAGS::HTTP_FOLLOWMOVEDFILES, false) iferr_return;
	maxon::DataDictionary headers;
	headers.Set("User-Agent"_s, "C4D-MMD-Tool-Update-Check"_s) iferr_return;
	headers.Set("Accept"_s, "application/vnd.github+json"_s) iferr_return;
	headers.Set("X-GitHub-Api-Version"_s, "2022-11-28"_s) iferr_return;
	url.Set(maxon::URLFLAGS::HTTP_ADDITIONAL_REQUEST_HEADER, headers) iferr_return;
	const auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(15);
	auto stream = url.OpenInputStream() iferr_return;
	// Close on success, cancellation and errors before releasing the reference.
	struct StreamCloser
	{
		maxon::InputStreamRef& stream;
		~StreamCloser() { iferr(stream.Close()) {} }
	} closer{stream};
	std::string body;
	maxon::Byte buffer[4096];
	while (!cancel.load() && std::chrono::steady_clock::now() < deadline)
	{
		const Int count = stream.ReadEOS(maxon::ToBlock(buffer)) iferr_return;
		if (count == 0) return body;
		if (body.size() + static_cast<std::size_t>(count) > 1024 * 1024) return std::string();
		body.append(reinterpret_cast<const char*>(buffer), static_cast<std::size_t>(count));
	}
	return std::string();
#endif
}
}

CMTUpdateManager& CMTUpdateManager::GetInstance()
{
	static CMTUpdateManager instance;
	return instance;
}

void CMTUpdateManager::Init()
{
	installed_ = InstalledVersion();
	if (const auto* prefs = GetWorldPluginData(g_cmt_command_id))
	{
		automatic_ = prefs->GetBool(PrefAutomatic, true);
		ignored_ = Utf8(prefs->GetString(PrefIgnored));
		latest_ = Utf8(prefs->GetString(PrefLatest));
		notes_ = Utf8(prefs->GetString(PrefNotes));
		lastAttempt_ = prefs->GetInt64(PrefLastAttempt);
		if (!cmt_update::ParseVersion(latest_)) latest_.clear();
	}
	if (!latest_.empty()) status_ = Status::Ready;
	Check(false);
}

void CMTUpdateManager::Shutdown()
{
	cancel_.store(true);
	if (worker_.joinable()) worker_.join();
}

void CMTUpdateManager::SavePreferences() const
{
	BaseContainer prefs;
	prefs.SetBool(PrefAutomatic, automatic_);
	prefs.SetString(PrefIgnored, String(ignored_.c_str()));
	prefs.SetInt64(PrefLastAttempt, lastAttempt_);
	prefs.SetString(PrefLatest, String(latest_.c_str()));
	prefs.SetString(PrefNotes, String(notes_.c_str(), STRINGENCODING::UTF8));
	SetWorldPluginData(g_cmt_command_id, prefs, true);
}

void CMTUpdateManager::Check(bool manual)
{
#if !CMT_SDK_HAS_NETWORK_URL_HEADER
	// 旧版 SDK（R21–2023）无法发起带请求头的 HTTPS 检查，保持 Status::Idle 并且不启动网络线程，
	// 避免把「能力缺失」显示成检查失败。
	(void)manual;
	return;
#else
	Poll();
	if (status_ == Status::Checking) return;
	const auto now = static_cast<std::int64_t>(std::time(nullptr));
	if (!manual && !cmt_update::CheckDue(automatic_, lastAttempt_, now)) return;
	if (worker_.joinable()) worker_.join();
	cancel_.store(false);
	manual_ = manual;
	if (manual) notificationRequested_ = true;
	lastAttempt_ = now;
	SavePreferences();
	status_ = Status::Checking;
	try { worker_ = std::thread([this]() { RunCheck(); }); }
	catch (const std::exception&) { status_ = Status::Failed; }
#endif
}

void CMTUpdateManager::RunCheck()
{
	std::optional<cmt_update::Release> release;
	try
	{
		ifnoerr (const auto response = FetchRelease(cancel_))
			release = cmt_update::ParseStableRelease(response);
	}
	catch (const std::exception&) { /* A worker failure must never escape into the host. */ }
	std::lock_guard<std::mutex> lock(resultMutex_);
	result_ = std::move(release);
	resultReady_ = true;
}

void CMTUpdateManager::Poll()
{
	std::lock_guard<std::mutex> lock(resultMutex_);
	if (!resultReady_) return;
	resultReady_ = false;
	if (result_)
	{
		latest_ = std::move(result_->tag);
		notes_ = std::move(result_->notes);
		status_ = Status::Ready;
		SavePreferences();
	}
	else status_ = Status::Failed;
}

void CMTUpdateManager::SetAutomatic(bool enabled)
{
	automatic_ = enabled;
	manual_ = false;
	if (!enabled) notificationRequested_ = false;
	SavePreferences();
	if (enabled) Check(false);
}

void CMTUpdateManager::IgnoreVersion(const std::string& version)
{
	if (!cmt_update::IsNewer(installed_, version)) return;
	ignored_ = version;
	manual_ = false;
	SavePreferences();
}

bool CMTUpdateManager::Remind() const
{
	return cmt_update::ShouldRemind(installed_, latest_, ignored_, automatic_, manual_);
}

void CMTUpdateManager::OnToolUse()
{
	if (!GeIsMainThread()) return;
	Check(false);
	if (automatic_) notificationRequested_ = true;
}

bool CMTUpdateManager::TakeNotification()
{
	if (!notificationRequested_ || status_ == Status::Checking) return false;
	notificationRequested_ = false;
	if (!Remind() || (!manual_ && cmt_update::SameVersion(latest_, notified_))) return false;
	notified_ = latest_;
	manual_ = false;
	return true;
}

bool CMTUpdateManager::OpenReleasePage() const
{
	return GeOpenHTML(String(cmt_update::PageForVersion(latest_).c_str()));
}
