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
	int *pivot, i, j;

	pivot = arr + end;
	for (i = j = start; j < end; j++)
	{
		if (arr[j] < *pivot)
		{
			if (i < j)
			{
				swap(arr + j, arr + i);
				print_array(arr, size);
			}
			i++;
		}
	}
	if (arr[i] > *pivot)
	{
		swap(arr + i, pivot);
		print_array(arr, size);
	}
	return (i);
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
