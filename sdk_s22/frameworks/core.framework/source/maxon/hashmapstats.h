#ifndef HASHMAPSTATS_H__
#define HASHMAPSTATS_H__

#include "maxon/hashmap.h"
#include "maxon/string.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

class HashMapStatistics
{
public:
	template <typename HASHMAP> static String ToString(const HASHMAP& map, const FormatStatement* formatStatement)
	{
		iferr_scope_handler
		{
			return String();
		};

		BaseArray<Int> bucketSizeFrequency;
		HashMap<UInt, Int> hashCodeCounts;
		String result;

		if (bucketSizeFrequency.Resize(1) == FAILED)
			return String();

		Int elementCount = 0;
		for (Int i = 0; i < map.GetNonEmptyBucketCount(); ++i)
		{
			Int bs = 0;
			for (auto e = map.GetNonEmptyBucket(i); e; e = e->GetNextInBucket())
			{
				Bool created = false;
				Int& c = hashCodeCounts.InsertKey(e->GetHashCode(), created) iferr_return;
				if (created)
				{
					c = 1;
				}
				else
				{
					++c;
				}
				elementCount++;
				++bs;
			}
			if ((bucketSizeFrequency.GetCount() <= bs) && (bucketSizeFrequency.Resize(bs + 1) == FAILED))
			{
				return String();
			}
			++bucketSizeFrequency[bs];
		}
		result.AppendInt(map.GetCount());
		DebugAssert(map.GetCount() == elementCount);

		result.Append(" entries, "_s) iferr_return;
		result.AppendInt(map.GetNonEmptyBucketCount());
		result.Append(" non-empty buckets out of "_s) iferr_return;
		result.AppendInt(map.GetTableSize());
		result.Append("\nBucket size distribution:\n"_s) iferr_return;

		bucketSizeFrequency[0] = map.GetTableSize() - map.GetNonEmptyBucketCount();
		for (Int i = 0; i < bucketSizeFrequency.GetCount(); ++i)
		{
			result.Append("  "_s) iferr_return;
			result.AppendInt(i);
			result.Append(" : "_s) iferr_return;
			result.AppendInt(bucketSizeFrequency[i]);
			result.Append(" times\n"_s) iferr_return;
		}
		BaseArray<Int> hashCodeCountFrequency;
		for (auto& i: hashCodeCounts)
		{
			if ((hashCodeCountFrequency.GetCount() <= i.GetValue()) && (hashCodeCountFrequency.Resize(i.GetValue() + 1) == FAILED))
			{
				return String();
			}
			++hashCodeCountFrequency[i.GetValue()];
		}
		result.Append("Hash code collisions:\n"_s) iferr_return;
		for (Int i = 1; i < hashCodeCountFrequency.GetCount(); ++i)
		{
			result.Append("  "_s) iferr_return;
			result.AppendInt(i);
			result.Append(" occurrence(s) : "_s) iferr_return;
			result.AppendInt(hashCodeCountFrequency[i]);
			result.Append(" times\n"_s) iferr_return;
		}
		return result;
	}

	template <typename HASHMAP> static void Print(const HASHMAP& map)
	{
		DiagnosticOutput(ToString(map, nullptr));
	}
};

/// @}

} // namespace maxon

#endif // HASHMAPSTATS_H__
