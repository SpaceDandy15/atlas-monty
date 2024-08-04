#include "monty.h"

/**
 * initialize_stack - Initializes the stack.
 * Return: Poointer to the head of the stack.
*/
stack_t *initialize_stack(void)
{
	return NULL;
}

/**
 * free_stack - Frees the stack.
 * @stack: Pointer to the head of the stack.
*/
void free_stack(stack_t **stack)
{
	stack_t *temp;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}
