#include "monty.h"

/**
 * pchar - prints the char at the top of stack
 * @head: pointer to stack's top
 * @line_number: index for instruction
 * Return: void
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		free_mem(head);
	}
	if ( 0 <= (*head)->n && (*head)->n <= 127)
		printf("%c\n", (*head)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		free_mem(head);
	}
}
