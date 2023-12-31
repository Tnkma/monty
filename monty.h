#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct glo - A global variable that hold the value for each operation
 * @count: the line count that will be used to declare the line error
 * @arg: stores the argument gotten by strtok to be pushed into the stack
 * @head: the head of the stack
 *
 * Description: A data structure
 */
typedef struct glo
{
	unsigned int count;
	char *arg;
	stack_t *head;
	int check;
	char *line;
} glo_t;

extern glo_t fun_var;
void push(stack_t **head, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void (*opcodes(char *codes))(stack_t **stack, unsigned int line_number);
stack_t *add_dnodeint(stack_t **head, const int n);
stack_t *add_dnodeint_end(stack_t **head, const int n);
void free_dlistint(stack_t *head);
void push(stack_t **stack, unsigned int line_number);
void free_m(void);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void mstack(stack_t **stack, unsigned int line_number);
void mqueue(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void madd(stack_t **stack, unsigned int line_count);
void msub(stack_t **stack, unsigned int line_count);
void mdiv(stack_t **stack, unsigned int line_count);
void mmul(stack_t **stack, unsigned int line_count);
void mmod(stack_t **stack, unsigned int line_count);
void pchar(stack_t **stack, unsigned int line_count);
void pstr(stack_t **stack, unsigned int line_count);

#endif
