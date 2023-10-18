#include "main.h"
/**
 * processCmd - to process the cmd
 * @programName: the name of the program
 * @cmd: the command to handle
 * @interactive: mode interactive
 * Return: void
 */
void processCmd(const char *programName, char *cmd, int interactive)
{
	char **argC = separatrices(cmd);

	if (mystrCmp(argC[0], "exit") == 0)
	{
		handleExit(argC);
		free(cmd);
		exit(0);
	}
	else
		forkAndExecute(argC, programName);
	freeTok(argC);
	if (interactive)
		write(1, "\n", 1);
}
