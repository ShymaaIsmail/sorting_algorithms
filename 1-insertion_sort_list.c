#include "sort.h"

/**
* insertion_sort_list - insertion_sort_list
* @list: doubly linked list to be sorted
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	if (*list != NULL)
	{
		listint_t *current = (*list)->next;


		while (current->next != NULL)
		{
			printf("%d\n", current->n);
			if (current->n < current->prev->n)
			{
				print_list(*list);
			}
			current = current->next;
		}
	}
}
