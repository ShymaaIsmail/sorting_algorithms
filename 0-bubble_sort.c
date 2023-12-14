#include "sort.h"

/**
* bubble_sort - apply ascending bubble sorting algorithm
* @array: array of integers
* @size: length of the array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	unsigned long int i;

	int current_elem, prev_elem, is_swapped = 0;

	do {
		is_swapped = 0;
		for (i = 1; i < size; i++)
		{
			current_elem = array[i];
			prev_elem = array[i - 1];
			if (current_elem < prev_elem)
			{
				array[i - 1] = current_elem;
				array[i] = prev_elem;
				is_swapped = 1;
				print_array(array, size);
			}
		}
	} while (is_swapped);

}
