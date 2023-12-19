#include "sort.h"

/**
* swap_two_int - swap_two_int
* @a: first int
* @b: second int
*/
void swap_two_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
* partition - partition
* @array: array
* @size: size
* @low_indicator: start index
* @high_indicator: end index
* Return: int of the last element index (new pivot)
*/
int partition(int *array, size_t size, int low_indicator, int high_indicator)
{
	int pivot = array[high_indicator];
	int j = 0;
	int i = low_indicator - 1;

	for (j = low_indicator; j <= high_indicator - 1; j++)

	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap_two_int(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high_indicator])
	{
		swap_two_int(&array[i + 1], &array[high_indicator]);
		print_array(array, size);
	}
	return (i + 1);
}
/**
* recursive_sort - recursive_sort
* @array: array
* @size: size
* @low: low
* @high: high
* Return: nothing
*/
void recursive_sort(int *array, size_t size, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(array, size, low, high);

		recursive_sort(array, size, low, pivot - 1);
		recursive_sort(array, size, pivot + 1, high);
	}
}
/**
* quick_sort - quick_sort
* @array: array of int
* @size: size
* Return: void
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	recursive_sort(array, size, 0, size - 1);
}
