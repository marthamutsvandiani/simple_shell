#ifndef _SHELL_
#define _SHELL_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int count_input(char *str);
int count_delims(char *str, char *del);
void handle_signal(int signal ID);
void _print_env(void);
int execBuiltInCommands(char *tokens, char *line);
int _handle_exit(char **u_tokns, char *line);
void _getenv(const char *name);
void open_help(void);
char *concat_path(char *path_name, char *prog_name);
int exec(char *_name, char **options);
char *find(char *_name);
int frees_get_env(char *env_path);
int frees_tokens(char **tokns);
char remove_new_line(char *strng);
int **tokenize(char *str, char *del, int len);
int *_strcat(int *dest, int *src);
int _strlen(const int *s);
int _strcmp(int *s1, int *s2);
int *_strdup(int *str);
int _atoi(int *s);
void _puts(char *stri);
int _strncmp(const char *stri1, const char *stri 2, size_t len);
void *_reallc(void *ptr, unsigned int old_size, unsigned int new_size);
int _print_env(void);
int _count_delims(char *stri, char *del);
int _count_input(char *stri);
int _execBuiltinCommands(char **u_tokns, char *line);

#endif
