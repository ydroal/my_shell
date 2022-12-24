#include "shell.h"

/**
 * create_pathname - add path to command
 * @cmd: user's input command
 *
 * Return: pointer to command added the path
 */

char *create_pathname(char *cmd)
{
	char *pathname = NULL;
	char *path = NULL;
	char *PATH;
	int lencmd = 0;
	int lenpath = 0;

	PATH = getenv("PATH");

	path = strtok(PATH, ":");

	while (cmd[lencmd] != '\0')
		lencmd++;

	while (path[lenpath] != '\0')
		lenpath++;	

	while (path != NULL)
	{
		pathname = malloc(sizeof(char) * (lencmd + lenpath) + 2);
		if (pathname == NULL)
		{
			perror("Allocation error");
			exit(EXIT_FAILURE);
		}

		pathname = _strcpy(pathname, path);
		pathname = _strcat(pathname, "/");
		pathname = _strcat(pathname, cmd);
				
		if (access(pathname, X_OK) == 0)
			return (pathname);
		free(pathname);
		pathname = NULL;
		path = strtok(NULL, ":");
	}
	return (NULL);
}

/**
 * execute_cmd - executes the command
 *
 * @pathname: program to execute
 * @tokens: an array of argument strings passed to new program
 * Return: if success,0
 */

int execute_cmd(char *pathname, char **tokens, char **env)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0)
	{
		perror("fork faild");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(pathname, tokens, env) == -1)
			return (1);
	}
	else
		if (wait(&status) < 0)
		{
			perror("wait failed");
			return (1);
		}
	return (0);
}

/**
 * is_builtin - verify if command is internalCommand or not
 *
 * @cmd: user's input command
 * Return: 1
 */

int is_builtin(char **args)
{
	int i;
	builtin_t builtins[] = {
		{"cd", func_cd},
		{"pwd", func_pwd},
		{NULL, NULL}
	};

	for (i = 0; builtins[i].key != NULL; i++)
	{
		if (_strcmp(args[0], builtins[i].key) == 0)
			return (builtins[i].f(args));
	}
	return (1);
}

/**
 * parse_command - Distribute the command to be execute
 *
 * @tokens: table of tokens
 * Return: if command is not executed, 0
 */
int parse_command(char **tokens)
{
	extern char **environ;
	char *pathname = NULL;
	int result;

	if (tokens[0])
	{
		result = is_builtin(tokens);
		if (result == 1)/*if it was not biltin command */
		{
			if (execute_cmd(tokens[0], tokens, environ) == 0)/*command was absolute path*/
			{
				free_tab(tokens);
				return (1);
			}

			pathname = create_pathname(tokens[0]);
			if (pathname != NULL)
			{
				if (execute_cmd(pathname, tokens, environ) == 0)
				{
					free_tab(tokens);
					return (1);
				}
			}
		}
	}
	free_tab(tokens);
	return (1);
}
