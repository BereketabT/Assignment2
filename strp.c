#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *source);
char *Str_copy(char *dest, const char *source);
char *Str_concat(char *dest, const char *source);
int Str_compare(const char *str1, const char *str2);
char *Str_search (const char *haystack, const char *needle);

size_t Str_getLength(const char *source)
{
    const char *end;
    assert(source != NULL);
    end = source;
    while (*end != '\0')
        end++;
    return (size_t)(end - source);
}

char *Str_copy(char *dest, const char *source)
{
    assert(dest != NULL);
    assert(source != NULL);

    while (1) {
        *dest = *source;
        if (*source == '\0')
            return dest;
        dest++;
        source++;
    }
}

char *Str_concat(char *dest, const char *source)
{
    assert(dest != NULL);
    assert(source != NULL);

    Str_copy((dest + Str_getLength(dest)), source);
    return dest;
}

int Str_compare(const char *clientStr1, const char *clientStr2)
{
    assert(clientStr1 != NULL);
    assert(clientStr2 != NULL);

    char *str1 = clientStr1;
    char *str2 = clientStr2;

    while (*str1 == *str2) {
        if((*str1 == '\0') && (*str2 == '\0'))
            return 0;
        str1++;
        str2++;
    }

    if (*str1 < *str2)
        return -1;
    else
        return 1;
}

char *Str_search (const char *haystack, const char *needle)
{
    assert(haystack != NULL);
    assert(needle != NULL);

    char *searchStart = haystack;
    char *needleStart = needle;

    if (*needle =='\0')
        return haystack;

    while (*haystack != '\0') {
        searchStart = haystack; /* Keeps track of where in the haystack this search starts */
        needle = needleStart;     /* Resets the pointer needle to the start of the needle string */

        while (*haystack == *needle)
        {
            haystack++;
            needle++;
            if (*needle == '\0')
                return haystack;
        }

        haystack++;
    }

    return NULL;
}