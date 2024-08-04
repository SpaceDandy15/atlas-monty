#include "monty.h"

/**
 * push - Adds an element to the stack.
 * @stack: Pointer to the head of the stack.
 * @value: Value to be added to the stack.
*/
void push(stack_t **stack, int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error allocating memory\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;
	if (*stack)
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * pall - Prints all the values on the stack. 
 * @stack: Pointer to the head of the stack.
*/
void pall(stack_t **stack)
{
	stack_t *current = *stack;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
