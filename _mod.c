#include "monty.h"

/**
 * _mod - function that multiplies the second
 * top element of the stack, with the top element of the stack.
 * @stack: double pointer to the head of stack.
 * @line_number: script line number.
 *
 * Reuturn: no return
 */

void _mod(stack_t **stack, unsigned int line_number)
{
	int temp_variable;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp_variable = (*stack)->;
	_pop(stack, line_number);
	if (temp_variable == 0)
	{
		fprintf(stderr, "L%u: dvision by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)-> %= temp_variable;
}

	}
})