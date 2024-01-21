#include "sort.h"

/**
  * selection_sort - sort an array of integers in ascending order using
  *					the selection sort algorithm
  * @array: array to be sorted
  * @size: elements number in array
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int mem;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			mem = array[i];
			array[i] = array[min_index];
			array[min_index] = mem;

			print_array(array, size);
		}
	}
}
