#include "sort.h"
/**
 * counting_sort - function that sorts an array of integers
 * in ascending order using the Counting sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *k_arr, *tmp_arr, k, j;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	k = array[i];
	for (; i < size; i++)
		if (array[i] > k)
			k = array[i];


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

	tmp_arr = malloc(size * sizeof(int));
	if (tmp_arr == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		tmp_arr[k_arr[array[i]] - 1] = array[i];
		k_arr[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = tmp_arr[i];

	free(tmp_arr);
	free(k_arr);
}
