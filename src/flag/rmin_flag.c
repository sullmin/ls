/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include "my_ls.h"

static int take_lenght(my_file_t **my_file_inf)
{
    int i;

    for (i = 0; my_file_inf[i] != NULL; i++);
    return i - 1;
}

void rmin_flag(my_file_t **my_file_inf)
{
    int v_max = take_lenght(my_file_inf);
    my_file_t *stor;

    for (int t = 0; t - 1 < v_max / 2; t++) {
        stor = my_file_inf[v_max - t];
        my_file_inf[v_max - t] = my_file_inf[t];
        my_file_inf[t] = stor;
    }
}