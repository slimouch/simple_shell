#include "main.h"
/**
 * Duplicate - a customized strdup function
 * @s: the string to duplicate
 * Return: the duplicate one
 */
char *Duplicate(const char *s)
{
	char *dup = NULL;
	int i, len = 0;

	if (s == NULL)
		return (NULL);
	while (s[len] != '\0')
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup ==  NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		dup[i] = s[i];
	return (dup);
}
