#include "main.h"
/**
 * readCommand - reads the input
 * @programName: the program name
 * @interactive: interactive mode
 * Return: void
 */
void readCommand(char *programName, int interactive)
{
	char *bf = NULL;
	size_t sizeBF = 0;
	ssize_t NbCh;
	char **argC = NULL;

	while (1)
	{
		write(1, "$ ", 2);
		NbCh = getline(&bf, &sizeBF, stdin);
		if (NbCh == -1)
		{
			if (NbCh == EOF)
			{
				if (interactive)
					write(1, "\n", 1);
				break;
			}
			else
			{
				perror("getline error");
				free(bf);
				freeTok(argC);
				exit(EXIT_FAILURE);
			}
		}
		if (NbCh <= 1)
			continue;
		bf[NbCh - 1] = '\0';
		processCmd(programName, bf, interactive);
	}
	free(bf);
	bf = NULL;
}
