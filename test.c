#include <string.h>
#include <stdio.h>

#define TOK_DELIM "()"

int main()
{
	char haystack[] = "printf(strspn(dest, DELIM), strcspn(dest, DELIM));";
	char needle[] = "DELIM";

	char *token = NULL;

	printf("haystack: %s\n", haystack);

	token = strtok(haystack, TOK_DELIM);
	while (token)
	{
		printf("token: %s\n", token);

		token = strtok(NULL, TOK_DELIM);
	}

	return 0;
}