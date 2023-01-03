#include "sort.h"
void quicksrt(int *array, size_t lo, size_t hi, size_t size);
size_t partition(int *array, size_t lo, size_t hi, size_t size);

/**
 * quick_sort - sort an array using quicksort
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;

	quicksrt(array, 0, size - 1, size);
}


/**
 * quicksrt - sort a given range in an array recursively w quicksort
 * @array: array
 * @lo: lower index (from)
 * @hi: higher index (to / until)
 * @size: size of array
 *
 * Return: void
 */
void quicksrt(int *array, size_t lo, size_t hi, size_t size)
{
	size_t p;

	if (lo >= hi)
		return;

	p = partition(array, lo, hi, size);

	if (p > 0)
		quicksrt(array, lo, p - 1, size);
	quicksrt(array, p + 1, hi, size);
}

/**
 * partition - set last index in array as anchor and place all elements
 * lower than it at the start of the array. Then, place anchor at
 * following spot (anchor will be in sorted order)
 *
 * @array: array
 * @lo: lower index
 * @hi: higher index
 * @size: array size
 *
 * Return: index in which anchor was placed
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot = array[hi], tmp;
	size_t i = lo, j;

	for (j = i; j < hi; j++)
	{
		if (i == j && array[j] <= pivot)
			i++;
		else if (array[j] <= pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			i++;
			print_array(array, size);
		}
	}
	if (hi != i)
	{
		array[hi] = array[i];
		array[i] = pivot;
		print_array(array, size);
	}
	return (i);
}
