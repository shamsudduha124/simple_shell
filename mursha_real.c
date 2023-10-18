

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
