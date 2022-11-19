#ifndef MAIN_H
#define MAIN_H
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/wait.h>

void _exec(char **args);
void execmd(char **argv);
char** _split_line(char *line);
char* _read_line();
char *SS_Read_Line(void);
#endif /*MAIN_H */
