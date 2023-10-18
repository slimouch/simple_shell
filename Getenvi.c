#include "main.h"
/**
 * Getenvi - a function that gets the full path env
 * @name: name
 * Return: a pointer to the str containing the name or NULL
 */
char *Getenvi(char *name)
{
	char *token;
	char *del = "=";
	int i = 0;
	char *tmp;

	while (environ[i])
	{
		tmp = Duplicate(environ[i]);
		token = strtok(tmp, del);
		if (mystrCmp(name, token) == 0)
			return (strtok(NULL, del));
		free(tmp);
		i++;
	}
	return (NULL);
}
