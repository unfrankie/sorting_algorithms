#include "sort.h"

/**
  * bubble_sort - Sort an array of integers in ascending order using
  *		the Bubble sort algorithm
  * @array: array to be sorted
  * @size: number of elements in array
  */

void bubble_sort(int *array, size_t size)
{
	int mem, swap;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				mem = array[j];
				array[j] = array[j + 1];
				array[j + 1] = mem;
				swap = 1;

				print_array(array, size);
			}
		}

		if (swap == 0)
			break;
	}
}
