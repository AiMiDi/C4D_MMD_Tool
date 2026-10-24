#pragma once
#include "cmt_runtime_profile.hpp"
#if CMT_ENABLE_RUNTIME_PROFILING
#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
#include <utility>

namespace cmt_runtime
{
struct ProfileContext
{
	std::uint64_t document = 0;
	std::uint64_t marker = 0;
	double seconds = 0.0;
	std::int64_t frame = 0;
	std::int32_t fps = 0;
	bool operator==(const ProfileContext& other) const
	{
		return document == other.document && marker == other.marker && seconds == other.seconds
			&& frame == other.frame && fps == other.fps;
	}
};

// A frame can produce multiple batches: sum counts/self times, take max(max_ms).
// Inclusive times of nested scopes must never be added as a frame total.
inline std::string FormatProfileBatch(const ProfileContext& context, const FrameMetrics& metrics,
	const std::uint64_t session, const std::uint64_t thread, const std::uint64_t batch)
{
	std::ostringstream out;
	out.imbue(std::locale::classic());
	out << std::setprecision(17) << "{\"schema\":1,\"session\":\"" << session << "\",\"thread\":\"" << thread
		<< "\",\"batch\":" << batch << ",\"document\":\"" << context.document
		<< "\",\"marker\":\"" << context.marker << "\",\"frame\":" << context.frame
		<< ",\"fps\":" << context.fps << ",\"time_seconds\":" << context.seconds
		<< ",\"root_calls\":" << metrics.root_calls << ",\"root_ms\":" << metrics.root_milliseconds << ",\"stages\":[";
	bool first = true;
	for (std::size_t i = 0; i < metrics.calls.size(); ++i)
	{
		if (!metrics.calls[i]) continue;
		if (!first) out << ',';
		first = false;
		out << "{\"name\":\"" << RuntimeStageName(static_cast<RuntimeStage>(i))
			<< "\",\"calls\":" << metrics.calls[i] << ",\"inclusive_ms\":" << metrics.milliseconds[i]
			<< ",\"self_ms\":" << metrics.self_milliseconds[i] << ",\"max_ms\":" << metrics.maximum_milliseconds[i] << '}';
	}
	out << "]}";
	return out.str();
}

template <class Sink>
class ProfileBatchCollector
{
public:
	explicit ProfileBatchCollector(Sink sink) : sink_(std::move(sink)) {}
	void Add(const ProfileContext& context, const FrameMetrics& metrics)
	{
		if (!metrics.root_calls) return;
		if (pending_ && !(context_ == context)) Flush();
		context_ = context;
		metrics_.Merge(metrics);
		pending_ = true;
	}
	void Flush()
	{
		if (!pending_) return;
		pending_ = false;
		const FrameMetrics completed = metrics_;
		metrics_ = FrameMetrics(true);
		sink_(context_, completed);
	}
private:
	Sink sink_;
	ProfileContext context_;
	FrameMetrics metrics_{true};
	bool pending_ = false;
};
} // namespace cmt_runtime
#endif
