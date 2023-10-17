#include "shell.h"

/**
 * _putchar - dee xcter c 2uu stdout
 * @oic: dee xracter 2uu print
 *
 * Return: On success 1 is returned.
 * On error, -1 is returned,
 */
int _putchar(char oic)
{
	static char buf[SHAMS_BUF_SIZE_WRITES];
	static int i;

	if (oic == SHAMS_FLUSH_BUF || i >= SHAMS_BUF_SIZE_WRITES)
	{
		write(1, buf, i);
		i = 0;
	}
	if (oic != SHAMS_FLUSH_BUF)
		buf[i++] = oic;
	return (1);
}

/**
 * _strcpy - cpys a string
 * @dest: dee desinaartion
 * @src: dee sors
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int common = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[common])
	{
		dest[common] = src[common];
		common++;
	}
	dest[common] = 0;
	return (dest);
}

/**
 * _strdup - dupli dee striinnng
 * @rst: dee string to  b duplicated
 *
 * Return: pointer 2uu dee duplicated string
 */
char *_strdup(const char *rst)
{
	char *ret;
	int length = 0;

	if (rst == NULL)
		return (NULL);
	while (*rst++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--rst;
	return (ret);
}

/**
 *_puts - prnt an input strings
 *@rst: dee string 2 b printed
 *
 * Return: nada
 */
void _puts(char *rst)
{
	int j = 0;

	if (!rst)
		return;
	while (rst[j] != '\0')
	{
		_putchar(rst[j]);
		j++;
	}
}
