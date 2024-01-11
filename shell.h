#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>

#define DELIM " \t\n"
extern char **environ;

char *read_line(void);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
void reverse_string(char *str, int len);
char *_itoa(int n);
char **tokenize(char *line);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _execute(char **command, char **argv, int index);
void free2Darr(char **arr);
char *_getenv(char *var);
char *_getPath(char *command);
void printerr(char *name, char *cmd, int index);

int is_builtin(char *command);
void handle_builtin(char **command, char **argv, int *status, int index);
void exit_shell(char **command, char **argv, int *status, int index);
void print_env(char **command, int *status);

int is_positive_number(char *str);
int _atoi(char *str);


#endif
