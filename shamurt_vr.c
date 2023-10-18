#include "shell.h"

/**
 * pl_sr - strng chnager
 * @old: former string
 * @new: current guy
 *
 * Return: 1 true 0 false
 */
int pl_sr(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
 * amin_chan - checks we cont on last status
 * @info: the struct
 * @buf: the buffer
 * @p: address  in buffalo
 * @i: starting n buffalo
 * @len: length buffalo
 *
 * Return: Void
 */
void amin_chan(mifo_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t esc = *p;

	if (info->cmd_buf_type == COMAND_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			esc = len;
		}
	}
	if (info->cmd_buf_type == COMAND_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			esc = len;
		}
	}

	*p = esc;
}


/**
 * sha_chain - i dont really know oo but i feel
 * @info: inrmatory
 * @buf:buffalo
 * @p: pointtdfgd
 *
 * Return: do your work
 */
int sha_chain(mifo_t *info, char *buf, size_t *p)
{
	size_t esc = *p;

	if (buf[esc] == '|' && buf[esc + 1] == '|')
	{
		buf[esc] = 0;
		esc++;
		info->cmd_buf_type = COMAND_OR;
	}
	else if (buf[esc] == '&' && buf[esc + 1] == '&')
	{
		buf[esc] = 0;
		esc++;
		info->cmd_buf_type = COMAND_AND;
	}
	else if (buf[esc] == ';')
	{
		buf[esc] = 0;
		info->cmd_buf_type = COMAND_CHAIN;
	}
	else
		return (0);
	*p = esc;
	return (1);
}

/**
 * pl_alas - kimba please dont flag me
 * @info: i dont knw
 *
 * Return: please
 */
int pl_alas(mifo_t *info)
{
	int i;
	mur_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = n_sw(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}

/**
 * pl_vr - god help us oo plg varaible
 * @info: it is well
 *
 * Return: yes / no
 */
int pl_vr(mifo_t *info)
{
	int i = 0;
	mur_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			pl_sr(&(info->argv[i]),
				_strdup(nu_base(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			pl_sr(&(info->argv[i]),
				_strdup(nu_base(getpid(), 10, 0)));
			continue;
		}
		node = n_sw(info->env, &info->argv[i][1], '=');
		if (node)
		{
			pl_sr(&(info->argv[i]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		pl_sr(&info->argv[i], _strdup(""));

	}
	return (0);
}
