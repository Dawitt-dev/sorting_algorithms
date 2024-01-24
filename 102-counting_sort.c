#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array in ascending order using Counting sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t j, index;
	int max, *counting_array, i;

	if (array == NULL || size < 2)
		return;

	max = array[0];

	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
		max = array[j];
	}
	counting_array = malloc((max + 1) * sizeof(int));

	if (counting_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (j = 0; j < size; j++)
		counting_array[array[j]]++;
	print_array(counting_array, max + 1);
	index = 0;

	for (i = 0; i <= max; i++)
	{
		while (counting_array[i] > 0)
		{
			array[index++] = i;
			counting_array[i]--;
		}
	}

	free(counting_array);
}
