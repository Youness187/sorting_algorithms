#include "sort.h"
void swap_arr(int *a, int *b);
void sift_down(int *arr, size_t start, size_t end, size_t size);
void heapify(int *arr, size_t size);
/**
 * heap_sort - function that sorts an array of integers
 * in ascending order using the Heap sort algorithm
 * @array: the array
 * @size: the size of the array
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (array == NULL || size < 2)
		return;

	heapify(array, size);
	end = size - 1;

	while (end > 0)
	{
		swap_arr(array + end, array);
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
/**
 * heapify - Build the heap in array a so that largest value is at the root
 * @arr: the array
 * @size: size of the array
 */

void heapify(int *arr, size_t size)
{
	int start = (int)((size - 1) / 2);

	while (start >= 0)
	{
		sift_down(arr, (size_t)start, size - 1, size);
		start--;
	}
}
/**
 * sift_down - sift down the node at index 'start' to the proper place
 * such that all nodes below the start index are in heap order
 * @arr: the array
 * @start: the root element
 * @end: the last element in the array
 * @size: the real size of the array
 */
void sift_down(int *arr, size_t start, size_t end, size_t size)
{
	size_t root = start, child, swap;

	while ((root * 2 + 1) <= end)
	{
		child = root * 2 + 1;
		swap = root;

		if (arr[swap] < arr[child])
			swap = child;
		if (child + 1 <= end && arr[swap] < arr[child + 1])
			swap = child + 1;
		if (swap == root)
			break;
		swap_arr(arr + root, arr + swap);
		print_array(arr, size);
		root = swap;
	}
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

