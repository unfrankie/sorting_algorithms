#include "sort.h"

/**
  * insertion_sort_list - sort a doubly linked list of integers in ascending
  *					order using the Insertion sort algorithm
  * @list: head pointer of the doubly linked list
  */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (current != NULL)
	{
		listint_t *mem = current;

		while (mem->prev != NULL && mem->n < mem->prev->n)
		{
			mem->prev->next = mem->next;
			if (mem->next != NULL)
				mem->next->prev = mem->prev;
			mem->next = mem->prev;
			mem->prev = mem->prev->prev;
			mem->next->prev = mem;

			if (mem->prev == NULL)
				*list = mem;

			print_list(*list);
		}

		current = current->next;
	}
}
