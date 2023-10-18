#include "shell.h"

/**
 * get_node_index - you better get it
 * @head: touch your head
 * @node: its node not a node
 *
 * Return: negative
 */

ssize_t get_node_index(mur_t *head, mur_t *node)
{
	size_t neg = 0;

	while (head)
	{
		if (head == node)
			return (neg);
		head = head->next;
		neg++;
	}
	return (-1);
}

/**
 * lst_t_strng - you need to  see list->str
 * @head: use your head
 *
 * Return: strings of arrays
 */
char **lst_t_strng(mur_t *head)
{
	mur_t *node = head;
	size_t ray = lst_ln(head), j;
	char **strs;
	char *str;

	if (!head || !ray)
		return (NULL);
	strs = malloc(sizeof(char *) * (ray + 1));
	if (!strs)
		return (NULL);
	for (ray = 0; node; node = node->next, ray++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < ray; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[ray] = str;
	}
	strs[ray] = NULL;
	return (strs);
}

/**
 * print_list - listing prints
 * @h: h means header i told ya
 *
 * Return: all lis
 */
size_t print_list(const mur_t *h)
{
	size_t ray = 0;

	while (h)
	{
		_puts(nu_base(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		ray++;
	}
	return (ray);
}

/**
 * n_sw - the prefix returner
 * @node: head list pointer
 * @prefix: macthmakr
 * @c: good character
 *
 * Return: mode null
 */
mur_t *n_sw(mur_t *node, char *prefix, char c)
{
	char *matcm = NULL;

	while (node)
	{
		matcm = starts_with(node->str, prefix);
		if (matcm && ((c == -1) || (*matcm == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * lst_ln - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t lst_ln(const mur_t *h)
{
	size_t mak = 0;

	while (h)
	{
		h = h->next;
		mak++;
	}
	return (mak);
}
