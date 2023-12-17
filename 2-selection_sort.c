#include "sort.h"

/**
* selection_sort - insertion_sort_list
* @array: array of int
* @size: size
* Return: void
*/
void selection_sort(int *array, size_t size)
{
	unsigned long int current_index, next_index, mini_num_index = 0;
	int temp = 0;

	if (array == NULL || size == 0)
		return;

	for (current_index = 0; current_index < size - 1; current_index++)
	{
		mini_num_index = current_index;
		for (next_index = current_index + 1;
				next_index < size; next_index++)
		{
			if (array[next_index] < array[mini_num_index])
			{
				mini_num_index = next_index;
			}
		}
		if (current_index != mini_num_index)
		{
			temp = array[current_index];
			array[current_index] = array[mini_num_index];
			array[mini_num_index] = temp;
			print_array(array, size);
		}
	}
}
