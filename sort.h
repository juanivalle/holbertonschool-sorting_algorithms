#ifndef _SORT_H_
#define _SORT_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void CountingSrt(int *array, int *countArray, int max, size_t size);
void merge_sort(int *array, size_t size);
void mergeArrays(int *ar1, size_t s1,  int *ar2, size_t s2);
void heap_sort(int *array, size_t size);
void SiftDown(int *ar, size_t index, size_t heapSize, size_t arraySize);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


void compare(int *array, int i, int j, int dir, size_t total_size);
void recBitonicSort(int *array, int lo, int cnt, int dir, size_t total_size);
void bitonic_sort(int *array, size_t size);
void bitonicMerge(int *array, int lo, int cnt, int dir, size_t total_size);
#endif
