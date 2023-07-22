#include "sort.h"
/**
 * shell_sort - function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, i, j;
	int tmp;

	if (size < 2)
		return;

	while (gap <= size / 3)
		gap = gap * 3 + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j] < array[j - gap]; j -= gap)
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
			}
		}
		gap = gap / 3;
		print_array(array, size);
	}
}

