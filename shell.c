#include "main.h"
/**
 * main - main function
 * @ac: arg count
 * @argv: arg vector
 * Return: 0 (success) or 1 (failure)
 */
int main(int ac, char *argv[])
{
	(void)ac;
	readCommand(argv[0]);
	return (0);
}
