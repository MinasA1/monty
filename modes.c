#include "monty.h"

/**
 * queue - sets the data_push mode to FIFO
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	glob.mode = 1;
}
/**
 * stack - sets the data_push mode to LIFO
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	glob.mode = 0;
}
