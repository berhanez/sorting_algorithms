#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

void bubble_sort(int *array, size_t size);
void swap_ints(int *a, int *b);
void print_array(const int *array, size_t size);

#endif /* _SORT_H_ */
