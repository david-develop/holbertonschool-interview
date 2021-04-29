#include <stdlib.h>
#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: pointer to firtst node.
 * @n: given int to be added.
 * Return: the address of the new element, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *cursor;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		cursor = *head;
		while (cursor->next != NULL && cursor->next->n <= number )
			cursor = cursor->next;
        new->next = cursor->next;
		cursor->next = new;
	}
	return (new);
}
