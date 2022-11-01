#include <stdio.h>
#include "cmdline.h"

int main(int argc, char **argv) {
	// Try to enable colors as early as possible
	enable_colors();

	XenoMC_Options options;
	parse_args(argc, argv, &options);

#ifndef NDEBUG
	dump_options(&options);
#endif
	return 0;
}
