/*
** EPITECH PROJECT, 2019
** my_ls
** File description:
** take_perm
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

static char file_type(struct stat test)
{
    if (S_ISDIR(test.st_mode))
        return 'd';
    if (S_ISCHR(test.st_mode))
        return 'c';
    if (S_ISREG(test.st_mode))
        return '-';
    if (S_ISLNK(test.st_mode))
        return 'l';
    if (S_ISFIFO(test.st_mode))
        return 'p';
    if (S_ISSOCK(test.st_mode))
        return 's';
    if (S_ISBLK(test.st_mode))
        return 'b';
    return '-';
}

static void prem_filler(char *perm, struct stat test, int *move)
{
    perm[(*move)++] = file_type(test);
    perm[(*move)++] = (test.st_mode & S_IRUSR) ? 'r' : '-';
    perm[(*move)++] = (test.st_mode & S_IWUSR) ? 'w' : '-';
    perm[(*move)++] = (test.st_mode & S_IXUSR) ? 'x' : '-';
    perm[(*move)++] = (test.st_mode & S_IRGRP) ? 'r' : '-';
    perm[(*move)++] = (test.st_mode & S_IWGRP) ? 'w' : '-';
    perm[(*move)++] = (test.st_mode & S_IXGRP) ? 'x' : '-';
    perm[(*move)++] = (test.st_mode & S_IROTH) ? 'r' : '-';
    perm[(*move)++] = (test.st_mode & S_IWOTH) ? 'w' : '-';
    perm[(*move)++] = (test.st_mode & S_ISVTX) ? 'T'
    : (test.st_mode & S_IXOTH) ? 'x' : '-';
}

char *get_permission(char const *filepath)
{
    int move = 0;
    struct stat test;
    char *perm = malloc(sizeof(char) * 12);

    if (lstat(filepath, &test) == -1 || !perm)
        exit(84);
    perm[11] = '\0';
    perm[10] = '.';
    prem_filler(perm, test, &move);
    return perm;
}