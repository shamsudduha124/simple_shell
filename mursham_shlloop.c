#include "shell.h"

/**
 * hsh - This one is just for running d code
 * @info: This is like his wife
 * @av: and this is like grand daughter
 *
 * Return: they live like family
 */
int hsh(mifo_t *info, char **av)
{
	ssize_t aminr = 0;
	int inbuit_ret = 0;

	while (aminr != -1 && inbuit_ret != -2)
	{
		in_clr(info);
		if (can_talk(info))
			_puts("$ ");
		lxa_pustchr(SHAMS_FLUSH_BUF);
		aminr = get_input(info);
		if (aminr != -1)
		{
			ifo_st(info, av);
			inbuit_ret = find_inbuit(info);
			if (inbuit_ret == -1)
				lk_cd(info);
		}
		else if (can_talk(info))
			_putchar('\n');
		_frinfo(info, 0);
	}
	his_patherns(info);
	_frinfo(info, 1);
	if (!can_talk(info) && info->status)
		exit(info->status);
	if (inbuit_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (inbuit_ret);
}

/**
 * find_inbuit - looking for a hous in zaria
 * @info: call aminat Murtalha
 *
 * Return: -1 not found,
 *			0 executed successfully,
 *			1 found but not successful,
 *		   -2 signals exit()
 */
int find_inbuit(mifo_t *info)
{
	int teef, inbut_ir = -1;
	inbuit_table inbuittbl[] = {
		{"exit", _usedor},
		{"env", _myenv},
		{"help", help_me},
		{"history", _historical},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", d_cm},
		{"alias", _silas},
		{NULL, NULL}
	};

	for (teef = 0; inbuittbl[teef].type; teef++)
		if (_strcmp(info->argv[0], inbuittbl[teef].type) == 0)
		{
			info->line_count++;
			inbut_ir = inbuittbl[teef].func(info);
			break;
		}
	return (inbut_ir);
}

/**
 * lk_cd - i dont know this one oo
 * @info: maybe you dhould aask my partner
 * Return: voillaa
 */
void lk_cd(mifo_t *info)
{
	char *path = NULL;
	int leth, qeth;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (leth = 0, qeth = 0; info->arg[leth]; leth++)
		if (!meli_si(info->arg[leth], " \t\n"))
			qeth++;
	if (!qeth)
		return;

	path = pat_fnda(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		kurf_cm(info);
	}
	else
	{
		if ((can_talk(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && comnd_si(info, info->argv[0]))
			kurf_cm(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			err_prnt(info, "not found\n");
		}
	}
}

/**
 * kurf_cm - comando kill the boss, but i cant.
 * @info: ask people that watch india movies
 *
 * Return: let
 */

void kurf_cm(mifo_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			_frinfo(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				err_prnt(info, "Permission denied\n");
		}
	}
}
