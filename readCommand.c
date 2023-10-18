#include "main.h"
/**
 * readCommand - reads the input
 * @programName: the program name
 * Return: void
 */
void readCommand(const char *programName)
{
	char *bf;
	size_t sizeBF;
	ssize_t NbCh;
	char **argC = NULL;

	bf = NULL;
	sizeBF = 0;
	while (1)
	{
		write(1, "$ ", 2);
		NbCh = getline(&bf, &sizeBF, stdin);
		if (NbCh <= 1)
		{
			if (NbCh == -1)
			{
				if (NbCh == EOF && isatty(STDIN_FILENO))
				{
					write(1, "\n", 1);
					break;
				}
				perror("getline error");
				free(bf);
				freeTok(argC);
				exit(EXIT_FAILURE);
			}
			continue;
		}
		bf[NbCh - 1] = '\0';
		argC = separatrices(bf);
		if (mystrCmp(argC[0], "exit") == 0)
		{
			handleExit(argC);
			free(bf);
			exit(0);
		}
		else
			forkAndExecute(argC, programName);
		freeTok(argC);
	}
	free(bf);
	bf = NULL;
}
