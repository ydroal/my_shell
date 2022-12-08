#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFSIZE 64

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

extern char **environ;

typedef struct builtin
{
	char *key;
	int (*f)();
} builtin_t;

char *read_line(void);
char **tokenize(char *buf);
int parse_command(char **tokens);
int execute_cmd(char *pathname, char **argv, char **env);
void free_tab(char **tokens);
int func_exit(void);
char *create_pathname(char *cmd);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
