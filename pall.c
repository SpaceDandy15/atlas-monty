#include "monty.h"

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