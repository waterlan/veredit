cmake_minimum_required(VERSION 3.10)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)

set(VERSION "${MAJOR_VERSION}.${MINOR_VERSION}")

add_compile_options(-Wall -Wextra -Wno-format-security)

project(veredit VERSION ${VERSION} LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

include(FeatureSummary)
feature_summary(WHAT ALL INCLUDE_QUIET_PACKAGES FATAL_ON_MISSING_REQUIRED_PACKAGES)

set(V_SRCS
  Usage.cc
  Driver.cc
  main.cc
 )

add_subdirectory(objects)
add_subdirectory(src)
add_subdirectory(util)
add_subdirectory(parser)

add_executable(veredit ${V_SRCS})
target_link_libraries(veredit PRIVATE parser src util)

install(TARGETS veredit DESTINATION $ENV{HOME}/bin)

target_include_directories(
 veredit
 PRIVATE
 .
 util
 objects
 parser
 src
)
