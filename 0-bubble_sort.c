#include "sort.h"

/**
 * bubble_sort - Implements bubble sort algorithms
 * @array: Array of ints to be sorted
 * @size: The size of array to be sorted
 */

voide bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i;
	bool unsorted = true;

	if(!array)
		return false;

	while (unsorted)
	{
		unsorted = false;
		for (i = 0; i < (size - 1); i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				print_array(array, size);
				unsorted = true;
			}
		}
	}
