/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_arg
*/

#include "my_ls.h"

static int my_path_cnt(int ac, char **av)
{
    int path_cnt = 0;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-')
            path_cnt++;
    }
    return path_cnt;
}

static void no_file_path(my_arg_t *my_arg, char **av, int path_cnt)
{
    if (path_cnt == 0)
        my_arg->my_filepath = malloc(sizeof(char *) * (path_cnt + 2));
    else my_arg->my_filepath = malloc(sizeof(char *) * (path_cnt + 1));
    if (!my_arg->my_filepath)
        exit (84);
    my_arg->my_filepath[path_cnt] = NULL;
    if (path_cnt == 0) {
        my_arg->my_filepath[0] = av[0];
        my_arg->my_filepath[0][2] = '\0';
        my_arg->my_filepath[1] = NULL;
    }
}

static my_arg_t *make_my_arg(int ac, char **av)
{
    int move = 0;
    int path_cnt = my_path_cnt(ac, av);
    my_arg_t *my_arg = malloc(sizeof(my_arg_t));

    if (!my_arg)
        exit(84);
    no_file_path(my_arg, av, path_cnt);
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-') {
            my_arg->my_filepath[move] = av[i];
            move++;
        }
    }
    return my_arg;
}

static void fill_my_arg(int ac, char **av, my_arg_t *my_arg)
{
    my_arg->t_l = false;
    my_arg->t_t = false;
    my_arg->t_d = false;
    my_arg->t_rmin = false;
    my_arg->t_rmaj = false;
    my_arg->t_a = false;
    my_arg->t_asc = false;
    my_arg->t_s = false;
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            is_present(av, my_arg, i);
        }
    }
}

my_arg_t *take_my_arg(int ac, char **av)
{
    my_arg_t *my_arg = make_my_arg(ac, av);

    if (!my_arg)
        exit (84);
    fill_my_arg(ac, av, my_arg);
    return my_arg;
}