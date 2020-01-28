/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_time.c
*/

#include <time.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "my.h"

char *get_time(const char *filepath)
{
    struct stat test;
    char *time;

    if (stat(filepath, &test) == -1)
        exit (84);
    time = ctime(&test.st_mtime);
    time[my_strlen(time) - 1] = '\0';
    time = my_strdup(time);
    if (!time)
        exit(84);
    return time;
}