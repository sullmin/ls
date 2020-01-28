/*
** EPITECH PROJECT, 2019
** my_str_to_word_array.c
** File description:
** task04
*/

#include <stdlib.h>

static int alphanum(char const *tab, int i)
{
    if ((tab[i] >= 48 && tab[i] <= 57) || (tab[i] >= 65 && tab[i] <= 90))
        return (1);
    if (tab[i] >= 97 && tab[i] <= 122)
        return (1);
    return (0);
}

static int count2(char const *str)
{
    int c2 = 0;
    int i = 0;

    if (str[i] != '\0' && alphanum(str, i) == 0) {
        c2--;
    }
    for (i = i; str[i] != '\0'; i++) {
        if ((alphanum(str, i) == 0) && (alphanum(str, i + 1) == 1)) {
            c2++;
        }
    }
    c2++;
    return (c2);
}

static int cmot(char const *str, int t)
{
    int st =  -1;
    int c = 0;
    int i = 0;

    while (str[i] != '\0' && alphanum(str, i) == 0) {
        i++;
    }
    for (i = i; str[i] != '\0'; i++) {
        if ((alphanum(str, i) == 1)) {
            st++;
        }
        else if (c == t) {
            return (st + 2);
        }
        else {
            st = 0;
            c++;
        }
    }
    return (st + 2);
}

static char **final(char const *str, char **tab)
{
    int i = 0;
    int j = 0;

    for (int p = 0; tab[p] !=  0; p++) {
        while (str[i] != '\0' && alphanum(str, i) == 0) {
            i++;
        }
        for (i = i; alphanum(str, i) == 1; i++) {
            tab[p][j] = str[i];
            j++;
        }
        i--;
        tab[p][j] = '\0';
        j = 0;
        i++;
    }
    return (tab);
}

char **my_str_to_word_array(char const *str)
{
    char **tab = malloc(sizeof(char*) * (count2(str) + 1));

    tab[count2(str)] = NULL;
    if (tab == NULL)
        return (0);
    for (int t = 0; t < count2(str); t++) {
        tab[t] = malloc(sizeof(char) * (cmot(str, t) + 2));
    }
    return (final(str, tab));
}