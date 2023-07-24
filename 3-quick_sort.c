#include "sort.h"

/**
 * swap_pos - swaps position of values in an array
 * @array: array to be changed
 * @first: first index
 * @second: second index
 */
void swap_pos(int **array, size_t first, size_t second)
{
	int holder;

	holder = (*array)[first];
	(*array)[first] = (*array)[second];
	(*array)[second] = holder;
}

/**
 * partition - splits the array into two parts
 * part lower than the sorted index and a part higher
 * @array: array to be sorted
 * @lower: lower boundary
 * @higher: higher boundary
 * @size: size of the array
 *
 * Return: index of sorted pivot
 */
size_t partition(int **array, size_t lower, size_t higher, size_t size)
{
	size_t before, after, pivot;

	pivot = higher;
	before = lower;

	for (after = before; after < higher; after++)
	{

		if ((*array)[after] <= (*array)[pivot])
		{
			if (before != after)
			{
				swap_pos(array, before, after);
				print_array(*array, size);
			}
			before += 1;
		}
	}

	if (before != after)
	{
		swap_pos(array, before, after);
		print_array(*array, size);
	}
	return (before);
}
/**
 * sorter - recursively sorts a given array
 *
 * @array: array to be sorted
 * @low: lower bound
 * @higher: higher bound
 * @size: size of the array
 */
void sorter(int **array, size_t low, size_t higher, size_t size)
{
	size_t sorted_index;

	if (low < higher && *array)
	{
		sorted_index = partition(array, low, higher, size);

		if (sorted_index - low > 1)
			sorter(array, low, sorted_index - 1, size);

		if (higher - sorted_index > 1)
			sorter(array, sorted_index + 1, higher, size);
	}
}

/**
 * quick_sort - applies quick sort algorithm in sorting array
 *
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	sorter(&array, 0, size - 1, size);
}
