#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, **u_tokns = NULL;
	size_t line_size = 0;
	ssize_t line_len = 0;

	while (line_len >= 0)
	{
		int w_len = 0;

		signal(SIGINT, signal_handler);
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "($) ", 4);
		line_len = getline(&line, &line_size, stdin);
		if (line_len == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		w_len = count_input(line);
		if (line[0] != '\n' && w_len > 0)
		{
			int execFlag = 0;

			u_tokns = tokenize(line, " \t", w_len);
			execFlag = execBuiltInCommands(u_tokns, line);
			if (!execFlag)
			{
				u_tokns[0] = find(u_tokns[0]);
				if (u_tokns[0] && access(u_tokns[0], X_OK) == 0)
					exec(u_tokns[0], u_tokns);
				else
					perror("./hsh");
			}
			free_tokens(u_tokns);
		}
	}
	free(line);
	return (0);
}
