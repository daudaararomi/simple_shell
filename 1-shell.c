#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - a UNIX command line interpreter
 *@ac: number of command
 *@argv:vector of command
 * Return: Nothing
 */
int main(int ac, char **argv)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	char *token;
	(void)ac;

	while (1)
	{
		printf("arafun $");
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read == -1)
		{
			if (feof(stdin))
			{
				exit(EXIT_SUCCESS);
			}
			else
			{
				perror("readline");
				exit(EXIT_FAILURE);
			}
		}
		argv = malloc(nchars_read * sizeof(char *));
		if (!argv)
		{
			fprintf(stderr, "lsh: allocation error\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			*argv = token;
			token = strtok(NULL, delim);
		}
		argv[1] = NULL;
		execmd(argv);
	}
	free(argv);
	free(lineptr);
}
