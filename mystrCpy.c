#include "main.h"
/**
 * mystrCpy - same as the strcpy of string.h
 * @dest: the holder
 * @src: the source
 * Return: char *
 */
char *mystrCpy(char *dest, char *src)
{
	char *origin;

	if (dest == NULL || src == NULL)
		return (dest);
	if (dest == src)
		return (dest);
	origin = dest;
	for (; *src != '\0'; dest++, src++)
		*dest = *src;
	*dest = '\0';
	return (origin);
}
