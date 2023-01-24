#include "sort.h"

/**
 * swap_ints - Swaps 2 ints in an array
 * @a: 1st int.
 * @b: 2nd int.
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - get subset of array of ints by
 * the lomuto partition scheme (last element as piv).
 * @array: array of ints.
 * @size: size of array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: final partition index.
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *piv, above, under;

	piv = array + right;
	for (above = under = left; under < right; under++)
	{
		if (array[under] < *piv)
		{
			if (above < under)
			{
				swap_ints(array + under, array + above);
				print_array(array, size);
			}
			above++;
		}
	}
	if (array[above] > *piv)
	{
		swap_ints(array + above, piv);
		print_array(array, size);
	}
	return (above);
}

/**
 * lomuto_sort - Implement quicksort algorithm through recursion.
 * @array: array of ints to sort.
 * @size: size of array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 * Description: Uses Lomuto partition scheme.
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int pt;

	if (right - left > 0)
	{
		pt = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, pt - 1);
		lomuto_sort(array, size, pt + 1, right);
	}
}

/**
 * quick_sort - Sort an array of ints.
 * @array: An array of integers.
 * @size: The size of the array.
 * Description: Prints array after each swap elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
