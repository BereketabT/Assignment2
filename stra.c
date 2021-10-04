#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char input[])
{
    size_t length = 0;
    assert(input != NULL);

    while (input[length] != '\0')
        length++;

    return length;
}

char *Str_copy(char dest[], const char source[])
{
    size_t i = 0;
    assert(dest != NULL);
    assert(source != NULL);

    while (source[i] != '\0') {
        dest[i] = source[i];
        i++;
    }
    return dest;
}

char *Str_concat(char dest[], const char source[])
{
    assert(dest != NULL);
    assert(source != NULL);

    Str_copy(&dest[Str_getLength(dest)], source);
    return dest;
}

int Str_compare(char str1[], char str2[])
{
    size_t i = 0;
    assert(str1 != NULL);
    assert(str2 != NULL);

    while (str1[i] == str2[i]) {
        if((str1[i] != '\0') && (str2[i] != '\0'))
            return 0;
        i++;
    }

    if (str1[i] < str2[i])
        return -1;
    else
        return 1;
}

char *Str_search (const char str[], const char query[])
{
    size_t i = 0;
    size_t j;
    assert(str != NULL);
    assert(query != NULL);

    while (str[i] != '\0') {
        j = 0;

        while (str[i + j] == query[i + j])
        {
            j++;
            if (query[i + j] == '\0')
                return (char *) &str[i];
        }

        i++;
    }

    return NULL;
}