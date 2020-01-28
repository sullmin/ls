/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_uid.c
*/

#include <stdlib.h>
#include <pwd.h>
#include <sys/stat.h>
#include "my.h"

char *get_uid(char const *filepath)
{
    struct stat test;
    char *uid;

    if (stat(filepath, &test) == -1)
        exit (84);
    uid = my_strdup(getpwuid(test.st_uid)->pw_name);
    if (!uid)
        exit(84);
    return uid;
}