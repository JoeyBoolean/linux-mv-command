/*
 * File: tlpi_hdr.h -- header file used by most example programs
                    -- listing 3-1 of the textbook
 */
#ifndef TLPI_HDR_H
#define TLPI_HDR_H      /* Prevent accidental double inclusion */

#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXT_SUCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system class */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */

#include "get_num.h"   /* Declares our functions for handling numeric
                          arguments (getInt() and getLong()) */

#include "error_functions.h" /* Declares our error-handling functions */

typedef enum { FALSE, TRUE } Boolean;

#define min(m,n)  ((m) < (n) ? (m) : (n))
#define max(m,n)  ((m) > (n) ? (m) : (n))

#endif

