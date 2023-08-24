#include "monty.h"

/**
 * mod - This function mods the topstack two elements of the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 * @line_number: line_number number of the opcode.
 */

void mod(stack_t **topstack, uint line_number)
{
	stack_t *tmp = *topstack;

	if (tmp == NULL || tmp->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp->next->n = tmp->next->n % tmp->n;
	*topstack = tmp->next;
	free(tmp);
}

/**
 * open_error - Handles error when file cannot be opened.
 * @argv: Command-line arguments.
 */
void open_error(char **argv)
{
	char *filename = argv[1];

	fprintf(stderr, "Error: can't open file %s\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * int_err - Handles error when "push"
 * instruction is not followed by an integer.
 * @line: The line number where the error occurred.
 */
void int_err(uint line)
{
	fprintf(stderr, "L%u: usage: push integer\n", line);
	exit(EXIT_FAILURE);
}
