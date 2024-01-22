#include "sort.h"
/**
 * insertion_sort_list -  sorts an array of integers in ascending order.
 *@list: list  to be sorted.
 *
 * Return: Nothing.
 */
void insertion_sort_list(listint_t **list)
{
	int i;
	listint_t *current, *prev, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
	{
		return;
	}

	current = (*list)->next;
	while (current != NULL)
	{
		i = current->n;
		prev = current->prev;
		while (prev != NULL && prev->n > i)
		{
			temp = prev->prev;
			if (temp != NULL)
			{
				temp->next = current;
			}
			current->prev = temp;
			prev->next = current->next;
			if (current->next != NULL)
			{
				current->next->prev = prev;
			}
			current->next = prev;
			prev->prev = current;
			if (*list == prev)
			{
				*list = current;
			}
			print_list(*list);
			prev = temp;
		}
		current = current->next;

	}
}
