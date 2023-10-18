#include "shell.h"

/**
 * _hisrenum - do yo know rema, hisrenum
 * @info: if you want info ask kimba
 * Return: no change
 */
int _hisrenum(mifo_t *info)
{
	mur_t *node = info->history;
	int rema = 0;

	while (node)
	{
		node->num = rema++;
		node = node->next;
	}
	return (info->histcount = rema);
}

/**
 * athens_his - athens and pathens they are from greece
 * @info: wikipedia knows more them
 * Return: nada
 */
int athens_his(mifo_t *info)
{
	int nada, last = 0, caunt_lne = 0;
	ssize_t file_display, ln_rd, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = histor_flget(info);

	if (!filename)
		return (0);

	file_display = open(filename, O_RDONLY);
	free(filename);
	if (file_display == -1)
		return (0);
	if (!fstat(file_display, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	ln_rd = read(file_display, buf, fsize);
	buf[fsize] = 0;
	if (ln_rd <= 0)
		return (free(buf), 0);
	close(file_display);
	for (nada = 0; nada < fsize; nada++)
		if (buf[nada] == '\n')
		{
			buf[nada] = 0;
			buid_lst(info, buf + last, caunt_lne++);
			last = nada + 1;
		}
	if (last != nada)
		buid_lst(info, buf + last, caunt_lne++);
	free(buf);
	info->histcount = caunt_lne;
	while (info->histcount-- >= AMINA_MAX)
		d_nat(&(info->history), 0);
	_hisrenum(info);
	return (info->histcount);
}


/**
 * his_patherns - thats the his_patherns function
 * @info: ask openai for the answer
 * Return: -1 and 1
 */
int his_patherns(mifo_t *info)
{
	ssize_t file_display;
	char *filename = histor_flget(info);
	mur_t *node = NULL;

	if (!filename)
		return (-1);

	file_display = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (file_display == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		lxa_pustfd(node->str, file_display);
		lxa_pustd('\n', file_display);
	}
	lxa_pustd(SHAMS_FLUSH_BUF, file_display);
	close(file_display);
	return (1);
}

/**
 * histor_flget -you know what this does, its for his
 * @info: ask bard google
 * Return: you can allocate it
 */

char *histor_flget(mifo_t *info)
{
	char *fub, *rib;

	rib = _getenv(info, "HOME=");
	if (!rib)
		return (NULL);
	fub = malloc(sizeof(char) * (_strlen(rib) + _strlen(MURT_STRINGTOKEN) + 2));
	if (!fub)
		return (NULL);
	fub[0] = 0;
	_strcpy(fub, rib);
	_strcat(fub, "/");
	_strcat(fub, MURT_STRINGTOKEN);
	return (fub);
}

/**
 * buid_lst - this is the buid_lst function
 * @info: at information info
 * @buf: as for bufallo
 * @caunt_lne: caunt linesss
 *
 * Return: Always 0
 */
int buid_lst(mifo_t *info, char *buf, int caunt_lne)
{
	mur_t *node = NULL;

	if (info->history)
		node = info->history;
	node_ada_end(&node, buf, caunt_lne);

	if (!info->history)
		info->history = node;
	return (0);
}
