/*
** EPITECH PROJECT, 2019
** my_strdup.c
** File description:
** task01
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    char *tab = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (tab == NULL)
        exit(84);
    tab[my_strlen(src)] = '\0';
    for (int t = 0; t < my_strlen(src); t++) {
        tab[t] = src[t];
    }
    return (tab);
}
