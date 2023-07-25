#include "sort.h"
void quickSort(int *arr, int start, int end, size_t size);
int partition(int *arr, int start, int end, size_t size);
void swap_arr(int *a, int *b);
/**
 * quick_sort_hoare - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm the Hoare partition scheme.
 * @array: array
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quickSort(array, 0, (int)size - 1, size);
}
/**
 * quickSort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @arr: array
 * @start: start of the array
 * @end: the end of the array
 * @size: size of the array
 */
void quickSort(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = partition(arr, start, end, size);
	quickSort(arr, start, pivot - 1, size);
	quickSort(arr, pivot, end, size);
}
/**
 * partition - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @arr: array
 * @start: start of the array
 * @end: the end of the array
 * @size: size of the array
 * Return: the partition
 */
int partition(int *arr, int start, int end, size_t size)
{
	int pivot = arr[end];
	int i = start - 1, j = end + 1;

	while (i < j)
	{
		i++;
		j--;
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
		{
			swap_arr(arr + i, arr + j);
			print_array(arr, size);
		}
	}
	return (i);
}
/**
 * swap_arr - sawp two elements
 * @a: a
 * @b: b
 */
void swap_arr(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

