#include "sort.h"
/**
 * get_max - Get maximum value in an array
 * @array: An array of ints
 * @size: size of the array
 * Return: maximum int in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - Sort using the counting sort algorithm.
 * @array: array of integers.
 * @size: size of the array.
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int *ct, *sort, max, i;

	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	ct = malloc(sizeof(int) * (max + 1));
	if (ct == NULL)
	{
		free(sort);
		return;
	}

	for (i = 0; i < (max + 1); i++)
		ct[i] = 0;
	for (i = 0; i < (int)size; i++)
		ct[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		ct[i] += ct[i - 1];
	print_array(ct, max + 1);

	for (i = 0; i < (int)size; i++)
	{
		sort[ct[array[i]] - 1] = array[i];
		ct[array[i]] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];

	free(sort);
	free(ct);
}
