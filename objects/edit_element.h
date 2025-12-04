// Copyright (C) 1999-2025  Erwin Waterlander
// Copyright (C) 1999       Ondrej Popp
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice in the documentation and/or other materials provided with
//    the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
// OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
// BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
// OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef edit_element_INCLUDED
#define edit_element_INCLUDED



// Extra Forward Declarations
// End Extra Forward Declarations

// External Functions
   extern bool eqSelfRenameInst(rename_instance_statement renameInst,
                                edit_element e);
   extern bool eqRenameInst(rename_instance_statement renameInst,
                            edit_element e);
   extern bool eqSelfAddport(addport_statement addport,
                             edit_element e);
   extern bool eqAddport(addport_statement addport,
                         edit_element e);
   extern bool eqSelfDelport(delport_statement delport,
                             edit_element e);
   extern bool eqDelport(delport_statement delport,
                         edit_element e);
   extern bool eqSelfEditinst(editinst_statement editinst,
                              edit_element e);
   extern bool eqEditinst(editinst_statement editinst,
                          edit_element e);
   extern bool eqSelfEditassign(editassign_statement editassign,
                                edit_element e);
   extern bool eqEditassign(editassign_statement editassign,
                            edit_element e);
   extern bool eqSelfEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                        edit_element e);
   extern bool eqEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                    edit_element e);
   extern bool eqSelfDelModule(delete_module_statement delModule,
                               edit_element e);
   extern bool eqDelModule(delete_module_statement delModule,
                           edit_element e);
   extern bool eqSelfBufferStat(buffer_statement bufferStat,
                                edit_element e);
   extern bool eqBufferStat(buffer_statement bufferStat,
                            edit_element e);
   extern bool eqSelfRemoveBufStat(remove_buf_statement removeBufStat,
                                   edit_element e);
   extern bool eqRemoveBufStat(remove_buf_statement removeBufStat,
                               edit_element e);
   extern bool eqSelfBufferNetStat(buffernet_statement bufferNetStat,
                                   edit_element e);
   extern bool eqBufferNetStat(buffernet_statement bufferNetStat,
                               edit_element e);
   extern bool eqSelfInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                        edit_element e);
   extern bool eqInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                    edit_element e);
   extern bool eqSelfInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                         edit_element e);
   extern bool eqInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                     edit_element e);
   extern bool eqSelfListInstStat(listInst_statement listInstStat,
                                  edit_element e);
   extern bool eqListInstStat(listInst_statement listInstStat,
                              edit_element e);
   extern bool eqSelfTiecellStat(tiecell_statement tiecellStat,
                                 edit_element e);
   extern bool eqTiecellStat(tiecell_statement tiecellStat,
                             edit_element e);
   extern bool eqSelfShellStat(shell_statement shellStat,
                               edit_element e);
   extern bool eqShellStat(shell_statement shellStat,
                           edit_element e);
   extern bool eqSelfBufAssign(bufassigns_statement bufAssign,
                               edit_element e);
   extern bool eqBufAssign(bufassigns_statement bufAssign,
                           edit_element e);
   extern bool eqSelfPullupPin(pullup_pin_statement pullupPin,
                               edit_element e);
   extern bool eqPullupPin(pullup_pin_statement pullupPin,
                           edit_element e);
   extern bool eqSelf(edit_element a,
                      edit_element b);
   extern bool Eq(edit_element a,
                  edit_element b);
   extern rename_instance_statement getRenameInst(edit_element e);
   extern addport_statement getAddport(edit_element e);
   extern delport_statement getDelport(edit_element e);
   extern editinst_statement getEditinst(edit_element e);
   extern editassign_statement getEditassign(edit_element e);
   extern editparameter_decl_statement getEditparameter_decl(edit_element e);
   extern delete_module_statement getDelModule(edit_element e);
   extern buffer_statement getBufferStat(edit_element e);
   extern remove_buf_statement getRemoveBufStat(edit_element e);
   extern buffernet_statement getBufferNetStat(edit_element e);
   extern insertObsInput_statement getInsertObsInputStat(edit_element e);
   extern insertObsOutput_statement getInsertObsOutputStat(edit_element e);
   extern listInst_statement getListInstStat(edit_element e);
   extern tiecell_statement getTiecellStat(edit_element e);
   extern shell_statement getShellStat(edit_element e);
   extern bufassigns_statement getBufAssign(edit_element e);
   extern pullup_pin_statement getPullupPin(edit_element e);
   extern edit_element setRenameInst(rename_instance_statement renameInst,
                                     edit_element e);
   extern edit_element setAddport(addport_statement addport,
                                  edit_element e);
   extern edit_element setDelport(delport_statement delport,
                                  edit_element e);
   extern edit_element setEditinst(editinst_statement editinst,
                                   edit_element e);
   extern edit_element setEditassign(editassign_statement editassign,
                                     edit_element e);
   extern edit_element setEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                             edit_element e);
   extern edit_element setDelModule(delete_module_statement delModule,
                                    edit_element e);
   extern edit_element setBufferStat(buffer_statement bufferStat,
                                     edit_element e);
   extern edit_element setRemoveBufStat(remove_buf_statement removeBufStat,
                                        edit_element e);
   extern edit_element setBufferNetStat(buffernet_statement bufferNetStat,
                                        edit_element e);
   extern edit_element setInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                             edit_element e);
   extern edit_element setInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                              edit_element e);
   extern edit_element setListInstStat(listInst_statement listInstStat,
                                       edit_element e);
   extern edit_element setTiecellStat(tiecell_statement tiecellStat,
                                      edit_element e);
   extern edit_element setShellStat(shell_statement shellStat,
                                    edit_element e);
   extern edit_element setBufAssign(bufassigns_statement bufAssign,
                                    edit_element e);
   extern edit_element setPullupPin(pullup_pin_statement pullupPin,
                                    edit_element e);
   extern bool hasRenameInst(edit_element e);
   extern bool hasAddport(edit_element e);
   extern bool hasDelport(edit_element e);
   extern bool hasEditinst(edit_element e);
   extern bool hasEditassign(edit_element e);
   extern bool hasEditparameter_decl(edit_element e);
   extern bool hasDelModule(edit_element e);
   extern bool hasBufferStat(edit_element e);
   extern bool hasRemoveBufStat(edit_element e);
   extern bool hasBufferNetStat(edit_element e);
   extern bool hasInsertObsInputStat(edit_element e);
   extern bool hasInsertObsOutputStat(edit_element e);
   extern bool hasListInstStat(edit_element e);
   extern bool hasTiecellStat(edit_element e);
   extern bool hasShellStat(edit_element e);
   extern bool hasBufAssign(edit_element e);
   extern bool hasPullupPin(edit_element e);
   extern edit_element deepCopy(edit_element src);
   extern void deepFree(edit_element e);

   #ifdef edit_element_cc
      extern edit_element edit_elementNew(rename_instance_statement renameInst,
                                          addport_statement addport,
                                          delport_statement delport,
                                          editinst_statement editinst,
                                          editassign_statement editassign,
                                          editparameter_decl_statement editparameter_decl,
                                          delete_module_statement delModule,
                                          buffer_statement bufferStat,
                                          remove_buf_statement removeBufStat,
                                          buffernet_statement bufferNetStat,
                                          insertObsInput_statement insertObsInputStat,
                                          insertObsOutput_statement insertObsOutputStat,
                                          listInst_statement listInstStat,
                                          tiecell_statement tiecellStat,
                                          shell_statement shellStat,
                                          bufassigns_statement bufAssign,
                                          pullup_pin_statement pullupPin);
      extern edit_element copy(edit_element src,
                               size_t level);
      extern void dump(text Offset,
                       edit_element e,
                       FILE* fp,
                       bool showEmpty);
      extern void Free(edit_element e,
                       size_t level);

   #else
      extern edit_element edit_elementNew(rename_instance_statement renameInst = NULL,
                                          addport_statement addport = NULL,
                                          delport_statement delport = NULL,
                                          editinst_statement editinst = NULL,
                                          editassign_statement editassign = NULL,
                                          editparameter_decl_statement editparameter_decl = NULL,
                                          delete_module_statement delModule = NULL,
                                          buffer_statement bufferStat = NULL,
                                          remove_buf_statement removeBufStat = NULL,
                                          buffernet_statement bufferNetStat = NULL,
                                          insertObsInput_statement insertObsInputStat = NULL,
                                          insertObsOutput_statement insertObsOutputStat = NULL,
                                          listInst_statement listInstStat = NULL,
                                          tiecell_statement tiecellStat = NULL,
                                          shell_statement shellStat = NULL,
                                          bufassigns_statement bufAssign = NULL,
                                          pullup_pin_statement pullupPin = NULL);
      extern edit_element copy(edit_element src,
                               size_t level = 0);
      extern void dump(text Offset,
                       edit_element e,
                       FILE* fp = stdout,
                       bool showEmpty = false);
      extern void Free(edit_element e,
                       size_t level = 0);

   #endif
// End External Functions
#endif
