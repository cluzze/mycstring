#include "cstring.h"

#include "myassert.h"
#include <stdlib.h>
#include <stdio.h>

#define TABLE_SIZE 256
#define BUF_SIZE 160000

void *memcpy(void *dest, const void *src, size_t n)
{
	MYASSERT(dest)
	MYASSERT(src)

	char* d       = (char*)dest;
	const char* s = (const char*)src;

	while (n--)
		*d++ = *s++;

	return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
	MYASSERT(dest)
	MYASSERT(src)

	char* d       = (char*)dest;
	const char* s = (const char*)src;
	char* temp    = (char*)calloc(n, sizeof(char));

	if (!temp)
	{
		printf("allocation failure! in %s\n", __PRETTY_FUNCTION__);
		exit(EXIT_FAILURE);
	}

	memcpy(temp, s, n);
	memcpy(d, temp, n);

	free(temp);

	return dest;
}

void *memchr(const void *s, char c, size_t n)
{
	MYASSERT(s)

	unsigned char* ls = (unsigned char*)s;
	size_t i          = 0;

	for (i = 0; i < n; ++i)
		if (ls[i] == c)
			return ls + i;

	return NULL;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
	MYASSERT(s1)
	MYASSERT(s2)

	const char* ls1 = (const char*)s1;
	const char* ls2 = (const char*)s2;

	size_t i = 0;

	for (i = 0; i < n; ++i)
	{
		if (ls1[i] != ls2[i])
		{
			return ls1[i] < ls2[i] ? -1 : 1;
		}
	}

	return 0;
}

void *memset(void *s, int c, size_t n)
{
	MYASSERT(s)

	unsigned char* ls = (unsigned char*)s;
	
	while (n--)
	{
		*ls++ = (unsigned char)c;
	}

	return s;
}

char *strcat(char *dest, const char *src)
{
	MYASSERT(dest)
	MYASSERT(src)

	strcpy(dest + strlen(dest), src);

	return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
	MYASSERT(dest)
	MYASSERT(src)

	size_t i = 0;
	size_t j = 0;

	for (i = 0; dest[i] != '\0'; ++i)
		;

	for (j = 0; j < n; ++j, ++i)
	{
		dest[i] = src[j];
	}

	dest[i] = '\0';

	return dest;
}

char *strchr(const char *s, int c)
{
	MYASSERT(s)

	size_t i = 0;

	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == c)
			return (char*)(s + i);

	return NULL;
}

char *strrchr(const char *s, int c)
{
	MYASSERT(s)

	size_t i  = 0;
	char *res = NULL;

	for (i = 0; s[i] != '\0'; ++i)
		if (s[i] == c)
			res = (char*)(s + i);

	return res;
}

int strcmp(const char *s1, const char *s2)
{
	MYASSERT(s1)
	MYASSERT(s2)

	size_t i = 0;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; ++i)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] < s2[i] ? -1 : 1;
		}
	}

	if (s1[i] == '\0' && s2[i] == '\0') return 0;
	if (s1[i] == '\0')					return -1;
	if (s2[i] == '\0')					return 1;

	return 0;
}

int strncmp(const char *s1, const char *s2, size_t n)
{
	MYASSERT(s1)
	MYASSERT(s2)

	size_t i = 0;

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; ++i)
	{
		if (s1[i] != s2[i])
		{
			return s1[i] < s2[i] ? -1 : 1;
		}
	}

	if (s1[i] == '\0' && s2[i] == '\0') return 0;
	if (s1[i] == '\0')					return -1;
	if (s2[i] == '\0')					return 1;

	return 0;
}

char *strcpy(char *dest, const char *src)
{
	MYASSERT(dest)
	MYASSERT(src)

	char *res = dest;

	while(*dest++ = *src++)
		;

	return res;
}

char *strncpy(char *dest, const char *src, size_t n)
{
	MYASSERT(dest)
	MYASSERT(src)

	char *res = dest;

	do
	{
		if (!n--)
			return res;
	} while (*dest++ = *src++);

	while (!n--)
		*dest++ = NULL;

	return res;
}

size_t strlen(const char *src)
{
	MYASSERT(src)

	size_t i = 0;

	for (i = 0; src[i] != '\0'; ++i)
		;

	return i;
}

size_t strspn(const char *s, const char *accept)
{
	MYASSERT(s)
	MYASSERT(accept)

	size_t i = 0;

	int    table[TABLE_SIZE] = {0};

	const unsigned char* us      = (const unsigned char*)s;
	const unsigned char* uaccept = (const unsigned char*)accept;

	for (i = 0; uaccept[i] != '\0'; ++i)
	{
		table[uaccept[i]] = 1;
	}

	for (i = 0; us[i] != '\0' && table[us[i]] == 1; ++i)
		;

	return i;
}

size_t strcspn(const char *s, const char *reject)
{
	MYASSERT(s)
	MYASSERT(reject)

	size_t i = 0;

	int    table[TABLE_SIZE] = {0};

	const unsigned char* us      = (const unsigned char*)s;
	const unsigned char* ureject = (const unsigned char*)reject;

	for (i = 0; ureject[i] != '\0'; ++i)
	{
		table[ureject[i]] = 1;
	}

	for (i = 0; us[i] != '\0' && table[us[i]] != 1; ++i)
		;

	return i;
}

char *strpbrk(const char *s, const char *accept)
{
	MYASSERT(s)
	MYASSERT(accept)

	size_t i = 0;

	int    table[TABLE_SIZE] = {0};

	const unsigned char* us      = (const unsigned char*)s;
	const unsigned char* uaccept = (const unsigned char*)accept;

	for (i = 0; uaccept[i] != '\0'; ++i)
	{
		table[uaccept[i]] = 1;
	}

	for (i = 0; us[i] != '\0' && table[us[i]] == 1; ++i)
		;

	return (char*)(s + i);
}

char *strstr(const char *haystack, const char *needle)
{
	MYASSERT(haystack)
	MYASSERT(needle)

	size_t i = 0;
	size_t j = 0;
	size_t k = 0;

	for (i = 0; haystack[i] != '\0'; ++i)
	{
		j = 0;
		k = i;

		while (haystack[k] != '\0' && needle[j] != '\0' && needle[j++] == haystack[k++])
			;

		if (needle[j] == '\0')
			return (char*)(haystack + i);

		if (haystack[k] == '\0')
			return NULL;
	}

	return NULL;
}

char *strtok(char *str, const char *delim)
{
	MYASSERT(delim)

	static char *begin = NULL;
	char *start_delim  = NULL;
	char *end_delim    = NULL;

	if (str)
		begin = str;
	else if (!begin)
		return NULL;

	start_delim = begin + strcspn(begin, delim);
	end_delim = start_delim + strspn(start_delim, delim);

	*start_delim = '\0';

	str = begin;

	if (start_delim == end_delim)
		begin = NULL;
	else
		begin = end_delim;

	return str;
}

char *strdup(char *s)
{
	MYASSERT(s)

	size_t size = strlen(s) + 1;

	char *dups = (char*)calloc(strlen(s) + 1, sizeof(char));
	strcpy(dups, s);
	dups[size] = '\0';

	return dups;
}

char *_fgets(char *s, int size, FILE *stream)
{
	MYASSERT(s)

	int c     = 0;
	char *str = NULL;

	str       = s;

	if (size - 1 > 0)
		fscanf(stream, "%c", &c);

	while (--size > 0 && c != EOF)
	{
		if ((*str++ = c) == '\n')
			break;
		fscanf(stream, "%c", &c);
	}

	*str = '\0';

	return (c == EOF && str == s) ? NULL : str;
}

int _fputs(const char *s, FILE *stream)
{
	MYASSERT(s)

	int c = 0;

	while (c = *s++)
		fprintf(stream, "%c", c);

	return ferror(stream) ? EOF : 228;
}


ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	MYASSERT(lineptr);
	MYASSERT(n);

	int c = 0;
	ssize_t size = 0;

	if (*n == 0 && *lineptr != NULL)
	{
		fprintf(stderr, "hi\n");
		return -1;
	}

	if (*n == 0 && *lineptr == NULL)
	{
		*n = BUF_SIZE;
		*lineptr = (char*)calloc(*n, sizeof(char));
	}

	MYASSERT(*lineptr);

	fscanf(stream, "%c", &c);

	if (c == EOF)
		return -1;

	size = 0;

	while (c != EOF)
	{
		if (size + 1 >= *n)
		{
			*n *= 2;
			*lineptr = (char*)realloc(*lineptr, *n * sizeof(char));
			MYASSERT(*lineptr);
		}

		(*lineptr)[size++] = c;

		if (c == '\n')
			break;

		fscanf(stream, "%c", &c);
	}

	(*lineptr)[size] = '\0';
	return size;
}