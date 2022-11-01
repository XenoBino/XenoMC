#ifndef XenoMC_CMDLINE_H_
#define XenoMC_CMDLINE_H_

#include <stddef.h>
#include <stdio.h>

typedef struct {
	FILE **files;
	size_t filecount;
	size_t maxfiles;
	FILE *outfile;
} XenoMC_Options;

extern int tty_colors;

void parse_args(int argc, char **argv, XenoMC_Options *options);
void enable_colors();

void show_version();
void show_help(int exit_code);

#ifndef NDEBUG
void dump_options(XenoMC_Options *options);
#endif

#endif
