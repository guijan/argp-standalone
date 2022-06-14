#include <stdio.h>
#include <stdarg.h>

/* Look for "Flags for __v*printf_internal" in glibc/libio/libioP.h to find a
 * comment that explains what the extra __vsnprintf_internal parameter does.
 * The actual implementation ultimately leads to
 * glibc/stdio-common/vfprintf-internal.c so read that for more in-depth
 * information. The TL;DR is that we can ignore mode_flags and use the standard
 * vsnprintf.
 */
int
__vsnprintf_internal (char *s, size_t size, const char *fmt, va_list ap,
		      unsigned int mode_flags)
{
	(void)mode_flags;
	return vsnprintf(s, size, fmt, ap);
}
