find_package(PkgConfig)

PKG_CHECK_MODULES(PC_GR_QS1R gnuradio-qs1r)

FIND_PATH(
    GR_QS1R_INCLUDE_DIRS
    NAMES gnuradio/qs1r/api.h
    HINTS $ENV{QS1R_DIR}/include
        ${PC_QS1R_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    GR_QS1R_LIBRARIES
    NAMES gnuradio-qs1r
    HINTS $ENV{QS1R_DIR}/lib
        ${PC_QS1R_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/gnuradio-qs1rTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(GR_QS1R DEFAULT_MSG GR_QS1R_LIBRARIES GR_QS1R_INCLUDE_DIRS)
MARK_AS_ADVANCED(GR_QS1R_LIBRARIES GR_QS1R_INCLUDE_DIRS)
