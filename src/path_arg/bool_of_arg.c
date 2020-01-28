/*
** EPITECH PROJECT, 2019
** bool_of_arg.c
** File description:
** DESCRIPTION
*/

#include "my_ls.h"

static void make_true(bool *arg, bool *pres)
{
    *arg = true;
    *pres = true;
}

typedef struct {
    char flag;
    size_t offset;
} flag_t;

static const flag_t flags[] = {
    {'l', offsetof(my_arg_t, t_rmaj)}
}

static void put_flag_true(bool *pres, char c, my_arg_t *my_arg)
{
    *(my_arg + 6) = true;



    if (c == 'l')
        make_true(&my_arg->t_l , pres);
    if (c == 'R')
        make_true(&my_arg->t_rmaj , pres);
    if (c == 'r')
        make_true(&my_arg->t_rmin , pres);
    if (c == 't')
        make_true(&my_arg->t_t , pres);
    if (c == 'd')
        make_true(&my_arg->t_d , pres);
    if (c == 'a')
        make_true(&my_arg->t_a , pres);
    if (c == 'w')
        make_true(&my_arg->t_asc , pres);
    if (c == 'z')
        make_true(&my_arg->t_s , pres);
}

void is_present(char **av, my_arg_t *my_arg, int i)
{
    bool pres = false;

    for (int u = 1; av[i][u] != '\0'; u++) {
        pres = false;
        put_flag_true(&pres, av[i][u], my_arg);
        if (!pres)
            exit (84);
    }
}