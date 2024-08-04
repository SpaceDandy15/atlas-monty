#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}
stack_t;

stack_t *initialize_stack(void);
void push(stack_t **stack, int value);
void pall(stack_t **stack);

#endif
