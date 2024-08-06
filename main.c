#include "monty.h"

global_vars globv;

/**
 * main - check code
 * @ac: number of command line arguments
 * @av: pointer to array containing command line arguments.
 *
 * Return: Always 0
*/

int main(int ac, char **av)
{
	stack_t *head;
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_header(av[1] &head);
	exit(EXIT_SUCCESS);
}

/**
 * file_reader - process the whole monty file
 * @filename: str name of monty opcode file
 * @stack: double pointer to top of stack data struct
 * Return: return an error code or success
*/

int file_reader(char *filename, stack_t **stack)
{
	size_t len;
	ssize_t read;
	unsigned int line_number = 0;
	char * line = NULL;
	FILE *fp;
	char *op;

	if (!filename)
	{
		fprintf(stderr, "Error: Can't openf file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	atexit(free_all);
	while ((read = getline(&line, &len, fp)) != -1)
	{
		op = strtok(line, "\n\t\r ");
		line_number++;
		if (op)
		get_po(stack, op, line_number);
	}
	free(line);
	fclose(fp);
	return (EXIT_SUCCESS);
}

/**
 * stack_init - function that initializes all things.
 * @head: double pointer to top of stack.
 *
 * Reutrn: no return
*/
void stack_init(stack_t **head)
{
	*head = NULL;
	globv.top = head;
}

/**
 * free_all - function that frees all malloc'ed memory
 *
 * Reurn: no return
*/
void free_all(void)
{
	stack_t *tmp1, *tmp2 = NULL;

	tmp1 = *(globv.top);
	while (tmp1 != NULL)
	{
		tmp2 = tmp->next;
		free(tmp1);
		tmp1 = tmp2;
	}
}
