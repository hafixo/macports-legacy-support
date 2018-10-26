
#ifndef _MACPORTS_STDIO_H_
#define _MACPORTS_STDIO_H_

// Include the primary system time.h
#include_next <stdio.h>

// MP support header
#include "MacportsLegacySupport.h"

// strnlen
#if __MP_LEGACY_SUPPORT_GETLINE__
#ifdef __cplusplus
extern "C" {
#endif
  extern ssize_t getline(char **lineptr, size_t *n, FILE *stream);
#ifdef __cplusplus
}
#endif
#endif

#endif // _MACPORTS_STDIO_H_
