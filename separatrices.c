#include "main.h"
/**
 * separatrices - to separate a string
 * @s: the input string to be tokenized
 * Return: a pointer to the next token found, or NULL.
 */
char **separatrices(char *s)
{
	const char delimiteurs[] = " \t\n";
	char **NewTok = NULL;
	char *token;
	int i = 0;

	token = strtok(s, delimiteurs);
	while (token != NULL)
	{
		NewTok = (char **)myRealloc(NewTok, i * sizeof(char *),
				(i + 1) * sizeof(char *));
		if (NewTok == NULL)
		{
			perror("realloc error");
			exit(EXIT_FAILURE);
		}
		NewTok[i] = malloc(myStrlen(token) + 1);
		if (NewTok[i] == NULL)
		{
			perror("malloc error");
			freeTok(NewTok);
			exit(EXIT_FAILURE);
		}
		mystrCpy(NewTok[i], token);
		i++;
		token = strtok(NULL, delimiteurs);
	}
	NewTok = (char **)myRealloc(NewTok, i * sizeof(char *)
			, (i + 1) * sizeof(char *));
	if (NewTok == NULL)
	{
		perror("realloc error");
		exit(EXIT_FAILURE);
	}
	NewTok[i] = NULL;
	return (NewTok);
}
