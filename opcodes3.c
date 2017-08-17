#include "monty.h"
/**
 * mod - mods the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void mod(stack_t **head, unsigned int line_number)
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
	(*head)->prev->n %= (*head)->n;
	*head = (*head)->prev;
	free((*head)->next);
}
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
	if (0 <= (*head)->n && 127 >= (*head)->n)
		printf("%c\n", (*head)->n);
	else
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		free_mem(head);
	}
}
/**
 * pstr - prints the string starting at the top of stack
 * @head: pointer to stack's top
 * @line_number: index for instruction
 * Return: void
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;
	if (!*head)
		printf("\n");
	temp = *head;
	while (temp)
	{
		if ((0 <= temp->n && 127 >= temp->n) || !temp->n)
			printf("\n");
		else
			printf("%c", temp->n);
		temp = temp->prev;
	}
}
/**
 * rotl - puts the top element to the bottom of the stack
 * @head: pointer to stack's top
 * @line_number: index for instruction
 * Return: void
 */
void rotl(stack_t **head, unsigned int line_number)
{
	int a;
	stack_t *temp;

	(void)line_number;
	temp = *head;
	while (temp->prev)
	{
		a = temp->n;
		temp->n = temp->prev->n;
		temp = temp->prev;
		temp->n = a;
	}
}
/**
 * rotr - puts the bottom element to the top of the stack
 * @head: pointer to stack's top
 * @line_number: index for instruction
 * Return: void
 */
void rotr(stack_t **head, unsigned int line_number)
{
	int a;
	stack_t *temp;

	(void)line_number;
	temp = *head;
	while (temp->prev)
		temp = temp->prev;
	while (temp->next)
	{
		a = temp->n;
		temp->n = temp->next->n;
		temp = temp->next;
		temp->n = a;
	}
}
