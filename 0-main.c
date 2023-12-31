#include <stdio.h>
#include "monty.h"

glo_t fun_var;

/**
 * _fun_var - global function varibles
 *
 *
 * Return: void since were void
 */
void _fun_var(void)
{
	fun_var.count = 1;
	fun_var.check = 1;
	fun_var.head = NULL;
	fun_var.arg = NULL;
	fun_var.line = NULL;
}
/**
 * free_m - free all
 *
 *
 * Return: void since we are void
 */
void free_m(void)
{
	free_dlistint(fun_var.head);
	free(fun_var.line);
}
/**
 * open_file - checks if files can be opened
 * @argc: argument count
 * @argv: command line arguments
 *
 * Return: the open file
 */
FILE *open_file(int argc, char **argv)
{
	FILE *file;


	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	return (file);
}

/**
 * main - the main function
 * @argc: the argument count
 * @argv: the command line argumnet
 *
 * Return: Always 0 for success
 */

int main(int argc, char **argv)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	FILE *input;
	ssize_t read;
	size_t len = 0;
	char *token, *delim = " \t\n";

	input = open_file(argc, argv);
	_fun_var();
	read = getline(&fun_var.line, &len, input);
	while (read != -1)
	{
		token = strtok(fun_var.line, delim);
		if (token[0] != '#')
		{
			if (!token) /* skip empty lines */
			{
				continue;
			}
			f = opcodes(token);
			if (f == NULL)/* if its not a defined opcode*/
			{
				fprintf(stderr,"L%d: unknown instruction %s\n", fun_var.count, token);
				free_m();
				exit(EXIT_FAILURE);
			}
			if (strcmp(token, "push") == 0)
			{
				fun_var.arg = strtok(NULL, delim);
			}
			f(&fun_var.head, fun_var.count);
		}
		read = getline(&fun_var.line, &len, input);
		fun_var.count++;
	}
	free_m();
	fclose(input);
	return (0);
}
