#include "shell.h"

/**
 * in_clr - initializes info_t struct
 * @info: struct address
 */
void in_clr(mifo_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * ifo_st - initializes info_t struct
 * @info: struct address
 * @av: argument vector
 */
void ifo_st(mifo_t *info, char **av)
{
	int i = 0;

	info->fname = av[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (i = 0; info->argv && info->argv[i]; i++)
			;
		info->argc = i;

		pl_alas(info);
		pl_vr(info);
	}
}


