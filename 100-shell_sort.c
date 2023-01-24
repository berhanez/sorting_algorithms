#include "sort.h"
/**
 * swap_ints - Swap 2 ints
 * @a: 1st int
 * @b: 2nd int
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * shell_sort - Sort with shell sort algorithm.
 * @array: array of ints.
 * @size: size of the array.
 * Description: Uses the Knth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t space, i, j;

	if (array == NULL || size < 2)
		return;

	for (space = 1; space < (size / 3);)
		space = space * 3 + 1;

	for (; space >= 1; space /= 3)
	{
		for (i = space; i < size; i++)
		{
			j = i;
			while (j >= space && array[j - space] > array[j])
			{
				swap_ints(array + j, array + (j - space));
				j -= space;
			}
		}
		print_array(array, size);
	}
}
