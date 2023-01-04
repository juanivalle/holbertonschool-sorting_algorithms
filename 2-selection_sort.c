#include "sort.h"

/**
 * selection_sort - sort an array using selection sort
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int min, index;

	if (!array)
		return;

	for (i = 0; i < size; i++)
	{
		for (min = array[i], index = i, j = i + 1; j < size; j++)
		{
			if (min > array[j])
				min = array[j], index = j;
		}
		if (array[i] > min)
		{
			array[index] = array[i];
			array[i] = min;
			print_array(array, size);
		}
	}
}
