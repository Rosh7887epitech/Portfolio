##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/stat.c \
		src/compt.c \
		src/my_popup.c \
		src/my_strcpy.c \
		src/my_strlen.c \
		src/my_putstr.c \
		src/my_putchar.c \
		src/coordinate.c \
		src/move_player.c \
		src/mem_dup_2d_array.c \
		src/load_2d_arr_from_file.c \

OBJ	=	$(SRC:%.c=%.o)

NAME	=	Soko

all:	$(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) -lncurses  -Wall -Wextra -Werror
	-rm src/*.o

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
