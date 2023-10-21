#include "main.h"
/**
 * main - main function
 * @ac: arg count
 * @argv: arg vector
 * Return: 0 (success) or 1 (failure)
 */
int main(int ac, char *argv[])
{
	int LExitST = 0;
	int interactive = isatty(STDIN_FILENO);
	(void)ac;

	LExitST = readCommand(argv[0], interactive);
	return (LExitST);
}
