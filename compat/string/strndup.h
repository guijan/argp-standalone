#if !defined(H_STRNDUP)
#define H_STRNDUP

#include <config.h>

#if !HAVE_STRNDUP
#include <stddef.h>
char* strndup (const char *, size_t);
#endif

#endif
