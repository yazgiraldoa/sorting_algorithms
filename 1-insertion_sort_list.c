#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of ints in ascending order using Insertion sort algorithm
 * @list: doubly linked list to sort
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *first = NULL, *second = NULL;

	if (!list || !(*list) || !(*list)->next)
		return;

	first = *list;
	while (first)
	{
		if (first->prev != NULL && first->n < first->prev->n)
		{
			*list = swap_list(*list, first, 1);
			second = first;
			first = first->next;

			while (second->prev != NULL)
			{
				if (second->n < second->prev->n)
				{
					*list = swap_list(*list, second, 1);
					continue;
				}
				second = second->prev;
			}
		}
		first = first->next;
	}
}

/**
 * swap_list - Swapping function
 * @node: Node to swap at the following direction
 * @direction: Right is 0, Left is 1
 * @list: list to print
 * Return: Current node
 */

listint_t *swap_list(listint_t *list, listint_t *node, int direction)
{
	listint_t *aux1 = NULL, *aux2 = NULL, *temp = NULL;

	if (direction == 0)
	{
		aux2 = node;
		aux1 = aux2->next;
	}
	else
	{
		aux1 = node;
		aux2 = aux1->prev;
	}

	temp = aux1->next;
	aux1->next = aux2;
	aux1->prev = aux2->prev;
	if (aux2->prev != NULL)
		aux2->prev->next = aux1;
	else
		list = aux1;
	aux2->next = temp;
	aux2->prev = aux1;
	if (temp != NULL)
		temp->prev = aux2;

	print_list((const listint_t *) list);
	return (list);
}
