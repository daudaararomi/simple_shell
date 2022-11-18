#include "main.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
/**
 *
 *execmd - execute a command
 *@argv: command to execute
 *
 *Return: Nothing
 *
 */
void execmd(char **argv)
{
	char *command = NULL;

	if (argv)
	{
		command = argv[0];
		if (execve(command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
