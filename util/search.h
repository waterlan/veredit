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

#ifndef search_INCLUDED
#define search_INCLUDED


#include <stdlib.h>

#include "std_macro.h"
#include "structures.h"

#include "intset.h"


   template <class TmatchId,
             class Tset,
             class Tel>
   ssize_t Index(TmatchId matchId,
                 Tset set,
                 bool (*match_f) (TmatchId, Tel),
                 bool state = true,
                 Tel (*elementAt_f) (size_t, Tset) = elementAt,
                 size_t (*size_f) (Tset) = size)
   {
      size_t index = 0;
      while(index < size_f(set))
      {
         if (match_f(matchId, elementAt_f(index, set)) == state)
            return (ssize_t) index;

         index = index + 1;
      }

      return -1;
   }
   template <class TmatchId,
             class Tset,
             class Tel>
   intset Indexes(TmatchId matchId,
                  Tset set,
                  bool (*match_f) (TmatchId, Tel),
                  bool state = true,
                  Tel (*elementAt_f) (size_t, Tset) = elementAt,
                  size_t (*size_f) (Tset) = size)
   {
      intset indexes = NULL;

      size_t index = 0;
      while(index < size_f(set))
      {
         if (match_f(matchId, elementAt_f(index, set)) == state)
         {
            if (indexes == NULL)
               indexes = intsetNew();

            add((int) index, indexes);
         }
         index = index + 1;
      }

      return indexes;
   }
   template <class TmatchId,
             class Tset,
             class Tel>
   size_t matchCount(TmatchId matchId,
                     Tset set,
                     bool (*match_f) (TmatchId, Tel),
                     bool state = true,
                     Tel (*elementAt_f) (size_t, Tset) = elementAt,
                     size_t (*size_f) (Tset) = size)
   {
      size_t count = 0;

      size_t index = 0;
      while(index < size_f(set))
      {
         if (match_f(matchId, elementAt_f(index, set)) == state)
            count = count + 1;

         index = index + 1;
      }

      return count;
   }
   template <class TmatchId,
             class Tset,
             class Tel>
   bool exists(TmatchId matchId,
               Tset set,
               bool (*match_f) (TmatchId, Tel),
               bool state = true,
               Tel (*elementAt_f) (size_t, Tset) = elementAt,
               size_t (*size_f) (Tset) = size)
   {
      size_t index = 0;
      while(index < size_f(set))
      {
         if (match_f(matchId, elementAt_f(index, set)) == state)
            return true;

         index = index + 1;
      }

      return false;
   }
   template <class TmatchId,
             class Tset,
             class Tel>
   bool existsUnique(TmatchId matchId,
                     Tset set,
                     bool (*match_f) (TmatchId, Tel),
                     bool state = true,
                     Tel (*elementAt_f) (size_t, Tset) = elementAt,
                     size_t (*size_f) (Tset) = size)
   {
      bool seenOne = false;

      size_t index = 0;
      while(index < size_f(set))
      {
         if (match_f(matchId, elementAt_f(index, set)) == state)
         {
            if (seenOne)
               return false;
            else
               seenOne = true;
         }
         index = index + 1;
      }

      return seenOne;
   }
   template <class Tsrc,
             class TmatchId,
             class Tdest,
             class Tel>
   void filterAppend(Tsrc src,
                     TmatchId matchId,
                     Tdest dest,
                     bool (*match_f) (TmatchId, Tel),
                     bool state = true,
                     Tel (*elementAt_f) (size_t, Tsrc) = elementAt,
                     void (*add_f) (Tel, Tdest) = add,
                     size_t (*size_f) (Tsrc) = size)
   {
      Tel element;
      size_t index = 0;
      while(index < size_f(src))
      {
         element = elementAt_f(index, src);
         if (match_f(matchId, element) == state)
            add_f(element, dest);

         index = index + 1;
      }
   }
#endif
