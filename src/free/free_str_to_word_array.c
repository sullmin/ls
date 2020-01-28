/*
** EPITECH PROJECT, 2019
** str_to_word_array_destroy
** File description:
** free an str_to_word_array
*/

#include <stdlib.h>

void free_str_to_word_array(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        free(tab[i]);
    free(tab);
}