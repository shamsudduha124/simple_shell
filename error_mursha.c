#include "shell.h"

/**
 *lxa_pust - prints an inpt
 * @res: the string to be printd
 *
 * Return: Nothin
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
 * lxa_pustchr - writes the character c to stder
 * @c: The characta
 *
 * Return: On success 1.
 * On error, -1 is returned
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
 * lxa_pustd - writes the characta c to fd
 * @c: The characta
 * @fd: The filedescriptar
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
 *lxa_pustfd - prints an input strig
 * @srt: the string
 * @fd: the filedescripto
 *
 * Return: char put
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

