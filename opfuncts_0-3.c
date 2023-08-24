#include "monty.h"

/**
 * pall - Print list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * push - Insert a new value in list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *h = *stack;
	char *arg;

	arg = strtok(NULL, " \t\r\n");
	if (arg == NULL || (_isdigit(arg) != 0 && arg[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(arg);
	if (var.MODE == 0 || !*stack)
	{
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (h->next)
			h = h->next;
		h->next = temp;
		temp->prev = h;
		temp->next = NULL;
	}

}

/**
 * pint - Print last node
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
* pop - Delete top of list
* @stack: Double linked list
* @line_number: File line execution
*/
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!*stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = tmp->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	free(tmp);
}

/**
 * swap - Delete top of list
 * @stack: Double linked list
 * @line_number: File line execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n",
				line_number);
		gree_all();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
