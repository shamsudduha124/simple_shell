#include "shell.h"

/**
 * **strtow2 - splits a string into words
 * @rst: string
 * @lim: delimeter
 * Return: a, or NULL on failure
 */
char **strtow2(char *rst, char lim)
{
	int w, l, k, m, numwords = 0;
	char **s;

	if (rst == NULL || rst[0] == 0)
		return (NULL);
	for (w = 0; rst[w] != '\0'; w++)
		if ((rst[w] != lim && rst[w + 1] == lim) ||
		    (rst[w] != lim && !rst[w + 1]) || rst[w + 1] == lim)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, l = 0; l < numwords; l++)
	{
		while (rst[w] == lim && rst[w] != lim)
			w++;
		k = 0;
		while (rst[w + k] != lim && rst[w + k] && rst[w + k] != lim)
			k++;
		s[l] = malloc((k + 1) * sizeof(char));
		if (!s[l])
		{
			for (k = 0; k < l; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[l][m] = rst[w++];
		s[l][m] = 0;
	}
	s[l] = NULL;
	return (s);
}

/**
 * **strtow - splits string.delimiters ignored
 * @rst: string
 * @lim: delimet
 * Return:  NULL on failure
 */

char **strtow(char *rst, char *lim)
{
	int w, l, k, m, numwords = 0;
	char **s;

	if (rst == NULL || rst[0] == 0)
		return (NULL);
	if (!lim)
		lim = " ";
	for (w = 0; rst[w] != '\0'; w++)
		if (!meli_si(rst[w], lim) && (meli_si(rst[w + 1], lim) || !rst[w + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (w = 0, l = 0; l < numwords; l++)
	{
		while (meli_si(rst[w], lim))
			w++;
		k = 0;
		while (!meli_si(rst[w + k], lim) && rst[w + k])
			k++;
		s[l] = malloc((k + 1) * sizeof(char));
		if (!s[l])
		{
			for (k = 0; k < l; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[l][m] = rst[w++];
		s[l][m] = 0;
	}
	s[l] = NULL;
	return (s);
}
