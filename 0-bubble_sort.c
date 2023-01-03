#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void bubble_sort(int *array, size_t size)
{
	int pos;
	int aux;
	int largo = size - 1;
	int x = 0;

	do {
		for (pos = 0; pos < largo; pos++)
		{
			if (array[pos] > array[pos + 1])
			{
				aux = array[pos];
				array[pos] = array[pos + 1];
				array[pos + 1] = aux;
				print_array(array, size);
			}
		}
		x++;
	} while (x < largo);
}
