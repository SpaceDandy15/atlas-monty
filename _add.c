#include "monty.h"

/**
 * _add - function that adds the top two elements of the stack
 * @stack: double pointer to the head of the stack.
 * @line_number: script line number
 *
 * Usage: add
 * If the stack contains less tha two elements, print the error message,
 * <line_number>: can't add, stack too short,
 *  followed by a new line, and exit with the status EXIT_FAILURE
 * The result is stored in the second top element of the stack,
 * and the top element is removed, so that at the end:
 * The top element of the stack contains the result
 * The stack is one element shorter
 * 
 * Return: no return
*/

void _add(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n += temp_variable;
}
