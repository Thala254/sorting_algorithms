#include <stdio.h>
#include "sort.h"

/**
 * swap_entries - swaps two entries in an array
 * @array: array to sort
 * @i: first entry
 * @j: second entry
 * @size: size of array
 * Return: No Return
 */
void swap_entries(int *array, int i, int j)
{
        int tmp;

        if (array[i] != array[j])
        {
                tmp = array[i];
                array[i] = array[j];
                array[j] = tmp;
        }
}

/**
 * shell_sort -  sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 * @array: The array to sort.
 * @size: Size of the array
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 0,  i, j;

	if (size < 2)
		return;

	while (h <= size / 3)
		h = h * 3 + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
				swap_entries(array, j, j - h);
		h /= 3;
		print_array(array, size);
	}
}
