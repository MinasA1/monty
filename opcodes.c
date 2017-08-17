#include "monty.h"

/**
 * push - adds a number in stack
 * @top: pointer to stack's bottom
 * @n: number to add to stack
 * Return: void
 */
void push(stack_t **top, int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free_mem(top);
	}
	if (!glob.mode)
	{
		if (!*top)
			new->prev = NULL;
		else
		{
			new->prev = *top;
			new->prev->next = new;
		}
		new->next = NULL;
		new->n = n;
		*top = new;
	}
	else
	{
		new->n = n;
		new->prev = NULL;
		new->next = NULL;
		if (!*top)
			*top = new;
		else
		{
			temp = *top;
			while (temp->prev)
				temp = temp->prev;
			new->next = temp;
			temp->prev = new;
		}
	}
}
/**
 * pall - prints all values in stack, from top to bottom
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void pall(stack_t **head, unsigned int line_number)
{
	stack_t *temp = *head;

	(void)line_number;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->prev;
	}
}
/**
 * pint - prints the value at the stack's top
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!*head)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		free_mem(head);
	}
	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the stack's top element
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (!*head)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_mem(head);
	}
	temp = *head;
	*head = (*head)->prev;
	(*head)->next = NULL;
	free(temp);
}
/**
 * swap - swaps the stack's top two elements
 * @head: double pointer to top of stack
 * @line_number: index of instruction
 * Return: void
 */
void swap(stack_t **head, unsigned int line_number)
{
	int a;

	if (!(*head)->prev || !*head)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		free_mem(head);
	}
	a = (*head)->n;
	(*head)->n = (*head)->prev->n;
	(*head)->prev->n = a;
}
