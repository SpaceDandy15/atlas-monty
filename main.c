#include "monty.h"
/**
 * instruction_t instructions [] - Array of opcode-function pairs
 * Each element contains an opcode string and a corresponding function pointer.
*/
instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

/**
 * proccess_file - processes the Monty bytecode file.
 * @file: file pointer to the monty bytecode file.
 *
 * Description: Reads each line of the file, extracts the opcode,
 * and executes the corresponding function.
*/
void process_file(FILE *file);
/**
 * execute_instruction - Executes the appropriate function for a given opcode.
 * @opcode: the opcode to execute
 * @stack: pointer to the stack.
 * @line_number: the current line number in the file.
 *
 * Description: Matches the opcode with the correct function in the
 * instructions array and executes it.
*/
void execute_instruction(char *opcode, stack_t **stack,
unsigned int line_number);

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

	fclose(file);
	return (EXIT_SUCCESS);
}

/**
 * process_file - processes each line in the monty bytecode file.
 * @file: file pointer to the monty bytecode file.
 *
 * Description: Reads the file line by line, extraction and executing opcodes.
*/
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

/**
 * execute_instuction - Executes the function corresponding to the given opcode.
 * @opcode: the opcode to execute.
 * @stack: double pointer to the stack.
 * @line_number: the line number in the file where the opcode is found.
 *
 * Description: searches for the opcode in the instructions array and
 * calls the corresponding function. If the opcode is not found, it prints
 * an error message and exits.
*/
void execute_instruction(char *opcode,
stack_t **stack, unsigned int line_number)
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
