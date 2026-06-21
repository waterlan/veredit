set(PARSER_OUT ${CMAKE_CURRENT_SOURCE_DIR}/veredit_y.cc)
set(PARSER bison)
set(PARSER_FLAGS -y -d)

set(SCANNER_OUT ${CMAKE_CURRENT_SOURCE_DIR}/veredit_l.cc)
set(SCANNER flex)
set(SCANNER_FLAGS "")

add_custom_command (
  OUTPUT ${PARSER_OUT}
  COMMAND ${PARSER} ${PARSER_FLAGS} veredit.y
  COMMAND sed s/yy/veredit_yy/g <y.tab.c >${PARSER_OUT}
  COMMAND sed s/yy/veredit_yy/g <y.tab.h >${CMAKE_CURRENT_SOURCE_DIR}/veredit.h
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/veredit.y
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

add_custom_command (
  OUTPUT ${SCANNER_OUT}
  COMMAND ${SCANNER} ${SCANNER_FLAGS} veredit.l
  COMMAND sed s/yy/veredit_yy/g <lex.yy.c >${SCANNER_OUT}
  DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/veredit.l
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

set_source_files_properties(${PARSER_OUT} ${SCANNER_OUT} PROPERTIES GENERATED TRUE)

set(PARSER_SRCS
  ${PARSER_OUT}
  ${SCANNER_OUT}
)

add_library(parser STATIC ${PARSER_SRCS})

target_include_directories(parser
  PRIVATE
  "${CMAKE_SOURCE_DIR}"
  "${CMAKE_SOURCE_DIR}/util"
  "${CMAKE_SOURCE_DIR}/objects"
)
