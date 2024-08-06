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


extern stack_t **global_head;

void global_free(void);

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **stack, unsigned int line_number);
void _swap(stack_t **stack, unsigned int line_number);
void _pop(stack_t **stack, unsigned int line_number);
void _add(stack_t **stack, unsigned int line_number);
void _nop(stack_t **stack, unsigned int line_number);
void read_file(char *file, stack_t **stack);
void parse_command(stack_t **stack, char *op, unsigned int line_num);

#endif
