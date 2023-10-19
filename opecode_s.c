#include "monty.h"

/**
 * opcodes - opcode mappings for the functions
 * @stack: the stack for the opcode
 * @line_number: for printing error line
 *
 * Return: void since were void
 */

void (*opcodes(char *codes))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcode_calls[] =
	{
		{"push", push},
		{"pall", pall},
		{"pint", pint};
		{NULL, NULL}
	}
	int m;

	for (m = 0; opcode_calls[m].opcode; m++)
	{
		if (_strcmp(opcode_calls[m].opcode, codes) == 0)
		{
			return (opcode_calls[m].f);
		}
		else
		{

