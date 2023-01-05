#include "sort.h"

/**
 * heap_sort - sort an array using heap sort
 * @array: array
 * @size: array size
 *
 * Return: void
 */
void heap_sort(int *array, size_t size)
{
	size_t i, heapSize = size;
	int tmp;

	if (!array || size < 2)
		return;

	for (heapSize = size; heapSize > 1; heapSize--)
	{
		for (i = heapSize / 2 - 1; (int) i >= 0; i--)
			SiftDown(array, i, heapSize, size);

		tmp = array[0];
		array[0] = array[heapSize - 1];
		array[heapSize - 1] = tmp;
		print_array(array, size);
	}
}

/**
 * SiftDown - sift down funciton to sort the heap, given as an array
 * @ar: heap array, with heap not balanced
 * @index: index in the array to whiich we apply sift down
 * @heapSize: size of heap
 * @arraySize: array size (used for printing)
 *
 * Return: void
 */
void SiftDown(int *ar, size_t index, size_t heapSize, size_t arraySize)
{
	size_t left = 2 * index + 1,
	       right = 2 * index + 2,
	       greater;
	int tmp;

	while ((left < heapSize && ar[index] < ar[left])
			|| (right < heapSize && ar[index] < ar[right]))
	{
		if (right < heapSize)
			greater = (ar[left] > ar[right]) ? left : right;
		else
			greater = left;

		tmp = ar[index], ar[index] = ar[greater], ar[greater] = tmp;
		print_array(ar, arraySize);
		index = greater;
		left = 2 * index + 1, right = 2 * index + 2;
	}
}
