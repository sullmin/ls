/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include "my_ls.h"

void free_my_file_inf(my_file_t **my_file_inf)
{
    for (int i = 0; my_file_inf[i] != NULL; i++) {
        free(my_file_inf[i]->date);
        free(my_file_inf[i]->uid);
        free(my_file_inf[i]->gid);
        free(my_file_inf[i]->perm);
        free(my_file_inf[i]->name);
        free(my_file_inf[i]);
    }
    free(my_file_inf);
}