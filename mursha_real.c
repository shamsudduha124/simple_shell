#include "shell.h"

/**
 **_filmem - fills a memory area with a byte
 *@s: stringer
 *@b: byte filled
 *@n: number
 *Return: 0
 */
char *_filmem(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _loc - reallocates a block of memory
 * @ptr: reallocation pointer
 * @old_size: block size
 * @new_size: size
 *
 * Return: pointer	to null if error
 */
void *_loc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p = NULL;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * _frimee - frees a ppointer to a string
 * @pp: ppointer to ppointer to be freed
 */
void _frimee(char **pp)
{
	char **dm = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(dm);
}
