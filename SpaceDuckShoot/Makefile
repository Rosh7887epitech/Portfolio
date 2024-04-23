##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile pool
##

SRC	=	src/main.c \
		src/sound.c \
		src/sprite.c \
		src/mouse_event.c \
		src/move_sprite.c \
		src/dif_windows.c \
		src/menu_sprite.c \
		src/draw_sprite.c \
		src/close_windows.c \
		src/inttochar.c \
		src/display_txt.c \
		src/destroy.c \

OBJ		=	$(SRC:.c=.o)

NAME 	=	my_hunter

COMPIL 	= -I./include -L./lib/my -lmy -Wall -Wextra -Werror

SFML 	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME): lib	$(OBJ)
	-gcc -o $(NAME) $(OBJ) $(COMPIL) $(SFML)
	-rm src/*.o

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
