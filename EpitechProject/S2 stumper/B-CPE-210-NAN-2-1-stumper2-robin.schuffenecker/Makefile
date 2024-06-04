##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \

OBJ	=	$(SRC:.c=.o)

NAME 	=	a.out

COMPIL 	+=  -Wall -Wextra -Werror

CFLAGS += -I./include

all:	$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(COMPIL)

clean:
	rm -rf $(OBJ)
	rm -rf *.gc*
	rm -rf *~

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY:		fclean clean re all tests_run
