/*
** EPITECH PROJECT, 2024
** init_menu.c
** File description:
** initiation of all drop menu
*/

#include "my_project.h"

static void add_canva_menu(button_t *but)
{
    sfVector2f pos;

    but->menu[4] = init_menu((sfVector2f){1740, 480},
        (sfVector2f){180, 25}, "<             Filtre");
    pos = sfText_getPosition(but->menu[4]->text);
    sfText_setPosition(but->menu[4]->text,
        (sfVector2f) {pos.x + 13, pos.y + 2});
    add_menu_option(&but->menu[4]->options, (sfVector2f){1560, 465},
    (sfVector2f){180, 25}, "B&W");
    add_menu_option(&but->menu[4]->options, (sfVector2f){1560, 490},
    (sfVector2f){180, 25}, "Invert");
    add_menu_option(&but->menu[4]->options, (sfVector2f){1560, 515},
    (sfVector2f){180, 25}, "X-ray");
    but->menu[5] = init_menu((sfVector2f){1740, 146},
        (sfVector2f){180, 25}, "Transparence");
    pos = sfText_getPosition(but->menu[5]->text);
    pos = (sfVector2f){pos.x + 30, pos.y + 2};
    sfText_setPosition(but->menu[5]->text, pos);
}

static void add_tools_size_menu(button_t *but)
{
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 76},
    (sfVector2f){30, 25}, " 30");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 101},
    (sfVector2f){30, 25}, " 25");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 126},
    (sfVector2f){30, 25}, " 20");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 151},
    (sfVector2f){30, 25}, " 15");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 176},
    (sfVector2f){30, 25}, " 12");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 201},
    (sfVector2f){30, 25}, " 10");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 226},
    (sfVector2f){30, 25}, "  7");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 251},
    (sfVector2f){30, 25}, "  5");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 276},
    (sfVector2f){30, 25}, "  3");
    add_menu_option(&but->menu[3]->options, (sfVector2f){1710, 301},
    (sfVector2f){30, 25}, "  1");
}

static void add_file_menu(button_t *but)
{
    but->menu[0] = init_menu((sfVector2f){0, 0}, (sfVector2f){75, 20},
        "    File");
    add_menu_option(&but->menu[0]->options, (sfVector2f){0, 30},
    (sfVector2f){75, 25}, "New File");
    add_menu_option(&but->menu[0]->options, (sfVector2f){0, 60},
        (sfVector2f){75, 25}, "Open file");
    add_menu_option(&but->menu[0]->options, (sfVector2f){0, 90},
        (sfVector2f){75, 25}, "Save file");
}

static void add_tool_menu(button_t *but)
{
    but->menu[1] = init_menu((sfVector2f){78, 0},
        (sfVector2f){75, 20}, "     Edit");
    add_menu_option(&but->menu[1]->options, (sfVector2f){78, 120},
        (sfVector2f){75, 25}, "Pipette");
    add_menu_option(&but->menu[1]->options, (sfVector2f){78, 90},
        (sfVector2f){75, 25}, "Hand");
    add_menu_option(&but->menu[1]->options, (sfVector2f){78, 60},
        (sfVector2f){75, 25}, "Rubber");
    add_menu_option(&but->menu[1]->options, (sfVector2f){78, 30},
    (sfVector2f){75, 25}, "Pencil");
}

void add_help_menu(button_t *but)
{
    but->menu[2] = init_menu((sfVector2f){156, 0},
        (sfVector2f){75, 20}, "    Help");
    add_menu_option(&but->menu[2]->options, (sfVector2f){156, 60},
        (sfVector2f){75, 25}, "    About");
    add_menu_option(&but->menu[2]->options, (sfVector2f){156, 30},
        (sfVector2f){75, 25}, "      Help");
}

button_t *init_drop_menu(button_t *but)
{
    sfVector2f pos;

    but->menu = malloc(sizeof(menu_t *) * 7);
    add_file_menu(but);
    add_tool_menu(but);
    add_help_menu(but);
    add_canva_menu(but);
    but->menu[6] = init_menu((sfVector2f){1740, 216},
        (sfVector2f){180, 25}, "Shape");
    but->menu[3] = init_menu((sfVector2f){1740, 76},
        (sfVector2f){180, 25}, "<             Size");
    pos = sfText_getPosition(but->menu[3]->text);
    pos = (sfVector2f) {pos.x + 20, pos.y + 2};
    sfText_setPosition(but->menu[3]->text, pos);
    add_tools_size_menu(but);
    return but;
}
