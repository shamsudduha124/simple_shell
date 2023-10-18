#include "shell.h"

/**
 * _usedor - exits the shell
 * @info: Structure containing arguments Used to maintain
 *          constant prototpe
 *  Return: (0) if info.argv[0] not "exit"
 */
int _usedor(mifo_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = toi_error(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			err_prnt(info, "Illegal number: ");
			lxa_pust(info->argv[1]);
			lxa_pustchr('\n');
			return (1);
		}
		info->err_num = toi_error(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * d_cm - change currnt directree
 * @info: Structure containing potential arguments.
 *  Return: nothing
 */
int d_cm(mifo_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /*  what is this? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* what  this b? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		err_prnt(info, "can't cd to ");
		lxa_pust(info->argv[1]), lxa_pustchr('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * help_me - changes the current directory pls
 * @info: Structure containing potential arguments.
 *          constant function prototype.
 *  Return: 0
 */
int help_me(mifo_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
