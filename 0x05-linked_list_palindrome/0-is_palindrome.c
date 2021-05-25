#include "lists.h"
/**
 * compare_list - compare list
 * @head: pointer to list head
 * @half: pointer to list half node
 * Return: 1 if palindrome, 0 if not
 */
int compare_list(listint_t *head, listint_t *half)
{
	listint_t *cursor1 = head;
	listint_t *cursor2 = half;

	while (cursor2)
	{
		if (cursor1->n == cursor2->n)
		{
			cursor1 = cursor1->next;
			cursor2 = cursor2->next;
		}
		else
			return (0);
	}
	if (cursor2 == NULL)
		return (1);
	return (0);
}
/**
 * reverse_list - reverse order of list
 * @head: pointer to list
 * Return: pointer to new head
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL;
	listint_t *next;
	listint_t *cursor;

	for (cursor = head; cursor != NULL;)
	{
		next = cursor->next;
		cursor->next = prev;
		prev = cursor;
		cursor = next;
	}
	return (prev);
}
/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: pointer to list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *cursor;
	int count_nod = 0, i = 0, r;
	listint_t *half_cursor;

	if (*head == NULL)
		return (1);
	for (cursor = *head; cursor != NULL; cursor = cursor->next)
		count_nod++;
	if (count_nod % 2 == 0)
		count_nod--;
	for (cursor = *head; i < count_nod / 2; cursor = cursor->next)
		i++;
	cursor->next = reverse_list(cursor->next);
	half_cursor = cursor->next;
	r = compare_list(*head, half_cursor);
	return (r);
}
