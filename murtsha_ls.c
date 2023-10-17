#include "shell.h"

/**
 * node_ada - the head node
 * @head: adddres of the header
 * @str: goodman string
 * @num: num is known as number
 * Return: close the door
 */
mur_t *node_ada(mur_t **head, const char *str, int num)
{
	mur_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(mur_t));
	if (!new_head)
		return (NULL);
	_filmem((void *)new_head, 0, sizeof(mur_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * node_ada_end - the node is an adder
 * @head:the head of the familiar
 * @str: last born
 * @num: the amount of age in number
 *
 * Return: i know you like it
 */
mur_t *node_ada_end(mur_t **head, const char *str, int num)
{
	mur_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(mur_t));
	if (!new_node)
		return (NULL);
	_filmem((void *)new_node, 0, sizeof(mur_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * plstr - prints only the str element of a mur_t linked list
 * @h: this i dint know
 *
 * Return: last one
 */
size_t plstr(const mur_t *h)
{
	size_t tea = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		tea++;
	}
	return (tea);
}

/**
 * free_list - you are all free now
 * @head_ptr:point to the address
 *
 * Return: evrybody dies now
 */
void free_list(mur_t **head_ptr)
{
	mur_t *head, *node, *next_node;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}

/**
 * d_nat - my guy delete node
 * @head: the bid head
 * @index: kill them joor
 *
 * Return: the end
 */
int d_nat(mur_t **head, unsigned int index)
{
	mur_t *node, *prev_node;
	unsigned int noda = 0;

	if (!*head || !head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (noda == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		noda++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}


