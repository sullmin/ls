/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdbool.h>
#include "my.h"
#include "my_ls.h"

static char *make_dir_filepath(const char *filepath, const char *dir_name)
{
    int i;
    char *ret;
    int size1 = my_strlen(filepath);
    int size2 = my_strlen(dir_name);

    if (filepath[size1 - 1] == '/')
        ret = malloc(sizeof(char) * (size1 + size2 + 1));
    else ret = malloc(sizeof(char) * (size1 + size2 + 2));
    for (i = 0; filepath[i] != '\0'; i++)
        ret[i] = filepath[i];
    if (filepath[i - 1] != '/') {
        ret[i] = '/';
        i++;
    }
    for (int u = 0; dir_name[u] != '\0'; u++) {
        ret[i + u] = dir_name[u];
        ret[i + u + 1] = '\0';
    }
    return ret;
}

static bool no_infinit_loop(const char* file)
{
    if (my_strcmp(file, "..") == 0)
        return false;
    if (my_strcmp(file, ".") == 0)
        return false;
    return true;
}

void rmaj_flag(my_file_t **my_file_inf, const char *filepath, my_arg_t *my_arg)
{
    char *file;

    for (int i = 0; my_file_inf[i] != NULL; i++) {
        file = make_dir_filepath(filepath, my_file_inf[i]->name);
        if (is_directory(file) && no_infinit_loop(my_file_inf[i]->name)) {
            my_putchar('\n');
            my_diroctory_recusrsive(file, my_arg);
        }
        free(file);
    }
}