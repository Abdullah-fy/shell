#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>


void print_prompt();
void execmd(char **argv);
ssize_t read_input(char **lineptr, size_t *n);
char *get_location(char *command);
int stat(const char *pathname, struct stat *statbuf);
