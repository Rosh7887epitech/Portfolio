##
## EPITECH PROJECT, 2025
## B-ASM-400-NAN-4-1-asmminilibc-robin.schuffenecker
## File description:
## Makefile
##

ASM_FILES = strlen.asm \
			strchr.asm \
			strrchr.asm \
			memset.asm \
			memcpy.asm \
			strcmp.asm \
			strncmp.asm \
			strcasecmp.asm \
			strstr.asm \
			memmove.asm \
			strpbrk.asm \
			strcspn.asm \

OBJ_FILES = $(ASM_FILES:.asm=.o)

LIB_NAME = libasm.so

TESTS = tests/unit_test.c

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ_FILES)
	ld -shared -o $(LIB_NAME) $(OBJ_FILES)

%.o: %.asm
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(LIB_NAME)

re: fclean all

unit_tests:
	gcc -Wall -Werror -o unit_tests $(TESTS) -lcriterion --coverage

tests_run: unit_tests
	./unit_tests

coverage: tests_run
	gcovr --exclude tests/
