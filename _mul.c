#include "monty.h"

/**
 * _mul - function that multiplies the second top elemnt of the stack,
 * with the top element of the stack.
 * @stack: double pointer to the head of the stack
 * @line_number: script line number
 *
 * Return: no return
*/

void _mul(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_variable = (*stack)->n;
	_pop(stack, line_number);
	(*stack)->n *= temp_variable;
}
