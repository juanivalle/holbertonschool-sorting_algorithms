#include "sort.h"

/**
 * radix_sort - sort an array using radix sort (LSD)
 * @array: array
 * @size: size of array
 *
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	size_t i, j;
	int countArray[10] = { 0 },
	    powers[10] = {
		    1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000
	    },
	    digit, *tmp, flag = 0;

	if (!array || size < 2)
		return;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		exit(98);

	for (j = 0; j < 10 && !flag; j++)
	{
		for (i = 0; i < size; i++) /* Set up counting array */
			digit = (array[i] / powers[j]) % 10, countArray[digit]++;
		for (i = 1; i < size; i++) /* Make array cummulative */
			countArray[i] += countArray[i - 1];
		for (i = size; (int) i != 0; i--) /* Shift array to the right */
			countArray[i] = countArray[i - 1];
		countArray[0] = 0;
		for (i = 0; i < size; i++) /* Insert sorted values in tmp */
		{
			digit = (array[i] / powers[j]) % 10;
			tmp[countArray[digit]] = array[i];
			countArray[digit]++;
		}
		if (countArray[0] == (int) size)
			break;
		for (i = 0; i < size; i++) /* Copy what's on tmp to array */
		{
			(array[i] != tmp[i]) ? array[i] = tmp[i] : 0;
			(i < 10) ? countArray[i] = 0 : 0;
		}
		print_array(array, size);
	}
	free(tmp);
}

