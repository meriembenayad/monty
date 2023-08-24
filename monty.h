#ifndef _MAIN_H
#define _MAIN_H

#define _POSIX_C_SOURCE 200809L
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

extern int n;

#define uint unsigned int

#define DELIM "\n\t\r "

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, uint line_number);
} instruction_t;

/*executed function */
void exec_cmd(char **argv);
int is_comment(char *token, int line_counter);
int is_number(char *str);

/* opcodes.c */
void (*get_opcodes(char *token, uint line_number))(stack_t **, uint);

/* stack_functions_1.c */
void push(stack_t **topstack, uint line_number);
void pall(stack_t **topstack, uint line_number);
void pint(stack_t **topstack, uint line_number);
void pop(stack_t **topstack, uint line_number);
void swap(stack_t **topstack, uint line_number);

/* stack_functions_2.c */
void nop(stack_t **topstack, uint line_number);
void add(stack_t **topstack, uint line_number);
void sub(stack_t **topstack, uint line_number);
void _div(stack_t **topstack, uint line_number);
void mul(stack_t **topstack, uint line_number);

/* stack_functions_3.c */
void mod(stack_t **topstack, uint line_number);
void free_stack(stack_t *topstack);
void open_error(char **argv);
void int_err(uint line);

#endif /* _MONTY_H_ */
