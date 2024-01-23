#include "sort.h"

/**
 * swap - function swaps two elements in an array of ints
 * @array: pointer to an array of ints
 * @a: first element index
 * @b: second element index
 */
void swap(int *array, int a, int b)
{
	if (a == b)
		return;
	array[a] ^= array[b];
	array[b] ^= array[a];
	array[a] ^= array[b];
}

/**
 * selection_sort - function sorts array of int
 * @array: array to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, m;

	for (i = 0; i < (size - 1); i++)
	{
		m = i;
		for (j = (1 + i); j < size; j++)
		{
			if (array[j] < array[m])
				m = j;
		}
		if (m != i)
		{
			swap(array, m, i);
			print_array(array, size);
		}
	}
}
