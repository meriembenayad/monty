#include "monty.h"

/**
 * get_opcodes - This function gets the opcode.
 *
 * @token: Token to compare.
 * @line_number: line_number number of the opcode.
 * Return: Pointer to the function.
 */

void (*get_opcodes(char *token, uint line_number))(stack_t **, uint)
{
	int i;
	instruction_t operation[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"nop", nop},
	    {"add", add},
	    {"sub", sub},
	    {"_div", _div},
	    {"mul", mul},
	    {"mod", mod},
	    {NULL, NULL}};
	for (i = 0; operation[i].opcode != NULL; i++)
	{
		if (strcmp(token, operation[i].opcode) == 0)
		{
			return (operation[i].f);
		}
	}

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);

	return (NULL);
}
