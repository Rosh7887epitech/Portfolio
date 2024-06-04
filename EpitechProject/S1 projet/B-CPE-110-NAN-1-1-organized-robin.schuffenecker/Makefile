##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/add.c \
		src/main.c \
		src/disp.c \
		src/id_sort.c \
		src/del_list.c \
		src/sort_list.c \
		src/my_strdup.c \
		src/type_sort.c \
		src/name_sort.c \
		src/my_rev_list.c \
		basic/my_strlen.c \
		basic/my_putstr.c \
		basic/my_getnbr.c \
		basic/my_strcmp.c \
		basic/my_intcmp.c \
		basic/my_putchar.c \
		basic/my_put_nbr.c \

CFLAGS += -g

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

all:	$(NAME)

$(NAME): $(OBJ)
	-gcc -o $(NAME) $(OBJ) -I ./include -L./shell -lshell -Wall -Wextra -Werror
	-rm $(OBJ)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
