/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_nb_hard_link.c
*/

#include <sys/stat.h>

int get_nb_hard_link(char const *filepath)
{
    struct stat test;

    if (stat(filepath, &test) == -1)
        return -1;
    return test.st_nlink;
}