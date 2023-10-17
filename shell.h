#ifndef _SHELL_H_
#define _SHELL_H_

#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define INFO_INTAL \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}
#define COMAND_CHAIN 3
#define SHAMS_FLUSH_BUF -1
#define MURT_STRINGTOKEN ".simple_shell_history"
#define COMAND_NORM 0
#define SHAMS_BUF_SIZE_READS 1024
#define AMINA_MAX 4096
#define UNSIGN_CONVETER 2
#define LOWCASE_CONVERTERR 1
#define COMAND_AND 2
#define SHAMS_BUF_SIZE_WRITES 1024
#define MURT_TOKNSTR 0
#define COMAND_OR 1
#define MURT_USE_GTLINEE 0


extern char **environ;

/**
 * struct murtstr -its a structure for murtstruct
 * @num: like numberline
 * @next: then u move to next
 * @str: this is there oga string
 *
 */
typedef struct murtstr
{
	int num;
	struct murtstr *next;
	char *str;
} mur_t;

/**
 * struct mohbadpass - contans psudo-arg 2 pas to functn
 *
 * @fname: the file name
 * @env: the enviroment
 * @linecount_flag: on if linecount_flag
 * @environ: the environ
 * @history: historical level
 * @alias: as known as alias
 * @env_changed: like changing where you stay
 * @status: The status like whatsapp statsus
 * @cmd_buf: the main commando in the buffer
 * @cmd_buf_type: na scope ||, &&, ;
 * @readfd: for food only after reading
 *
 * @arg: when you argue too much
 * @argv: variable in arguing
 * @path: the straight road to meet jesus
 * @argc: counting your blessing by arguing
 * @histcount: aristotle history
 * @line_count: it can turn to a vamp
 * @err_num: the main vamiperr
 *
 * xtr_pub - dup_charas
 */

typedef struct mohbadpass
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	mur_t *env;
	mur_t *history;
	mur_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* COMAND_type ||, &&, ; */
	int readfd;
	int histcount;
} mifo_t;

/**
 *struct inbuit - lets say you want to build something
 *@type: the type of block you want to build
 *
 *@func: and the chimpazee monkey post
 */
typedef struct inbuit
{
	char *type;
	int (*func)(mifo_t *);
} inbuit_table;


/* constants  prototypes */
int hsh(mifo_t *, char **);
int find_inbuit(mifo_t *);
void lk_cd(mifo_t *);
void kurf_cm(mifo_t *);
int comnd_si(mifo_t *, char *);
char *xtr_pub(char *, int, int);
char *pat_fnda(mifo_t *, char *, char *);
int loophsh(char **);
void lxa_pust(char *);
int lxa_pustchr(char);
int lxa_pustd(char c, int fd);
int lxa_pustfd(char *str, int fd);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);
int _strlen(char *);
int _putchar(char);
void _puts(char *);
char *_strdup(const char *);
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);
char *_strncat(char *, char *, int);
char **strtow(char *, char *);
char **strtow2(char *, char);
char *_filmem(char *, char, unsigned int);
void _frimee(char **);
void *_loc(void *, unsigned int, unsigned int);
int afrie(void **);
int can_talk(mifo_t *);
int meli_si(char, char *);
int alfa_is(int);
int _atoi(char *);
int toi_error(char *);
void err_prnt(mifo_t *, char *);
int d_prnt(int, int);
char *nu_base(long int, int, int);
void kildcomment(char *);
int _usedor(mifo_t *);
int d_cm(mifo_t *);

int _silas(mifo_t *);
int help_me(mifo_t *);
int _historical(mifo_t *);
ssize_t get_input(mifo_t *);
int _getline(mifo_t *, char **, size_t *);
void sigintHandler(int);
void in_clr(mifo_t *);

void _frinfo(mifo_t *, int);
void ifo_st(mifo_t *, char **);
int _unsetenv(mifo_t *, char *);
int _setenv(mifo_t *, char *, char *);
char *histor_flget(mifo_t *info);
int _myenv(mifo_t *);
int _mysetenv(mifo_t *);
char *_getenv(mifo_t *, const char *);
int populate_env_list(mifo_t *);
int _myunsetenv(mifo_t *);
char **get_environ(mifo_t *);
int his_patherns(mifo_t *info);
int athens_his(mifo_t *info);
int buid_lst(mifo_t *info, char *buf, int linecount);
int _hisrenum(mifo_t *info);
mur_t *node_ada(mur_t **, const char *, int);
mur_t *node_ada_end(mur_t **, const char *, int);
size_t plstr(const mur_t *);
int d_nat(mur_t **, unsigned int);
void free_list(mur_t **);

size_t lst_ln(const mur_t *);
char **lst_t_strng(mur_t *);
ssize_t get_node_index(mur_t *, mur_t *);
size_t print_list(const mur_t *);
mur_t *n_sw(mur_t *, char *, char);
int sha_chain(mifo_t *, char *, size_t *);
void amin_chan(mifo_t *, char *, size_t *, size_t, size_t);
int pl_alas(mifo_t *);
int pl_vr(mifo_t *);
int pl_sr(char **, char *);

#endif
