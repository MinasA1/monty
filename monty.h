#ifndef __MONTY_H__
#define __MONTY_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/*INSTRUCTION PROCESS*/
int processor(char *line, unsigned int ln, stack_t **bot);

/*OPCODE INSTRUCTION FUNCTIONS*/
int push(stack_t **top, char *n, unsigned int ln);
void pall(stack_t **head, unsigned int line_number);

/*FREE MEMORY*/
void free_stack(stack_t **top);

#endif