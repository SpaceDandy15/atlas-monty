#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top.
 * @stack: double pointer to the stack.
 * @line_number: the line number in the file where the opcode is found.
 *
 * Description: prints all values on the stack, starting from the top,
 * in the order they were added. If the stack is empty,
 * nothing is printed.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	/** to avoid unused variable warning*/
	(void)line_number;
	while (current != NULL)
	{printf("%d\n", current->n);
	current = current->next;
	}
}
