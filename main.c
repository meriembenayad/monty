#include "monty.h"

void process_line(char *line, interpreter_t *interpreter)
{
	char *opcode = strtok(line, "\n\t\r ");
	int i;

	if (opcode && opcode[0] != '#') /* Ignore comments */
	{
		for (i = 0; interpreter->op_func[i].opcode; i++)
		{
			if (strcmp(opcode, interpreter->op_func[i].opcode) == 0)
			{
				interpreter->op_func[i].f(interpreter->stack, interpreter->line_number);
				return;
			}
		}
		if (!interpreter->op_func[i].opcode) /* Opcode not found */
		{
			fprintf(stderr, "L%d: unknown instruction %s\n",
				interpreter->line_number, opcode);
			exit(EXIT_FAILURE);
		}
	}
}

void process_file(FILE *file, interpreter_t *interpreter)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while ((read = getline(&line, &len, file)) != -1)
	{
		interpreter->line_number++;
		process_line(line, interpreter);
	}

	free(line);
}

int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	instruction_t op_func[] = {
	    {"push", push},
	    {"pall", pall},
	    {"pint", pint},
	    {"pop", pop},
	    {"swap", swap},
	    {"add", add},
	    {"sub", sub},
	    {"nop", nop},
	    {NULL, NULL}};
	interpreter_t interpreter;

	interpreter.stack = &stack;
	interpreter.line_number = 0;
	interpreter.op_func = op_func;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_file(file, &interpreter);

	fclose(file);

	return (EXIT_SUCCESS);
}
