##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	my_popup.c \

OBJ	=	$(SRC:.c=.o)

NAME	=	my_popup

all:	$(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) -lncurses  -Wall -Wextra -Werror
	-rm *.o

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
