#include "sort.h"
/**
 * selection_sort - function that sorts an array of integers
 * in ascending order using the Selection sort algorithm
 * @array: array
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int tmp, tmp_n;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		tmp = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[tmp] > array[j])
				tmp = j;
		}
		if (array[i] != array[tmp])
		{
			tmp_n = array[tmp];
			array[tmp] = array[i];
			array[i] = tmp_n;
			print_array(array, size);
		}
	}
}

