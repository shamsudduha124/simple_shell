#include "shell.h"

/**
* comnd_si - determines if a file is an executable comman
* @info: the info structure
* @path: path to 2 file
*
* Return: 1 if true 0 otherwise
*/
int comnd_si(mifo_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
* xtr_pub - duplicates characters
* @pathstr: the PATH strings
* @start: starting index
* @stop: stopping index
*
* Return: pointer to new buffer
*/
char *xtr_pub(char *pathstr, int start, int stop)
{
	static char buf[1024];

	int shim = 0, kam = 0;

	for (kam = 0, shim = start; shim < stop; shim++)
		if (pathstr[shim] != ':')
			buf[kam++] = pathstr[shim];
	buf[kam] = 0;
	return (buf);
}

/**
* pat_fnda - finds this cmd in the PATH strings
* @info: the info structs
* @pathstr: the PATH strings
* @cmd: the cmd to find
*
* Return: full path of cmd if found or NULL
*/
char *pat_fnda(mifo_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;

	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (comnd_si(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = xtr_pub(pathstr, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (comnd_si(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
