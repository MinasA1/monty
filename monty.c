#include "monty.h"

/**
* main - interpreter for Monty ByteCodes files
* ac - arguments count
* av - arguments string
* Return: 0 if success , EXIT_FAILURE if fails
*/

int main(int ac, char **av)
{
	FILE *inst;
	size_t size;
	char *buffer = NULL, *line, *n;
	stack_t *top = NULL;
	unsigned int ln = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inst = fopen(av[1], "r");
	if (!inst)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, inst) != -1)
	{
		ln++;
		line = strtok(buffer, " \t\n");
		if (!strcmp(line, "push"))
		{
			n = strtok(NULL, " \t\n");
			if(push(&top, n, ln))
				free_mem(inst, buffer, &top);
			continue;
		}
		if(processor(line, ln, &top))
			free_mem(inst, buffer, &top);
	}
	free_stack(&top);
	free(buffer);
	fclose(inst);
	return (0);
}

/**
 * processor - checks for instruction and executes it
 * @line: instruction
 * @n: value to push in stack
 * @ln: index of instuction
 * @top: double pointer to top of stack
 * Return: 0 if executes 1 if fails
 */
int processor(char *line, unsigned int ln, stack_t **top)
{
	static instruction_t codes[] = {
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (codes[i].opcode)
	{
		if (!strcmp(codes[i].opcode, line))
		{
			codes[i].f(top, ln);
			return (0);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n", ln, line);
	return (1);
}

/**
 * free_stack - deallocates memory used by stack
 * @top: double pointer to stack's top
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	while(*top)
	{
		temp = *top;
		*top = (*top)->prev;
		free(temp);
	}
}

/**
 * free_mem - free memory and EXIT_FAILURE
 * @inst: file to close
 * @buffer: buffer that holds input from file
 * @top: double pointer to stack's top
 */
void free_mem(FILE *inst, char *buffer,stack_t **top)
{
	free_stack(top);
	free(buffer);
	fclose(inst);
	exit(EXIT_FAILURE);
}
