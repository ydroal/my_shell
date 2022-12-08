#include "shell.h"
#define BUFSIZE 64

/**
 * tokenize - split the texit and tokenize it
 * @buf: text to split
 *
 * Return: table of tokens
 */
char **tokenize(char *buf)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * BUFSIZE);
	if (tokens == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(buf, " \t\n");
	tokens[i] = token;
	i++;

	while (token != NULL)
	{
		token = strtok(NULL, " \t\n");
		tokens[i] = token;
		i++;
	}
	tokens[i] = NULL;

	return (tokens);
}

/**
 * read_line - reading a string of text from stream
 *
 * Return: pointer to the buffer containing the text read
 */
char *read_line(void)
{
	char *buf = NULL;
	size_t bufsize = 0;

	if (getline(&buf, &bufsize, stdin) == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			printf("No such file or directory\n");
			exit(EXIT_FAILURE);
		}
	}
	return (buf);
}

/**
 * main - the starting point for program execution
 *
 * Return: 0 success
 */
int main(void)
{
	int status;
	char *buf = NULL;
	char **tokens;

	while (status)
	{
		write(STDOUT_FILENO, "$ ", 2);
		buf = read_line();
		tokens = tokenize(buf);
		status = parse_command(tokens);
	}
	return (0);
}






