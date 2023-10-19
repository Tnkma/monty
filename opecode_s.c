#include "monty.h"

/**
 * opcodes - the finction to a pointer
 * @codes: - the opcodes received
 *
 * Return: void since were void
 */

void (*opcodes(char *codes))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_calls[] =	{
		{"push", push},
		{"pall", pall},
		{"pint", pint};
		{NULL, NULL}
	};
	int m;

	for (m = 0; opcode_calls[m].opcode; m++)
	{
		if (_strcmp(opcode_calls[m].opcode, codes) == 0)
		{
			return (opcode_calls[m].f);
		}
	}
	return (NULL);
}

/**
 * pint - prints only the head of the stack
 * @stack: the stack
 * @line_number: used to print the error line
 *
 * Return: void since were void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	printf("%d\n", tmp->n);
}

/**
 * pall - prints the values of the stack
 * @stack: the stack
 * @line_number: used to print the eror line
 *
 * Return: void since were void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
	{
		return;
	}
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
