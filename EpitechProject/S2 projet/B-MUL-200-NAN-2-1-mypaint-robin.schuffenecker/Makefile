##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile the my library copy it in the lib
## folder copy the header in the include
## folder and implement the clean rule
##

FILECOMPIL = main.c

NAME = my_paint

SRC =	src/create_pixel_tab.c 	\
		src/eraser.c			\
		src/paint_bucket.c 		\
		src/create_crossair.c 	\
		src/create_background.c \
		src/create_button.c		\
		src/button_action.c		\
		src/evenement.c			\
		src/init_structure.c	\
		src/create_palette.c 	\
		src/our_zoom.c 			\
		src/loop.c 				\
		src/our_move.c 			\
		src/our_pipette.c 		\
		src/export.c			\
		src/import.c			\
		src/open_file.c			\
		src/create_drop_menu.c 	\
		src/export_all.c 		\
		src/my_strcat.c			\
		src/menu_tools.c		\
		src/init_menu.c    		\
		src/documentation.c 	\
		src/scrool.c			\
		src/init_canva_but.c 	\
		src/import_all.c		\
		src/our_layer.c			\
		src/new_file.c		 	\
		src/my_strcmp.c			\
		src/modify_canva.c		\
		src/aboutus.c			\
		src/free_node.c			\
		src/slide_button.c		\
		src/filter.c			\
		src/all_slide.c 		\
		src/free_button.c		\

OBJ = $(SRC:.c=.o)

RM = rm

CC = gcc

CFLAGS = -Wall -Wextra -Wshadow -I./include

CSFML = -lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) -o $(NAME) $(OBJ) main.o $(CSFML)
clean:
	$(RM) -f $(OBJ) main.o
	$(RM) -f *.gcda
	$(RM) -f *.gcno
fclean: clean
	$(RM) -f my_paint
re : fclean all
unit_tests : fclean
	$(GCC) -o unit_tests $(SRC) -g tests/test_project.c -lcriterion --coverage
tests_run : unit_tests
	./unit_tests
coverage : tests_run
	gcovr --exclude tests/
	rm *.gc*
