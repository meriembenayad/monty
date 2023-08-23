#include "monty.h"

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	char *opcode;
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
	int i;

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

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, "\n\t\r ");
		if (opcode && opcode[0] != '#') /* Ignore comments */
		{
			for (i = 0; op_func[i].opcode; i++)
			{
				if (strcmp(opcode, op_func[i].opcode) == 0)
				{
					op_func[i].f(&stack, line_number);
					break;
				}
			}
			if (!op_func[i].opcode) /* Opcode not found */
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	fclose(file);

	return (EXIT_SUCCESS);
}
