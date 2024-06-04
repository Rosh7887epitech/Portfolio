##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/draw.c \
		src/add_list.c \
		src/colision.c \
		src/shape_init.c \
		src/close_windows.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_radar

COMPIL 	= -I./include -L./lib/my -lmy -Wall -Wextra -Werror

SFML 	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

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
