#if !defined(H_ARGP)
#define H_ARGP

/*
 * This header sits between argp's user and a verbatim copy of glibc's argp.h.
 * It provides anything glibc's argp.h needs to work outside of glibc.
 */

/* Check out glibc's misc/sys/cdefs.h for __THROW's declaration in glibc.
 * The gist of it is that it's an optimization so we'll just do the low effort
 * but correct thing.
 */
#if !defined(__THROW)
#define __THROW
#endif

/* Related to __THROW. See glibc's misc/sys/cdefs.h. */
#if !defined(__NTH)
#define __NTH(x) x
#endif

#include <argp-standalone/argp.h>

#endif
