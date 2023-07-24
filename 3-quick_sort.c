#include "sort.h"

/**
* quick_sort - Sorts an array of integers in ascending order
*              using the Quick sort algorithm with Lomuto partition scheme.
*
* @array: The array to be sorted.
* @size: Number of elements in the array.
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

/* Recursive function to perform quick sort */
void quicksort(int *array, ssize_t low, ssize_t high, size_t size);

quicksort(array, 0, size - 1, size);
}

/**
* quicksort - Recursive function to perform quick sort
*
* @array: The array to be sorted.
* @low: The starting index of the partition to be sorted.
* @high: The ending index of the partition to be sorted.
* @size: Number of elements in the array.
*/
void quicksort(int *array, ssize_t low, ssize_t high, size_t size)
{
if (low < high)
{
ssize_t partition = lomuto_partition(array, low, high, size);
quicksort(array, low, partition - 1, size);
quicksort(array, partition + 1, high, size);
}
}

/**
* lomuto_partition - Lomuto partition scheme for Quick sort
*
* @array: The array to be sorted.
* @low: The starting index of the partition to be sorted.
* @high: The ending index of the partition to be sorted.
* @size: Number of elements in the array.
*
* Return: The index of the pivot element.
*/
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
int pivot, temp;
ssize_t i, j;

pivot = array[high];
i = low - 1;

for (j = low; j <= high - 1; j++)
{
if (array[j] <= pivot)
{
i++;
if (i != j)
{
/* Swap array[i] and array[j] */
temp = array[i];
array[i] = array[j];
array[j] = temp;

/* Prints the array after each swap */
print_array(array, size);
}
}
}

if ((i + 1) != high)
{
/* Swap array[i + 1] and array[high] */
temp = array[i + 1];
array[i + 1] = array[high];
array[high] = temp;

print_array(array, size);
}

return (i + 1);
}

