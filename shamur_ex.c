#include "shell.h"

/**
 **_strncpy - copys the stng
 *@dest: the desnatn stnng 2uu bee copied 2
 *@src: dee sorce strnngg
 *@kimba: d amaount off characters 2uu bee copyd
 *Return: dee concatenated strrnngg
 */
char *_strncpy(char *dest,  char *src, int kimba)
{
	char *amina = dest;
	int ji, masun;

	ji = 0;
	while (src[ji] != '\0' && ji < kimba - 1)
	{
		dest[ji] = src[ji];
		ji++;
	}
	if (ji < kimba)
	{
		masun = ji;
		while (masun < kimba)
		{
			dest[masun] = '\0';
			masun++;
		}
	}
	return (amina);
}

/**
 **_strncat - concatenates 2uu strings
 *@dest: the first string
 *@src: the second string
 *@kimba: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int kimba)
{
	int ji, masun;
	char *s = dest;

	masun = 0;
	ji = 0;
	while (dest[ji] != '\0')
		ji++;
	while (src[masun] != '\0' && masun < kimba)
	{
		dest[ji] = src[masun];
		ji++;
		masun++;
	}
	if (masun < kimba)
		dest[ji] = '\0';
	return (s);
}

/**
 **_strchr - locates a xcter ing a strg
 *@rst: the string to be parsed
 *@arc: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *rst, char arc)
{
	do {
		if (*rst == arc)
			return (rst);
	} while (*rst++ != '\0');

	return (NULL);
}
