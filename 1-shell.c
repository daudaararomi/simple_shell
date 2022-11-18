#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
/**
 * main - a UNIX command line interpreter
 *@ac: number of command
 *@argv:vector of command
 *
 * Return: Nothing
 *
 */

void  main(int ac, char **argv)
{
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	char **tokens;
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
		  tokens= malloc(nchars_read * sizeof(char*));
		  if (!tokens)
		  {
			  fprintf(stderr, "lsh: allocation error\n");
			  exit(EXIT_FAILURE);
			  }
		  token = strtok(lineptr, delim);
		  while (token != NULL)
		  {
			  *tokens = token;
			 argv = tokens;
			  tokens++;
			  token = strtok(NULL, delim);
		  }
		  tokens++;
		  *tokens = NULL;
		  argv[1] = *tokens;
		execmd(argv);

	}


	free(tokens);
	free(lineptr);

	return (0);
}
