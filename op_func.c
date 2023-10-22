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
	int num;


	if (!fun_var.arg)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_m();
		exit(EXIT_FAILURE);
	}
	if (!is_integer(fun_var.arg))
	{
		fprintf(stderr, "L%d:  usage: push integer\n", line_number);
		free_m();
		exit(EXIT_FAILURE);
	}
	num = atoi(fun_var.arg);
	if (fun_var.check == 1)
	{
		add_dnodeint(stack, num);
	}
	else
	{
		add_dnodeint_end(stack, num);
	}
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
/**
 * pchar - prints the ascii value of the integer
 * @stack: the stack
 * @line_count: used to print the error line
 *
 * Return: void since were void
 */

void pchar(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = *stack;
	int m = tmp->n;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_count);
		exit(EXIT_FAILURE);
	}
	if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
	{
		printf("%c\n", m);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_count);
		exit(EXIT_FAILURE);
	}
}
/**
 * pstr - prints the string starting at the top of the stack
 * @stack: the top stack
 * @line_count: the error line counter
 *
 * Return: void since we're void
 */
void pstr(stack_t **stack, unsigned int line_count)
{
	stack_t *tmp = *stack;
	int m;
	(void)line_count;

	if (tmp == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL && tmp->n != 0)
	{
		m = tmp-> n;
		if ((m >= 'a' && m <= 'z') || (m >= 'A' && m <= 'Z'))
		{
			printf("%c", m);
		}
		tmp = tmp->next;
	}
	printf("\n");
}
