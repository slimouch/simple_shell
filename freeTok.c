#include "main.h"
/**
 * freeTok - free the tokens
 * @tokens: tokens
 * Return: void
 */
void freeTok(char **tokens)
{
	int i;

	if (tokens == NULL)
		return;
	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
		tokens[i] = NULL;
	}
	free(tokens);
}
