#include "log.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include "cmdline.h"

int errors = 0;
int warnings = 0;

void exit_if_errors() {
	if (errors > 0) {
		exit(1);
	}
}

void exit_if_warnings() {
	if (warnings > 0) {
		exit(1);
	}
}

void errf(const char *format, ...) {
	errors++;

	va_list args;
	va_start(args, format);

	char *colored_prefix = "xmc: Error: ";
	char *non_colored_prefix = "xmc: \e[31mError: \e[0m";

	char *prefix = (tty_colors ? colored_prefix : non_colored_prefix);
	char *buffer = malloc(strlen(prefix) + strlen(format) + 1);

	strcat(buffer, prefix);
	strcat(buffer, format);

	vfprintf(stderr, buffer, args);

	va_end(args);
}

void fatalf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	char *colored_prefix = "xmc: Fatal: ";
	char *non_colored_prefix = "xmc: \e[31mFatal: \e[0m";

	char *prefix = (tty_colors ? colored_prefix : non_colored_prefix);
	char *buffer = malloc(strlen(prefix) + strlen(format) + 1);

	strcat(buffer, prefix);
	strcat(buffer, format);

	vfprintf(stderr, buffer, args);

	va_end(args);
	exit(1);
}

void warnf(const char *format, ...) {
	warnings++;

	va_list args;
	va_start(args, format);

	char *colored_prefix = "xmc: Warning: ";
	char *non_colored_prefix = "xmc: \e[33mWarning: \e[0m";

	char *prefix = (tty_colors ? colored_prefix : non_colored_prefix);
	char *buffer = malloc(strlen(prefix) + strlen(format) + 1);

	strcat(buffer, prefix);
	strcat(buffer, format);

	vfprintf(stderr, buffer, args);

	va_end(args);
}

void msgf(const char *format, ...) {
	va_list args;
	va_start(args, format);

	char *colored_prefix = "xmc: Message: ";
	char *non_colored_prefix = "xmc: \e[32mMessage: \e[0m";

	char *prefix = (tty_colors ? colored_prefix : non_colored_prefix);
	char *buffer = malloc(strlen(prefix) + strlen(format) + 1);

	strcat(buffer, prefix);
	strcat(buffer, format);

	vfprintf(stderr, buffer, args);

	va_end(args);
}
