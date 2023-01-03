#include "sort.h"
/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: int
 * @size: size_t
 * Return: always 0
 */

void selection_sort(int *array, size_t size)
{
	int pos;
	int com;
	int aux;
	int largo = size - 1;
	int x = 0;

	do {
		for (pos = 0; pos < largo; pos++)
		{
			for (com = pos + 1; com <= largo; com++)
			{	
				if (array[pos] > array[com])
				{
					aux = array[pos];
					array[pos] = array[com];
					array[com] = aux;
					print_array(array, size);
				}
			}
		}
	x++;
	} while (x < largo);
}
