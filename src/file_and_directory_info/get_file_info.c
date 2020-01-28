/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my_ls.h"
#include "my.h"

bool is_directory(const char *filepath)
{
    struct stat test;

    if (stat(filepath, &test) == -1)
        exit(84);
    if (S_ISDIR(test.st_mode))
        return true;
    return false;
}

static my_file_t **is_not_dir(void)
{
    size_t nb_init_elem = 1;
    my_file_t **my_file_inf = malloc(sizeof(my_file_t *) * (nb_init_elem + 1));

    if (!my_file_inf)
        exit(84);
    my_file_inf[0] = malloc(sizeof(my_file_t));
    if (!my_file_inf[0])
        exit(84);
    my_file_inf[1] = NULL;
    return my_file_inf;
}

my_file_t **make_file_struct(my_arg_t *my_arg, int i)
{
    int size;
    my_file_t **my_file_inf;

    if (!is_directory(my_arg->my_filepath[i]))
        return is_not_dir();
    size = get_malloc_size(my_arg->my_filepath[i], my_arg);
    my_file_inf = malloc(sizeof(my_file_t *) * (size + 1));
    if (!my_file_inf)
        exit(84);
    my_file_inf[size] = NULL;
    for (int i = 0; i < size; i++) {
        my_file_inf[i] = malloc(sizeof(my_file_t));
        if (!my_file_inf[i])
            exit(84);
    }
    return my_file_inf;
}

void files_save(int *move, const char *filepath, my_file_t **my_file_inf,
    struct dirent *my_dir_contents)
{
    char *file;
    struct stat test;

    file = take_file_in_dir(filepath, my_dir_contents->d_name);
    if (stat(file, &test) == -1)
        exit(84);
    my_struct_filler(my_file_inf[*move], file);
    free(file);
    *move += 1;
}

void get_file_info(my_arg_t *my_arg, const char *filepath,
    my_file_t **my_file_inf, int move)
{
    DIR *my_dir;
    struct dirent *my_dir_contents;

    if (!is_directory(filepath)) {
        my_struct_filler(my_file_inf[0], filepath);
        return;
    }
    my_dir = opendir(filepath);
    my_dir_contents = readdir(my_dir);
    if (!my_dir)
        exit(84);
    while (my_dir_contents) {
        if (my_dir_contents->d_name[0] != '.' || my_arg->t_d || my_arg->t_a)
            files_save(&move, filepath, my_file_inf, my_dir_contents);
        my_dir_contents = readdir(my_dir);
    }
    closedir(my_dir);
}