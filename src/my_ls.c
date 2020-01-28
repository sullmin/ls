/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

static void flag_gest(my_arg_t *my_arg, my_file_t **my_file_inf, int i)
{
    if (my_arg->t_asc)
        asc_flag(my_file_inf);
    if (my_arg->t_s)
        sort_flag(my_file_inf);
    if (my_arg->t_rmin)
        rmin_flag(my_file_inf);
    if (my_arg->t_d)
        d_flag(my_file_inf, my_arg->my_filepath[i]);
    if (my_arg->t_rmaj) {
        my_putstr(my_arg->my_filepath[i]);
        my_putstr(":\n");
    }
    if (my_arg->t_t)
        t_flag(my_file_inf);
    if (my_arg->t_l)
        l_flag(my_file_inf, my_arg);
    else no_flag(my_file_inf, my_arg);
    if (my_arg->t_rmaj)
        rmaj_flag(my_file_inf, my_arg->my_filepath[i], my_arg);
}

int my_ls(int ac, char **av)
{
    my_arg_t *my_arg = take_my_arg(ac, av);
    my_file_t **my_file_inf;

    for (int i = 0; my_arg->my_filepath[i] != NULL; i++) {
        if (my_arg->my_filepath[1] != NULL) {
            my_putstr(my_arg->my_filepath[i]);
            my_putstr(":\n");
        }
        my_file_inf = make_file_struct(my_arg, i);
        get_file_info(my_arg, my_arg->my_filepath[i], my_file_inf, START_VAL);
        flag_gest(my_arg, my_file_inf, i);
        free_my_file_inf(my_file_inf);
        if (my_arg->my_filepath[i + 1] != NULL)
            my_putchar('\n');
    }
    free(my_arg->my_filepath);
    free(my_arg);
    return 0;
}