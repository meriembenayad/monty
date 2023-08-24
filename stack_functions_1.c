#include "monty.h"

int data_structure_type = 0; /* 0 for stack, 1 for queue */

/**
 * push - This function pushes an element to the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void push(stack_t **topstack, unsigned int line_number)
{
	stack_t *new_node, *last;

	/* Check if arg is NULL or not an integer */
	if (DELIM == NULL || !is_number(DELIM))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = atoi(arg);

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (*topstack == NULL) /* Validate if empty list*/
	{
		*topstack = new_node;
	}
	else if (data_structure_type == 1) /* If it's a queue */
	{
		last = *topstack;
		while (last->next != NULL) /* Go to the end */
			last = last->next;
		new_node->prev = last;
		last->next = new_node;
	}
	else /* if it's not empty list and it's a stack */
	{
		new_node->next = *topstack;
		(*topstack)->prev = new_node;
		*topstack = new_node;
	}
}
/**
 * pall - This function prints all the values on the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void pall(stack_t **topstack, uint line_number)
{
	stack_t *tmp = *topstack;
	(void)line_number;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - This function prints the value at the topstack of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void pint(stack_t **topstack, uint line_number)
{
	stack_t *tmp = *topstack;

	if (tmp != NULL)
		printf("%d\n", tmp->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * pop - This function removes the topstack element of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void pop(stack_t **topstack, uint line_number)
{
	stack_t *tmp;

	tmp = *topstack;
	if (*topstack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = tmp->next;
	free(*topstack);
	*topstack = tmp;
}

/**
 * swap - This function swaps the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void swap(stack_t **topstack, uint line_number)
{
	int num;

	if (*topstack == NULL || (*topstack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	num = (*topstack)->n;
	(*topstack)->n = (*topstack)->next->n;
	(*topstack)->next->n = num;
}
