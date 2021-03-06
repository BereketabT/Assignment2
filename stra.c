/*--------------------------------------------------------------------*/
/* stra.c                                                             */
/* Author: Bereketab Tessema                                          */
/*--------------------------------------------------------------------*/
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char source[]);
char *Str_copy(char dest[], const char source[]);
char *Str_concat(char dest[], const char source[]);
int Str_compare(const char str1[], const char str2[]);
char *Str_search(const char haystack[], const char needle[]);

size_t Str_getLength(const char source[])
{
    size_t length = 0;
    assert(source != NULL);

    while (source[length] != '\0')
        length++;

    return length;
}

char *Str_copy(char dest[], const char source[])
{
    size_t i = 0;
    assert(dest != NULL);
    assert(source != NULL);

    while (1)
    {
        dest[i] = source[i];
        if (source[i] == '\0')
            return dest;
        i++;
    }
}

char *Str_concat(char dest[], const char source[])
{
    assert(dest != NULL);
    assert(source != NULL);

    Str_copy(&dest[Str_getLength(dest)], source);
    return dest;
}

int Str_compare(const char str1[], const char str2[])
{
    size_t i = 0;
    assert(str1 != NULL);
    assert(str2 != NULL);

    while (str1[i] == str2[i])
    {
        if ((str1[i] == '\0') && (str2[i] == '\0'))
            return 0;
        i++;
    }

    if (str1[i] < str2[i])
        return -1;
    else
        return 1;
}

char *Str_search(const char haystack[], const char needle[])
{
    size_t i = 0;
    size_t j;
    assert(haystack != NULL);
    assert(needle != NULL);

    if (needle[0] == '\0')
        return (char *)haystack;

    while (haystack[i] != '\0')
    {
        j = 0;

        while (haystack[i + j] == needle[j])
        {
            j++;
            if (needle[j] == '\0')
                return (char *)&haystack[i];
        }

        i++;
    }

    return NULL;
}