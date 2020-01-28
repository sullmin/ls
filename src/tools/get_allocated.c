/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <sys/stat.h>

int get_allocated(char const *filepath)
{
    struct stat test = {0};

    if (stat(filepath, &test) == -1)
        return -1;
    return test.st_blocks;
}