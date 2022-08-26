#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define BUF_SIZE 16

#define MYASSERT(condition)																		\
	if (!(condition))																			\
	{																							\
		fprintf(stderr, "Error: %s\nAccured in function: %s, from file: %s, on line: %d\n",		\
			#condition, __PRETTY_FUNCTION__, __FILE__, __LINE__);								\
		abort();																				\
	}			


void printArray(char **arr, int heap_size);

void swap(char **a, char **b)
{
	MYASSERT(a)
	MYASSERT(b)

	char* temp = *a;
	*a = *b;
	*b = temp;
}

int strings_cmp(char *str1, char *str2)
{
	while (*str1++ == *str2++)
		;
	return (unsigned char*)str1 - (unsigned char*)str2;
}

void build_heap(char **arr, int heap_size, int root, int (*cmp)(char *str1, char *str2))
{
	MYASSERT(arr)
	MYASSERT(heap_size >= 0)

	int new_root    = root;
	int left_child  = 2 * root + 1;
	int right_child = 2 * root + 2;

	if (left_child < heap_size && strcmp(arr[left_child], arr[new_root]) > 0)
	{
		new_root = left_child;
	}

	if (right_child < heap_size && strcmp(arr[right_child], arr[new_root]) > 0)
	{
		new_root = right_child;
	}

	if (new_root != root)
	{
		swap(&arr[root], &arr[new_root]);
		printArray(arr, 10);
		build_heap(arr, heap_size, new_root, cmp);
	}
}
 
void heap_sort(char **arr, int heap_size)
{
	MYASSERT(arr)

	for (int i = heap_size / 2 - 1; i >= 0; i--)
	{
		build_heap(arr, heap_size, i, strings_cmp);
	}

	for (int i = heap_size - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		printArray(arr, 10);
		build_heap(arr, i, 0, strings_cmp);
	}
}
 
void printArray(char **arr, int heap_size)
{
	for (int i = 0; i < heap_size; i++)
	{
		for (int j = 0; arr[i][j] != '\0'; ++j)
		{
			switch (arr[i][j])
			{
				case '\r':
					printf("\\r");
					break;
				case '\n':
					printf("\\n");
					break;
				default:
					printf("%c", arr[i][j]);
			}
		}
		printf(" ");
	}
	printf("\n");
}

int main()
{
	char **arr = (char**)calloc(10, sizeof(char*));

	for (int i = 0; i < 10; i++)
	{
		arr[i] = (char*)calloc(10, sizeof(char));
		for (int j = 0; j < 8; j++)
		{
			char c = '0' + rand() % 10;
			arr[i][j] = c;
		}
		if (i != 9)
		{
			arr[i][8] = '\r';
			arr[i][9] = '\n';
		}
	}

	int N = 10;
	printArray(arr, N);
	heap_sort(arr, N);
	printf("Sorted array is\n");
	printArray(arr, N);

	for (int i = 0; i < 10; i++)
	{
		free(arr[i]);
		
	}
	free(arr);

	return 0;
}


