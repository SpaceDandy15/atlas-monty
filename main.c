#include "monty.h"

/** instructions array*/
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

int main(int argc, char **argv)
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
	instruction_t *instruction;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode [0] == '#')
		continue;

		for (instruction = instructions; instruction->opcode != NULL; instruction++)
		{
			if (strcmp(opcode, instruction->opcode) == 0)
			{
				instruction->f(&stack, line_number);
				break;
			}
		}

		if (instruction->opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
	
	free(line);
	fclose(file);
	/**free the stack*/
	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}
