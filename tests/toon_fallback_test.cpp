#include "utils/cmt_toon_fallback.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
	using cmt_material::UseNeutralToonFallback;
	if (!UseNeutralToonFallback(0, -1, false)
		|| UseNeutralToonFallback(0, -1, true)
		|| UseNeutralToonFallback(0, 0, false)
		|| UseNeutralToonFallback(0, 3, true)
		|| UseNeutralToonFallback(1, 0, false)
		|| UseNeutralToonFallback(1, 0, true))
	{
		std::cerr << "Unassigned Toon must remain distinct from missing assigned texture\n";
		return EXIT_FAILURE;
	}
	std::cout << "Explicit no-Toon fallback and assigned texture distinctions passed\n";
}
