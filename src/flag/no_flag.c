/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** flag
*/

#include <stdlib.h>
#include "my_ls.h"
#include "my.h"

#define COLOR_LIGHT (fbzufa)

void my_color_file(const char *perm)
{
    if (perm[0] == 'd')
        my_putstr("\e[34m");
    if (perm[0] == '-')
        my_putstr("\e[0;m");
    if (perm[0] == 'c')
        my_putstr("\e[38;5;208m");
    if (perm[0] == 'b')
        my_putstr("\e[93m");
    if (perm[0] == 'l')
        my_putstr("\e[96mLight");
}

void no_flag(my_file_t **my_file_inf, my_arg_t *my_arg)
{
    for (int i = 0; my_file_inf[i] != NULL; i++) {
        if (my_file_inf[i]->name[0] != '.' || my_arg->t_d || my_arg->t_a) {
            my_color_file(my_file_inf[i]->perm);
            my_putstr(my_file_inf[i]->name);
            my_putstr("\e[0;m");
            my_putchar('\n');
        }
    }
}