#include "monty.h"

/**
 * mod - modulo
 * @stack: Double linked list
 * @line_number: File line execution
 */
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (!s || !s->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if (s->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	s->next->n = s->next->n % s->n;
	pop(stack, line_number);
}

/**
 * pchar - pchar
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (!stack || !s)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	if (isascii(s->n))
	{
		printf("%c\n", s->n);
		return;
	}
	fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	free_all();
	exit(EXIT_FAILURE);
}
