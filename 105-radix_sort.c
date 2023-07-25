#include "sort.h"
void counting_radix(int *arr, size_t size, int d);
/**
 * radix_sort - function that sorts an array of integers
 * in ascending order using the Radix sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, d;
	size_t i;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (d = 1; max / d > 0; d *= 10)
	{
		counting_radix(array, size, d);
		print_array(array, size);
	}
}
/**
 * counting_radix - sort the significant digits of an arr in ascending
 * order using the counting sort algorithm
 * @arr: the array
 * @size: the size of the array
 * @d: The significant digit
 */
void counting_radix(int *arr, size_t size, int d)
{
	int k_arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int *tmp;
	size_t i;

	tmp = malloc(sizeof(int) * size);
	if (tmp == NULL)
		return;

	for (i = 0; i < size; i++)
		k_arr[(arr[i] / d) % 10]++;

	for (i = 1; i < 10; i++)
		k_arr[i] += k_arr[i - 1];

	for (i = size; i > 0 ; i--)
	{
		tmp[k_arr[(arr[i - 1] / d) % 10] - 1] = arr[i - 1];
		k_arr[(arr[i - 1] / d) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = tmp[i];

	free(tmp);
}

