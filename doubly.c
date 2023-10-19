#include "monty.h"

/**
 * add_dnodeint - adds the node at the beginning
 * @head: the head of the node
 * @n: the variable contenting the data for the node
 *
 * Return:the address of the new element or NULL if failed
 */

stack_t *add_dnodeint(dlistint_t **head, const int n)
{
	stack_t *newnode;
	stack_t *h;


	newnode = malloc(sizeof(stack_t));
	if (newnode == NULL)
	{
		exit(EXIT_FAILURE);
	}
	/* set the prev pointer to NULL */
	newnode->prev = NULL;
	/*set the next pointer to the NULL */
	newnode->n = n;
	newnode->prev = NULL;
	h = *head;
	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}
	/* set the head prev pointer to point to newnode */
	newnode->next = h;
	/*if it fails return null */
	if (h != NULL)
	{
		h->prev = newnode;
	}
	*head = newnode;
	return (newnode);
}

/**
 * add_dnodeint_end - adds the node at the end
 * @head: the head node
 * @n: contains the data
 *
 * Return: the new element or NULL id it failed
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *endnode, *h;

	endnode = malloc(sizeof(stack_t));
	if (endnode == NULL)
	{
		exit(EXIT_FAILURE);;
	}
	endnode->n = n;
	endnode->next = NULL;
	h = *head;
	if (h != NULL)
	{
		while (h->next != NULL)
		{
			h = h->next;
		}
		h->next = endnode;
	}
	else
	{
		*head = endnode;
	}
	endnode->prev = h;
	return (endnode);
}
#include "lists.h"

/**
 * free_dlistint - frees all memory allocated
 * @head: the head of the list
 *
 * Return: oid since were void
 */

void free_dlistint(stack_t *head)
{
	if (!head)
	{
		return;
	}
	while (head->next)
	{
		head = head->next;
		free(head->prev);
	}
	free(head);
}
