#include "main.h"
/**
 * ChildExecute - a function that handles the child process execution
 * @argC: arg array
 * @programName: program name
 * Return: void
 */
void ChildExecute(char **argC, char *programName)
{
	char *FULLpath = Which(argC[0]);

	if (FULLpath == NULL)
	{
		write(2, programName, myStrlen(programName));
		write(2, ": 1: ", 5);
		write(2, argC[0], myStrlen(argC[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		freeTok(argC);
		exit(EXIT_FAILURE);
	}
	argC[0] = FULLpath;
	if (execve(argC[0], argC, environ) == -1)
	{
		write(2, programName, myStrlen(programName));
		write(2, ": ", 2);
		write(2, argC[0], myStrlen(argC[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		free(FULLpath);
		freeTok(argC);
		exit(EXIT_FAILURE);
	}
	else
	{
		free(FULLpath);
		freeTok(argC);
		exit(EXIT_SUCCESS);
	}
}
