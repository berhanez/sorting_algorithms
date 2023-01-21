#include "sort.h"
/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sort an array with selection sort algorithm.
 * @array: array of ints
 * @size: ize of the array.
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *least;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		least = array + i;
		for (j = i + 1; j < size; j++)
			least = (array[j] < *least) ? (array + j) : least;

		if ((array + i) != least)
		{
			swap_ints(array + i, least);
			print_array(array, size);
		}
	}
}
