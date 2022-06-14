#include <string.h>

int
strcasecmp (const char *s1, const char *s2)
{
	/* Only Windows doesn't have a strcasecmp() anyway. */
	return _stricmp(s1, s2);
}
