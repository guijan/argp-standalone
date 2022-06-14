#if !defined(H_STRCHRNUL)
#define H_STRCHRNUL

#include <config.h>

#if !HAVE_STRCHRNUL
char *strchrnul (const char *, int);
#endif

#endif
