#include "sort.h"

/**
 * lomutoPartition - Implements the Lomuto partition scheme for quicksort
 * @arr: The array to be sorted
 * @low: The starting index of the segment of the array to be sorted
 * @high: The ending index of the segment of the array to be sorted
 * @size: the size of the array
 *
 * Return: The partitioning index
 */

int lomutoPartition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = low;
	int j;
	int tmp;
	(void) size;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
		}
	}
	tmp = arr[i];
	arr[i] = arr[high];
	arr[high] = tmp;

	return (i);
}


/**
 * quickSortRecursive - A recursive helper function for quick_sort
 * @arr: The array to be sorted
 * @low: The starting index of the current segment
 * @high: The ending index of the current segment
 * @size: the size of the array
 */

void quickSortRecursive(int arr[], int low, int high, size_t size)
{
	int partitioning_index;

	if (low < high)
	{
		partitioning_index = lomutoPartition(arr, low, high, size);

		quickSortRecursive(arr, low, partitioning_index - 1, size);
		print_array(arr, size);
		quickSortRecursive(arr, partitioning_index + 1, high, size);
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
		quickSortRecursive(array, 0, size - 1, size);
	print_array(array, size);
}

