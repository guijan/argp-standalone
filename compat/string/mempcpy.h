#if !defined(H_MEMPCPY)
#define H_MEMPCPY

#include <config.h>

#if !defined(HAVE_MEMPCPY)
#include <stddef.h>
void* mempcpy(void* to, const void* from, size_t size);
#endif

#endif
