#include "main.h"

/**
 * _exec - to execute a command
 *@args: command to execute
 *
 *Return: Nothing
 */
void _exec(char **args)
{
	int status;
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("error");
		exit(1);
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("error");
	}
}

/**
 * _split_line - to split user commands to individual command for execution
 *@line: pointer to line of commands
 * Return: pointer splitted command
 */
char **_split_line(char *line)
{
	int length = 0, i = 0;

	while (!line)
	{
		++line;
		i++;
	}
	char **tokens = malloc(i * sizeof(char *));

	char *delimiters = " \t\r\n";
	char *token = strtok(line, delimiters);

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	while (token != NULL)
	{
		tokens[length] = token;
		length++;
		token = strtok(NULL, delimiters);
	}

	tokens[length] = NULL;
	return (tokens);
}

/**
 * _read_line - read in commands from standard input
 * Return: pointer to commands read
 */
char *_read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	if (getline(&line, &buflen, stdin) == -1)
	{
		if (feof(stdin))
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

/**
 *main - simple shell
 * Return: Nothing
 */
int main(void)
{
	while (true)
	{
		printf("arafun $  ");
		char *line = _read_line();
		char **tokens = _split_line(line);

		if (tokens[0] != NULL)
			_exec(tokens);

		free(tokens);
		free(line);
	}
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}
