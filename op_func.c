#include "monty.h"

/**
 * is_integer - checks if fun_var.arg is integer
 * @str: the argument it receives
 *
 * Return: 0 for success and 1 for negative
 */
int is_integer(char *str)
{
	if (!str || !*str) /* checks if str is empty */
	{
		return (0);
	}
	if (*str == '-') /* check for negative number*/
		str++;

