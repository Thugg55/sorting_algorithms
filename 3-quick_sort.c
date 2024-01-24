#include "sort.h"

/**
 * swap - function swaps two integers
 * @a: The first integer
 * @b: The second integer
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}


/**
 * partition - divides the array into partitions of two
 * @array: The array
 * @low: The lower bound index
 * @high: The upper bound index
 * @size: The size of the original array
 * Return: The Privot index
 */

int partition(int *array, int low, int high, size_t size)
{
	int *piv;
	int up, down;

	piv = &array[high];
	for (up = down = low ; down < high; down++)
	{
		if (array[down] < *piv)
		{
			if (up < down)
			{
				swap(array + down, array + up);
				print_array(array, size);
			}
			up++;
		}
	}
	if (array[up] > *piv)
	{
		swap(array + up, piv);
		print_array(array, size);
	}
	return (up);
}


/**
 * sort - function of recursive quick sort
 * @array: The array
 * @low: the lower bound index
 * @high: the upper ound index
 * @size: The size of array to be divided
 */

void sort(int *array,int low, int high, size_t size)
{
	int x;

	if (low >= high || low < 0)
		return;
	x = partition(array, low, high, size);

	sort(array, low, x-1, size);
	sort(array, x+1, high, size);
}


/**
 * quick_sort - function activates the quick sort algorithm
 * @array: The array to be sorted
 * @size: the size if the array
 */

void quick_sort(int *array, size_t size)
{
	int high = (int)size;

	if (array == NULL || size > 2)
	{
		return;
	}

	sort(array, 0, high - 1, size);
}
