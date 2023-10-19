#include "monty.h"

/**
 * is_integer - checks if fun_var.arg is integer
 * @str: the argument it receives
 *
 * Return: 1 for success and 0 for negative
 */
int is_integer(char *str)
{
	if (!str || !*str) /* checks if str is empty */
	{
		return (0);
	}
	if (*str == '-') /* check for negative number*/
		str++;
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * push - push the value to the stack
 * @stack: he stack head
 * @line_number: error line counter
 *
 * Return: void since were void
 */

void push(stack_t **stack, unsigned int line_number)
{
	int num, i;


	if (!fun_var.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_m();
		exit(EXIT_FAILURE);
	}

	for (i = 0; fun_var.arg[i] != '\0'; i++)
	{
		if (!fun_var.arg || !is_integer(fun_var.arg))
		{
			fprintf(stderr, "L%d:  usage: push integer", line_number);
			free_m();
			exit(EXIT_FAILURE);
		}
	}
	num = atoi(fun_var.arg);
	add_dnodeint(stack, num);
}
/**
 * pop - removes the first node
 * @stack: the stack
 * @line_number: the number to print the error line
 *
 * Return: void since were void
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
