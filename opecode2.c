#include "monty.h"

/**
 * swap - swaps the two top elemet of the stack
 * @stack: the stack
 * @line_number: the line number
 *
 * Return: void since were void
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	int i = 0;

	for (tmp = *stack; tmp != NULL; tmp = tmp->next)
		i++;
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_m();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	tmp->next = (*stack)->next;
	if (tmp->next)
		tmp->next->prev = tmp;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = *stack;
}
void mqueue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	fun_var.check = 0;
}
void mstack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	fun_var.check = 1;
}
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
