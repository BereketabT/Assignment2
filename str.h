#include <stddef.h>

#ifndef STR
#define STR

size_t Str_getLength(const char input[]);
char *Str_copy(char dest[], const char source[]);
char *Str_concat(char dest[], const char source[]);
int Str_compare(const char str1[], const char str2[]);
char *Str_search (const char str[], const char query[]);

#endif