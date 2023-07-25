#include "sort.h"

/**
* shell_sort - Sorts an array of integers in ascending order
*              using the Shell sort algorithm with Knuth sequence.
* @array: The array to be sorted.
* @size: Number of elements in the array.
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/* initial value of gap*/
	while (gap < size)
		gap = gap * 3 + 1;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

	print_array(array, size);
	}
}
