#include "shell.h"

/**
 * get_environ - returns d string
 * @info: Structure containng potential arguments.
 * Return: null
 */
char **get_environ(mifo_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = lst_t_strng(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}
/**
 * _setenv - Initializ a new environment variable,
 * @info: did u get the message
 * @var: variable nam property
 * @value: tvalueue
 *  Return: nothing
 */
int _setenv(mifo_t *info, char *var, char *value)
{
	char *buf = NULL;
	mur_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	node_ada_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

/**
 * _unsetenv - Remv an environment variable
 * @info: Structua containing potential arguments.
 *  Return: 1 del 0 otherwise
 * @var: d string env var
 */
int _unsetenv(mifo_t *info, char *var)
{
	mur_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = d_nat(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}
