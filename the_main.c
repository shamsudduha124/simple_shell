#include "shell.h"

/**
 * main - the gatekeeper
 * @ac: your arg counter
 * @av: your argument vector
 *
 * Return: 0 on voilla, 1 on error
 */
int main(int ac, char **av)
{
	mifo_t info[] = { INFO_INTAL };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				lxa_pust(av[0]);
				lxa_pust(": 0: cannot open ");
				lxa_pust(av[1]);
				lxa_pust(": No such file");
				lxa_pustchr('\n');
				lxa_pustchr(SHAMS_FLUSH_BUF);
				exit(2);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	athens_his(info);
	hsh(info, av);
	return (EXIT_SUCCESS);
}
