##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	main.c						\
		print_typed_value.c \
		push_to_list.c \
		display_list.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	organized

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
