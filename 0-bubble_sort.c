#include "sort.h"
#include <stdbool.h>

/**
 * swap - swaps two integers
 * @x: first integer
 * @y: second integer
 */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using Bubble Sort
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    bool swapped;

    for (i = 0; i < size - 1; i++)
    {
        swapped = false;

        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                print_array(array, size);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

