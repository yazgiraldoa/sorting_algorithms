#include "sort.h"
/**
 * swap_array - function to swap two integers
 * @a: int to swap with b
 * @b: int to swap with a
 * Return: nothing
 */
void swap_array(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, size - 1, size);
}

/**
 * quickSort - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @arr: array of integers
 * @low: Starting Index
 * @high: Ending Index
 * @size: size of the array
 * Return: Nothing
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	int pi = 0;

	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now at right place */
		pi = partition(arr, low, high, size);

		/* partition and after partition */
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * partition - function that sorts an array of integers
 * in ascending order using the Quick sort algorithm
 * @arr: array of integers
 * @low: Starting Index
 * @high: Ending Index
 * @size: size of the array
 * Return: Nothing
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j = 0;

	/**
	 * Index of smaller element and indicates the
	 * right position of pivot found so far
	 */

	for (j = low; j <= high - 1; j++)
	{
		/* If current element is smaller than the pivot */
		if (arr[j] <= pivot)
		{
			/* increment index of smaller element */
			i++;
			swap_array(&arr[i], &arr[j]);
			if (i != j)
				print_array(arr, size);
		}
	}
	swap_array(&arr[i + 1], &arr[high]);
	if (i != j)
		print_array(arr, size);
	return (i + 1);
}
