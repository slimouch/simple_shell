#include "main.h"
/**
 * handleExit - to handle the built-in command exit
 * @argC: the input
 * Return: void
 */
void handleExit(char **argC)
{
	int i = 0;

	while (argC[i] != NULL)
	{
		free(argC[i]);
		i++;
	}
	free(argC);
}
