/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <unistd.h>
#include "my_ls.h"
#include "my.h"

static void display_size(int size, int max_size)
{
    int temp = size;
    int length_max_size;
    int length_size;

    for (length_max_size = 1; max_size >= 10; length_max_size++)
        max_size /= 10;
    for (length_size = 1; size >= 10; length_size++)
        size /= 10;
    for (int i = 0; i < length_max_size - length_size; i++)
        my_putchar(' ');
    my_put_nbr(temp);
}

static int take_maxsize(my_file_t **my_file_inf)
{
    int temp = 0;

    for (int i = 0; my_file_inf[i] != NULL; i++)
        if (my_file_inf[i]->size > temp)
            temp = my_file_inf[i]->size;
    return temp;
}

static int take_maxnb_hardlink(my_file_t **my_file_inf)
{
    int temp = 0;

    for (int i = 0; my_file_inf[i] != NULL; i++)
        if (my_file_inf[i]->nb_hardlink > temp)
            temp = my_file_inf[i]->nb_hardlink;
    return temp;
}

static void put_size_or_inode(my_file_t **my_file_inf, int i)
{
    int max_size = take_maxsize(my_file_inf);

    if (my_file_inf[i]->minor != 0 || my_file_inf[i]->major != 0) {
        my_put_nbr(my_file_inf[i]->major);
        my_putstr(", ");
        my_put_nbr(my_file_inf[i]->minor);
    }
    else display_size(my_file_inf[i]->size, max_size);
}

void my_l_flag_display(my_file_t **my_file_inf, int i)
{
    int nb_hardlink_max = take_maxnb_hardlink(my_file_inf);

    my_putstr(my_file_inf[i]->perm);
    my_putchar(' ');
    display_size(my_file_inf[i]->nb_hardlink, nb_hardlink_max);
    my_putchar(' ');
    my_putstr(my_file_inf[i]->uid);
    my_putchar(' ');
    my_putstr(my_file_inf[i]->gid);
    my_putchar(' ');
    put_size_or_inode(my_file_inf, i);
    my_putchar(' ');
    write(1, my_file_inf[i]->date + 4, 12);
    my_putchar(' ');
    my_color_file(my_file_inf[i]->perm);
    my_putstr(my_file_inf[i]->name);
    my_putstr("\e[0;m");
    my_putchar('\n');
}