#include "monty.h"


struct global glob;

/**
* main - interpreter for Monty ByteCodes files
* @ac:  arguments count
* @av: arguments string
* Return: 0 if success , EXIT_FAILURE if fails
*/
int main(int ac, char **av)
{
	size_t size;
	char *line, *n;
	stack_t *top = NULL;
	unsigned int ln = 0;

	glob.buffer = NULL;
	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	glob.inst = fopen(av[1], "r");
	if (!glob.inst)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&glob.buffer, &size, glob.inst) != -1)
	{
		ln++;
		line = strtok(glob.buffer, " \t\n#");
		if (!strcmp(line, "push"))
		{
			n = strtok(NULL, " \t\n#");
			push(&top, n, ln);
			continue;
		}
		processor(line, ln, &top);
	}
	free_stack(&top);
	free(glob.buffer);
	fclose(glob.inst);
	return (0);
}

/**
 * processor - checks for instruction and executes it
 * @line: instruction
 * @ln: index of instuction
 * @top: double pointer to top of stack
 * Return: void
 */
int processor(char *line, unsigned int ln, stack_t **top)
{
	static instruction_t codes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"nop", nop},
		{"mul", mul},
		{"div", divv},
		{"pchar", pchar},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (codes[i].opcode)
	{
		if (!strcmp(codes[i].opcode, line))
		{
			codes[i].f(top, ln);
			return (1);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n", ln, line);
	free_mem(top);
	return (1);
}

/**
 * free_stack - deallocates memory used by stack
 * @top: double pointer to stack's top
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	while (*top)
	{
		temp = *top;
		*top = (*top)->prev;
		free(temp);
	}
}

/**
 * free_mem - free memory and EXIT_FAILURE
 * @top: double pointer to stack's top
 */
void free_mem(stack_t **top)
{
	free_stack(top);
	free(glob.buffer);
	fclose(glob.inst);
	exit(EXIT_FAILURE);
}
