set(SRC_SRCS
  DeclarationsList.cc
  EditElement.cc
  Instance.cc
  InstantiationList.cc
  MatchList.cc
  Module.cc
  ModuleEdit.cc
  ModuleItem.cc
  ModuleItemList.cc
  ModuleList.cc
  Nameset.cc
  Portmap.cc
  Portmap_element.cc
  SignalList.cc
  Signal_.cc
  Signal_type.cc
  SimpleSignal.cc
  SimpleSignalList.cc
  TextFunctions.cc
  TranslationUnit.cc
  VariableList.cc
  VerilogItemList.cc
  Vname.cc
  Vnode.cc
  doEdits.cc
  hierarchy.cc
  writeDot.cc
  writeEdtLib.cc
  writeIfspec.cc
  writeInitialEdits.cc
  writeInst.cc
  writeInstallFile.cc
  writeVerilog.cc
)

add_library(src STATIC ${SRC_SRCS})

target_link_libraries(src PRIVATE objects)

target_include_directories(src
  PRIVATE
  "${CMAKE_SOURCE_DIR}/objects"
)
