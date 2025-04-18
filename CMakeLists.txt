#
#
#  MIT License
#
#  Copyright (c) 2025 Yafiyogi
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#
#

# PKG_CONFIG_PATH=${HOME}/code/tp/lib/pkgconfig:${HOME}/code/tp/share/pkgconfig:${PKG_CONFIG_PATH} cmake --fresh -DCMAKE_INSTALL_PREFIX=${HOME}/code/cpp/build -DYY_THIRD_PARTY_LIBRARY=${HOME}/code/tp -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE -DCMAKE_BUILD_TYPE=Release .
# cmake --fresh -DCMAKE_INSTALL_PREFIX=${HOME}/code/cpp/build -DYY_THIRD_PARTY_LIBRARY=${HOME}/code/tp -DCMAKE_POSITION_INDEPENDENT_CODE=TRUE -DCMAKE_BUILD_TYPE=Release .

cmake_minimum_required(VERSION 3.25)

project(yy_values_proj LANGUAGES CXX VERSION 0.0.1)

set(YY_ROOT "${PROJECT_SOURCE_DIR}/..")
set(YY_CMAKE "${YY_ROOT}/yy_cmake")

include(${YY_CMAKE}/cmake_common.txt)
include(${YY_CMAKE}/cmake_clang_tidy.txt)

add_library(yy_values STATIC)

target_compile_options(yy_values
  PRIVATE
  "-DSPDLOG_COMPILED_LIB"
  "-DSPDLOG_FMT_EXTERNAL")

target_include_directories(yy_values
  PRIVATE
    "${CMAKE_INSTALL_PREFIX}/include" )

target_include_directories(yy_values
  SYSTEM PRIVATE
    "${YY_THIRD_PARTY_LIBRARY}/include")

target_sources(yy_values
  PRIVATE
    yy_configure_label_actions.cpp
    yy_configure_values.cpp
    yy_label_action_copy.cpp
    yy_label_action_drop.cpp
    yy_label_action_keep.cpp
    yy_label_action_replace_path.cpp
    yy_replacement_format.cpp
    yy_value_action_keep.cpp
    yy_value_action_switch.cpp
    yy_values_labels.cpp
    yy_values_labels.cpp
    yy_values_metric.cpp
    yy_values_metric_id.cpp
    yy_values_metric_data.cpp

  PUBLIC FILE_SET HEADERS
    FILES
      yy_configure_label_actions.hpp
      yy_configure_values.hpp
      yy_label_action.hpp
      yy_label_action_fwd.hpp
      yy_label_action_copy.hpp
      yy_label_action_drop.hpp
      yy_label_action_keep.hpp
      yy_label_action_replace_path.hpp
      yy_replacement_format.hpp
      yy_value_action.hpp
      yy_value_action_fwd.hpp
      yy_value_action_keep.hpp
      yy_value_action_switch.hpp
      yy_values_labels.hpp
      yy_values_labels_fwd.hpp
      yy_values_metric.hpp
      yy_values_metric_id.hpp
      yy_values_metric_id_fmt.hpp
      yy_values_metric_labels.hpp
      yy_values_metric_data.hpp
      yy_value_type.hpp )

install(TARGETS yy_values
  EXPORT yy_valuesTargets
  FILE_SET HEADERS DESTINATION include/yy_values)

install(EXPORT yy_valuesTargets
  NAMESPACE yy_values::
  DESTINATION lib/cmake/yy_values)

include(CMakePackageConfigHelpers)
write_basic_package_version_file("yy_valuesConfigVersion.cmake"
  VERSION ${yy_values_VERSION}
  COMPATIBILITY AnyNewerVersion)

install(FILES "yy_valuesConfig.cmake" "${CMAKE_CURRENT_BINARY_DIR}/yy_valuesConfigVersion.cmake"
  DESTINATION lib/cmake/yy_values)

#add_subdirectory(unit_tests)
#add_subdirectory(examples)
#add_subdirectory(benchmarks)

add_yy_tidy_all(yy_values)
