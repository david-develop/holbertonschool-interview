#include "search.h"

/**
 * linear_skip - searches for a value in a sorted skip list of integers.
 * @list: pointer to the head of the skip list to search in
 * @value: value to search for
 *
 * Return: A pointer on the first node where value is located or NULL if not
 * value or not head
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t idx;
	skiplist_t *n_bef, *n_min;

	n_bef = list;
	n_min = list;

	if (list == NULL)
		return (NULL);

	while (n_bef && n_bef->next && n_bef->n < value)
	{
		n_min = n_bef;
		if (n_bef->express)
		{
			n_bef = n_bef->express;
			printf("Value checked at index [%lu] = [%d]\n",
				   n_bef->index, n_bef->n);
		}
		else
		{
			while (n_bef->next)
				n_bef = n_bef->next;
		}
	}

	printf("Value found between indexes [%lu] and [%lu]\n",
		   n_min->index, n_bef->index);

	for (idx = n_min->index;
		 idx <= n_bef->index && n_min->n <= value;
		 idx++, n_min = n_min->next)
	{
		printf("Value checked at index [%lu] = [%d]\n", idx, n_min->n);
		if (n_min && n_min->n == value)
			return (n_min);
	}
	if (n_min)
		printf("Value checked at index [%lu] = [%d]\n", idx, n_min->n);
	return (NULL);
}
