#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 *               using the Bubble sort algorithm
 * @array: array
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	int tmp, bool = 0;
	size_t i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				bool = 1;
				print_array(array, size);
			}
		}
		if (bool == 0)
			break;
		bool = 0;
	}
}

