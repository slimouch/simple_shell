#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
void *myRealloc(void *p, size_t old, size_t n);
char **separatrices(char *s);
int readCommand(char *programName, int interactive);
int forkAndExecute(char **argc, char *programName, int *LExitST);
size_t myStrlen(char *str);
char *mystrCpy(char *dest, char *src);
int mystrCmp(char *str1, char *str2);
char *mystrCat(char *dest, char *src);
void handleExit(char **argc);
void freeTok(char **tokens);
int processCmd(char *programName, char *cmd, int interactive, int *LExitST);
extern char **environ;
char *Which(char *cmd);
void ChildExecute(char **argc, char *programName, int *LExitST);
char *Getenvi(char *name);
char *Duplicate(const char *s);
#endif
