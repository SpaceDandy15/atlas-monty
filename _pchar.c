#include "monty.h"

/**
 * _pchar - function that prints the char at the top of the stack
 * @stack: double pointer to the head of stack
 * @line_number: script line number
 *
 * Return: No reuturn
 */

void _pchar(stack_t **stack, unsigned int line_number)
{
	int ch;
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ch = (*stack)->n;
	if (!isascii(ch))
	{
		fprinft(stderr, "L%u: can't pchar, value out of range\n", line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ch);
}
