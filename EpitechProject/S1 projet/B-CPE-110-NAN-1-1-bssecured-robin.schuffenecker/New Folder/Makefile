##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/my_putchar.c \
		src/my_put_nbr.c \
		src/my_putstr.c \
		src/my_strlen.c	\
		src/my_strdup.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	libhashtable

COMPIL 	= -I./include -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	-gcc -o $(NAME) $(OBJ) $(COMPIL) $(SFML)
	-rm $(OBJ)

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)

re: fclean all

.PHONY:		fclean clean re all lib
