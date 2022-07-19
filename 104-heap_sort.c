#include "sort.h"

/**
 * swap_entries - swaps 2 values of an array.
 * @array: the array
 * @i: First index
 * @j: Second index
 * @r_size: The size constant for print
 * Return: void
 */
void swap_entries(int *array, int i, int j, const int r_size)
{
	int tmp;
	(void) r_size;

	if (i != j)
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, (size_t)r_size);
	}
}

/**
 * _largest - Find the largest number btween the layers
 * @array: The array for sort
 * @size: The minor element
 * @i: The largest.
 * @r_size: The size for print in swap
 * Return: void
 */
void _largest(int *array, size_t size, int i, const int r_size)
{
	int largest = i;
	int lft = (2 * i) + 1;
	int rgt = (2 * i) + 2;

	if (lft < (int)size && array[lft] > array[largest])
		largest = lft;

	if (rgt < (int)size && array[rgt] > array[largest])
		largest = rgt;

	if (largest != i)
	{
		swap_entries(array, i, largest, r_size);
		_largest(array, size, largest, r_size);
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order using the
 * Heap sort algorithm
 * @array: The array
 * @size: Size of the array
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	const int r_size = (const int)size;
	int i;

	if (size < 2 || !array)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		_largest(array, size, i, r_size);
	for (i = size - 1; i >= 0; i--)
	{
		swap_entries(array, 0, i, r_size);
		_largest(array, i, 0, r_size);
	}
}
