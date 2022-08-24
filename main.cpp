#include <stdlib.h>
#include <stdio.h>

#include "cstring.h"

#define DELIM "ads"
#define TOK_DELIM "()"

#define SIZE 10

int main()
{
	/*char str[] = "asdbasdasdasd";
	printf("%lu\n", strlen(str));
	char *dest = (char*)calloc(SIZE * 2, sizeof(char));
	memset(dest, 'a', 3);
	printf("before: %s\n", dest);
	strcat(dest, str);
	printf("after: %s\n", dest);

	printf("first occurenes of \'d\' in dest: %s\n", strchr(dest, 'd'));

	char dest2[] = "aaaasdasdasdasd";

	printf("%s =? %s: %d\n", dest, dest2, strcmp(dest, dest2));

	printf("before: %s, ", dest);
	
	strcpy(dest, str);
	
	printf("after: %s\n", dest);

	printf("%lu, %lu\n", strspn(dest, DELIM), strcspn(dest, DELIM));
					 //0000000000111111111122222222223
					 //0123456789012345678901234567890
	char haystack[] = "printf(strspn(dest, DELIM), strcspn(dest, DELIM));";
	char needle[] = "DELIM";

	printf("%s\n", strstr(haystack, needle));

	char *token = NULL;

	printf("\n\n%s\n\n", haystack);

	token = strtok(haystack, TOK_DELIM);
	while (token)
	{
		printf("token: %s\n", token);

		token = strtok(NULL, TOK_DELIM);
	}*/

	fprintf(stdin, "main\n");
	size_t size = 0;
	char *dest = (char*)calloc(SIZE * 2, sizeof(char));
	printf("read: %ld\n", _getline(&dest, &size, stdin));
	_fputs(dest, stdout);

	free(dest);
	return 0;
}







