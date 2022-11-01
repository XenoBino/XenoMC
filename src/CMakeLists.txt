list(APPEND XenoMCSources
  ${XenoMCSourceDir}/main.c
  ${XenoMCSourceDir}/cmdline.h
  ${XenoMCSourceDir}/cmdline.c
  ${XenoMCSourceDir}/log.h
  ${XenoMCSourceDir}/log.c
)

configure_file(
  ${XenoMCSourceDir}/config.in.h
  ${XenoMCSourceDir}/config.h
  @ONLY
  NEWLINE_STYLE UNIX
)

add_executable(XenoMC ${XenoMCSources})

set_target_properties(XenoMC PROPERTIES OUTPUT_NAME "xmc")
