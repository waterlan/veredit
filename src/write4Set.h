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

#ifndef write4Set_INCLUDED
#define write4Set_INCLUDED


#include <stdio.h>

#include "std_macro.h"
#include "structures.h"

#include "text.h"


   template <class Tset>
   void write4Set(size_t tabs,
                 Tset set,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), fp);
         index = index + 1;
      }
   }
   template <class Tset>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), fp);
         index = index + 1;
      }
   }
   template <class Tset>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElementAt(set), fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), fp);

         index = index + 1;
      }
   }
   template <class Tset,
             class Targ>
   void write4Set(size_t tabs,
                 Tset set,
                 Targ arg,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), arg, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 Targ arg,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), arg, fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), arg, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          Targ arg,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElement(set), arg, fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), arg, fp);

         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2>
   void write4Set(size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), arg1, arg2, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), arg1, arg2, fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), arg1, arg2, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          Targ1 arg1,
                          Targ2 arg2,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElement(set), arg1, arg2, fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), arg1, arg2, fp);

         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3>
   void write4Set(size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), arg1, arg2, arg3, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), arg1, arg2, arg3, fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), arg1, arg2, arg3, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          Targ1 arg1,
                          Targ2 arg2,
                          Targ3 arg3,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElement(set), arg1, arg2, arg3, fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), arg1, arg2, arg3, fp);

         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4>
   void write4Set(size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 Targ4 arg4,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), arg1, arg2, arg3, arg4, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 Targ4 arg4,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), arg1, arg2, arg3, arg4, fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), arg1, arg2, arg3, arg4, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          Targ1 arg1,
                          Targ2 arg2,
                          Targ3 arg3,
                          Targ4 arg4,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElement(set), arg1, arg2, arg3, arg4, fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), arg1, arg2, arg3, arg4, fp);

         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4,
             class Targ5>
   void write4Set(size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 Targ4 arg4,
                 Targ5 arg5,
                 FILE* fp = stdout)
   {
      size_t index = 0;
      while(index < size(set))
      {
         write4(tabs, elementAt(index, set), arg1, arg2, arg3, arg4, arg5, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4,
             class Targ5>
   void write4Set(text firstSeparator,
                 text nextSeparator,
                 size_t tabs,
                 Tset set,
                 Targ1 arg1,
                 Targ2 arg2,
                 Targ3 arg3,
                 Targ4 arg4,
                 Targ5 arg5,
                 FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
         write4(firstSeparator, tabs, firstElement(set), arg1, arg2, arg3, arg4, arg5, fp);

      size_t index = 1;
      while(index < size(set))
      {
         write4(nextSeparator, tabs, elementAt(index, set), arg1, arg2, arg3, arg4, arg5, fp);
         index = index + 1;
      }
   }
   template <class Tset,
             class Targ1,
             class Targ2,
             class Targ3,
             class Targ4,
             class Targ5>
   void write4SetHandleSep(text firstSeparator,
                          text nextSeparator,
                          size_t tabs,
                          Tset set,
                          Targ1 arg1,
                          Targ2 arg2,
                          Targ3 arg3,
                          Targ4 arg4,
                          Targ5 arg5,
                          FILE* fp = stdout)
   {
      if (isEmpty(set) eq false)
      {
         fprintf(fp, "%s%s", firstSeparator, Tab(tabs));
         write4("", tabs, firstElement(set), arg1, arg2, arg3, arg4, arg5, fp);
      }

      size_t index = 1;
      while(index < size(set))
      {
         fprintf(fp, "%s%s", nextSeparator, Tab(tabs));
         write4("", tabs, elementAt(index, set), arg1, arg2, arg3, arg4, arg5, fp);

         index = index + 1;
      }
   }
#endif
