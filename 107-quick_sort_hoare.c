#include "sort.h"
void quick_sort_hoare(int *array, size_t size);
void HoareQwksrt(int *array, int lo, int hi, size_t size);
int HoarePartition(int *array, int lo, int hi, size_t size);

/**
 * quick_sort_hoare - sort an array using quicksort, Hoare partition
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	HoareQwksrt(array, 0, size - 1, size);
}


/**
 * HoareQwksrt - sort a given range in an array recursively w quicksort
 * @array: array
 * @lo: lower index (from)
 * @hi: higher index (to / until)
 * @size: size of array
 *
 * Return: void
 */
void HoareQwksrt(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = HoarePartition(array, lo, hi, size);
		HoareQwksrt(array, lo, p - 1, size);
		HoareQwksrt(array, p, hi, size);
	}
}

/**
 * HoarePartition - implement hoare partition
 *
 * @array: array
 * @lo: lower index
 * @hi: higher index
 * @size: array size
 *
 * Return: index in which anchor was placed
 */
int HoarePartition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi], swap;
	int i = lo - 1, j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap = array[i], array[i] = array[j], array[j] = swap;
		print_array(array, size);
	}
}
