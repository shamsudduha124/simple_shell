#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf:adr for buffer
 * @len:adr for len var
 *
 * Return: bytes read
 */
ssize_t input_buf(mifo_t *info, char **buf, size_t *len)
{
	ssize_t r = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if MURT_USE_GTLINEE
		r = getline(buf, &len_p, stdin);
#else
		r = _getline(info, buf, &len_p);
#endif
		if (r > 0)
		{
			if ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
				r--;
			}
			info->linecount_flag = 1;
			kildcomment(*buf);
			buid_lst(info, *buf, info->histcount++);
			{
				*len = r;
				info->cmd_buf = buf;
			}
		}
	}
	return (r);
}

/**
 * sigintHandler - for ctrl-C command
 * @sig_num: the signal number
 *
 * Return: NULL
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(SHAMS_FLUSH_BUF);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
ssize_t get_input(mifo_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(SHAMS_FLUSH_BUF);
	r = input_buf(info, &buf, &len);
	if (r == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		amin_chan(info, buf, &j, i, len);
		while (j < len)
		{
			if (sha_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = COMAND_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (r);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(mifo_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, SHAMS_BUF_SIZE_READS);
	if (r >= 0)
		*i = r;
	return (r);
}


/**
 * _getline - gets the next line of input from STDIN
 * @info: parmeter structs
 * @ptr: pointer to preallocated ptr buffer
 * @length: size of preallocated ptr buffer
 *
 * Return: s
 */
int _getline(mifo_t *info, char **ptr, size_t *length)
{
	static char buf[SHAMS_BUF_SIZE_READS];
	static size_t i, len;
	size_t nife;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	nife = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _loc(p, s, s ? s + nife : nife + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, nife - i);
	else
		_strncpy(new_p, buf + i, nife - i + 1);

	s += nife - i;
	i = nife;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
