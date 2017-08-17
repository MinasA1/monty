#include "monty.h"

/**
 * add - adds the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	if (!(*head)->prev || !*head)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		free_mem(head);
	}
	(*head)->prev->n += (*head)->n;
	*head = (*head)->prev;
	free((*head)->next);
}

/**
 * sub - subtracts the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (!(*head)->prev || !*head)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		free_mem(head);
	}
	(*head)->prev->n -= (*head)->n;
	*head = (*head)->prev;
	free((*head)->next);
}
/**
 * nop - does nothing
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
/**
 * divv - diveds the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void divv(stack_t **head, unsigned int line_number)
{
	if (!(*head)->prev || !*head)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		free_mem(head);
	}
	if (!(*head)->n)
	{
		printf("L%u: division by zero\n", line_number);
		free_mem(head);
	}
	(*head)->prev->n /= (*head)->n;
	*head = (*head)->prev;
	free((*head)->next);
}
/**
 * mul - multiplies the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (!(*head)->prev || !*head)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		free_mem(head);
	}
	(*head)->prev->n *= (*head)->n;
	*head = (*head)->prev;
	free((*head)->next);
}
