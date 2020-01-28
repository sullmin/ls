/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_gid.c
*/

#include <stdlib.h>
#include <grp.h>
#include <sys/stat.h>
#include "my.h"

char *get_gid(char const *filepath)
{
    struct stat test;
    char *gid;

    if (stat(filepath, &test) == -1)
        exit(84);
    gid = my_strdup(getgrgid(test.st_gid)->gr_name);
    if (!gid)
        exit(84);
    return gid;
}