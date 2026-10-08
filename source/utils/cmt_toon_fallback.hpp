#pragma once

namespace cmt_material
{
// A PMX independent Toon index of -1 means no Toon multiplication. Keep a
// missing assigned texture distinct from that explicit unassigned state.
inline bool UseNeutralToonFallback(const int toon_mode, const int texture_index,
	const bool has_texture_path)
{
	return toon_mode == 0 && texture_index < 0 && !has_texture_path;
}
}
