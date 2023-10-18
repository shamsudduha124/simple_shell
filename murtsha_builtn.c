#include "shell.h"

/**
 * _historical - displays the history list, one command by line, preceded
 *
 * @info: Structure containing potential arguments. Used to maintain
 *  Return: 0
 */
int _historical(mifo_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias -alias to string
 * @info: struct parameter
 * @str: string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(mifo_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = d_nat(&(info->alias),
		get_node_index(info->alias, n_sw(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - alias to string
 * @info: parameter struct
 * @str: dee string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(mifo_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (node_ada_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: alias node
 *
 * Return: 0 success, 1 error
 */
int print_alias(mur_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _silas - mimics inbuit (man alias)
 * @info: Structure containing potential arguments.
 *  Return: 0
 */
int _silas(mifo_t *info)
{
	int i = 0;
	char *p = NULL;
	mur_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(n_sw(info->alias, info->argv[i], '='));
	}

	return (0);
}
