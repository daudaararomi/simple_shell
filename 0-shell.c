#include <stdio.h>
#include "main.h"
#include <stdlib.h>

/**
 * SS_Read_Line: reads entire line from stream
 *
 *Return:pointer to line read
 */
 char *SS_Read_Line(void)
 {
	char *lnPtr = NULL;
	size_t n = 0;

	if (getline(&lnPtr, &n, stdin) == -1)
	{
		if (feof(stdin))
		   exit(EXIT_SUCCESS);
		else
		{	perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (lnPtr);
}
/**
*main - UNIX command line interpreter
*@argc:number of argument
@argv:argument
*
Return: return 0
*/
int main(int argc, char **argv)
{
	char *line;
	if (argc < 0)
	{
		fprintf(stderr, "Usage: %s <file>\n", *argv);
		exit(EXIT_FAILURE);
	}
	do{
		printf("$");
		line =SS_Read_Line();
		printf(" %s", line);
		free(line);
	} while (1);
}

			
