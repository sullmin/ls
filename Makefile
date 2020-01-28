##
## EPITECH PROJECT, 2019
## Makefile doop
## File description:
## task02
##

SRC	=	src/main.c	\
		src/my_ls.c	\
		src/free/free_str_to_word_array.c	\
		src/free/function_for_free.c	\
		src/path_arg/my_arg_of_ls.c	\
		src/path_arg/bool_of_arg.c	\
		src/file_and_directory_info/get_file_info.c	\
		src/file_and_directory_info/get_malloc_size.c	\
		src/file_and_directory_info/directory_recursive.c	\
		src/file_and_directory_info/move_in_dir.c	\
		src/tools/get_permission.c	\
		src/tools/get_file_size.c	\
		src/tools/get_uid.c	\
		src/tools/get_gid.c	\
		src/tools/get_major.c	\
		src/tools/get_minor.c	\
		src/tools/get_time.c	\
		src/tools/get_allocated.c	\
		src/tools/get_nb_hard_link.c	\
		src/tools/get_name.c	\
		src/flag/no_flag.c	\
		src/flag/l_flag/l_flag.c	\
		src/flag/l_flag/l_flag_display.c	\
		src/flag/d_flag.c	\
		src/flag/rmaj_flag.c	\
		src/flag/rmin_flag.c	\
		src/flag/t_flag/t_flag.c	\
		src/sort_flag.c	\
		src/flag/t_flag/get_month_val.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	+=	-Wall	-Wextra	-I./include -g

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o	$(NAME)	$(OBJ) -I ./include -L./lib/my -lmy

clean:
	rm	-f 	$(OBJ)

fclean: clean
	rm	-f	$(NAME)

re:	fclean	all

tests_run :
	make re -C tests/