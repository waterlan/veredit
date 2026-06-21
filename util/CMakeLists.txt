set(UTIL_SRCS
  arithmetic.cc
  command.cc
  error.cc
  file.cc
  text.cc
)

add_library(util STATIC ${UTIL_SRCS})

target_include_directories(util
  PRIVATE
  "${CMAKE_SOURCE_DIR}"
  "${CMAKE_SOURCE_DIR}/objects"
)
