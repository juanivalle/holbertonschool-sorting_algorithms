#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sort an array using counting sort
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *countArray, max;
	size_t i;

	if (!array || size < 2)
		return;

	for (i = 1, max = array[0]; i < size; i++)
		if (max < array[i])
			max = array[i];
	countArray = malloc(sizeof(int) * (max + 1));
	if (!countArray)
		exit(98);

	for (i = 0; i < (size_t) max + 1; i++)
		countArray[i] = 0;
	for (i = 0; i < size; i++)
		countArray[array[i]]++;
	for (i = 0; i < (size_t) max; i++)
	{
		if (countArray[i + 1] == 0)
			countArray[i + 1] = countArray[i];
		else
			countArray[i + 1] = countArray[i] + 1;
		printf("%d, ", countArray[i]);
	}
	countArray[max] = size;
	printf("%d\n", countArray[max]);
	CountingSrt(array, countArray, max, size);
	free(countArray);
}

/**
 * CountingSrt - inbetween function to implement counting sort
 * @array: array to sort
 * @countArray: count array, not yet shifted
 * @max: max value of arrar
 * @size: size of array
 *
 * Return: void
 */
void CountingSrt(int *array, int *countArray, int max, size_t size)
{
	int *tmp;
	size_t i;

	for (i = max; i > 0; i--)
		countArray[i] = countArray[i - 1];
	countArray[0] = 0;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
	{
		free(countArray);
		exit(98);
	}

	for (i = 0; i < size; i++)
	{
		tmp[countArray[array[i]]] = array[i];
		countArray[array[i]]++;
	}
	for (i = 0; i < size; i++)
		array[i] = tmp[i];
	free(tmp);
}

