#include "sort.h"
void _quickSort(int *arr, int start, int end, size_t size);
int partition(int *arr, int start, int end, size_t size);
/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	_quickSort(array, 0, (int)size - 1, size);
}
/**
 * _quickSort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @arr: array
 * @start: start of the array
 * @end: the end of the array
 * @size: size of the array
 */
void _quickSort(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (end <= start)
		return;

	pivot = partition(arr, start, end, size);
	_quickSort(arr, start, pivot - 1, size);
	_quickSort(arr, pivot + 1, end, size);
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
	int pivot = arr[end], tmp;
	int i = start - 1, j = start;

	for (; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			if (i + 1 != j)
			{
				i += 1;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				print_array(arr, size);
			}
			else
				i += 1;
		}
	}
	i += 1;
	if (arr[i] > arr[end])
	{
		tmp = arr[i];
		arr[i] = arr[end];
		arr[end] = tmp;
		print_array(arr, size);
	}
	return (i);
}
