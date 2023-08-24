#include "monty.h"

/**
 * add - add the top two elements of the stack
 * @stack: Double linked list
 * @line_number: File line execution
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (!s || !s->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	s->next->n = s->next->n + s->n;
	pop(stack, line_number);
}

/**
 * sub - substract the top two elements of the stack
 * @stack: Double linked list
 * @line_number: Line counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *s = *stack;

	if (!s || !s->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n",
				line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	s->next->n = s->next->n - s->n;
	pop(stack, line_number);
}
