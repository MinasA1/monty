#include "monty.h"

/**
 * push - adds a number in stack
 * @top: pointer to stack's bottom
 * @n: string containing int to add
 * @ln: index for instruction
 * Return: void
 */
void push(stack_t **top, char *n, unsigned int ln)
{
	stack_t *new;
	int num, i = 0;

	while (n[i])
	{
		if (!isdigit(n[i]))
		{
			printf("L%u: usage: push integer\n", ln);
		        free_mem(top);
		}
		i++;
	}
	num = atoi(n);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		free_mem(top);
	}
	if (!*top)
	{
		new->next = NULL;
		new->n = num;
		new->prev = NULL;
		*top = new;
	}
	else
	{
		new->next = NULL;
		new->n = num;
		new->prev = *top;
		new->prev->next = new;
		*top = new;
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
	printf("%d", (*head)->n);
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
	stack_t *temp;

	if (!(*head)->prev || !*head)
	{printf("L%u: can't swap, stack too short\n", line_number);
		free_mem(head);
	}
	temp = (*head)->prev;
	temp->next = NULL;
	(*head)->prev = temp->prev;
	(*head)->next = temp;
	temp->prev = *head;
	*head = temp;
}
