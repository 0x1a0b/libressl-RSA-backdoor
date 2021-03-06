/*
 * Public domain
 * stdio.h compatibility shim
 */

#ifndef LIBCRYPTOCOMPAT_STDIO_H
#define LIBCRYPTOCOMPAT_STDIO_H

#ifdef _MSC_VER
#if _MSC_VER >= 1900
#include <../ucrt/stdlib.h>
#include <../ucrt/corecrt_io.h>
#include <../ucrt/stdio.h>
#else
#include <../include/stdio.h>
#endif
#else
#include_next <stdio.h>
#endif

#ifndef HAVE_ASPRINTF
#include <stdarg.h>
int vasprintf(char **str, const char *fmt, va_list ap);
int asprintf(char **str, const char *fmt, ...);
#endif

#ifdef _WIN32

void posix_perror(const char *s);
FILE * posix_fopen(const char *path, const char *mode);
int posix_rename(const char *oldpath, const char *newpath);

#ifndef NO_REDEF_POSIX_FUNCTIONS
#define perror(errnum) posix_perror(errnum)
#define fopen(path, mode) posix_fopen(path, mode)
#define rename(oldpath, newpath) posix_rename(oldpath, newpath)
#endif

#ifdef _MSC_VER
#define snprintf _snprintf
#endif

#endif

#endif
