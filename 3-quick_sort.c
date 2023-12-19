#include "sort.h"

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
	int index = low_indicator;
	int iterator = low_indicator;
	int temp = 0;

	for (iterator = low_indicator; iterator < high_indicator; iterator++)
	{
		if (array[iterator] < pivot)
		{
			temp = array[index];
			array[index] = array[iterator];
			array[iterator] = temp;
			print_array(array, size);
			index++;
		}
	}
	temp = array[index];
	array[index] = array[high_indicator];
	array[high_indicator] = temp;
	return (index);
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
	if (array == NULL || size == 0)
		return;
	if (size >= 2)
	{
		recursive_sort(array, size, 0, size - 1);
	}
}
