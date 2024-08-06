#include "monty.h"

/**
 * _nop - function that doesn't do anything
 * @stack: double pointer to the head of the stack
 * @line_number: script line number
 *
 * usage: nop
 *
 * Return: No return
*/

void _nop(stack_t **stack, unsigned int line_number)
{
	(void)(stack);
	(void)(line_number);
}
