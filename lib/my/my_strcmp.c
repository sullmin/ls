/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** task06
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] != s2[i] && s1[i] < s2[i]) {
            return (-1);
        }
        if (s1[i] != s2[i] && s1[i] > s2[i]) {
            return (1);
        }
    }
    if (s1[i] != '\0')
        return (1);
    else if (s2[i] != '\0')
        return (-1);
    else return (0);
}
