##
## EPITECH PROJECT, 2024
## bs
## File description:
## Makefile
##

CC 			= 	gcc
CFLAGS 		= 	-Wall -Wextra -g
LDLIBS		= 	-lmy
CFLAGS 		+= 	-I$(INCLUDE_DIR)
LDFLAGS 	= 	-L$(LIB_DIR)
CSFML 		= 	-lcsfml-graphics -lcsfml-system -lcsfml-window\
				-lcsfml-audio -lm

GCOV_DIR 	= 	$(BUILD_DIR)/gcov
COVERAGE 	= 	--coverage
CRITERION 	= 	-lcriterion
OPTFLAGS 	= 	-O2
DEBUGFLAGS 	= 	-g3 -ggdb3 -DDEBUG
CFLAGS 		+=  $(OPTFLAGS)
TEST_ALL_FLAGS = $(LDFLAGS) $(LDLIBS) $(CRITERION) $(CSFML)
TEST_FLAGS  = 	$(CFLAGS) $(TEST_ALL_FLAGS) $(COVERAGE)

INCLUDE_DIR = 	includes
LIB_DIR 	= 	lib
SRC_DIR 	= 	src
TEST_DIR	= 	tests
BUILD_DIR 	= 	build

NO_COLOR=\033[0m
RED=\033[0;31m
GREEN=\033[0;32m
BLUE=\033[0;34m

define COMPILE
	@echo -e "$(BLUE)Compilation of $<...$(NO_COLOR)"
	@mkdir -p $(dir $@)
	@{ $(CC) $(CFLAGS) -o $@ -c $< || echo -e \
	"$(RED)Compilation error.$(NO_COLOR)" ;}
	@echo -e "$(GREEN)Compilation finished.$(NO_COLOR)"
endef

define BUILD_EXEC
	@echo -e "$(BLUE)Building the executable $@...$(NO_COLOR)"
	@{ $(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) $(LDLIBS) $(CSFML) && echo -e \
	"$(GREEN)$@ building completed.$(NO_COLOR)" || echo -e \
	"$(RED)Error during construction.$(NO_COLOR)" ;}
endef

MAIN 		= 	main.c
TEST_FILES 	=   unit_tests.c
FILES 		=	events.c 							\
				my_rpg.c 							\
				create_button.c 					\
				game/draw_npc.c 					\
				game/game_logic.c 					\
				game/game_loop.c 					\
				game/game_render.c 					\
				shutdown.c 							\
				window.c 							\
				window_close.c 						\
				init/init_player.c 					\
				init/init_rect.c 					\
				init/init_ui.c 						\
				init/init.c 						\
				init/init_room.c 					\
				controllers/menu_controller.c 		\
				controllers/player_controller.c 	\
				controllers/player_attack.c 		\
				models/player.c 					\
				models/npc/dialogues_opt.c 			\
				models/npc/free_npc.c 				\
				models/npc/npc_dialogues.c 			\
				models/npc/npc.c 					\
				models/npc/print_npc.c 				\
				models/npc/stories.c 				\
				models/npc/verif_npc_json.c 		\
				models/npc/fill_npc_sprite.c 		\
				models/quests/quest.c 				\
				models/quests/add_quest_step.c 		\
				models/quests/add_quest.c 			\
				models/quests/free_quest.c 			\
				models/quests/print_quest_steps.c 	\
				models/quests/print_quest.c 		\
				models/quests/verif_quest_json.c 	\
				models/inventory.c 					\
				models/enemy.c 						\
				models/collision.c 					\
				models/items/items.c 				\
				models/items/json_to_items.c 		\
				models/items/print_items.c 			\
				models/items/sprite_items.c 		\
				models/items/type_items.c 			\
				models/text/display_text.c 			\
				models/text/text.c 					\
				models/minimap.c					\
				models/room_door.c 					\
				utils/vector_edition.c 				\
				utils/rect.c 						\
				views/menu_views.c 					\
				views/game_views.c 					\
				views/settings_views.c 				\
				menu/init_start_buttons.c 			\
				menu/init_settings_menu.c 			\
				menu/init_intra_game_buttons.c 		\
				menu/intra_menu.c 					\
				menu/menu.c 						\
				menu/settings_menu.c 				\
				menu/start_menu.c 					\
				inventory/inventory.c 				\
				inventory/init_inventory.c 			\
				inventory/set_inventory_sprites.c 	\
				menu/handle_buttons_start_menu.c 	\
				menu/handle_buttons_in_game.c 		\
				menu/handle_buttons_settings.c 		\

SRCS 		= 	$(addprefix $(SRC_DIR)/, $(FILES))
MAIN_SRC 	= 	$(addprefix $(SRC_DIR)/, $(MAIN))
OBJS 		= 	$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
MAIN_OBJ 	=	$(MAIN_SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

TEST_SRCS	= 	$(addprefix $(TEST_DIR)/, $(TEST_FILES))
TEST_OBJS	= 	$(TEST_SRCS:$(TEST_DIR)/%.c=$(BUILD_DIR)/test/%.o)

EXEC		=	my_rpg
TEST_EXEC 	=	unit_tests

all: $(EXEC)

$(EXEC): $(OBJS) $(MAIN_OBJ)
	@$(MAKE) build_libmy
	$(BUILD_EXEC)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(COMPILE)

$(BUILD_DIR)/test/%.o: $(TEST_DIR)/%.c
	$(COMPILE)

build_libmy:
	@$(MAKE) -C $(LIB_DIR)/my -j4

clean_libmy:
	@$(MAKE) -C $(LIB_DIR)/my clean

fclean_libmy:
	@$(MAKE) -C $(LIB_DIR)/my fclean

re_libmy: fclean_libmy build_libmy

clean: clean_libmy
	@echo -e "$(BLUE)Cleaning the project...$(NO_COLOR)"
	@rm -rf $(BUILD_DIR) *.gcda *.gcno
	@echo -e "$(GREEN)Cleaning completed.$(NO_COLOR)"

fclean: fclean_libmy fclean_tests
	@echo -e "$(BLUE)Removing executables...$(NO_COLOR)"
	@rm -rf $(EXEC) $(TEST_EXEC) $(BUILD_DIR) *.gcda *.gcno
	@echo -e "$(GREEN)Removal completed.$(NO_COLOR)"

tests_run: $(TEST_EXEC)
	@echo -e "$(BLUE)Starting tests...$(NO_COLOR)"
	@{ ./$(TEST_EXEC) --verbose || echo -e \
	"$(RED)Error during tests.$(NO_COLOR)" ;}
	@{ mkdir -p $(GCOV_DIR) ; for file in *.gcda *.gcno; do if \
	[ -f "$$file" ]; then mv "$$file" $(GCOV_DIR); fi; done ;}
	@echo -e "$(GREEN)Tests completed.$(NO_COLOR)"

$(TEST_EXEC): $(TEST_OBJS) $(OBJS)
	@$(MAKE) build_libmy
	@{ $(CC) -o $@ $^ $(TEST_FLAGS) && echo -e \
	"$(GREEN)Executable $@ built.$(NO_COLOR)" || echo -e \
	"$(RED)Error during construction.$(NO_COLOR)" ;}

valgrind_test: $(TEST_EXEC)
	valgrind --leak-check=full ./$(TEST_EXEC)

valgrind_exec: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

coverage:
	@gcovr --exclude $(TEST_DIR)
	@gcovr --exclude $(TEST_DIR) --branches

fclean_tests:
	@echo -e "$(BLUE)Removing test files...$(NO_COLOR)"
	@rm -f $(TEST_EXEC)
	@echo -e "$(GREEN)Removal completed.$(NO_COLOR)"

debug: CFLAGS += $(DEBUGFLAGS)
debug: re

re: fclean all

.PHONY: all clean fclean re tests_run debug re_libmy build_libmy \
	clean_libmy fclean_libmy fclean_tests valgrind_test valgrind_exec \
	coverage
