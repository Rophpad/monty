#include "monty.h"

/**
 * check_input - Procced to the first verification:
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: file pointer
 */
FILE *check_input(int ac, char *av[])
{
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(av[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	return (fd);
}

/**
 * main - This is the main function
 * @argc: Total numbers of arguments that
 * the program take at the running time
 * @argv: A pointer to an array containning the list
 * of arguments
 *
 * Return: 0 on sucess
 */
int main(int argc, char *argv[])
{
	char *opcode;

	if (init_var(&var) != 0)
		return (EXIT_FAILURE);
	var.file = check_input(argc, argv);

	while (getline(&var.buff, &var.size, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \t\r\n");
		if (opcode != NULL)
		{
			if (get_funct(&var, opcode) == EXIT_FAILURE)
			{
				free_all();
				return (EXIT_FAILURE);
			}
		}
		var.line_number++;
	}
	free_all();

	return (0);
}
