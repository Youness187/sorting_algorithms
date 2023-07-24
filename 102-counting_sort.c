#include "sort.h"
/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *k_arr, k, j, tmp;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	k = array[i];
	for (; i < size; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	k_arr = malloc(sizeof(int) * (k + 1));
	if (k_arr == NULL)
		return;

	for (j = 0; j <= k; j++)
		k_arr[j] = 0;

	for (i = 0; i < size ; i++)
		k_arr[array[i]] += 1;

	for (j = 1; j <= k; j++)
		k_arr[j] += k_arr[j - 1];

	print_array(k_arr, k + 1);

	for (i = 0; i < size; i++)
	{
		tmp = array[k_arr[array[i]] - 1];
		array[k_arr[array[i]] - 1] = array[i];
		array[i] = tmp;
	}
	free(k_arr);
}
