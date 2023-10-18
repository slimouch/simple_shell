#include "main.h"
/**
 * myStrlen - calculates the length of a string
 * @str: the string
 * Return: size_t
 */
size_t myStrlen(char *str)
{
	size_t l = 0;

	while (str[l] != '\0')
		l++;
	return (l);
}
