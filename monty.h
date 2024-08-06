#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

/**
 * struct stack_s - doulby linked list representation of a stack (or queue)
 * @n: ineger
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next elemnt of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}
stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, ques, LIFO, FIFO
*/

typedef struct instruction_s
{
	char *opcode;
	void (*f) (stack_t **stack, unsigned int line_number);
}
instruction_t;

/**
 * stuct global_vars - globally useful variables, all rolled into one
 * @top: double pointer to top of stack
 * @ops: double pointer to an instruction stuct
*/
typedef struct global_vars
{
	stack_t **top;
	instruction_t **ops;
} glob_vars;

extern glob_vars globv;

/**
 * stuct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
*/
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

var_t var;

extern var_t var;

#define STACK 0
#define QUEUE 1

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
int file_reader(char *filename, stack_t **stack);
void free_all(void);
void stack_init(stack_t **head);


#endif
