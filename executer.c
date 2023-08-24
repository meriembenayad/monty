#include "monty.h"
/**
 * free_stack - This function frees the stack.
 *
 * @topstack: Pointer to the topstack of the stack.
 */

void free_stack(stack_t *topstack)
{
	stack_t *temp;

	if (topstack == NULL)
		return;

	while (topstack != NULL)
	{
		temp = topstack;
		topstack = topstack->next;
		free(temp);
	}
	free(topstack);
}

/**
 * exec_cmd - Opens and reads the Monty file, executing the commands.
 * @argv: pointer to array of arguments.
 */
void exec_cmd(char **argv)
{
	void (*p_func)(stack_t **, uint);
	FILE *fp;
	char *buf = NULL, *token = NULL, command[1024];
	size_t len = 0;
	int line_size;
	uint line_counter = 1;
	stack_t *topstack = NULL;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		open_error(argv);

	while ((line_size = getline(&buf, &len, fp)) != EOF)
	{
		token = strtok(buf, DELIM);
		if (token == NULL)
			continue;
		strcpy(command, token);
		if (is_comment(token, line_counter) == 1)
			continue;
		if (strcmp(token, "push") == 0)
		{
			token = strtok(NULL, DELIM);
			if (token == NULL || is_number(token) == -1)
				int_err(line_counter);
			number = atoi(token);
			p_func = get_opcodes(command, line_counter);
			p_func(&topstack, line_counter);
		}
		else
		{
			p_func = get_opcodes(token, line_counter);
			p_func(&topstack, line_counter);
		}
		line_counter++;
	}
	fclose(fp);
	if (buf != NULL)
		free(buf);
	free_stack(topstack);
}

/**
 * is_number - Checks if a string represents a valid number.
 * @token: The string to check.
 *
 * Return: 1 if the string is a valid number, -1 otherwise.
 */
int is_number(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '-' && isdigit(str[i]) == 0)
			return (0);
	}

	return (1);
}

/**
 * is_comment - Checks if a token is a comment.
 * @token: The token to check.
 * @line_counter: The current line_number counter.
 *
 * Return: 1 if the token is a comment, -1 otherwise.
 */
int is_comment(char *token, int line_counter)
{
	if (token == NULL || token[0] == '#')
	{
		line_counter++;
		return (1);
	}
	return (-1);
}
