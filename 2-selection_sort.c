#include "sort.h"
void swap(int *x, int *y);
/**
 * selection_sort - sorts an array of integers in ascending order.
 *@array: array to be sorted
 *@size: size of the array
 *
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	for (i = 0; i < size; i++)
	{
		min_index = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			swap(&array[i], &array[min_index]);
			print_array(array, size);
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
