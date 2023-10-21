#include "main.h"
/**
 * processCmd - to process the cmd
 * @programName: the name of the program
 * @cmd: the command to handle
 * @interactive: mode interactive
 * @LExitST: exit status
 * Return: int
 */
int processCmd(char *programName, char *cmd, int interactive, int *LExitST)
{
	int status, result;
	char **argC = separatrices(cmd);

	if (mystrCmp(argC[0], "exit") == 0)
	{
		handleExit(argC);
		free(cmd);
		exit(*LExitST);
	}
	else
	{
		result = forkAndExecute(argC, programName, LExitST);
		if (result == -1)
		{
			perror("fork error");
			freeTok(argC);
			*LExitST = EXIT_FAILURE;
			return (EXIT_FAILURE);
		}
		if (wait(&status) == -1)
		{
			freeTok(argC);
			*LExitST = EXIT_FAILURE;
			return (EXIT_FAILURE);
		}
		*LExitST = WEXITSTATUS(status);
		return (*LExitST);
	}
	freeTok(argC);
	if (interactive)
		write(1, "\n", 1);
	return (*LExitST);
}
