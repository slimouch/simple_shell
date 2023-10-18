#include "main.h"
/**
 * Which - a function that search the full path of a cmd
 * @cmd: the command
 * Return: the full path of command
 */
char *Which(char *cmd)
{
	struct stat st;
	char *pathEnv = Getenvi("PATH");
	char *tmp = Duplicate(pathEnv);
	char *path = strtok(pathEnv, ":");

	if (stat(cmd, &st) == 0)
		return (cmd);
	while (path != NULL)
	{
	char *FULLp = (char *)malloc(myStrlen(path) + myStrlen(cmd) + 2);

	if (FULLp == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	mystrCpy(FULLp, path);
	mystrCat(FULLp, "/");
	mystrCat(FULLp, cmd);
	if (stat(FULLp, &st) == 0)
	{
		free(tmp);
		return (FULLp);
	}
	free(FULLp);
	path = strtok(NULL, ":");
	}
	free(tmp);
	return (NULL);
}
