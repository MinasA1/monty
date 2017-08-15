#include "monty.h"

/**
 * push - adds a number in stack
 * @top: pointer to stack's bottom
 * @n: string containing int to add
 * @ln: index for instruction
 * return: 0 if success EXIT_FAILURE if fails
 */
int push(stack_t **top, char *n)
{
	stack_t *new;
	int num;

	if (strlen(n) != 1)
		num = atoi(n);
	else if (strlen(n) == 1 && !n[0])
		num = 0;
	else
	{
		printf("L%u: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
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
		new->n num;
		new->prev = *top;
		*top = new;
	}
	return(0);
}
