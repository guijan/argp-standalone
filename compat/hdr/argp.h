#if !defined(H_ARGP)
#define H_ARGP

/*
 * This header sits between argp's user and a verbatim copy of
 * glibc/argp/argp.h. It provides anything glibc's argp.h needs to work outside
 * of glibc.
 */

/* Check out glibc/misc/sys/cdefs.h for __THROW's declaration.
 * The gist of it is that it's an optimization so we'll just do the low effort
 * but correct thing.
 */
#undef __THROW
#define __THROW

/* Related to __THROW. See glibc/misc/sys/cdefs.h */
#undef __NTH
#define __NTH(x) x

/* C++ needs to know that types and declarations are C, not C++.
 * glibc/misc/sys/cdefs.h
 */
#undef __BEGIN_DECLS
#undef __END_DECLS
#ifdef __cplusplus
# define __BEGIN_DECLS	extern "C" {
# define __END_DECLS	}
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif

#include <argp-standalone/argp.h>

#endif
