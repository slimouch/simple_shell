#include "main.h"
/**
 * forkAndExecute - fork and execute the command
 * @argC: array of arguments
 * @programName: the program name
 * Return: void
 */
void forkAndExecute(char **argC, const char *programName)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		freeTok(argC);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		ChildExecute(argC, programName);
	} else
	{
		if (wait(&status) == -1)
		{
			perror("wait error");
			freeTok(argC);
			exit(EXIT_FAILURE);
		}
	}
}
