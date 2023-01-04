#include "sort.h"

/**
 * cocktail_sort_list - sort a doubly linked list using cocktail sort
 * @list: pointer to head of linked list
 *
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tmp, *aux;
	int swaps = 1;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (swaps)
	{
		for (tmp = *list, swaps = 0; tmp->next; tmp = tmp->next)
		{
			aux = tmp->next;
			if (tmp->n > aux->n) /* Swap tmp and tmp->next, swaps = 1 */
			{
				if (tmp->prev)
					tmp->prev->next = aux;
				if (aux->next)
					aux->next->prev = tmp;
				aux->prev = tmp->prev, tmp->prev = aux;
				tmp->next = aux->next, aux->next = tmp;
				print_list(*list), swaps = 1, tmp = aux;
			}
		}
		for (; tmp->prev; tmp = tmp->prev)
		{
			aux = tmp->prev;
			if (tmp->n < aux->n) /* Swap tmp and tmp->prev, swaps = 1 */
			{
				if (tmp->next)
					tmp->next->prev = aux;
				if (aux->prev)
					aux->prev->next = tmp;
				else /* Change head if insert is at the beginning of list */
					*list = tmp;
				aux->next = tmp->next, tmp->prev = aux->prev;
				aux->prev = tmp, tmp->next = aux;
				print_list(*list), swaps = 1, tmp = aux;
			}
		}
	}
}
