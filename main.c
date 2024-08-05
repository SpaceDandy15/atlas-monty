#include "monty.h"

stack_t **global_head;

/**
 * main - the root of the project
 * @argc: how many arguments were passed to a program
 * @argv: arguments vector
 *
 * Return: on success, always EXIT_SUCCESS
*/

int main(int argc, char *argv[])
{
	stack_t *head;
	
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

		global_head = &head;
		read_file(argv[1], &head);

		global_free(); /** calling global free if needed*/

		atexit(global_free);

		return (EXIT_SUCCESS);
}
