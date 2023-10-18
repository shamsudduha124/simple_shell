#include "shell.h"
/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @hamz1: the first strang
 * @hamz2: the second strang
 *
 * Return: negative if hamz1 < hamz2,
 * hamz1 > hamz2, 0 if hamz1 == hamz2
 */
int _strcmp(char *hamz1, char *hamz2)
{
	while (*hamz1 && *hamz2)
	{
		if (*hamz1 != *hamz2)
			return (*hamz1 - *hamz2);
		hamz1++;
		hamz2++;
	}
	if (*hamz1 == *hamz2)
		return (0);
	else
		return (*hamz1 < *hamz2 ? -1 : 1);
}
/**
 * _strlen - returns the length of a string
 * @ring: de strng whose lent 2 check
 *
 * Return: integer length of string
 */
int _strlen(char *ring)
{
	int rim = 0;

	if (!ring)
		return (0);

	while (*ring++)
		rim++;
	return (rim);
}

/**
 * _strcat - cocatente 2uu srings
 * @dest: dee destinatn buffa
 * @src: dee sorce buffa
 *
 * Return: pointa 2u destinatn buffa
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}


/**
 * starts_with - checks if substak stat wit murstak
 * @murstak: strnng 2u sach
 * @substak: de substring 2u find
 *
 * Return: adres off nex chara off murstak oor NNULL
 */
char *starts_with(const char *murstak, const char *substak)
{
	while (*substak)
		if (*substak++ != *murstak++)
			return (NULL);
	return ((char *)murstak);
}
