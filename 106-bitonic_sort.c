#include "sort.h"
void swap_arr(int *a, int *b);
void bitonicSort(int *arr, size_t start, size_t end, int d, size_t size);
void bitonic_merge(int *arr, size_t start, size_t end, int d);
/**
 * bitonic_sort - function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: the array
 * @size: the size of the array equals to 2^k
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonicSort(array, 0, size, 1, size);
}
/**
 * bitonicSort - Convert an array of integers into a bitonic sequence
 * @arr: the array
 * @start: the start index
 * @end: the end index
 * @d: The direction to sort
 * @size: the size of the arr
 */
void bitonicSort(int *arr, size_t start, size_t end, int d, size_t size)
{
	size_t k;
	char *str = (d == 1) ? "UP" : "DOWN";

	if (end <= 1)
		return;
	k = end / 2;

	printf("Merging [%lu/%lu] (%s):\n", end, size, str);
	print_array(arr + start, end);

	bitonicSort(arr, start, k, 1, size);
	bitonicSort(arr, start + k, k, 0, size);
	bitonic_merge(arr, start, end, d);

	printf("Result [%lu/%lu] (%s):\n", end, size, str);
	print_array(arr + start, end);
}
/**
 * bitonic_merge - merge a bitonic sequence inside an array of integers
 * @arr: the array
 * @start: the start index
 * @end: the end index
 * @d: The direction to sort
 */
void bitonic_merge(int *arr, size_t start, size_t end, int d)
{
	size_t k, i;

	if (end <= 1)
		return;

	k = end / 2;
	for (i = start; i < start + k; i++)
		if (d == (arr[i] > arr[i + k]))
			swap_arr(arr + i, arr + (i + k));

	bitonic_merge(arr, start, k, d);
	bitonic_merge(arr, start + k, k, d);
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

