##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/create_book.c \
		src/main.c \
		src/modify_book.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	secured

COMPIL 	= -I./include -L./lib/my -lmy -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) $(COMPIL) $(SFML)
	-rm $(OBJ)

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
