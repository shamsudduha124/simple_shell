#include "shell.h"

/**
 * afrie - frees the memory of a pointa
 * @ptr: the pointer 2 be freed
 *
 * Return: 1 if successful 0 if not
 */
int afrie(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
