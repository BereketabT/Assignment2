#include <stddef.h>

#ifndef STR
#define STR

/* Returns the length of string input */
size_t Str_getLength(const char source[]);

/* Copies the string source to dest and returns pointer to dest */
char *Str_copy(char dest[], const char source[]);

/* Concaticates string source to end of string dest and returns pointer to dest */
char *Str_concat(char dest[], const char source[]);

/* Compares the strings str1 and str2 alphabetically. If str1 comes before str2, returns negative number.
   If str1 comes after str2, returns positive number. If the strings are equal, returns 0. */
int Str_compare(const char str1[], const char str2[]);

/* Searches string haystack for first occurance of string needle and returns pointer to first occurance */
char *Str_search (const char haystack[], const char needle[]);

#endif