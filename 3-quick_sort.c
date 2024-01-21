#include "sort.h"

/**
  * quick_sort - sort an array of integers in ascending order using
  *				the quick sort algorithm
  * @array: array to be sorted
  * @size: elements number in array
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_q_s(array, 0, size - 1, size);
}

/**
  * lomuto - lomuto partition for quick sort
  * @arr: array to be partitioned
  * @start: start index of partition
  * @end: end index of partition
  * @size: elements number in array
  * Return: partition index
  */

int lomuto(int *arr, int start, int end, size_t size)
{
	int pivot, i, j;

	pivot = arr[end];
	i = start - 1;
	for (j = start; j <= end - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&arr[i], &arr[j]);
				print_array(arr, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&arr[i + 1], &arr[end]);
		print_array(arr, size);
	}
	return (i + 1);
}

/**
  * recursive_q_s - recursive for quick sort
  * @arr: array to be sorted
  * @start: start index of partition
  * @end: end index of partition
  * @size: elements number in array
  */

void recursive_q_s(int *arr, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = lomuto(arr, start, end, size);
		recursive_q_s(arr, start, pivot - 1, size);
		recursive_q_s(arr, pivot + 1, end, size);
	}
}

/**
  * swap - swap two integers
  * @a: 1st integer
  * @b: 2nd integer
  */

void swap(int *a, int *b)
{
	int mem = *a;

	*a = *b;
	*b = mem;
}
