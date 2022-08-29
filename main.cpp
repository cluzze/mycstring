#include <stdlib.h>
#include <stdio.h>

#include "cstring.h"

#define DELIM "ads"
#define TOK_DELIM "()"

#define SIZE 10

int main()
{
	size_t size = SIZE;
	ssize_t read = 0;
	char *line = (char*)calloc(SIZE, sizeof(char));
	read = _getline(&line, &size, stdin);
	printf("read: %ld, line:\n%s\n", read, line);

	free(line);
	return 0;
}







