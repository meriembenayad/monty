#include "monty.h"
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n += (*stack)->n;
	pop(stack, line_number);
}

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n -= (*stack)->n;
	pop(stack, line_number);
}

void div(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->next->n / tmp->n;
	*stack = tmp->next;
	free(tmp);
}

void _mul(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	tmp->n *= (*stack)->n;
	pop_stack(stack, line_number);
}

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
