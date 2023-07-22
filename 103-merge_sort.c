#include "sort.h"
void merge(int *l_arr, int *r_arr, int *arr, size_t size);
/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	size_t middle = size / 2;
	int *left_arr, *rigth_arr;
	size_t i_l, i_r;

	if (size <= 1)
		return;

	left_arr = malloc(sizeof(int) * middle);
	if (left_arr == NULL)
		return;
	rigth_arr = malloc(sizeof(int) * (size - middle));
	if (rigth_arr == NULL)
		return;

	for (i_l = 0, i_r = 0; i_l < size; i_l++)
	{
		if (i_l < middle)
			left_arr[i_l] = array[i_l];
		else
		{
			rigth_arr[i_r] = array[i_l];
			i_r++;
		}
	}
	merge_sort(left_arr, middle);
	merge_sort(rigth_arr, size - middle);
	merge(left_arr, rigth_arr, array, size);
	free(left_arr);
	free(rigth_arr);
}
/**
 * merge - merge an array of integers
 * @l_arr: left array
 * @r_arr: rigth array
 * @arr: array
 * @size: size
 */
void merge(int *l_arr, int *r_arr, int *arr, size_t size)
{
	size_t l_size = size / 2, r_size = size - l_size;
	size_t i = 0, l = 0, r = 0;

	printf("Merging...\n[left]: ");
	print_array(l_arr, l_size);
	printf("[right]: ");
	print_array(r_arr, r_size);

	for (; l < l_size && r < r_size; i++)
	{
		if (l_arr[l] < r_arr[r])
		{
			arr[i] = l_arr[l];
			l++;
		}
		else
		{
			arr[i] = r_arr[r];
			r++;
		}
	}
	for (; l < l_size; l++, i++)
		arr[i] = l_arr[l];
	for (; r < r_size; r++, i++)
		arr[i] = r_arr[r];
	printf("[Done]: ");
	print_array(arr, size);
}
