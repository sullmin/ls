/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** get_malloc_size
*/

#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_ls.h"
#include "my.h"

static void special_gest(const char *filepath, char *end, int *i)
{
    if (filepath[my_strlen(filepath) - 1] != '/') {
        end[*i] = '/';
        *i += 1;
    }
}

char *take_file_in_dir(const char *filepath, const char *name)
{
    int i;
    char *end;
    int size_str;

    if (filepath[my_strlen(filepath) - 1] == '/')
        size_str = my_strlen(filepath) + my_strlen(name) + 1;
    else
        size_str = my_strlen(filepath) + my_strlen(name) + 2;
    end = malloc(sizeof(char) * size_str);
    if (!end)
        exit (84);
    end[size_str - 1] = '\0';
    for (i = 0; filepath[i] != '\0'; i++)
        end[i] = filepath[i];
    special_gest(filepath, end, &i);
    for (int u = 0; name[u] != '\0'; u++) {
        end[i] = name[u];
        i++;
    }
    return end;
}

static void my_dir_check(DIR *my_dir)
{
    if (!my_dir)
        exit(84);
}

int get_malloc_size(const char *filepath, my_arg_t *my_arg)
{
    int nb_file = 0;
    char *file;
    DIR *my_dir = opendir(filepath);
    struct dirent *my_dir_contents;
    struct stat test;

    my_dir_check(my_dir);
    my_dir_contents = readdir(my_dir);
    while (my_dir_contents) {
        if (my_dir_contents->d_name[0] != '.' || my_arg->t_d || my_arg->t_a) {
            file = take_file_in_dir(filepath, my_dir_contents->d_name);
            nb_file++;
            if (stat(file, &test) == -1)
                exit(84);
            free(file);
        }
        my_dir_contents = readdir(my_dir);
    }
    closedir(my_dir);
    return nb_file;
}