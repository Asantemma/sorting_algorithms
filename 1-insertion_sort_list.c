#include "sort.h"

/**
* insertion_sort_list - Sorts a doubly linked list of integers in ascending
* order using the Insertion sort algorithm.
*
* @list: A double pointer to the head of the list.
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		sorted = current->prev;
		while (sorted && sorted->n > current->n)
		{
			temp = sorted->prev;
		if (temp)
			temp->next = current;
		else
			*list = current;
		sorted->prev = current;
		sorted->next = current->next;
		current->prev = temp;
		if (current->next)
		current->next->prev = sorted;
		current->next = sorted;
		print_list(*list);
		sorted = current->prev;
		}
		current = current->next;
	}
}
