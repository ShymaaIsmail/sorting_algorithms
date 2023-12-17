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
		listint_t *temp, *prev_temp;

		while (current != NULL)
		{
			temp = current;
			while (temp->prev != NULL && temp->n < temp->prev->n)
			{
				prev_temp = temp->prev;
				prev_temp->next = temp->next;
				if (temp->next != NULL)
					temp->next->prev = prev_temp;

				temp->next = prev_temp;
				temp->prev = prev_temp->prev;
				prev_temp->prev = temp;
				if (temp->prev != NULL)
					temp->prev->next = temp;
				else
					*list = temp;

				print_list(*list);
			}
			current = current->next;
		}
	}
}
