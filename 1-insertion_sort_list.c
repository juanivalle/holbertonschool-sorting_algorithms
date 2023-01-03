#include "sort.h"

/**
 * insertion_sort_list - sort a linked list using insertion sort
 * @list: list head pointer
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *node, *tmp;

	if (!list || !(*list))
		return;

	for (head = *list, node = *list; node; node = node->next)
	{
		if (node->prev)
		{
			if (node->n >= node->prev->n) /* nothing to do */
				continue;

			tmp = node->prev;
			while (tmp && node->n < tmp->n)
			{
				tmp->next = node->next;
				node->prev = tmp->prev;
				if (node->next)
					node->next->prev = tmp;
				if (tmp->prev)
					tmp->prev->next = node;
				else
					head = node, *list = node;
				tmp->prev = node;
				node->next = tmp;
				tmp = node->prev;
				print_list(head);
			}

		}
	}
}
