#include "sort.h"

/**
 * swap_entries - swaps two entries of an array
 * @array: array
 * @i: first value
 * @j: second value
 * Return: void
 */
void swap_entries(int *array, int i, int j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * partial_sort - sorts a partition of data in relation to a pivot
 * @array: data to sort
 * @min: Left wall
 * @max: right wall
 * @size: size of array
 * Return: new pivot
 */
int partial_sort(int *array, int min, int max, size_t size)
{
	int i, j, pivot = array[max];

	for (i = min, j = max; 1; i++, j--)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (i >= j)
			return (i);
		swap_entries(array, i, j);
		print_array(array, size);
	}
}

/**
 * quicksort -  sorts an array of integers in ascending order
 * using the Quick sort algorithm Lomuto partition scheme
 * @array: data to sort
 * @min: Left wall
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
		quicksort(array, p, max, size);
	}
}

/**
 * quick_sort_hoare -  sorts an array of integers in ascending order
 * using the Quick sort algorithm Hoare partition scheme
 * @array: data to sort
 * @size: size of data
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
