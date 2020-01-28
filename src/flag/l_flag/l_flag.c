/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include "my_ls.h"
#include "my.h"

static void total_display(my_file_t **my_file_inf)
{
    int total = 0;

    if (my_file_inf[0] == NULL)
        return;
    if (my_file_inf[1] == NULL)
        return;
    for (int i = 0; my_file_inf[i] != NULL; i++)
        total += my_file_inf[i]->nb_allocated / 2;
    my_putstr("total ");
    my_put_nbr(total);
    my_putchar('\n');
}

void l_flag(my_file_t **my_file_inf, my_arg_t *my_arg)
{
    total_display(my_file_inf);
    for (int i = 0; my_file_inf[i] != NULL; i++) {
        if (my_file_inf[i]->name[0] != '.' || my_arg->t_d || my_arg->t_a) {
            my_l_flag_display(my_file_inf, i);
        }
    }
}