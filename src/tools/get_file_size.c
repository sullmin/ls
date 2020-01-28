/*
** EPITECH PROJECT, 2019
** get_file_size.c
** File description:
** my_ls
*/

#include <sys/stat.h>

int get_file_size(char const *filepath)
{
    struct stat test;

    if (stat(filepath, &test) == -1)
        return -1;
    return test.st_size;
}