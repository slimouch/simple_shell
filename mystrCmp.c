#include "main.h"
/**
 * mystrCmp -  my customized strcmp function
 * @str1: the first string
 * @str2: the second string
 * Return: int
 */
int mystrCmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 > *str2)
			return (1);
		if (*str1 < *str2)
			return (-1);
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return (0);
	if (*str1 == '\0')
		return (-1);
	if (*str2 == '\0')
		return (1);
	return (0);
}
