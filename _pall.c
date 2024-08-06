#include "monty.h"

/**
 * pall - prints all values form the stack
 * @stack: double pointer to the head of the stack
 * @line_number: the number of a line of the file
 *
 * Return: void
*/
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *element = *stack;

	(void) line_number;

	while (element != NULL)
	{
		printf("%d\n", element->n);
		element = element->next;
	}
}
