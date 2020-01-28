/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

static void my_sort_files(unsigned int *array, int size, my_file_t **myfile_inf)
{
    int storage;
    my_file_t *temp;

    for (int o = 0; o < size - 1; o++) {
        if (array[o + 1] > array[o]) {
            storage = array[o + 1];
            temp = myfile_inf[o + 1];

            array[o + 1] = array[o];
            myfile_inf[o + 1] = myfile_inf[o];

            array[o] = storage;
            myfile_inf[o] = temp;
            o = -1;
        }
    }
}

static int get_size(my_file_t **my_file_inf)
{
    int i;

    for (i = 0; my_file_inf[i] != NULL; i++);
    return i;
}

static unsigned int get_val_for_sort(char **my_parth)
{
    unsigned int val = 0;

    val += my_getnbr(my_parth[5]) * 10000000;
    val += month_val(my_parth[0]) * 10000;
    val += my_getnbr(my_parth[1]) * 1000;
    val += my_getnbr(my_parth[2]) * 100;
    val += my_getnbr(my_parth[3]) * 10;
    val += my_getnbr(my_parth[4]) * 1;
    return val;
}

static unsigned int *make_int_tab(my_file_t **my_file_inf, int size)
{
    unsigned int *tab = malloc(sizeof(unsigned int) * size);
    char *time;
    char **my_parth;

    for (int i = 0; my_file_inf[i] != NULL; i++) {
        time = my_strdup(my_file_inf[i]->date);
        if (!time)
            exit(84);
        my_parth = my_str_to_word_array(time + 4);
        if (!my_parth)
            exit(84);
        for (int i = 0; i < 6; i++)
            if (!my_parth[i])
                exit(84);
        tab[i] = get_val_for_sort(my_parth);
        free(time);
        free_str_to_word_array(my_parth);
    }
    return tab;
}

void t_flag(my_file_t **my_file_inf)
{
    int size = get_size(my_file_inf);
    unsigned int *my_tab = make_int_tab(my_file_inf, size);

    my_sort_files(my_tab, size, my_file_inf);

    free(my_tab);
}