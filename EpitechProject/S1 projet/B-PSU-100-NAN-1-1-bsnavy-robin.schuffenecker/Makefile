##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/process_info.c \
		src/kill_it.c \
		src/who_sig_me.c \
		src/signal_me.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	navy

COMPIL 	= -I./include -L./lib/my -lmy -Wall -Wextra -Werror

all: $(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) $(COMPIL)
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
