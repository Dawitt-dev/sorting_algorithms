#include "sort.h"
#include <stdbool.h>
void swap(int *x, int *y);
/**
 * bubble_sort -  sorts an array of integers in ascending order.
 *@array: array to be sorted.
 *@size: size of the array.
 *
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swapped = 1;
			}

		}

		print_array(array, size);

		if (!swapped)
		{
			break;
		}
	}
}
/**
 * swap - swaps to intigers in an array.
 *@x: integer to be swaped
 *@y: integer to be swaped
 * Return: None
 */
void swap(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}
