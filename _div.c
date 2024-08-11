#include "monty.h"

/**
 * _div - funciton that divides the second top elment of the stack by,
 * the top element of the stack
 * @stack: double pointer to the head of the stack.
 * @line_number: script the line number.
 *
 * Retrun: no return
*/
void _div(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_variable = (*stack)->n;
	if (temp_variable == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	_pop(stack, line_number);
	(*stack)->n /= temp_variable;
	}
