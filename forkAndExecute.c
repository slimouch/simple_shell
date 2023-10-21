#include "main.h"
/**
 * forkAndExecute - fork and execute the command
 * @argC: array of arguments
 * @programName: the program name
 * @LExitST: exit status
 * Return: int
 */
int forkAndExecute(char **argC, char *programName, int *LExitST)
{
	int status;
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		freeTok(argC);
		*LExitST = EXIT_FAILURE;
		return (-1);
	}
	else if (pid == 0)
	{
		ChildExecute(argC, programName, LExitST);
	}
	else
	{
		if (wait(&status) == -1)
		{
			freeTok(argC);
			*LExitST = EXIT_FAILURE;
			return (-1);
		}
		*LExitST = WEXITSTATUS(status);
	}
	return (*LExitST);
}
