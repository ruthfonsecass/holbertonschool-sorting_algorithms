#include "sort.h"

/**
 * lomuto_partition - Implements the Lomuto partition scheme for quicksort
 * @arr: The array to be sorted
 * @low: The starting index of the segment of the array to be sorted
 * @high: The ending index of the segment of the array to be sorted
 * @size: the size of the array
 *
 * Return: The partitioning index
 */

int lomuto_partition(int *arr, int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low;
	int j;
	int temp;

	for (j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			if (i != j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;

				print_array(arr, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		temp = arr[i];
		arr[i] = arr[high];
		arr[high] = temp;

		print_array(arr, size);
	}

	return (i);
}

/**
 * quick_sort_recursive - A recursive helper function for quick_sort
 * @arr: The array to be sorted
 * @low: The starting index of the current segment
 * @high: The ending index of the current segment
 * @size: the size of the array
 */

void quick_sort_recursive(int arr[], int low, int high, size_t size)
{
	int partitioning_index;

	if (low < high)
	{
		partitioning_index = lomuto_partition(arr, low, high, size);

		quick_sort_recursive(arr, low, partitioning_index - 1, size);
		quick_sort_recursive(arr, partitioning_index + 1, high, size);
	}
}


/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * quicksort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size > 1)
		quick_sort_recursive(array, 0, size - 1, size);
}
