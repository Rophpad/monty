#include "monty.h"

/**
 * rotr - s
 * @stack: Double linked list
 * @line_number: File line execution
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void) line_number;

	if (!stack || !*stack || !(*stack)->next)
		return;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;

	(*stack)->prev = tmp;
	*stack = tmp;
}
