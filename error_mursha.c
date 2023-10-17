#include "shell.h"

/**
 *lxa_pust - prints an input
 * @res: the string to be printed
 *
 * Return: Nothing
 */
void lxa_pust(char *res)
{
	int aye = 0;

	if (!res)
		return;
	while (res[aye] != '\0')
	{
		lxa_pustchr(res[aye]);
		aye++;
	}
}

/**
 * lxa_pustchr - writes the character c to stderr
 * @c: The character
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int lxa_pustchr(char c)
{
static int aye;
	static char buf[SHAMS_BUF_SIZE_WRITES];

	if (c == SHAMS_FLUSH_BUF || aye >= SHAMS_BUF_SIZE_WRITES)
	{
		write(2, buf, aye);
		aye = 0;
	}
	if (c != SHAMS_FLUSH_BUF)
		buf[aye++] = c;
	return (1);
}

/**
 * lxa_pustd - writes the character c to fd
 * @c: The character
 * @fd: The filedescriptor
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int lxa_pustd(char c, int fd)
{
	static int i;
	static char buf[SHAMS_BUF_SIZE_WRITES];

	if (c == SHAMS_FLUSH_BUF || i >= SHAMS_BUF_SIZE_WRITES)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != SHAMS_FLUSH_BUF)
		buf[i++] = c;
	return (1);
}

/**
 *lxa_pustfd - prints an input string
 * @srt: the string
 * @fd: the filedescriptor
 *
 * Return: chars put
 */
int lxa_pustfd(char *srt, int fd)
{
	int i = 0;

	if (!srt)
		return (0);
	while (*srt)
	{
		i += lxa_pustd(*srt++, fd);
	}
	return (i);
}
