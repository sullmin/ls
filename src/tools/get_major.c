/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_major.c
*/

#include <sys/stat.h>
#include <sys/sysmacros.h>

unsigned int get_major(char const *filepath)
{
    unsigned int my_major;
    struct stat test;

    if (stat(filepath, &test) == -1)
        return -1;
    my_major = major(test.st_rdev);
    return my_major;
}