#include "monty.h"

/** instructions array*/
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

void process_file(FILE *file);
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number);

int main(int argc, char **argv)
{
	FILE *file;

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

	process_file(file);
	
	flcose(file);
	return (EXIT_SUCCESS);
}

void process_file(FILE *file)
{
	char *line = NULL;
	size_t len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;

	while (getline(&line, &len, file) != -1)
	{
		line_number++;
		char *opcode = strtok(line, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
		
		continue;

		execute_instruction(opcode, &stack, line_number);
	}

	free(line);

	while (stack != NULL)
	{
		stack_t *temp = stack;
		stack = stack->next;
		free(temp);
	}
}

void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t *instruction;

	for (instruction = instructions; instruction->opcode != NULL; instruction++)
	{
		if (strcmp(opcode, instruction->opcode) == 0)
		{
			instruction->f(stack, line_number);
			return;
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	exit(EXIT_FAILURE);
}
