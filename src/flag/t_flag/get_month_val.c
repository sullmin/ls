/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** my_ls
*/

#include "my.h"

int month_val(const char *month)
{
    int my_month = -1;

    my_month = (my_strcmp(month, "Jan") == 0) ? 1 : my_month;
    my_month = (my_strcmp(month, "Feb") == 0) ? 2 : my_month;
    my_month = (my_strcmp(month, "Mar") == 0) ? 3 : my_month;
    my_month = (my_strcmp(month, "Apr") == 0) ? 4 : my_month;
    my_month = (my_strcmp(month, "May") == 0) ? 5 : my_month;
    my_month = (my_strcmp(month, "Jun") == 0) ? 6 : my_month;
    my_month = (my_strcmp(month, "Jul") == 0) ? 7 : my_month;
    my_month = (my_strcmp(month, "Aug") == 0) ? 7 : my_month;
    my_month = (my_strcmp(month, "Sep") == 0) ? 9 : my_month;
    my_month = (my_strcmp(month, "Oct") == 0) ? 10 : my_month;
    my_month = (my_strcmp(month, "Nov") == 0) ? 11 : my_month;
    my_month = (my_strcmp(month, "Dec") == 0) ? 12 : my_month;

    return my_month;
}