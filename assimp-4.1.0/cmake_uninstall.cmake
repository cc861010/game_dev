IF(NOT EXISTS "/home/cc/ClionProjects/game_dev/assimp-4.1.0/install_manifest.txt")
  MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/home/cc/ClionProjects/game_dev/assimp-4.1.0/install_manifest.txt\"")
ENDIF(NOT EXISTS "/home/cc/ClionProjects/game_dev/assimp-4.1.0/install_manifest.txt")

FILE(READ "/home/cc/ClionProjects/game_dev/assimp-4.1.0/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")
FOREACH(file ${files})
  MESSAGE(STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  EXEC_PROGRAM(
    "/usr/local/bin/cmake" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
    OUTPUT_VARIABLE rm_out
    RETURN_VALUE rm_retval
    )
  IF(NOT "${rm_retval}" STREQUAL 0)
    MESSAGE(FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
  ENDIF(NOT "${rm_retval}" STREQUAL 0)
ENDFOREACH(file)
