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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>

#include "structures.h"
#include "std_macro.h"

#include "text.h"
#include "version.h"

static text GetDate(void)
{
   time_t t    = time(NULL);
   rwtext   date = ctime(&t);

   if (date[strlen(date) - 1] eq '\n')  /* should always be true... */
      date[strlen(date) - 1] = '\0';    /* remove trailing '\n' */

  return date;
}

expfun text userName(void)
{  
   text t = getlogin();

   if (t eq NULL)
   {  
/***********************************************************************************
 * I have not found a solution to link MPC staticly and the system functions get*()
 * dynamicly with gcc on a SunOS sparc system.
 * See also ../Config.h
 * Erwin Waterlander
 ***********************************************************************************/
#ifdef sparc
      struct passwd *pw;
      pw = NULL;
#else
      struct passwd *pw = getpwuid(getuid());
#endif
      if (pw eq NULL)
      {
         if ((t = getenv("LOGNAME")) == NULL)
            return "Unknown Artist";
         else
            return t;
      }
      else
         return pw->pw_name;
   }
   else
      return t;
}   

/*
expfun text realName(void)
{  

#ifdef sparc
      struct passwd *pw;
      pw = NULL;
#else
    struct passwd *pw = getpwuid(getuid());
#endif
      if (pw eq NULL)
         return "";
      else
         return pw->pw_gecos;
}   
*/

expfun void writeHeader(FILE *fp)
{
   fprintf(fp,"// veredit version : %s (%s)\n",VEREDIT_VERSION, VEREDIT_DATE);
   fprintf(fp,"// creation date   : %s\n",GetDate());
   fprintf(fp,"// user            : %s\n",userName());
// fprintf(fp,"// real name       : %s\n",realName());
   fprintf(fp,"\n");
}


