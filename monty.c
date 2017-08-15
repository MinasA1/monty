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
	stack_t *bot = NULL;
	unsigned int ln = 0;

	if (ac != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	inst = fopen(av[1], "r");
	if (inst)
	{
		printf("Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &size, inst) != -1)
	{
		ln++;
		line = strtok(buffer, " \t\n");
		if (!strcmp(line, "push"))
			n = strtok(NULL, " \t\n");
		processor(line, n, ln, &bot);
	}
	free(buffer);
	fclose(inst);
	return (0);
}


/**
 * processor - checks for instruction and executes it
 * @line: instruction
 * @n: value to push in stack
 * @ln: index of instuction
 * @bot: pointer to stack's bottom
 * Return: 0 if executes EXIT_FAILURE if fails
 */
int processor(char *line, char *n, unsigned int ln, stack_t **bot)
{
	static instruction_t codes[] ={
		{"pall", pall},
		{NULL, NULL}
	};
	unsigned int i = 0;

	while (code[i])
	{
		if (!strcmp(code[i].opcode, line))
		{
			code[i].f(bot, ln);
			return (0);
		}
		i++;
	}
	printf("L%u: unknown instruction %s\n" ln, line);
	exit(EXIT_FAILURE);
}
