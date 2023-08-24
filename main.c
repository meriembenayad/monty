#include "monty.h"

/**
 * main - Monty interpreter program.
 * @argc: The number of arguments.
 * @argv: Array of arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	exec_cmd(argv);
	return (0);
}
