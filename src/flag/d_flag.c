/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <unistd.h>
#include <stdlib.h>
#include "my_ls.h"
#include "my.h"

void d_flag(my_file_t **my_file_inf, const char *filepath)
{
    my_file_t *temp;

    for (int i = 0; my_file_inf[i] != NULL; i++) {
        if (my_file_inf[i]->name[0] == '.' && my_file_inf[i]->name[1] == '\0') {
            temp = my_file_inf[0];
            my_file_inf[0] = my_file_inf[i];
            my_file_inf[i] = temp;
            free(my_file_inf[0]->name);
            my_file_inf[0]->name = my_strdup(filepath);
        }
    }
    for (int i = 1; my_file_inf[i] != NULL; i++) {
        free(my_file_inf[i]->date);
        free(my_file_inf[i]->uid);
        free(my_file_inf[i]->gid);
        free(my_file_inf[i]->perm);
        free(my_file_inf[i]->name);
        free(my_file_inf[i]);
    }
    my_file_inf[1] = NULL;
}