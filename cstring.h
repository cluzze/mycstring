#ifndef _MY_CSTRING_
#define _MY_CSTRING_

#include <stddef.h>
#include <stdio.h>

void *memcpy(void *dest, const void *src, size_t n);

void *memmove(void *dest, const void *src, size_t n);

void *memchr(const void *s, char c, size_t n);

int memcmp(const void *s1, const void *s2, size_t n);

void *memset(void *s, int c, size_t n);

char *strcat(char *dest, const char *src);

char *strncat(char *dest, const char *src, size_t n);

char *strchr(const char *s, int c);

char *strrchr(const char *s, int c);

int strcmp(const char *s1, const char *s2);

int strncmp(const char *s1, const char *s2, size_t n);

char *strcpy(char *dest, const char *src);

char *strncpy(char *dest, const char *src, size_t n);

size_t strlen(const char *src);

size_t strspn(const char *s, const char *accept);

size_t strcspn(const char *s, const char *reject);

char *strpbrk(const char *s, const char *accept);

char *strstr(const char *haystack, const char *needle);

char *strtok(char *str, const char *delim);

char *strdup(char *s);

char *_fgets(char *s, int size, FILE *stream);

int _fputs(const char *s, FILE *stream);

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

#endif