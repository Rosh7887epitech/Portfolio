##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	setting_up.c  \
		main.c 			\
		mem_alloc_2d_array.c \
		mem_dup_2d_array.c \
		load_2d_arr_from_file.c \
		fs_get_number_from_first_line.c \
		find_biggest_square.c \
		size_of_square.c \
		pos_of_square.c \
		stat.c \
		load_file_in_mem.c \
		change_char.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	setting_up

all:	$(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) -I ./include -L./lib/my -lmy -Wall -Wextra -Werror
	-rm *.o

lib:
	-make -C lib/my

clean:
	-rm -f $(OBJ)
	-make -C ./lib/my clean

fclean: clean
	-rm -f $(NAME)
	-make -C ./lib/my fclean

re: fclean all

.PHONY:		fclean clean re all lib
