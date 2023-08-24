#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

/* Included librairies */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/* data structures */
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
 * struct globals - global variable to use
 * @file: file name
 * @buff: Buffer for getline function
 * @size: Counter for getline
 * @dict: instruction dict
 * @head: Head of the list
 * @line_number: Current line number
 * @MODE: Program config stack or queue
 */
typedef struct globals
{
	FILE *file;
	char *buff;
	size_t size;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} gvar;

extern gvar var;

/* sysconfig functions */
int init_var(gvar *var);
instruction_t *init_instructions(void);
int get_funct(gvar *var, char *opcode);
void free_all(void);

/* opcode functions */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);

/* additionnal functions */
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
/*int isascii(int c);*/
int _isdigit(char *string);
int is_delimiter(char c, const char *delim);
size_t _strlen(const char *str);
int _strcmp(char *s1, char *s2);
/*char *_strtok(char *str, char *delim);*/

#endif
