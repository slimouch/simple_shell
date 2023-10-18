#include "main.h"
/**
 * myRealloc - my customized realloc function
 * @p: pointer to a memory
 * @old: old size
 * @n: new size
 * Return: void *
 */
void *myRealloc(void *p, size_t old, size_t n)
{
	char *tmp;
	size_t Size;

	if (!p)
		return (malloc(n));
	if (!n)
	{
		free(p);
		return (NULL);
	}
	if (n == old)
		return (p);
	tmp = malloc(n);
	if (!tmp)
		return (NULL);
	Size = old < n ? old : n;
	while (Size--)
		tmp[Size] = ((char *)p)[Size];
	free(p);
	return (tmp);
}
