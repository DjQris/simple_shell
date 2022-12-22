#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

/* Utility functions */
int _atoi(char *s);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t len);
char *_strdup(char *str);
int _strlen(const char *s);

#endif
