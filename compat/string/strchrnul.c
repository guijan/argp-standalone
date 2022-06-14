/* Written by Niels Moeller <nisse@lysator.liu.se>
 *
 * This file is hereby placed in the public domain.
 */

char*
strchrnul(const char* s, int c)
{
    const char* p = s;
    while (*p && (*p != c))
        p++;

    return (char*) p;
}
