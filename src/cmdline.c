#include "cmdline.h"
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "log.h"
#include "config.h"

#define boolToStr(x) (x == 0 ? "false" : "true")

int tty_colors = 0;

#define XenoMC_SHORT_OPTS "-:o:hv"
const struct option xenomc_options[] = {
	{"output", required_argument, NULL, 'o'},
	{"version", no_argument, NULL, 'v'},
	{"help", no_argument, NULL, 'h'},
};

void parse_args(int argc, char **argv, XenoMC_Options *options) {
	memset(options, 0x00, sizeof(*options));

	options->maxfiles = 10;
	options->files = malloc(10 * sizeof(FILE*));

	memset(options->files, 0x00, 10 * sizeof(FILE*));

	char ch = 0;
	while ((ch = getopt_long(argc, argv, XenoMC_SHORT_OPTS, xenomc_options, NULL)) != -1) {
		switch (ch) {
		case 1: {
			if (++(options->filecount) > 1) {
				fatalf("Currently only 1 file input is supported");
			}

			FILE *f = NULL;
			if (strcmp(optarg, "-") == 0) {
				options->files[0] = stdin;
			}
			else {
				options->files[0] = fopen(optarg, "r");
			}

			break;
		}

		case 'o':
			options->outfile = fopen(optarg, "w");
			break;

		case 'h':
			show_help(0);
			break;

		case 'v':
			show_version();
			break;

		case '?':
			errf("Invalid option -- '%c'", optopt);
			break;

		case ':':
			errf("option requires an argument -- '%c'", optopt);
			break;
		}
	}

	exit_if_errors();
	if (options->filecount == 0) {
		errf("No input files");
	}
}

void show_version() {
	printf("xmc: %s\n", XenoMC_VERSION_STRING);
	exit(0);
}

void show_help(int exit_code) {
	puts("Usage: xmc [OPTIONS] <-o|--output <file>> <...input files>");
	puts("");
	puts("  -v --version  Print the version number and exit");
	puts("  -h --help     Show this help message and exit");
	puts("  -o --output   The output file name");
	puts("");
	puts("This program is free software: you can redistribute it and/or modify");
	puts("it under the terms of the GNU General Public License as published by");
	puts("the Free Software Foundation, either version 3 of the License, or");
	puts("(at your option) any later version.");
	puts("");
	puts("This program is distributed in the hope that it will be useful,");
	puts("but WITHOUT ANY WARRANTY; without even the implied warranty of");
	puts("MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the");
	puts("GNU General Public License for more details.");
	puts("");
	puts("You should have received a copy of the GNU General Public License");
	puts("along with this program.  If not, see <https://www.gnu.org/licenses/>.");
	exit(exit_code);
}

void enable_colors() {
	tty_colors = isatty(fileno(stdin));
}

#ifndef NDEBUG
void dump_options(XenoMC_Options *options) {
	printf("XenoMC_Options options {\n");
	printf("\tfiles = %p;\n", options->files);
	printf("\tfilecount = %d;\n", options->filecount);
	printf("\tmaxfiles = %d;\n", options->maxfiles);
	printf("\toutfile = %p;\n", options->outfile);
	printf("}\n");
}
#endif
