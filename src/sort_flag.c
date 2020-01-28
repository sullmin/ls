/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

static char *lowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
        }
    }
    return (str);
}

static void swap(my_file_t **my_file_inf, int *i)
{
    my_file_t *stor;

    stor = my_file_inf[*i];
    my_file_inf[*i] = my_file_inf[(*i) + 1];
    my_file_inf[(*i) + 1] = stor;
    (*i) = -1;
}

void sort_flag(my_file_t **my_file_inf)
{
    int temp;
    int a;
    char *s1;
    char *s2;

    for (int i = 0; my_file_inf[i + 1] != NULL; i++) {
        s1 = my_strdup(my_file_inf[i]->name);
        s2 = my_strdup(my_file_inf[i + 1]->name);
        lowcase(s1);
        lowcase(s2);
        a = my_strcmp(s1, s2);
        temp = my_strcmp(my_file_inf[i]->name, my_file_inf[i + 1]->name);
        if (a == 1)
            swap(my_file_inf, &i);
        else if (a == 0 && temp == -1)
            swap(my_file_inf, &i);
        free(s1);
        free(s2);
    }
}

void asc_flag(my_file_t **my_file_inf)
{
    my_file_t *stor;

    for (int i = 0; my_file_inf[i + 1] != NULL; i++) {
        if (my_strcmp(my_file_inf[i]->name, my_file_inf[i + 1]->name) == 1) {
            stor = my_file_inf[i];
            my_file_inf[i] = my_file_inf[i + 1];
            my_file_inf[i + 1] = stor;
            i = -1;
        }
    }
}