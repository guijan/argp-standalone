#if !defined(H_STRCASE)
#define H_STRCASE

#include <config.h>

#if !defined(HAVE_STRCASECMP)
int strcasecmp(const char *, const char *);
#endif

#endif
