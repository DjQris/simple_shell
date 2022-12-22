#include "shell.h"

/**
  * exit_helper - exit helper
  * @tokens: tokens
  * @line: line
  *
  */
void exit_helper(char **tokens, char *line)
{
	int status = 0;

	if (tokens[1] == NULL || (!_strcmp(tokens[1], "0")))
	{
		free_tokens(tokens);
		free(line);
		exit(0);
	}
	status = _atoi(tokens[1]);
	if (status != 0)
	{
		free_tokens(tokens);
		free(line);
		exit(status);
	}
	else
	{
		_puts("exit: Illegal number: ");
		_puts(tokens[1]);
		_puts("\n");
		exit(2);
	}

	free_tokens(tokens);
	free(line);
	exit(EXIT_SUCCESS);
}
