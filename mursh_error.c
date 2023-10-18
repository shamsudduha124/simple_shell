#include "shell.h"

/**
 * toi_error - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if string otherwise -1 on errors
 */
int toi_error(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * err_prnt - prints an error message
 * @info: return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void err_prnt(mifo_t *info, char *estr)
{
	lxa_pust(info->fname);
	lxa_pust(": ");
	d_prnt(info->line_count, STDERR_FILENO);
	lxa_pust(": ");
	lxa_pust(info->argv[0]);
	lxa_pust(": ");
	lxa_pust(estr);
}

/**
 * d_prnt - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int d_prnt(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = lxa_pustchr;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * nu_base - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *nu_base(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & UNSIGN_CONVETER) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & LOWCASE_CONVERTERR ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * kildcomment - function replaces first instance of '#' with '\0'
 * @adr: address of the string to modifies
 *
 * Return: Always 0;
 */
void kildcomment(char *adr)
{
	int i;

	for (i = 0; adr[i] != '\0'; i++)
		if (adr[i] == '#' && (!i || adr[i - 1] == ' '))
		{
			adr[i] = '\0';
			break;
		}
}
