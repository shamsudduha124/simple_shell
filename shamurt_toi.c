#include "shell.h"

/**
 * can_talk - if true shel is interactive
 * @info: struct addres
 *
 * Return: 1 if can_talk mode 0 if not
 */
int can_talk(mifo_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * meli_si - checks if is a delimeter
 * @c: the char 2 checks
 * @delim: the delim strings
 * Return: 1 if true, 0 otherwise
 */
int meli_si(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 *alfa_is - alphabetic character
 *@i: A character to inputs
 *Return: 0 if c is not alphabetic 1 if alphabetic
 */

int alfa_is(int i)
{
	if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - string 4 integar
 *@sr: converted strings
 *Return: null for number in string, 1 otherwise
 */

int _atoi(char *sr)
{
	int pie, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (pie = 0;  sr[pie] != '\0' && flag != 2; pie++)
	{
		if (sr[pie] == '-')
			sign *= -1;

		if (sr[pie] >= '0' && sr[pie] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (sr[pie] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
