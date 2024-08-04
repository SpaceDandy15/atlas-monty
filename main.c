#include "monty.h"
#include <ctype.h> /** for isspace and isdigit*/

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	if (argc != 2) 
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (!file) 
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
		if (isspace((unsigned char)*line) || *line == '#')
		continue;

		char *opcode = strtok(line, " \t\n");
		if (opcode && strcmp(opcode, "push") == 0)
		{
			int value = atoi(strtok(NULL, "\t\n"));
			push(&stack, value);
		}
		else if (opcode && strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", __LINE__);
			free_stack(&stack);
			fclose(file);
			free(line);
			exit(EXIT_FAILURE);
			}
		}
		
	free(line);
	fclose(file);
	free_stack(&stack); /** frees the stack)*/
	 return 0;
}
