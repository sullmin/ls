/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include "my.h"

char *get_name(const char *filepath)
{
    int u;
    int val = 1;
    int i;
    char *name;

    if (filepath[my_strlen(filepath) - val] == '/')
        val++;
    for (i = my_strlen(filepath) - val; i >= 0 && filepath[i] != '/'; i--);
    name = malloc(sizeof(char) * (my_strlen(filepath) - i + 1));
    if (!name)
        exit (84);
    for (u = 0; filepath[i + u + 1] != '\0'; u++)
        name[u] = filepath[i + u + 1];
    name[u] = '\0';
    return name;
}