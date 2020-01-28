/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include "my_ls.h"
#include "my.h"

static int arg_size(my_arg_t *my_arg)
{
    int ret = 2;

    ret = (my_arg->t_rmin) ? ret + 1 : ret;
    ret = (my_arg->t_rmaj) ? ret + 1 : ret;
    ret = (my_arg->t_l) ? ret + 1 : ret;
    ret = (my_arg->t_t) ? ret + 1 : ret;
    ret = (my_arg->t_d) ? ret + 1 : ret;
    return ret;
}

static void char_filler(my_arg_t *my_arg, char **tab, int *val)
{
    if (my_arg->t_rmin) {
        tab[*val] = my_strdup("-r");
        *val += 1;
    }
    if (my_arg->t_rmaj) {
        tab[*val] = my_strdup("-R");
        *val += 1;
    }
    if (my_arg->t_l) {
        tab[*val] = my_strdup("-l");
        *val += 1;
    }
    if (my_arg->t_t) {
        tab[*val] = my_strdup("-t");
        *val += 1;
    }
    if (my_arg->t_d) {
        tab[*val] = my_strdup("-d");
        *val += 1;
    }
}

static char **make_my_av(const char *filepath, my_arg_t *my_arg)
{
    int ac = arg_size(my_arg);
    char **tab = malloc(sizeof(char *) * (ac + 1));

    if (!tab)
        exit(84);
    tab[0] = my_strdup("./my_ls");
    tab[1] = my_strdup(filepath);
    tab[ac] = NULL;
    return tab;
}

void my_diroctory_recusrsive(const char *filepath, my_arg_t *my_arg)
{
    int val = 2;
    int ac = arg_size(my_arg);
    char **tab = make_my_av(filepath, my_arg);

    char_filler(my_arg, tab, &val);
    my_ls(ac, tab);
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}