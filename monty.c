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

	glob.mode = 0;
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
		line = strtok(glob.buffer, "\r \t\n");
		if (line[0] == '#')
			continue;
		if (!strcmp(line, "push"))
		{
			n = strtok(NULL, "\r \t\n");
			push(&top, make_int(&top, n, ln));
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
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
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
/**
 * make_int - converts string to int
 * @top: double pointer to stack's top
 * @n: string holding int
 * @ln: line index
 * Return: converted int or free_mem
 */
int make_int(stack_t **top, char *n, unsigned int ln)
{
	int num = 1, i = 0;

	if (n[0] == '-')
		i = 1;
	while (n[i])
	{
		if (!isdigit(n[i]))
		{
			printf("L%u: usage: push integer\n", ln);
			free_mem(top);
		}
		i++;
	}
	num *= atoi(n);
	return (num);
}
