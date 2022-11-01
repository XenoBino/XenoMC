#ifndef XenoMC_LOG_H_
#define XenoMC_LOG_H_

extern int errors;
extern int warnings;

void errf(const char *format, ...);
void fatalf(const char *format, ...);
void warnf(const char *format, ...);
void msgf(const char *format, ...);
void exit_if_errors();

#endif
