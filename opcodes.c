#include "monty.h"

/**
 * push - adds a number in stack
 * @top: pointer to stack's bottom
 * @n: string containing int to add
 * @ln: index for instruction
 * Return: 0 if success EXIT_FAILURE if fails
 */
int push(stack_t **top, char *n, unsigned int ln)
{
	stack_t *new;
	int num, i = 0;

	while (n[i])
	{
		if (!isdigit(n[i]))
		{
			printf("L%u: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	num = atoi(n);
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!top)
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
		*top = new;
	}
	return (0);
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
