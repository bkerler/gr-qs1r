# Copyright 2020 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

########################################################################
# Check if there is C++ code at all
########################################################################
if(NOT qs1r_sources)
    message(STATUS "No C++ sources... skipping python bindings")
    return()
endif(NOT qs1r_sources)

########################################################################
# Check for pygccxml
########################################################################
gr_python_check_module_raw("pygccxml" "import pygccxml" PYGCCXML_FOUND)

include(GrPybind)

########################################################################
# Python Bindings
########################################################################

list(APPEND qs1r_python_files qs1r_src_python.cc python_bindings.cc)

gr_pybind_make_oot(qs1r ../../.. gr::qs1r "${qs1r_python_files}")

# copy bindings extension for use in QA test module
add_custom_command(
    TARGET qs1r_python
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:qs1r_python>
            ${PROJECT_BINARY_DIR}/test_modules/gnuradio/qs1r/)

install(
    TARGETS qs1r_python
    DESTINATION ${GR_PYTHON_DIR}/gnuradio/qs1r
    COMPONENT pythonapi)
