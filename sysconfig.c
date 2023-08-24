#include "monty.h"

/**
 * init_var - Initialize global variables
 * @var: Global var
 *
 * Return: 0 on success and 1 when fails
 */
int init_var(gvar *var)
{
	var->file = NULL;
	var->buff = NULL;
	var->dict = init_instructions();
	if (!var->dict)
		return (EXIT_FAILURE);
	var->head = NULL;
	var->line_number = 1;
	var->MODE = 0;
	return (EXIT_SUCCESS);
}

/**
 * init_instructions - Initialize instructions
 *
 * Return: A set of pointer
 */
instruction_t *init_instructions(void)
{
	instruction_t *all = malloc(sizeof(instruction_t) * 18);

	if (!all)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}

	all[0].opcode = "pall", all[0].f = pall;
	all[1].opcode = "push", all[1].f = push;
	all[2].opcode = "pint", all[2].f = pint;
	all[3].opcode = "pop", all[3].f = pop;
	all[4].opcode = "swap", all[4].f = swap;
	all[5].opcode = "add", all[5].f = add;
	all[6].opcode = "nop", all[6].f = NULL;
	all[7].opcode = "sub", all[7].f = sub;
	all[8].opcode = "div", all[8].f = _div;
	all[9].opcode = "mul", all[9].f = mul;
	all[10].opcode = "mod", all[10].f = mod;
	all[11].opcode = NULL, all[11].f = NULL;

	return (all);
}

/**
 * get_funct - Call functions
 * @var: Gobal var
 * @opcode: The command to excecute
 *
 * Return: 0 or 1
 */
int get_funct(gvar *var, char *opcode)
{
	instruction_t *entry = var->dict;

	while (entry->opcode)
	{
		if (strcmp(opcode, entry->opcode) == 0)
		{
			if (!entry->f)
				return (EXIT_SUCCESS);
			entry->f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
		entry++;
	}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n",
				var->line_number, opcode);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/**
 * free_all - Clean all program mallocs
 */
void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);
	if (var.file != NULL)
		fclose(var.file);
	free(var.dict);
	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}
/* Additionnal function */
/**
 * _isdigit - Check if it number
 * @string: string to check
 *
 * Return: 0 or 1
 */
int _isdigit(char *string)
{
	int i;

	for (i = 0; string[i]; i++)
	{
		if (string[i] < 48 || string[i] > 57)
			return (1);
	}
	return (0);
}
