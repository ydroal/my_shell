#include "shell.h"

/**
 * func_cd - changes the current working directory of the calling
 *           process to the directory specified in path.
 * @args: user input
 * Return: if success 0, failure -1.
 */

int func_cd(char **args)
{
        char *user;
        char *path;

        if (args[1] == NULL)
        {
                user = getlogin();
                printf("%s", user);
                path = _strcat("/home/", user);
                printf("%s", path);
                return (chdir(path));
        }

	if (chdir(args[1]) != 0)  
	{   
		perror("cd command error\n");
		exit(EXIT_FAILURE);
	}   
        return (0);
}


/**
 * func_pwd - display an absolute pathname of the current working directory
 *
 * @args: user input
 * Return: if success 0, failure -1.
 */

int func_pwd(__attribute__((unused))char **args)
{
	char pathname[256];

	getcwd(pathname, 256);
	printf("%s\n", pathname);

	return (0);
}
