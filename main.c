#include "monty.h"

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

	}

	free(line);
	fclose(file);
	free_stack(&stack); /** frees the stack)*/
	 return 0;
}
