#include "monty.h"
/**
 * add - This function adds the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void add(stack_t **topstack, uint line_number)
{
	stack_t *tmp;

	if (*topstack == NULL || (*topstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*topstack)->next;
	tmp->n += (*topstack)->n;
	pop(topstack, line_number);
}

/**
 * nop - This function does nothing.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void nop(stack_t **topstack, uint line_number)
{
	(void)topstack;
	(void)line_number;
}

/**
 * sub - This function subtracts the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void sub(stack_t **topstack, uint line_number)
{
	stack_t *tmp;

	if (*topstack == NULL || (*topstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*topstack)->next;
	tmp->n -= (*topstack)->n;
	pop(topstack, line_number);
}

/**
 * _div - This function divides the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void div(stack_t **topstack, unsigned int line_number)
{
	stack_t *tmp;

	if (*topstack == NULL || (*topstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*topstack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*topstack)->next;
	tmp->n /= (*topstack)->n;
	pop(topstack, line_number);
}

/**
 * mul - This function multiplies the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void mul(stack_t **topstack, uint line_number)
{
	stack_t *tmp;

	if (*topstack == NULL || (*topstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*topstack)->next;
	tmp->n *= (*topstack)->n;
	pop(topstack, line_number);
}
