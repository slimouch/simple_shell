#include "main.h"
/**
 * mystrCat - my customized strcat function
 * @dest: the holder of the final string
 * @src: the source
 * Return: char *
 */
char *mystrCat(char *dest, char *src)
{
	char *NewDest = dest;

	while (*dest != '\0')
		dest++;
	for (; *src != '\0'; dest++, src++)
		*dest = *src;
	*dest = '\0';
	return (NewDest);
}
