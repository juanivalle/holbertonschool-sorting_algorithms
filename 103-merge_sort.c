#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * merge_sort - sort an array using mergesort
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t half = size / 2, odd = size % 2;

	if (size == 1)
		return;

	merge_sort(array, half);
	merge_sort(&array[half], half + odd);
	mergeArrays(array, half, &array[half], half + odd);
}

/**
 * mergeArrays - merge (in-place) two sorted arrays
 * @ar1: first array (left)
 * @s1: size of first array
 * @ar2: second array (right)
 * @s2: size of second array
 *
 * Return: void
 * Note: the function assumes the arrays are next to each other
 */
void mergeArrays(int *ar1, size_t s1,  int *ar2, size_t s2)
{
	int *tmp;
	size_t i, j;

	tmp = malloc(s1 + s2);
	if (!tmp)
		return;

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < s1; i++)
		(i != s1 - 1) ? printf("%d, ", ar1[i]) : printf("%d\n", ar1[i]);
	printf("[right]: ");
	for (i = 0; i < s2; i++)
		(i != s2 - 1) ? printf("%d, ", ar2[i]) : printf("%d\n", ar2[i]);

	for (i = 0, j = 0; i + j < s1 + s2;)
	{
		if (i < s1 && j < s2)
		{
			if (ar1[i] < ar2[j])
				tmp[i + j] = ar1[i], i++;
			else
				tmp[i + j] = ar2[j], j++;
		}
		else if (i < s1)
			tmp[i + j] = ar1[i], i++;
		else
			tmp[i + j] = ar2[j], j++;
	}
	for (i = 0; i < s1 + s2; i++)
		ar1[i] = tmp[i];
	free(tmp);
	printf("[Done]: ");
	for (i = 0; i < s1 + s2; i++)
		(i != s1 + s2 - 1) ? printf("%d, ", ar1[i]) : printf("%d\n", ar1[i]);
}
