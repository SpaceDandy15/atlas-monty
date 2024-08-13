#include "monty.h"

/**
 * _rotl - function that rotates the stack to the top
 * @stack: double pointer to the head of stack
 * @line_number: script line number
 *
 * Return: no return
*/
void _rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp_variable = *stack, *new_top;

	(void)(line_number);
	if (*stack == NULL || (*stack)->next == NULL)
	return;
	new_top = (*stack)->next;
	new_top->prev = NULL;
	while (temp_variable->next != NULL)
	temp_variable = temp_variable->next;
	temp_variable->next = NULL;
	(*stack)->next = temp_variable;
	(*stack) = new_top;
}
