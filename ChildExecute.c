#include "main.h"
/**
 * ChildExecute - a function that handles the child process execution
 * @argC: arg array
 * @programName: program name
 * @LExitST: exit status
 * Return: void
 */
void ChildExecute(char **argC, char *programName, int *LExitST)
{
	int result;
	char *FULLpath = Which(argC[0]);

	if (FULLpath == NULL)
	{
		write(2, programName, myStrlen(programName));
		write(2, ": 1: ", 5);
		write(2, argC[0], myStrlen(argC[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		freeTok(argC);
		*LExitST = EXIT_FAILURE;
		return;
	}
	argC[0] = FULLpath;
	result = execve(argC[0], argC, environ);
	if (result == -1)
	{
		write(2, programName, myStrlen(programName));
		write(2, ": ", 2);
		write(2, argC[0], myStrlen(argC[0]));
		write(2, ": ", 2);
		write(2, "not found\n", 10);
		free(FULLpath);
		freeTok(argC);
		*LExitST = EXIT_FAILURE;
	}
	if (result == -1 || *LExitST == EXIT_FAILURE)
		exit(EXIT_FAILURE);
	else
		exit(EXIT_SUCCESS);
}
