##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Compile the my library copy it in the lib
## folder copy the header in the include
## folder and implement the clean rule
##

NAME = 42sh

SRC =	chain_list/add_pos.c 		\
		chain_list/free_pos.c 		\
		chain_list/create_node.c 	\
		put_fct/my_itoa.c 			\
		put_fct/my_strdup.c			\
		put_fct/my_putstr.c			\
		put_fct/my_strlen.c			\
		put_fct/my_strcpy.c			\
		put_fct/my_strcmp.c 		\
		put_fct/my_getnbr.c 		\
		put_fct/my_strcat.c 		\
		put_fct/my_putchar.c		\
		put_fct/my_strncpy.c		\
		put_fct/my_put_nbr.c		\
		put_fct/is_alphanum.c 		\
		put_fct/char_to_str.c		\
		put_fct/print_errors.c 		\
		src/cd_function.c		 	\
		src/array_cpy.c 			\
		src/getline.c 				\
		src/print_2d.c 				\
		src/find_path.c 			\
		src/add_env.c 				\
		src/free_array.c 			\
		src/envp_to_list.c 			\
		src/execute.c 				\
		src/exit.c 					\
		src/init_struct.c 			\
		src/build_in.c				\
		src/clean_str.c				\
		src/pipe_execute.c			\
		src/redirection.c			\
		src/my_strtok.c				\
		src/globbings.c				\
		src/parse_redirection.c		\
		src/error_redi.c			\
		src/injection.c				\
		src/injection_handle.c	    \
		src/echo.c					\
		src/job_control.c			\
		src/jobs_error.c    		\
		src/handle_job.c			\
		src/execute_buildin.c		\
		src/open_file.c 			\
		src/count.c 				\
		src/add_history.c 			\
		src/history.c 				\
		src/exclamation_history.c 	\
		src/search_history.c 		\
		src/concat_history.c 		\
		src/history_errors.c 		\
		src/history_wt_args.c		\
		src/my_delete_line_in_tab.c \
		src/create_alias.c			\
		src/add_alias.c				\
		src/add_alias_rc.c			\
		src/semicolon_pipe.c		\
		src/correct_inhibitors.c	\
		src/handle_esperluette.c	\
		src/handle_pipes_or.c		\
		src/which.c					\
		src/execute_new_buildin.c	\
		src/where.c					\
		src/alias_looping.c			\
		src/special_variable.c 		\
		src/termios.c				\
		src/get_the_line.c			\
		src/handle_termios_arrow.c	\
		src/add_char_in_str.c		\
		src/auto_completion.c		\
		src/completion_with_path.c	\
		src/inhibitors.c			\
		src/add_delim.c				\
		put_fct/str_to_word_array.c	\
		put_fct/my_revstr.c			\
		src/our_sh.c				\
		src/quotes_redirection.c	\
		src/termios_cursor.c		\
		src/local.c					\
		src/ignoreof.c				\
		put_fct/my_strtok_with_quotes.c	\
		src/backtick.c				\
		src/correct_array.c			\
		src/error_backtick.c		\
		put_fct/strcat_at_pos.c		\
		src/replace_dollar.c		\

OBJ = $(SRC:.c=.o)

RM = rm

CC = gcc

CFLAGS += -Wall -Wextra -I./include

COMPIL_TEST = tests/test_project.c -lcriterion --coverage -I./include

all: $(NAME)

$(NAME): $(OBJ) main.o
	$(CC) -o $(NAME) $(OBJ) main.o

clean:
	$(RM) -f $(OBJ)
	$(RM) -f main.o
	$(RM) -f *.gcda
	$(RM) -f *.gcno
	$(RM) -f unit_tests
fclean: clean
	$(RM) -f $(NAME)

re : fclean all

test_uni : fclean
	$(CC) -o unit_tests $(SRC) $(COMPIL_TEST)

tests_run : test_uni
	./unit_tests

coverage : tests_run
	gcovr --exclude tests/
	$(RM) -f *.gcda
	$(RM) -f *.gcno
	$(RM) -f unit_tests
