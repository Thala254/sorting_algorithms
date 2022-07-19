#include "sort.h"
#include <stdio.h>

/**
 * _bigest -  returns the largest number in a array of integers
 * @array: Integer array
 * @size: Size of array
 * Return: The largest number
 */
int _bigest(int *array, size_t size)
{
	size_t i;
	int k = 0;

	for (i = 0; i < size; i++)
	{
		if (k < array[i])
			k = array[i];
	}
	return (k);
}

/**
 * _memset -  Create a integer array with 0 as its entries
 * @size: Size of array
 * Return: The integer array
 */
int *_memset(int size)
{
	int *ptr = NULL;
	int i;

	ptr = malloc((size) * sizeof(int));
	for (i = 0; i < size; i++)
		ptr[i] = 0;
	return (ptr);
}

/**
 * counting_sort -  sorts an array of integers in ascending order using
 * the Counting sort algorithm
 * @array: Integer array
 * @size: Size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int k = 0;
	int *ptr = NULL, *sorted_arr = NULL;

	if (size < 2)
		return;
	k = _bigest(array, size);
	ptr = _memset(k + 1);
	if (!ptr)
		return;
	for (i = 0; i < size; i++)
		for (j = 0; (int)j < k + 1; j++)
			if ((int)j == array[i])
				ptr[j] += 1;
	for (i = 0; (int)i < k; i++)
		ptr[i + 1] = ptr[i] + ptr[i + 1];
	print_array(ptr, k + 1);
	sorted_arr = malloc(size * sizeof(int));
	if (!sorted_arr)
	{
		free(ptr);
		return;
	}
	for (i = 0; i < size; i++)
	{
		sorted_arr[ptr[array[i]] - 1] = array[i];
		ptr[array[i]] -= 1;
	}
	for (j = 0; j < size; j++)
		array[j] = sorted_arr[j];
	free(sorted_arr);
	free(ptr);
}
