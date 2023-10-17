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


/*  readd/writee bufferssize */
#define SHAMS_BUF_SIZE_READS 1024
#define SHAMS_BUF_SIZE_WRITES 1024
#define SHAMS_FLUSH_BUF -1

/* command types*/
#define COMAND_NORM		0
#define COMAND_OR		1
#define COMAND_AND		2
#define COMAND_CHAIN	3

/* nu_base */
#define LOWCASE_CONVERTERR	1
#define UNSIGN_CONVETER		2

#define MURT_USE_GTLINEE 0
#define MURT_TOKNSTR 0

#define MURT_STRINGTOKEN	".simple_shell_history"
#define AMINA_MAX	4096

extern char **environ;


/**
 * struct murtstr -sngly linked lst
 * @num: d number fiuld by getline
 * @next: points 2 d next node
 * @str: thr string
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
 * allowing 1form protype for fxns poin2er struct
 *
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @linecount_flag: if on count this line of input
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: COMAND_type ||, &&, ;
 * @readfd: the fd from which to read line input
 *
 * @arg: string generated from getline containing arguements
 * @argv: an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @histcount: the history line number count
 * @line_count: the error count
 * @err_num: the error number
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

#define INFO_INTAL \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct inbuit - contains a inbuit string and related fxns
 *@type: the inbuit comand flg
 *@func: the fxns
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
int help_me(mifo_t *);
int _historical(mifo_t *);
int _silas(mifo_t *);
ssize_t get_input(mifo_t *);
int _getline(mifo_t *, char **, size_t *);
void sigintHandler(int);
void in_clr(mifo_t *);
void ifo_st(mifo_t *, char **);
void _frinfo(mifo_t *, int);
int _myenv(mifo_t *);
int _mysetenv(mifo_t *);
char *_getenv(mifo_t *, const char *);
int populate_env_list(mifo_t *);
int _myunsetenv(mifo_t *);
char **get_environ(mifo_t *);
int _unsetenv(mifo_t *, char *);
int _setenv(mifo_t *, char *, char *);
char *histor_flget(mifo_t *info);
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
