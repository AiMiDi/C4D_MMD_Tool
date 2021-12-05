#ifndef PARALLELIMAGE_H__
#define PARALLELIMAGE_H__

#include "maxon/thread.h"
#include "maxon/atomictypes.h"

namespace maxon
{

/// @addtogroup THREADING Threading
/// @{

//----------------------------------------------------------------------------------------
/// This is a utility class for parallel processing of 2d data - usually images. The per
/// pixel computations are distributed to several threads. This is intended for time
/// consuming computations, it makes no sense to call this to clear all pixels of an image.
//----------------------------------------------------------------------------------------
class ParallelImage
{
	template <typename WORKER> struct ImageData
	{
		ImageData(Int xRes, Int yRes, Int tileSize, const WORKER& worker) : _tilesX(xRes / tileSize), _tilesY(yRes / tileSize), _tileSize(tileSize), _worker(worker)
		{
		}

		const Int						_tilesX;
		const Int						_tilesY;
		const Int						_tileSize;
		const WORKER&				_worker;
		mutable AtomicInt32	_tileModeBarrier;
		mutable AtomicInt32	_lineModeBarrier;
	};

	template <typename WORKER> class PixelJob : public JobInterfaceTemplate<PixelJob<WORKER>>
	{
public:
		PixelJob(Int x, Int y, const ImageData<WORKER>& data) : _data(data), _x(x), _y(y) { }

		/// move constructor
		PixelJob(PixelJob&& src) : _data(src._data), _x(src._x), _y(src._y) { }
		/// move assignment operator
		MAXON_OPERATOR_MOVE_ASSIGNMENT(PixelJob);

		Result<void> operator ()()
		{
			_data._worker(_x, _y);
			return OK;
		}

		const Char* GetName() const
		{
			return "ParallelImage::PixelJob";
		}

private:
		const ImageData<WORKER>& _data;
		const Int								 _x;
		const Int								 _y;
	};

	template <typename WORKER> class LineJob : public JobInterfaceTemplate<LineJob<WORKER>>
	{
public:
		LineJob(Int x1, Int x2, Int y, const ImageData<WORKER>& data) : _data(data), _x1(x1), _x2(x2), _y(y)	{ }

		Result<void> operator ()()
		{
			const WORKER& worker = _data._worker;
			StaticJobGroupInterface<PixelJob<WORKER>>* pixelGroup = nullptr;
			Int				pixelJobCnt = 0;
			const Int y = _y;
			Int				x;

			for (x = _x1; x < _x2; x++)
			{
				if (_data._lineModeBarrier.LoadConsume() < 0)
				{
					pixelJobCnt = _x2 - x;
					pixelGroup	= StaticJobGroupInterface<PixelJob<WORKER>>::Alloc(pixelJobCnt) iferr_ignore("Pointer is checked");
					if (pixelGroup)
						break;
				}
			retry:
				worker(x, y);
			}

			if (pixelGroup)
			{
				StaticJobArray<PixelJob<WORKER>> jobs(pixelGroup, STATICJOBARRAYFLAGS::INITIALIZE_LATER);
				Int tmpX = x;

				for (PixelJob<WORKER>& job : jobs)
						new (&job) PixelJob<WORKER>(tmpX++, y, _data);

				pixelGroup->Add(jobs);

				// If adding the group failed this is no problem because the loop can continue.
				if (MAXON_UNLIKELY(this->AddSubGroup(pixelGroup) == FAILED))
				{
					_data._lineModeBarrier.StoreRelease(0);
					goto retry;
				}
			}
			// mark tile as done
			_data._lineModeBarrier.SwapDecrement();

			return OK;
		}

		const Char* GetName() const
		{
			return "ParallelImage::LineJob";
		}

private:
		const ImageData<WORKER>& _data;
		const Int _x1;
		const Int _x2;
		const Int	_y;
	};

	template <typename WORKER> class TileJob : public JobInterfaceTemplate<TileJob<WORKER>>
	{
public:
		TileJob(Int index, const ImageData<WORKER>& data) : _data(data), _index(index)	{ }

		Result<void> operator ()()
		{
			const WORKER& worker = _data._worker;
			StaticJobGroupInterface<LineJob<WORKER>>* lineGroup = nullptr;
			Int				lineJobCnt = 0;
			const Int	tileSize = _data._tileSize;
			const Int	xTile = _index % _data._tilesX;
			const Int yTile = _index / _data._tilesX;
			const Int xOff	= xTile * _data._tileSize;
			const Int	yOff	= yTile * _data._tileSize;
			Int				x = 0, y;

			for (y = yOff; y < yOff + tileSize; y++)
			{
				for (x = xOff; x < xOff + tileSize; x++)
				{
					if (_data._tileModeBarrier.LoadConsume() < 0)
					{
						lineJobCnt = yOff + tileSize - y;
						lineGroup	 = StaticJobGroupInterface<LineJob<WORKER>>::Alloc(lineJobCnt) iferr_ignore("Pointer is checked");
						if (lineGroup)
							break;
					}
				retry:
					worker(x, y);
				}

				if (lineGroup)
					break;
			}

			if (lineGroup)
			{
				StaticJobArray<LineJob<WORKER>> jobs(lineGroup, STATICJOBARRAYFLAGS::INITIALIZE_LATER);
				Int tmpX = x;
				Int tmpY = y;

				for (LineJob<WORKER>& job : jobs)
				{
					new (&job) LineJob<WORKER>(tmpX, xOff + tileSize, tmpY++, _data);
					tmpX = xOff;
				}

				lineGroup->Add(jobs);
				_data._lineModeBarrier.SwapAdd(Int32(lineJobCnt - 1));

				// If adding the group failed this is no problem because the loop can continue.
				if (MAXON_UNLIKELY(this->AddSubGroup(lineGroup) == FAILED))
				{
					_data._tileModeBarrier.StoreRelease(0);
					goto retry;
				}
			}

			// mark tile as done
			_data._tileModeBarrier.SwapDecrement();

			return OK;
		}

		const Char* GetName() const
		{
			return "ParallelImage::TileJob";
		}

private:
		const ImageData<WORKER>& _data;
		const Int _index;
	};

	template <typename WORKER> MAXON_ATTRIBUTE_NO_INLINE static void Fallback(Int width, Int height, const WORKER& worker)
	{
		// Error handling: run single-threaded.
		for (Int y = 0; y < height; y++)
		{
			for (Int x = 0; x < width; x++)
				worker(x, y);
		}
	}

public:
	//----------------------------------------------------------------------------------------
	/// Invokes the worker method for all pixels of the image (uses dynamic distribution).
	/// @param[in] width							Image width in pixels.
	/// @param[in] height							Image height in pixels.
	/// @param[in] tileSize						Initial tile size to be used (a tile will be tileSize pixels wide and tileSize pixels high)
	/// @param[in] worker							Lambda or object with operator (), will be called for every pixel (concurrently from different threads)
	/// @tparam WORKER								A class containing an operator ()(Int x, Int y) used for the loop.
	//----------------------------------------------------------------------------------------
	template <typename WORKER> static void Process(Int width, Int height, Int tileSize, const WORKER& worker)
	{
		Int threadCnt = JobRef::GetCurrentThreadCount();
		ImageData<WORKER>	data(width, height, tileSize, worker);
		Int tileCnt = data._tilesX * data._tilesY;

		ifnoerr (JobGroupRef group = JobGroupRef::Create())
		{
			if (threadCnt > tileCnt)
				threadCnt = tileCnt;

			data._tileModeBarrier.StoreRelaxed((Int32)(tileCnt - threadCnt));

			for (Int j = 0; j < tileCnt; j++)
			{
				if (group->Add(NewObj(TileJob<WORKER>, j, data)) == FAILED)
				{
					group = nullptr;
					break;
				}
			}
		}

		if (group)
		{
			group->EnqueueAndWait() iferr_cannot_fail("Group handles errors internally.");
		}
		else
		{
			Fallback(width, height, worker);
		}
	}
};

/// @}

} // namespace maxon

#endif // PARALLELIMAGE_H__
