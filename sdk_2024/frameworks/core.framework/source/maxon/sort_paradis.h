#include "maxon/defaultallocator.h"
#include "maxon/errorbase.h"
#include "maxon/jobgroup.h"
#include "maxon/parallelfor.h"

namespace maxon
{
const Int32 MAXTHREADS = 128;
const Int32 MaxDataSize = LIMIT<Int32>::MAX;
const Int32 MaxDataNum = 2147483647;
const Int32 BYTEMAX = 256;

static const Int32 RADIXBITS = 8;
static const Int32 RADIXMASK = (1 << RADIXBITS) - 1;
static const Int32 RADIXBIN = 1 << RADIXBITS;

template <typename T, typename GETINT>
inline Int32 DetermineByteDigit(Int32 stage, T num, GETINT&& getInt)
{
	return ((getInt(num) >> (8 * stage)) & RADIXMASK);
}

template <typename T, typename GETINT>
inline Bool Compare(const T& x, const T& y, GETINT&& getInt)
{
	return getInt(x) < getInt(y);
}

template <typename T, typename GETINT>
inline void InsertSort(Block<T> data, Int32 start, Int32 end, GETINT&& getInt)
{
	for (Int32 i = start + 1; i < end; ++i)
	{
		if (Compare(data[i], data[i - 1], getInt))
		{
			auto tmp = data[i];
			data[i] = data[i - 1];
			Int32 j = i - 1;
			for (; j > start && Compare(tmp, data[j - 1], getInt); --j)
			{
				data[j] = data[j - 1];
			}
			data[j] = tmp;
		}
	}
}


struct alignas(MAXON_FALSE_SHARING_SIZE) PerThreadData
{
	Int32 _threadHistogram[BYTEMAX]; 
	Int32 _threadHead[BYTEMAX];
	Int32 _threadTail[BYTEMAX];
};

class HistogramJob : public JobInterfaceTemplate<HistogramJob>
{
public:
	explicit HistogramJob(Int32 (&histogram)[BYTEMAX], BaseArray<PerThreadData>& perThreadData, Int32 processID, Int32 processes) : _histogram(histogram), _perThreadData(perThreadData), _processID(processID), _processes(processes)  { }

	Result<void> operator ()()
	{
		for (Int32 j = 0; j < _processes; j++)
		{
			_histogram[_processID] += _perThreadData[j]._threadHistogram[_processID];
		}
		return OK;
	}

private:
	Int32 (&_histogram)[BYTEMAX];
	BaseArray<PerThreadData>& _perThreadData;
	Int32 _processID = 0;
	Int32 _processes = 0;
};

template <int kth_byte, typename T, typename GETINT>
class ParadisSortJob : public JobInterfaceTemplate<ParadisSortJob<kth_byte, T, GETINT>>
{
public:
	explicit ParadisSortJob(PerThreadData& perThreadData, Int32 (&globalHead)[BYTEMAX], Int32 (&globalTail)[BYTEMAX], Block<T> data, Int32 processID, Int32 processes, GETINT&& getInt) : _perThreadData(perThreadData), _globalHead(globalHead), _globalTail(globalTail), _data(data), _pID(processID), _processes(processes), _getInt(std::forward<decltype(getInt)>(getInt))  { }

	Result<void> operator ()()
	{
		for (Int32 i = 0; i < RADIXBIN; i++)
		{
			Int32 threadPart = (Int32)(_globalTail[i] - _globalHead[i]) / _processes;
			Int32 rest = (Int32)(_globalTail[i] - _globalHead[i]) % _processes;
			if (_pID < _processes - 1)
			{
				_perThreadData._threadHead[i] = threadPart * _pID + _globalHead[i];
				_perThreadData._threadTail[i] = threadPart * (_pID + 1) + _globalHead[i];
			}
			else
			{
				_perThreadData._threadHead[i] = threadPart * _pID + _globalHead[i];
				_perThreadData._threadTail[i] = threadPart * (_pID + 1) + _globalHead[i] + rest;
			}
		}


		for (Int32 i = 0; i < RADIXBIN; i++)
		{
			Int32 head = _perThreadData._threadHead[i];
			while (head < _perThreadData._threadTail[i])
			{
				auto value = _data[head];
				Int32 k = DetermineByteDigit(kth_byte, value, _getInt);
				while (k != i && _perThreadData._threadHead[k] < _perThreadData._threadTail[k])
				{
					Swap(value, _data[_perThreadData._threadHead[k]]);
					_perThreadData._threadHead[k]++;
					k = DetermineByteDigit(kth_byte, value, _getInt);
				}
				if (k == i)
				{
					_data[head] = _data[_perThreadData._threadHead[i]];
					head++;
					_data[_perThreadData._threadHead[i]] = value;
					_perThreadData._threadHead[i]++;
				}
				else
				{
					_data[head] = value;
					head++;
				}
			}
		}
		return OK;
	}

private:
	PerThreadData& _perThreadData;
	Int32 (&_globalHead)[BYTEMAX];
	Int32 (&_globalTail)[BYTEMAX];
	Block<T> _data;
	Int32 _pID = 0;
	Int32 _processes = 0;
	GETINT&& _getInt;
};

template <int kth_byte, typename T, typename GETINT>
class ParadisHealJob : public JobInterfaceTemplate<ParadisHealJob<kth_byte, T, GETINT>>
{
public:
	explicit ParadisHealJob(BaseArray<Int32>& pfp, BaseArray<PerThreadData>& perThreadData, Int32 (&globalHead)[BYTEMAX], Int32 (&globalTail)[BYTEMAX], Block<T> data, Int32 processID, Int32 processes, GETINT&& getInt) : _pfp(pfp), _perThreadData(perThreadData), _globalHead(globalHead), _globalTail(globalTail), _data(data), _pID(processID), _processes(processes), _getInt(std::forward<decltype(getInt)>(getInt)) { }

	Result<void> operator ()()
	{
		for (Int32 i = _pfp[_pID]; i < _pfp[_pID + 1]; i++)
		{
			Int32 tail = _globalTail[i];
			{
				for (Int32 pID = 0; pID < _processes; pID++)
				{
					Int32 head = _perThreadData[pID]._threadHead[i];
					while (head < _perThreadData[pID]._threadTail[i] && head < tail)
					{
						const auto v = _data[head];
						head++;
						if (DetermineByteDigit(kth_byte, v, _getInt) != i)
						{
							while (head <= tail)
							{
								tail--;
								const auto w = _data[tail];
								if (DetermineByteDigit(kth_byte, w, _getInt) == i)
								{
									_data[head - 1] = w;
									_data[tail] = v;
									break;
								}
							}
						}
					}
				}
			}
			_globalHead[i] = tail;
		}
		return OK;
	}

private:
	BaseArray<Int32>& _pfp;
	BaseArray<PerThreadData>& _perThreadData;
	Int32 (&_globalHead)[BYTEMAX];
	Int32 (&_globalTail)[BYTEMAX];
	Block<T> _data;
	Int32 _pID = 0;
	Int32 _processes = 0;
	GETINT&& _getInt;
};



template <int kth_byte, typename T, typename GETINT>
MAXON_ATTRIBUTE_NO_INLINE Result<void> ParadisByte(Int32 start, Int32 target, Block<T> data, GETINT&& getInt, JobQueueRef& jobQueue, Int32 processes = 1)
{
	iferr_scope;

	Int32 elenum = target - start;

	Int32 histogram[BYTEMAX] = {};
	Int32 globalHead[BYTEMAX];
	Int32 globalTail[BYTEMAX];
	Int32 starts[BYTEMAX];

	BaseArray<PerThreadData> perThreadData;
	perThreadData.Resize(processes) iferr_return;

	Int32 leftoverUnsorted = elenum;
	BaseArray<Int32> pfp;
	pfp.Resize(processes + 1) iferr_return;

	for (Int32 i = 0; i < RADIXBIN; ++i)
	{
		for (Int32 pro = 0; pro < processes; ++pro)
		{
			perThreadData[pro]._threadHistogram[i] = 0;
		}
	}

	ParallelFor::Dynamic<ParallelFor::BaseContext>(
		start, start + elenum, [&data, &perThreadData, &getInt](Int32 i, ParallelFor::BaseContext& ctx)
		{
			Int32 digit = DetermineByteDigit(kth_byte, data[i], getInt);
			perThreadData[ctx.GetLocalThreadIndex()]._threadHistogram[digit]++;
		}, ParallelFor::Granularity(maxon::PARALLELFOR_DEFAULTGRANULARITY, processes != 1), jobQueue, (Int)processes);

	StaticJobGroupRef<HistogramJob> jobGroup = StaticJobGroupRef<HistogramJob>::Create(RADIXBIN) iferr_return;
	StaticJobArray<HistogramJob> jobsHisto(jobGroup, STATICJOBARRAYFLAGS::INITIALIZE_LATER);

	Int32 processID = 0;
	for (HistogramJob& job : jobsHisto)
	{
		new (&job) HistogramJob(histogram, perThreadData, processID, processes);
		processID++;
	}

	jobGroup.Add(jobsHisto);
	jobGroup.EnqueueAndWait(jobQueue) iferr_return;

	globalHead[0] = start;
	globalTail[0] = globalHead[0] + histogram[0];
	starts[0] = globalHead[0];
	
	// create global tail and head
	for (Int32 i = 1; i < RADIXBIN; i++)
	{
		globalHead[i] = globalHead[i - 1] + histogram[i - 1];
		globalTail[i] = globalHead[i] + histogram[i];
		starts[i] = globalHead[i];
	}



	using SortJobType = ParadisSortJob<kth_byte, T, GETINT>;
	using HealJobType = ParadisHealJob<kth_byte, T, GETINT>;
	// sort thread distributed parts
	while (leftoverUnsorted != 0)
	{
		StaticJobGroupRef<SortJobType> jobGroup2 = StaticJobGroupRef<SortJobType>::Create(processes) iferr_return;
		StaticJobArray<SortJobType> jobsSort(jobGroup2, STATICJOBARRAYFLAGS::INITIALIZE_LATER);

		processID = 0;
		for (SortJobType& job : jobsSort)
		{
			new (&job) SortJobType(perThreadData[processID], globalHead, globalTail, data, processID, processes, std::forward<decltype(getInt)>(getInt));
			processID++;
		}
		
		jobGroup2.Add(jobsSort);
		jobGroup2.EnqueueAndWait(jobQueue) iferr_return;

		leftoverUnsorted = 0;
		Int32 pfpN = RADIXBIN / processes;
		Int32 pfpM = RADIXBIN % processes;
		pfp[0] = 0;
		Int32 pfpMR = 0;
		for (Int32 i = 1; i < processes + 1; i++)
		{
			if (pfpMR < pfpM)
				pfpMR++;
			pfp[i] = i * pfpN + pfpMR;
		}

		StaticJobGroupRef<HealJobType> jobGroup3 =  StaticJobGroupRef<HealJobType>::Create(processes) iferr_return;
	
		StaticJobArray<HealJobType> jobsHeal(jobGroup3, STATICJOBARRAYFLAGS::INITIALIZE_LATER);
		processID = 0;
		for (HealJobType& job : jobsHeal)
		{
			new (&job) HealJobType(pfp, perThreadData, globalHead, globalTail, data, processID, processes, std::forward<decltype(getInt)>(getInt));
			processID++;
		}

		jobGroup3.Add(jobsHeal);
		jobGroup3.EnqueueAndWait(jobQueue) iferr_return;

		for (Int32 i = 0; i < RADIXBIN; i++)
		{
			leftoverUnsorted += (globalTail[i] - globalHead[i]);
		}
	} // end of while

	if (kth_byte > 0)
	{
		JobGroupRef jobGroup4 = JobGroupRef::Create(JOBGROUPFLAGS::FINALIZE_ON_WAIT) iferr_return;
		jobGroup4.Enqueue(jobQueue);

		Bool enqueued = false;

		for (Int32 i = 0; i < RADIXBIN; i++)
		{
			Int32 nextStageThreads = (Int32)((Float)processes * ((Float)histogram[i] * (Ln((Float)histogram[i]) / Ln((Float)RADIXBIN)) / ((Float)elenum * (Ln((Float)elenum) / Ln((Float)RADIXBIN)))));
			if (histogram[i] > 64)
			{
				jobGroup4.Add([nextStageThreads, &starts, &histogram, &data, i, &getInt, &jobQueue]() -> Result<void>
					{
						iferr_scope;
						ParadisByte<(kth_byte > 0 ? (kth_byte - 1) : 0)>(starts[i], starts[i] + histogram[i], data, getInt, jobQueue, Max(nextStageThreads, 1)) iferr_return;
						return OK;
					}) iferr_return;

				enqueued = true;
			}
			else if (histogram[i] > 1)
			{
				InsertSort(data, starts[i], starts[i] + histogram[i], getInt);
			}
		}

		if (enqueued)
			jobGroup4.Wait();
	}

	return OK;
}


//----------------------------------------------------------------------------------------
/// Parallel inplace Radix implementation to sort lists based on integers
///
/// To use this templated class a block of the data to sort has to be passed together with a lambda or delegate that defines how to extract an integer type from the underlying element type.
///
/// Example usage:
/// class MyType
/// {
///		Int32 intType = 0;
/// }
/// BaseArray<MyType> myData
/// // fill myData with data
///	Block<MyType> myDataBlock {myData.GetFirst(), myData.GetCount()};
/// Paradis(myDataBlock, 16, [](const MyType& entry)-> const Int32&
/// {
///		return entry.intType;
/// });
///
/// 
/// It is recommended to only have positive values in the list, but it does support negative values. This will just require additional memory and is slower.
/// 
/// @param[in] data								The array of type T that should be sorted.
/// @param[in] threadNum					The amount of parallel threads to be used. Maximum is 16 for stack memory reasons.
/// @param[in] getInt							A lambda or delegate that returns an int type and has const T& as parameter signature. const Int&/Int32&(const& T)
/// @return												OK on success.
//----------------------------------------------------------------------------------------
template <typename T, typename GETINT>
inline Result<void> Paradis(const Block<T>& data, UInt32 threadNum, GETINT&& getInt)
{
	iferr_scope;

	if (data.GetCount() <= 1)
		return maxon::OK;

	if (data.GetCount() > (Int)MaxDataSize)
		return IllegalStateError(MAXON_SOURCE_LOCATION, "Paradis sort can sort a maximum of 2147483647 entries"_s);

	JobQueueRef jobQueue = JOBQUEUE_CURRENT;
	const size_t vsize = sizeof(decltype(std::declval<GETINT>()(std::declval<T>())));
	ParadisByte<vsize - 1>(0, (Int32)data.GetCount(), data, std::forward<decltype(getInt)>(getInt), jobQueue, Min(MAXTHREADS, (Int32)threadNum)) iferr_return;

	Int32 dataCount = (Int32)data.GetCount();
	if (getInt(data[dataCount - 1]) < 0)
	{
		Int32 indexOfNeg = 0;
		for (Int32 i = dataCount - 1; i > 0; --i)
		{
			if (getInt(data[i]) >= 0)
			{
				indexOfNeg = i + 1;
				break;
			}
		}
		BaseArray<T> tempCopy;

		Int32 negValues = dataCount - indexOfNeg;
		tempCopy.Resize(negValues, COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

		MemCopyType(tempCopy.GetFirst(), data.GetFirst() + indexOfNeg, negValues);
		MemCopyType(data.GetFirst() + negValues, data.GetFirst(), indexOfNeg);
		MemCopyType(data.GetFirst(), tempCopy.GetFirst(), negValues);
	}

	return OK;
}
}
