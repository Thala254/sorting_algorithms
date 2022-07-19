#include "sort.h"
#include <stdio.h>

/**
 * swap_entries - swaps two entries in an array
 * @array: array to sort
 * @i: first entry
 * @j: second entry
 * @size: size of array
 * Return: No Return
 */
void swap_entries(int *array, int i, int j, int size)
{
	int tmp;

	if (array[i] != array[j])
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}

/**
 * partial_sort - sorts portion of array data in relation to a pivot
 * @array: array to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of array
 * Return: new pivot
 */
int partial_sort(int *array, int min, int max, size_t size)
{
	int i = min, j, pivot = array[max];

	for (j = min; j <= max; j++)
	{
		if (array[j] < pivot)
		{
			swap_entries(array, i, j, size);
			i++;
		}
	}
	swap_entries(array, i, max, size);
	return (i);
}

/**
 * quicksort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 * @array: array to sort
 * @min: left wall
 * @max: right wall
 * @size: size of array
 * Return: void
 */
void quicksort(int *array, int min, int max, size_t size)
{
	int p;

	if (min < max)
	{
		p = partial_sort(array, min, max, size);
		quicksort(array, min, p - 1, size);
		quicksort(array, p + 1, max, size);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending order using the
 * Quick sort algorithm Lomuto partition scheme
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
