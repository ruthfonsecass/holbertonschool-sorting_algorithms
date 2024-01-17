#include "sort.h"

/**
 * selection_sort - A sorting algoritm that uses the selection sort method.
 * @array: the array to be printed.
 * @size: number of elements in @array.
 */

void selection_sort(int *array, size_t size)
{
	int tmp;
	size_t min_index;
	size_t j;
	size_t i;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_index])
				min_index = j;

		if (min_index != i)
		{
			tmp = array[i];
			array[i] = array[min_index];
			array[min_index] = tmp;

			print_array(array, size);
		}
	}
}
