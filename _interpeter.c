#include "monty.h"

/**
 * interpreter - wrapper around strtol, handling monty specific errors
 * @num_string: string that represents an integer
 * @line_number: line counter of monty file
 * Return: long int that strtol converted
*/

int interpreter(char *num_string, unsigned int line_number)
{
	int base = 10;
	char *endptr;
	long val;

	errno = 0;
	val = strtol(num_string, &endptr, base);

	if (errno == Erange && (val == LONG_MAX || val == LONG_MIN))

	{
		exit(EXIT_FAILURE);
	}
	if (endptr == num_string)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (num_string[0] != '\0')
	if (!isdigit(num_string[0]) && *endptr != '\0')
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	return (val);
}
