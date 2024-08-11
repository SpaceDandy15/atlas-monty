#include "monty.h"

/**
 * _pstr - funciton that prints the string starting at
 * the top of the stack
 * @stack: double pointer to the head of stack
 * @line_number: script line number
 *
 * Return: no return
*/

void _pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack;

	(void)(line_number);
	if (!(*stack))
	{
		printf("\n");
		return;
	}
	while (temp-variable)
	{
		if (isascii(temp_variable->n) && temp_variable->n !=0)
		putchar(temp_variable->n);
		else
		break;
		temp_variable = temp_variable->next;
	}
	putchar('\n');
}
