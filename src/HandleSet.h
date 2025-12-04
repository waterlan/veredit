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

#ifndef HANDLESET_INCLUDED
#define HANDLESET_INCLUDED

#include <stdio.h>

#include "std_macro.h"
#include "structures.h"



   template <class Tset>
   void handleSet(Tset set)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set));
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ>
   void handleSet(Tset set,
                  Targ arg)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2>
   void handleSet(Tset set,
                  Targ1 arg1,
                  Targ2 arg2)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg1, arg2);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3>
   void handleSet(Tset set,
                  Targ1 arg1,
                  Targ2 arg2,
                  Targ3 arg3)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg1, arg2, arg3);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4>
   void handleSet(Tset set,
                  Targ1 arg1,
                  Targ2 arg2,
                  Targ3 arg3,
                  Targ4 arg4)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg1, arg2, arg3, arg4);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4,
             class Targ5>
   void handleSet(Tset set,
                  Targ1 arg1,
                  Targ2 arg2,
                  Targ3 arg3,
                  Targ4 arg4,
                  Targ5 arg5)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg1, arg2, arg3, arg4, arg5);
         index = index + 1;
      }
   }

   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4,
             class Targ5,
             class Targ6>
   void handleSet(Tset set,
                  Targ1 arg1,
                  Targ2 arg2,
                  Targ3 arg3,
                  Targ4 arg4,
                  Targ5 arg5,
                  Targ6 arg6)
   {
      size_t index = 0;
      while(index < size(set))
      {
         handle(elementAt(index, set), arg1, arg2, arg3, arg4, arg5, arg6);
         index = index + 1;
      }
   }

#endif
