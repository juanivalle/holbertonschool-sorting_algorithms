#include "sort.h"

/**
 * shell_sort - sorts an array using shell sort
 * (gap sequence used is Knuth sequence)
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h, gap = 1;
	int tmp;

	while (3 * gap + 1 < size)
		gap = 3 * gap + 1;

	while (gap)
	{
		for (h = 0; h < gap; h++)
		{
			for (i = gap + h; i < size; i += gap)
			{
				for (j = i; j >= gap; j -= gap)
					if (array[j] < array[j - gap])
						tmp = array[j], array[j] = array[j - gap], array[j - gap] = tmp;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}

