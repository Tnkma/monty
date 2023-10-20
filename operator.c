#include "monty.h"

void madd(stack_t **stack, unsigned int line_count)
{
	int m = 0;
	stack_t *tmp = NULL;

	tmp = *stack;
	for (; tmp != NULL; tmp = tmp->next, m++)
		;
	if (m < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
		free_m();
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	pop(stack, line_count);
}
void msub(stack_t **stack, unsigned int line_count)
{
        int m = 0;
        stack_t *tmp = NULL;

        tmp = *stack;
        for (; tmp != NULL; tmp = tmp->next, m++)
                ;
        if (m < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
                free_m();
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;
        tmp->n -= (*stack)->n;
        pop(stack, line_count);
}
void mmul(stack_t **stack, unsigned int line_count)
{
        int m = 0;
        stack_t *tmp = NULL;

        tmp = *stack;
        for (; tmp != NULL; tmp = tmp->next, m++)
                ;
        if (m < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
                free_m();
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;
        tmp->n *= (*stack)->n;
        pop(stack, line_count);
}
void mdiv(stack_t **stack, unsigned int line_count)
{
        int m = 0;
        stack_t *tmp = NULL;

        tmp = *stack;
        for (; tmp != NULL; tmp = tmp->next, m++)
                ;
        if (m < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
                free_m();
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;
        tmp->n /= (*stack)->n;
        pop(stack, line_count);
}
void mmod(stack_t **stack, unsigned int line_count)
{
        int m = 0;
        stack_t *tmp = NULL;

        tmp = *stack;
        for (; tmp != NULL; tmp = tmp->next, m++)
                ;
        if (m < 2)
        {
                fprintf(stderr, "L%d: can't add, stack too short\n", line_count);
                free_m();
                exit(EXIT_FAILURE);
        }
        tmp = (*stack)->next;
        tmp->n %= (*stack)->n;
        pop(stack, line_count);
}
