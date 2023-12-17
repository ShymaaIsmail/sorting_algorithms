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
		listint_t *temp, *prev_temp = NULL;

		while (current != NULL)
		{
			printf("%d\n", current->n);
			if (current->prev != NULL && current->n < current->prev->n)
			{
				temp = current;
				prev_temp = current->prev;

				prev_temp->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev_temp;
				temp->prev = prev_temp->prev;
				if (prev_temp->prev != NULL)
					prev_temp->prev->next = temp;
				else
					*list = temp;
				prev_temp->prev = temp;
				temp->next = prev_temp;
				current = prev_temp;
				print_list(*list);
			}
			current = current->next;
		}
	}
}
