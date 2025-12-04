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

#define edit_element_cc

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "error.h"
#include "text.h"
#include "rename_instance_statement.h"
#include "addport_statement.h"
#include "delport_statement.h"
#include "editinst_statement.h"
#include "editassign_statement.h"
#include "editparameter_decl_statement.h"
#include "delete_module_statement.h"
#include "buffer_statement.h"
#include "remove_buf_statement.h"
#include "buffernet_statement.h"
#include "insertObsInput_statement.h"
#include "insertObsOutput_statement.h"
#include "listInst_statement.h"
#include "tiecell_statement.h"
#include "shell_statement.h"
#include "bufassigns_statement.h"
#include "pullup_pin_statement.h"
#include "edit_element.h"


expfun edit_element edit_elementNew(rename_instance_statement renameInst = NULL,
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
                                    pullup_pin_statement pullupPin = NULL)
{
   edit_element e = (edit_element) malloc (sizeof(edit_element_struct));
   if (e != NULL)
   {
      e->renameInst = renameInst;
      e->addport = addport;
      e->delport = delport;
      e->editinst = editinst;
      e->editassign = editassign;
      e->editparameter_decl = editparameter_decl;
      e->delModule = delModule;
      e->bufferStat = bufferStat;
      e->removeBufStat = removeBufStat;
      e->bufferNetStat = bufferNetStat;
      e->insertObsInputStat = insertObsInputStat;
      e->insertObsOutputStat = insertObsOutputStat;
      e->listInstStat = listInstStat;
      e->tiecellStat = tiecellStat;
      e->shellStat = shellStat;
      e->bufAssign = bufAssign;
      e->pullupPin = pullupPin;
   }
   else
      malloc_error("edit_elementNew()");

   return e;
}
expfun bool eqSelfRenameInst(rename_instance_statement renameInst,
                             edit_element e)
{
   if ((renameInst == NULL) || (hasRenameInst(e) == false))
      return false;
   else if (eqSelf(renameInst, getRenameInst(e)))
      return true;
   else
      return false;
}
expfun bool eqRenameInst(rename_instance_statement renameInst,
                         edit_element e)
{
   if ((renameInst == NULL) || (hasRenameInst(e) == false))
      return false;
   else if (Eq(renameInst, getRenameInst(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfAddport(addport_statement addport,
                          edit_element e)
{
   if ((addport == NULL) || (hasAddport(e) == false))
      return false;
   else if (eqSelf(addport, getAddport(e)))
      return true;
   else
      return false;
}
expfun bool eqAddport(addport_statement addport,
                      edit_element e)
{
   if ((addport == NULL) || (hasAddport(e) == false))
      return false;
   else if (Eq(addport, getAddport(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfDelport(delport_statement delport,
                          edit_element e)
{
   if ((delport == NULL) || (hasDelport(e) == false))
      return false;
   else if (eqSelf(delport, getDelport(e)))
      return true;
   else
      return false;
}
expfun bool eqDelport(delport_statement delport,
                      edit_element e)
{
   if ((delport == NULL) || (hasDelport(e) == false))
      return false;
   else if (Eq(delport, getDelport(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditinst(editinst_statement editinst,
                           edit_element e)
{
   if ((editinst == NULL) || (hasEditinst(e) == false))
      return false;
   else if (eqSelf(editinst, getEditinst(e)))
      return true;
   else
      return false;
}
expfun bool eqEditinst(editinst_statement editinst,
                       edit_element e)
{
   if ((editinst == NULL) || (hasEditinst(e) == false))
      return false;
   else if (Eq(editinst, getEditinst(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditassign(editassign_statement editassign,
                             edit_element e)
{
   if ((editassign == NULL) || (hasEditassign(e) == false))
      return false;
   else if (eqSelf(editassign, getEditassign(e)))
      return true;
   else
      return false;
}
expfun bool eqEditassign(editassign_statement editassign,
                         edit_element e)
{
   if ((editassign == NULL) || (hasEditassign(e) == false))
      return false;
   else if (Eq(editassign, getEditassign(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                     edit_element e)
{
   if ((editparameter_decl == NULL) || (hasEditparameter_decl(e) == false))
      return false;
   else if (eqSelf(editparameter_decl, getEditparameter_decl(e)))
      return true;
   else
      return false;
}
expfun bool eqEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                 edit_element e)
{
   if ((editparameter_decl == NULL) || (hasEditparameter_decl(e) == false))
      return false;
   else if (Eq(editparameter_decl, getEditparameter_decl(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfDelModule(delete_module_statement delModule,
                            edit_element e)
{
   if ((delModule == NULL) || (hasDelModule(e) == false))
      return false;
   else if (eqSelf(delModule, getDelModule(e)))
      return true;
   else
      return false;
}
expfun bool eqDelModule(delete_module_statement delModule,
                        edit_element e)
{
   if ((delModule == NULL) || (hasDelModule(e) == false))
      return false;
   else if (Eq(delModule, getDelModule(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfBufferStat(buffer_statement bufferStat,
                             edit_element e)
{
   if ((bufferStat == NULL) || (hasBufferStat(e) == false))
      return false;
   else if (eqSelf(bufferStat, getBufferStat(e)))
      return true;
   else
      return false;
}
expfun bool eqBufferStat(buffer_statement bufferStat,
                         edit_element e)
{
   if ((bufferStat == NULL) || (hasBufferStat(e) == false))
      return false;
   else if (Eq(bufferStat, getBufferStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfRemoveBufStat(remove_buf_statement removeBufStat,
                                edit_element e)
{
   if ((removeBufStat == NULL) || (hasRemoveBufStat(e) == false))
      return false;
   else if (eqSelf(removeBufStat, getRemoveBufStat(e)))
      return true;
   else
      return false;
}
expfun bool eqRemoveBufStat(remove_buf_statement removeBufStat,
                            edit_element e)
{
   if ((removeBufStat == NULL) || (hasRemoveBufStat(e) == false))
      return false;
   else if (Eq(removeBufStat, getRemoveBufStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfBufferNetStat(buffernet_statement bufferNetStat,
                                edit_element e)
{
   if ((bufferNetStat == NULL) || (hasBufferNetStat(e) == false))
      return false;
   else if (eqSelf(bufferNetStat, getBufferNetStat(e)))
      return true;
   else
      return false;
}
expfun bool eqBufferNetStat(buffernet_statement bufferNetStat,
                            edit_element e)
{
   if ((bufferNetStat == NULL) || (hasBufferNetStat(e) == false))
      return false;
   else if (Eq(bufferNetStat, getBufferNetStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                     edit_element e)
{
   if ((insertObsInputStat == NULL) || (hasInsertObsInputStat(e) == false))
      return false;
   else if (eqSelf(insertObsInputStat, getInsertObsInputStat(e)))
      return true;
   else
      return false;
}
expfun bool eqInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                 edit_element e)
{
   if ((insertObsInputStat == NULL) || (hasInsertObsInputStat(e) == false))
      return false;
   else if (Eq(insertObsInputStat, getInsertObsInputStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                      edit_element e)
{
   if ((insertObsOutputStat == NULL) || (hasInsertObsOutputStat(e) == false))
      return false;
   else if (eqSelf(insertObsOutputStat, getInsertObsOutputStat(e)))
      return true;
   else
      return false;
}
expfun bool eqInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                  edit_element e)
{
   if ((insertObsOutputStat == NULL) || (hasInsertObsOutputStat(e) == false))
      return false;
   else if (Eq(insertObsOutputStat, getInsertObsOutputStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfListInstStat(listInst_statement listInstStat,
                               edit_element e)
{
   if ((listInstStat == NULL) || (hasListInstStat(e) == false))
      return false;
   else if (eqSelf(listInstStat, getListInstStat(e)))
      return true;
   else
      return false;
}
expfun bool eqListInstStat(listInst_statement listInstStat,
                           edit_element e)
{
   if ((listInstStat == NULL) || (hasListInstStat(e) == false))
      return false;
   else if (Eq(listInstStat, getListInstStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfTiecellStat(tiecell_statement tiecellStat,
                              edit_element e)
{
   if ((tiecellStat == NULL) || (hasTiecellStat(e) == false))
      return false;
   else if (eqSelf(tiecellStat, getTiecellStat(e)))
      return true;
   else
      return false;
}
expfun bool eqTiecellStat(tiecell_statement tiecellStat,
                          edit_element e)
{
   if ((tiecellStat == NULL) || (hasTiecellStat(e) == false))
      return false;
   else if (Eq(tiecellStat, getTiecellStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfShellStat(shell_statement shellStat,
                            edit_element e)
{
   if ((shellStat == NULL) || (hasShellStat(e) == false))
      return false;
   else if (eqSelf(shellStat, getShellStat(e)))
      return true;
   else
      return false;
}
expfun bool eqShellStat(shell_statement shellStat,
                        edit_element e)
{
   if ((shellStat == NULL) || (hasShellStat(e) == false))
      return false;
   else if (Eq(shellStat, getShellStat(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfBufAssign(bufassigns_statement bufAssign,
                            edit_element e)
{
   if ((bufAssign == NULL) || (hasBufAssign(e) == false))
      return false;
   else if (eqSelf(bufAssign, getBufAssign(e)))
      return true;
   else
      return false;
}
expfun bool eqBufAssign(bufassigns_statement bufAssign,
                        edit_element e)
{
   if ((bufAssign == NULL) || (hasBufAssign(e) == false))
      return false;
   else if (Eq(bufAssign, getBufAssign(e)))
      return true;
   else
      return false;
}
expfun bool eqSelfPullupPin(pullup_pin_statement pullupPin,
                            edit_element e)
{
   if ((pullupPin == NULL) || (hasPullupPin(e) == false))
      return false;
   else if (eqSelf(pullupPin, getPullupPin(e)))
      return true;
   else
      return false;
}
expfun bool eqPullupPin(pullup_pin_statement pullupPin,
                        edit_element e)
{
   if ((pullupPin == NULL) || (hasPullupPin(e) == false))
      return false;
   else if (Eq(pullupPin, getPullupPin(e)))
      return true;
   else
      return false;
}
expfun bool eqSelf(edit_element a,
                   edit_element b)
{
   if ((a == NULL) || (b == NULL))
      return false;
   else if (a == b)
      return true;
   else
      return false;
}
expfun bool Eq(edit_element a,
               edit_element b)
{
   if (eqSelf(a, b))
      return true;
   else if (eqRenameInst(getRenameInst(a), b) == false)
      return false;
   else if (eqAddport(getAddport(a), b) == false)
      return false;
   else if (eqDelport(getDelport(a), b) == false)
      return false;
   else if (eqEditinst(getEditinst(a), b) == false)
      return false;
   else if (eqEditassign(getEditassign(a), b) == false)
      return false;
   else if (eqEditparameter_decl(getEditparameter_decl(a), b) == false)
      return false;
   else if (eqDelModule(getDelModule(a), b) == false)
      return false;
   else if (eqBufferStat(getBufferStat(a), b) == false)
      return false;
   else if (eqRemoveBufStat(getRemoveBufStat(a), b) == false)
      return false;
   else if (eqBufferNetStat(getBufferNetStat(a), b) == false)
      return false;
   else if (eqInsertObsInputStat(getInsertObsInputStat(a), b) == false)
      return false;
   else if (eqInsertObsOutputStat(getInsertObsOutputStat(a), b) == false)
      return false;
   else if (eqListInstStat(getListInstStat(a), b) == false)
      return false;
   else if (eqTiecellStat(getTiecellStat(a), b) == false)
      return false;
   else if (eqShellStat(getShellStat(a), b) == false)
      return false;
   else if (eqBufAssign(getBufAssign(a), b) == false)
      return false;
   else if (eqPullupPin(getPullupPin(a), b) == false)
      return false;
   else
      return true;
}
expfun rename_instance_statement getRenameInst(edit_element e)
{
   if (e != NULL)
      return e->renameInst;
   else
      return NULL;
}
expfun addport_statement getAddport(edit_element e)
{
   if (e != NULL)
      return e->addport;
   else
      return NULL;
}
expfun delport_statement getDelport(edit_element e)
{
   if (e != NULL)
      return e->delport;
   else
      return NULL;
}
expfun editinst_statement getEditinst(edit_element e)
{
   if (e != NULL)
      return e->editinst;
   else
      return NULL;
}
expfun editassign_statement getEditassign(edit_element e)
{
   if (e != NULL)
      return e->editassign;
   else
      return NULL;
}
expfun editparameter_decl_statement getEditparameter_decl(edit_element e)
{
   if (e != NULL)
      return e->editparameter_decl;
   else
      return NULL;
}
expfun delete_module_statement getDelModule(edit_element e)
{
   if (e != NULL)
      return e->delModule;
   else
      return NULL;
}
expfun buffer_statement getBufferStat(edit_element e)
{
   if (e != NULL)
      return e->bufferStat;
   else
      return NULL;
}
expfun remove_buf_statement getRemoveBufStat(edit_element e)
{
   if (e != NULL)
      return e->removeBufStat;
   else
      return NULL;
}
expfun buffernet_statement getBufferNetStat(edit_element e)
{
   if (e != NULL)
      return e->bufferNetStat;
   else
      return NULL;
}
expfun insertObsInput_statement getInsertObsInputStat(edit_element e)
{
   if (e != NULL)
      return e->insertObsInputStat;
   else
      return NULL;
}
expfun insertObsOutput_statement getInsertObsOutputStat(edit_element e)
{
   if (e != NULL)
      return e->insertObsOutputStat;
   else
      return NULL;
}
expfun listInst_statement getListInstStat(edit_element e)
{
   if (e != NULL)
      return e->listInstStat;
   else
      return NULL;
}
expfun tiecell_statement getTiecellStat(edit_element e)
{
   if (e != NULL)
      return e->tiecellStat;
   else
      return NULL;
}
expfun shell_statement getShellStat(edit_element e)
{
   if (e != NULL)
      return e->shellStat;
   else
      return NULL;
}
expfun bufassigns_statement getBufAssign(edit_element e)
{
   if (e != NULL)
      return e->bufAssign;
   else
      return NULL;
}
expfun pullup_pin_statement getPullupPin(edit_element e)
{
   if (e != NULL)
      return e->pullupPin;
   else
      return NULL;
}
expfun edit_element setRenameInst(rename_instance_statement renameInst,
                                  edit_element e)
{
   if (e != NULL)
      e->renameInst = renameInst;
   return e;
}
expfun edit_element setAddport(addport_statement addport,
                               edit_element e)
{
   if (e != NULL)
      e->addport = addport;
   return e;
}
expfun edit_element setDelport(delport_statement delport,
                               edit_element e)
{
   if (e != NULL)
      e->delport = delport;
   return e;
}
expfun edit_element setEditinst(editinst_statement editinst,
                                edit_element e)
{
   if (e != NULL)
      e->editinst = editinst;
   return e;
}
expfun edit_element setEditassign(editassign_statement editassign,
                                  edit_element e)
{
   if (e != NULL)
      e->editassign = editassign;
   return e;
}
expfun edit_element setEditparameter_decl(editparameter_decl_statement editparameter_decl,
                                          edit_element e)
{
   if (e != NULL)
      e->editparameter_decl = editparameter_decl;
   return e;
}
expfun edit_element setDelModule(delete_module_statement delModule,
                                 edit_element e)
{
   if (e != NULL)
      e->delModule = delModule;
   return e;
}
expfun edit_element setBufferStat(buffer_statement bufferStat,
                                  edit_element e)
{
   if (e != NULL)
      e->bufferStat = bufferStat;
   return e;
}
expfun edit_element setRemoveBufStat(remove_buf_statement removeBufStat,
                                     edit_element e)
{
   if (e != NULL)
      e->removeBufStat = removeBufStat;
   return e;
}
expfun edit_element setBufferNetStat(buffernet_statement bufferNetStat,
                                     edit_element e)
{
   if (e != NULL)
      e->bufferNetStat = bufferNetStat;
   return e;
}
expfun edit_element setInsertObsInputStat(insertObsInput_statement insertObsInputStat,
                                          edit_element e)
{
   if (e != NULL)
      e->insertObsInputStat = insertObsInputStat;
   return e;
}
expfun edit_element setInsertObsOutputStat(insertObsOutput_statement insertObsOutputStat,
                                           edit_element e)
{
   if (e != NULL)
      e->insertObsOutputStat = insertObsOutputStat;
   return e;
}
expfun edit_element setListInstStat(listInst_statement listInstStat,
                                    edit_element e)
{
   if (e != NULL)
      e->listInstStat = listInstStat;
   return e;
}
expfun edit_element setTiecellStat(tiecell_statement tiecellStat,
                                   edit_element e)
{
   if (e != NULL)
      e->tiecellStat = tiecellStat;
   return e;
}
expfun edit_element setShellStat(shell_statement shellStat,
                                 edit_element e)
{
   if (e != NULL)
      e->shellStat = shellStat;
   return e;
}
expfun edit_element setBufAssign(bufassigns_statement bufAssign,
                                 edit_element e)
{
   if (e != NULL)
      e->bufAssign = bufAssign;
   return e;
}
expfun edit_element setPullupPin(pullup_pin_statement pullupPin,
                                 edit_element e)
{
   if (e != NULL)
      e->pullupPin = pullupPin;
   return e;
}
expfun bool hasRenameInst(edit_element e)
{
   if (getRenameInst(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasAddport(edit_element e)
{
   if (getAddport(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasDelport(edit_element e)
{
   if (getDelport(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasEditinst(edit_element e)
{
   if (getEditinst(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasEditassign(edit_element e)
{
   if (getEditassign(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasEditparameter_decl(edit_element e)
{
   if (getEditparameter_decl(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasDelModule(edit_element e)
{
   if (getDelModule(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBufferStat(edit_element e)
{
   if (getBufferStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasRemoveBufStat(edit_element e)
{
   if (getRemoveBufStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBufferNetStat(edit_element e)
{
   if (getBufferNetStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInsertObsInputStat(edit_element e)
{
   if (getInsertObsInputStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasInsertObsOutputStat(edit_element e)
{
   if (getInsertObsOutputStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasListInstStat(edit_element e)
{
   if (getListInstStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasTiecellStat(edit_element e)
{
   if (getTiecellStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasShellStat(edit_element e)
{
   if (getShellStat(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasBufAssign(edit_element e)
{
   if (getBufAssign(e) != NULL)
      return true;
   else
      return false;
}
expfun bool hasPullupPin(edit_element e)
{
   if (getPullupPin(e) != NULL)
      return true;
   else
      return false;
}
expfun edit_element copy(edit_element src,
                         size_t level = 0)
{
   edit_element e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (edit_element) malloc (sizeof(edit_element_struct));
      if (e != NULL)
      {
         if (level > 0)
         {
            e->renameInst = copy(src->renameInst, level - 1);
            e->addport = copy(src->addport, level - 1);
            e->delport = copy(src->delport, level - 1);
            e->editinst = copy(src->editinst, level - 1);
            e->editassign = copy(src->editassign, level - 1);
            e->editparameter_decl = copy(src->editparameter_decl, level - 1);
            e->delModule = copy(src->delModule);
            e->bufferStat = copy(src->bufferStat, level - 1);
            e->removeBufStat = copy(src->removeBufStat, level - 1);
            e->bufferNetStat = copy(src->bufferNetStat, level - 1);
            e->insertObsInputStat = copy(src->insertObsInputStat, level - 1);
            e->insertObsOutputStat = copy(src->insertObsOutputStat, level - 1);
            e->listInstStat = copy(src->listInstStat, level - 1);
            e->tiecellStat = copy(src->tiecellStat, level - 1);
            e->shellStat = copy(src->shellStat, level - 1);
            e->bufAssign = copy(src->bufAssign, level - 1);
            e->pullupPin = copy(src->pullupPin, level - 1);
         }
         else
         {
            e->renameInst = src->renameInst;
            e->addport = src->addport;
            e->delport = src->delport;
            e->editinst = src->editinst;
            e->editassign = src->editassign;
            e->editparameter_decl = src->editparameter_decl;
            e->delModule = src->delModule;
            e->bufferStat = src->bufferStat;
            e->removeBufStat = src->removeBufStat;
            e->bufferNetStat = src->bufferNetStat;
            e->insertObsInputStat = src->insertObsInputStat;
            e->insertObsOutputStat = src->insertObsOutputStat;
            e->listInstStat = src->listInstStat;
            e->tiecellStat = src->tiecellStat;
            e->shellStat = src->shellStat;
            e->bufAssign = src->bufAssign;
            e->pullupPin = src->pullupPin;
         }
      }
      else
         malloc_error("copy()");

      return e;
   }
}
expfun edit_element deepCopy(edit_element src)
{
   edit_element e;

   if (src == NULL)
      return NULL;
   else
   {
      e = (edit_element) malloc (sizeof(edit_element_struct));
      if (e != NULL)
      {
         e->renameInst = deepCopy(src->renameInst);
         e->addport = deepCopy(src->addport);
         e->delport = deepCopy(src->delport);
         e->editinst = deepCopy(src->editinst);
         e->editassign = deepCopy(src->editassign);
         e->editparameter_decl = deepCopy(src->editparameter_decl);
         e->delModule = copy(src->delModule);
         e->bufferStat = deepCopy(src->bufferStat);
         e->removeBufStat = deepCopy(src->removeBufStat);
         e->bufferNetStat = deepCopy(src->bufferNetStat);
         e->insertObsInputStat = deepCopy(src->insertObsInputStat);
         e->insertObsOutputStat = deepCopy(src->insertObsOutputStat);
         e->listInstStat = deepCopy(src->listInstStat);
         e->tiecellStat = deepCopy(src->tiecellStat);
         e->shellStat = deepCopy(src->shellStat);
         e->bufAssign = deepCopy(src->bufAssign);
         e->pullupPin = deepCopy(src->pullupPin);
      }
      else
         malloc_error("deepCopy()");

      return e;
   }
}
expfun void dump(text Offset,
                 edit_element e,
                 FILE* fp = stdout,
                 bool showEmpty = false)
{
   text increment = " ";
   rwtext new_Offset = rwtextNew(strlen(Offset) + strlen(increment) + 1);
   sprintf(new_Offset, "%s%s", Offset, increment);

   if (e == NULL)
   {
      if (showEmpty)
      {
         fprintf(fp, "%s{\n", Offset);
         fprintf(fp, "%sNULL\n", new_Offset);
         fprintf(fp, "%s}\n", Offset);
      }
   }
   else
   {
      fprintf(fp, "%s{\n", Offset);

      if (hasRenameInst(e) || showEmpty)
      {
         fprintf(fp, "%srename_instance_statement renameInst,\n", new_Offset);
         dump(new_Offset, e->renameInst, fp, showEmpty);
         fprintf(fp, "%s\\end rename_instance_statement\n", new_Offset);
      }

      if (hasAddport(e) || showEmpty)
      {
         fprintf(fp, "%saddport_statement addport,\n", new_Offset);
         dump(new_Offset, e->addport, fp, showEmpty);
         fprintf(fp, "%s\\end addport_statement\n", new_Offset);
      }

      if (hasDelport(e) || showEmpty)
      {
         fprintf(fp, "%sdelport_statement delport,\n", new_Offset);
         dump(new_Offset, e->delport, fp, showEmpty);
         fprintf(fp, "%s\\end delport_statement\n", new_Offset);
      }

      if (hasEditinst(e) || showEmpty)
      {
         fprintf(fp, "%seditinst_statement editinst,\n", new_Offset);
         dump(new_Offset, e->editinst, fp, showEmpty);
         fprintf(fp, "%s\\end editinst_statement\n", new_Offset);
      }

      if (hasEditassign(e) || showEmpty)
      {
         fprintf(fp, "%seditassign_statement editassign,\n", new_Offset);
         dump(new_Offset, e->editassign, fp, showEmpty);
         fprintf(fp, "%s\\end editassign_statement\n", new_Offset);
      }

      if (hasEditparameter_decl(e) || showEmpty)
      {
         fprintf(fp, "%seditparameter_decl_statement editparameter_decl,\n", new_Offset);
         dump(new_Offset, e->editparameter_decl, fp, showEmpty);
         fprintf(fp, "%s\\end editparameter_decl_statement\n", new_Offset);
      }

      if (hasDelModule(e) || showEmpty)
      {
         fprintf(fp, "%sdelete_module_statement delModule,\n", new_Offset);
         dump(new_Offset, e->delModule, fp, showEmpty);
         fprintf(fp, "%s\\end delete_module_statement\n", new_Offset);
      }

      if (hasBufferStat(e) || showEmpty)
      {
         fprintf(fp, "%sbuffer_statement bufferStat,\n", new_Offset);
         dump(new_Offset, e->bufferStat, fp, showEmpty);
         fprintf(fp, "%s\\end buffer_statement\n", new_Offset);
      }

      if (hasRemoveBufStat(e) || showEmpty)
      {
         fprintf(fp, "%sremove_buf_statement removeBufStat,\n", new_Offset);
         dump(new_Offset, e->removeBufStat, fp, showEmpty);
         fprintf(fp, "%s\\end remove_buf_statement\n", new_Offset);
      }

      if (hasBufferNetStat(e) || showEmpty)
      {
         fprintf(fp, "%sbuffernet_statement bufferNetStat,\n", new_Offset);
         dump(new_Offset, e->bufferNetStat, fp, showEmpty);
         fprintf(fp, "%s\\end buffernet_statement\n", new_Offset);
      }

      if (hasInsertObsInputStat(e) || showEmpty)
      {
         fprintf(fp, "%sinsertObsInput_statement insertObsInputStat,\n", new_Offset);
         dump(new_Offset, e->insertObsInputStat, fp, showEmpty);
         fprintf(fp, "%s\\end insertObsInput_statement\n", new_Offset);
      }

      if (hasInsertObsOutputStat(e) || showEmpty)
      {
         fprintf(fp, "%sinsertObsOutput_statement insertObsOutputStat,\n", new_Offset);
         dump(new_Offset, e->insertObsOutputStat, fp, showEmpty);
         fprintf(fp, "%s\\end insertObsOutput_statement\n", new_Offset);
      }

      if (hasListInstStat(e) || showEmpty)
      {
         fprintf(fp, "%slistInst_statement listInstStat,\n", new_Offset);
         dump(new_Offset, e->listInstStat, fp, showEmpty);
         fprintf(fp, "%s\\end listInst_statement\n", new_Offset);
      }

      if (hasTiecellStat(e) || showEmpty)
      {
         fprintf(fp, "%stiecell_statement tiecellStat,\n", new_Offset);
         dump(new_Offset, e->tiecellStat, fp, showEmpty);
         fprintf(fp, "%s\\end tiecell_statement\n", new_Offset);
      }

      if (hasShellStat(e) || showEmpty)
      {
         fprintf(fp, "%sshell_statement shellStat,\n", new_Offset);
         dump(new_Offset, e->shellStat, fp, showEmpty);
         fprintf(fp, "%s\\end shell_statement\n", new_Offset);
      }

      if (hasBufAssign(e) || showEmpty)
      {
         fprintf(fp, "%sbufassigns_statement bufAssign,\n", new_Offset);
         dump(new_Offset, e->bufAssign, fp, showEmpty);
         fprintf(fp, "%s\\end bufassigns_statement\n", new_Offset);
      }

      if (hasPullupPin(e) || showEmpty)
      {
         fprintf(fp, "%spullup_pin_statement pullupPin,\n", new_Offset);
         dump(new_Offset, e->pullupPin, fp, showEmpty);
         fprintf(fp, "%s\\end pullup_pin_statement\n", new_Offset);
      }

      fprintf(fp, "%s}\n", Offset);
   }
}
expfun void Free(edit_element e,
                 size_t level = 0)
{
   if (e ne NULL)
   {
      if (level > 0)
      {

         Free(e->renameInst, level - 1);
         e->renameInst = NULL;

         Free(e->addport, level - 1);
         e->addport = NULL;

         Free(e->delport, level - 1);
         e->delport = NULL;

         Free(e->editinst, level - 1);
         e->editinst = NULL;

         Free(e->editassign, level - 1);
         e->editassign = NULL;

         Free(e->editparameter_decl, level - 1);
         e->editparameter_decl = NULL;

         Free(e->delModule);
         e->delModule = NULL;

         Free(e->bufferStat, level - 1);
         e->bufferStat = NULL;

         Free(e->removeBufStat, level - 1);
         e->removeBufStat = NULL;

         Free(e->bufferNetStat, level - 1);
         e->bufferNetStat = NULL;

         Free(e->insertObsInputStat, level - 1);
         e->insertObsInputStat = NULL;

         Free(e->insertObsOutputStat, level - 1);
         e->insertObsOutputStat = NULL;

         Free(e->listInstStat, level - 1);
         e->listInstStat = NULL;

         Free(e->tiecellStat, level - 1);
         e->tiecellStat = NULL;

         Free(e->shellStat, level - 1);
         e->shellStat = NULL;

         Free(e->bufAssign, level - 1);
         e->bufAssign = NULL;

         Free(e->pullupPin, level - 1);
         e->pullupPin = NULL;
      }


      free((void *) e);
   }
}
expfun void deepFree(edit_element e)
{
   if (e ne NULL)
   {

      deepFree(e->renameInst);
      e->renameInst = NULL;

      deepFree(e->addport);
      e->addport = NULL;

      deepFree(e->delport);
      e->delport = NULL;

      deepFree(e->editinst);
      e->editinst = NULL;

      deepFree(e->editassign);
      e->editassign = NULL;

      deepFree(e->editparameter_decl);
      e->editparameter_decl = NULL;

      Free(e->delModule);
      e->delModule = NULL;

      deepFree(e->bufferStat);
      e->bufferStat = NULL;

      deepFree(e->removeBufStat);
      e->removeBufStat = NULL;

      deepFree(e->bufferNetStat);
      e->bufferNetStat = NULL;

      deepFree(e->insertObsInputStat);
      e->insertObsInputStat = NULL;

      deepFree(e->insertObsOutputStat);
      e->insertObsOutputStat = NULL;

      deepFree(e->listInstStat);
      e->listInstStat = NULL;

      deepFree(e->tiecellStat);
      e->tiecellStat = NULL;

      deepFree(e->shellStat);
      e->shellStat = NULL;

      deepFree(e->bufAssign);
      e->bufAssign = NULL;

      deepFree(e->pullupPin);
      e->pullupPin = NULL;

      free((void *) e);
   }
}
