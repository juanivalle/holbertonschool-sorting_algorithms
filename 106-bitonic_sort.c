#include "sort.h"
#include <stdio.h>

/**
 * bitonic_sort - sort an array of size 2^k using bitonic sort
 * @array: array
 * @size: array size. Of the form 2^k
 *
 * Return: void
 */
void bitonic_sort(int *array, size_t size)
{
	int ascending = 1;

	if (!array || size < 2)
		return;

	recBitonicSort(array, 0, (int) size, ascending, size);
}

/**
 * recBitonicSort - first it generates a bitonic sequence, and then sorts it
 * using BitonicMerge
 * @array: array to sort
 * @lo: initial index from which we're sorting
 * @cnt: number of items in the array to sort
 * @dir: direction in which to sort. 1 = ASCENDING, 0 = DESCENDING
 * @total_size: total size of array... used only for printing
 *
 * Return: void
 */
void recBitonicSort(int *array, int lo, int cnt, int dir, size_t total_size)
{
	int ASCENDING = 1, DESCENDING = 0;
	int k;

	if (cnt > 1)
	{
		k = cnt / 2;
		printf("Merging [%d/%ld] (%s)\n", cnt, total_size, dir ? "UP" : "DOWN");
		print_array(&array[lo], cnt);
		recBitonicSort(array, lo, k, ASCENDING, total_size);
		recBitonicSort(array, lo + k, k, DESCENDING, total_size);
		bitonicMerge(array, lo, cnt, dir);
		printf("Result [%d/%ld] (%s)\n", cnt, total_size,  dir ? "UP" : "DOWN");
		print_array(&array[lo], cnt);
	}
}

/**
 * bitonicMerge - merges a bitonic sequence into a sorted array
 * @array: array which we're merging
 * @lo: initial index in array
 * @cnt: number of items we're sorting
 * @dir: direction of sort. 1 = ASCENDING, 0 = DESCENDING
 *
 * Return: void
 */
void bitonicMerge(int *array, int lo, int cnt, int dir)
{
	int k, i;

	if (cnt > 1)
	{
		k = cnt / 2;
		for (i = lo; i < lo + k; i++)
			compare(array, i, i + k, dir);
		bitonicMerge(array, lo, k, dir);
		bitonicMerge(array, lo + k, k, dir);
	}
}


/**
 * compare - compares two elements in a bitonic sequence. Switches elements
 * if comparison is in accordance with dir
 * @array: arrain in which we have a bitonic seq
 * @i: first index we're comparing
 * @j: second index we're comparing
 * @dir: direction of comparison (1 for ar[i] > ar[j], else 0)
 *
 * Return: void
 */
void compare(int *array, int i, int j, int dir)
{
	int tmp;

	if (dir == (array[i] > array[j]))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
	}
}

