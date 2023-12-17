#include "sort.h"

/**
* insertion_sort_list - insertion_sort_list
* @list: doubly linked list to be sorted
* Return: void
*/
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	if (*list != NULL)
	{
		listint_t *current = (*list)->next;
		listint_t *temp, *prev_temp, *sorted_current = NULL;

		while (current != NULL)
		{
			if (current->prev != NULL && current->n < current->prev->n)
			{
				temp = current;
				prev_temp = current->prev;
				prev_temp->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev_temp;
				sorted_current = prev_temp;
				while (sorted_current->prev != NULL && sorted_current->prev->n > temp->n)
				{
					sorted_current = sorted_current->prev;
				}

				temp->prev = sorted_current->prev;
				if (sorted_current->prev != NULL)
					sorted_current->prev->next = temp;
				else
					*list = temp;
				sorted_current->prev = temp;
				temp->next = sorted_current;
				current = prev_temp;
				print_list(*list);
			}
			current = current->next;
		}
	}
}
