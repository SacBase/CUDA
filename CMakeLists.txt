CMAKE_MINIMUM_REQUIRED (VERSION 3.3)

PROJECT (sac-cudamodule)
#FIXME(artem) we can create a definitoin for language "SAC" which will
#             automatically pull sac2c compiler.

# Where the compiled sac modules result
SET (DLL_BUILD_DIR  "${PROJECT_BINARY_DIR}/lib")

# For what targets we build modules
SET (TARGETS            cuda        CACHE STRING "Build stdlib-cuda for these targets")
SET (SAC2C_EXEC                     CACHE STRING "A path to sac2c compiler")
SET (LINKSETSIZE        "0"         CACHE STRING "Set a value for -linksetsize parameter of sac2c")
SET (ENABLE_CUDA_CHECK  OFF         CACHE STRING "Activate CUDA runtime checks")

# Check whether sac2c is operational
INCLUDE ("cmake-common/check-sac2c.cmake")
INCLUDE ("cmake-common/misc-macros.cmake")

# Ensure CUDA is available
FIND_PACKAGE (CUDA REQUIRED)

CONFIGURE_FILE ("${PROJECT_SOURCE_DIR}/cmake/config.h.in"
                "${PROJECT_BINARY_DIR}/include/config.h")

# For every target run CMakeLists.txt in src
FOREACH (TARGET IN ITEMS ${TARGETS})
    ADD_SUBDIRECTORY (src   src-${TARGET})
ENDFOREACH ()

# This build target is responsible for generating the package sac2crc file
CREATE_SAC2CRC_TARGET ("cudamodule" "${DLL_BUILD_DIR}" "${DLL_BUILD_DIR}")
