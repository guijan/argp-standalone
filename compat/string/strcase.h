#if !defined(H_STRCASE)
#define H_STRCASE

#include <config.h>

#if !HAVE_STRCASECMP
#define strcasecmp _stricmp
#endif

#endif
