/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include "my_ls.h"

void my_struct_filler(my_file_t *my_file, const char *filepath)
{
    if (!my_file)
        return;
    my_file->perm = get_permission(filepath);
    my_file->gid = get_gid(filepath);
    my_file->date = get_time(filepath);
    my_file->name = get_name(filepath);
    my_file->uid = get_uid(filepath);
    my_file->nb_hardlink = get_nb_hard_link(filepath);
    my_file->nb_allocated = get_allocated(filepath);
    my_file->minor = get_minor(filepath);
    my_file->major = get_major(filepath);
    my_file->size = get_file_size(filepath);
}

void move_in_dir(struct dirent *my_dir_contents, my_file_t **my_file_inf,
    int *move, const char *filepath)
{
    char *file;
    struct stat test;

    if (my_dir_contents->d_name[0] != '.') {
        file = take_file_in_dir(filepath, my_dir_contents->d_name);
        if (stat(file, &test) == -1)
            exit(84);
        my_struct_filler(my_file_inf[*move], file);
        free(file);
        *move += 1;
    }
}