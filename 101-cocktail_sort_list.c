#include "sort.h"
#include <stdio.h>

/**
 * swap_node - Swap a node with its previous one.
 * @node: Node to be swapped.
 * @list: Doubly linked list.
 * Return: Return a pointer to the node after the swap.
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *back = node->prev, *current = node;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;

	return (current);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker sort.
 * @list: Pointer to the doubly linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swap_done = 1;

	if (!list || !(*list) || !(*list)->next)
		return;
	node = *list;
	while (swap_done)
	{
		swap_done = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swap_done = 1;
				print_list(*list);
			}

			node = node->next;
		}
		if (!swap_done)
			break;
		swap_done = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swap_done = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}

