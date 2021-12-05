#ifndef BASEARRAY_HELPER_H__
#define BASEARRAY_HELPER_H__

namespace maxon
{

template <Bool SKIPERRORS = false, typename FN, typename SRC, typename DST> inline Result<void> MoveFromWithFilter(DST& dst, SRC& src, const FN& filter)
{
	for (Int i = src.GetCount() - 1; i >= 0; --i)
	{
		if (filter(src[i]))
		{
			iferr (dst.Append(std::move(src[i])))
			{
				if (SKIPERRORS == false)
					return err;
			}
			iferr (src.Erase(i))
				DebugStop();
		}
	}
	return OK;
}

}

#endif // BASEARRAY_HELPER_H__
