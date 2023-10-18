#include "main.h"
/**
 * ChildExecute - a function that handles the child process execution
 * @argC: arg array
 * @programName: program name
 * Return: void
 */
void ChildExecute(char **argC, const char *programName)
{
	char *FULLpath = Which(argC[0]);

	if (FULLpath == NULL)
	{
		perror("NOT FOUND");
		freeTok(argC);
		exit(EXIT_FAILURE);
	}
	argC[0] = FULLpath;
	execve(argC[0], argC, environ);
	perror(programName);
	freeTok(argC);
	exit(EXIT_FAILURE);
}
