#include "monty.h"

/**
 * push - pushes an integer onto the stack.
 * @stack: Double pointer to the stack.
 * @line_number: the line number in the file where the opcode is found.
 *
 * Description: The integer is pushed onto the top of the stack. If the
 * argument is not a valid integer, the function exits with an error.
*/
void push(stack_t **stack, unsigned int line_number)
{
	char *arg;
	int value;
	stack_t *new_node;

	arg = strtok(NULL, " \n\t");
	if (arg == NULL || !is_number(arg))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;
	*stack = new_node;
}

/**
 * is_number - checks if a string is a valid integer.
 * @str: the string to check.
 *
 * Description: returns 1 if the string is a valid integer, otherwise 0.
 * Return: 1 if the string is a valid integer, 0 otherwise.
*/
int is_number(char *str)
{
	int i = 0;

	if (str[0] == '-' || str[0] == '+')
	i++;

	for (; str[i]; i++)
	{
		if (!isdigit(str[i]))
		return (0);
	}
	return (1);
}
