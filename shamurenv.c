#include "shell.h"
/**
 * _myenv - prints my current environment
 * @info: Structure containing potential arguments.
 *
 * Return: Always 0
 */
int _myenv(mifo_t *info)
{
	plstr(info->env);
	return (0);
}

/**
 * _getenv - gets the val of an environ variable
 * @info: Structure contaning potential arguments
 * @name: env var nam
 *
 * Return: the value
 */
char *_getenv(mifo_t *info, const char *name)
{
	mur_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments.
 *  Return: Always 0
 */
int _mysetenv(mifo_t *info)
{
	if (info->argc != 3)
	{
		lxa_pust("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(mifo_t *info)
{
	int i;

	if (info->argc == 1)
	{
		lxa_pust("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(mifo_t *info)
{
	mur_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		node_ada_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
