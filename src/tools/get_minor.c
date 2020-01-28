/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_minor.c
*/

#include <sys/stat.h>
#include <sys/sysmacros.h>

unsigned int get_minor(char const *filepath)
{
    unsigned int my_minor;
    struct stat test;

    if (stat(filepath, &test) == -1)
        return -1;
    my_minor = minor(test.st_rdev);
    return my_minor;
}