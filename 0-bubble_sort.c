#include "sort.h"

/**
 * bubble_sort - s a simple sorting algorithm that repeatedly
 * steps through the input list element by element
 * @array: the array to be printed.
 * @size: number of elements in @array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0;
	size_t j = 0;
	size_t tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
		if (array[j] > array[j + 1])
		{
			tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;

			print_array(array, size);
		}
}
