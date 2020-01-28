/*
** EPITECH PROJECT, 2020
** my_ls
** File description:
** my_ls.h
*/

#ifndef MY_LS_H
#define MY_LS_H

#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/types.h>

#define START_VAL 0

typedef struct my_arg_s
{
    char **my_filepath;
    bool t_rmin;
    bool t_l;
    bool t_d;
    bool t_rmaj;
    bool t_t;
    bool t_a;
    bool t_asc;
    bool t_s;
} my_arg_t;

typedef struct my_file_s
{
    char *perm;
    char *uid;
    char *gid;
    char *date;
    char *name;
    int size;
    int nb_hardlink;
    int nb_allocated;
    int minor;
    int major;
} my_file_t;

my_arg_t *take_my_arg(int ac, char **av);
void is_present(char **av, my_arg_t *my_arg, int i);
void free_str_to_word_array(char **tab);
int month_val(const char *month);
int my_ls(int ac, char **av);
void my_diroctory_recusrsive(const char *filepath, my_arg_t *my_arg);

void no_flag(my_file_t **my_file_inf, my_arg_t *my_arg);
void l_flag(my_file_t **my_file_inf, my_arg_t *my_arg);
void t_flag(my_file_t **my_file_inf);
void rmaj_flag(my_file_t **my_file_inf, const char *filepath, my_arg_t *my_arg);
void rmin_flag(my_file_t **my_file_inf);
void d_flag(my_file_t **my_file_inf, const char *filepath);
void asc_flag(my_file_t **my_file_inf);
void sort_flag(my_file_t **my_file_inf);

void get_file_info(my_arg_t *my_arg, const char *filepath,
    my_file_t **my_file_inf, int move);
my_file_t **make_file_struct(my_arg_t *my_arg, int i);
int get_malloc_size(const char *filepath, my_arg_t *my_arg);
char *take_file_in_dir(const char *filepath, const char *name);
void free_my_file_inf(my_file_t **my_file_inf);
void move_in_dir(struct dirent *my_dir_contents, my_file_t **my_file_inf,
    int *move, const char *filepath);
void my_struct_filler(my_file_t *my_file, const char *filepath);
bool is_directory(const char* filepath);
void my_l_flag_display(my_file_t **my_file_inf, int i);
void my_color_file(const char *perm);

char *get_uid(char const *filepath);
char *get_gid(char const *filepath);
char *get_time(char const *filepath);
char *get_name(char const *filepath);
char *get_permission(char const *filepath);
int get_nb_hard_link(char const *filepath);
int get_allocated(char const *filepath);
int get_file_size(char const *filepath);
unsigned int get_minor(char const *filepath);
unsigned int get_major(char const *filepath);

#endif
