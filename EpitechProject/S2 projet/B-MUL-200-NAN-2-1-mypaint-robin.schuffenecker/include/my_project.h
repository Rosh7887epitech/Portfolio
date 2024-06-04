/*
** EPITECH PROJECT, 2023
** my_project.h
** File description:
** header of my project
*/
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "our_struct.h"

#ifndef MY_PROJECT
    #define MY_PROJECT

/* FUNCTION FOR SET AND MODIFY THE CROSSAIR */
void move_crosshair(win_t *win);
char **create_crossair_tab(void);
void modify_crosshair(win_t *win, char *filename, sfVector2f origin);
void switch_crossair(win_t *win, char **crossair, canva_t *canva);

/* FUNCTION FOR INIT THE CANVA AND MODIFY IT */
sfRectangleShape *create_background(void);
canva_t *init_canva(int width, int height, sfVector2f pos_button_layer);
void draw_canva(canva_t *canva, win_t *win);
sfUint8 *create_sfuint8_array(int height, int width);
void modify_sfuint8(win_t *win, canva_t *canva);

/* FUNCTION FOR OUR TOOLS */
void our_eraser(win_t *win, canva_t *canva);
void draw_tools_button(win_t *win, button_t *butt);
sfColor get_pixel_color(layer_t *layer, int tab_index);
void our_pipette(win_t *win, canva_t *canva, button_t *button);
void change_color(win_t *win, canva_t *canva, button_t *button);
void paint_bucket(canva_t *canva, win_t *win, sfColor *new_color);
void tools_action(win_t *win, canva_t *canva, button_t *button);

/* FUNCTION FOR CREATE BUTTON STRUCT, AND BUTTONS CLICKABLE*/
button_t *create_buttons(char **crossair_tab);
obj_t *init_button(sfVector2f pos, sfVector2f size, sfColor color, char *file);

/* FUNCTION FOR BUTTON STATEMENT */
sfBool is_option_clicked(sfEvent event, opt_t *option);
sfBool is_button_pressed(sfEvent event, obj_t *boutton);
sfBool is_clicked(obj_t *boutton, sfMouseButtonEvent *evt);
sfBool is_button_hover(obj_t *boutton, sfMouseMoveEvent *evt);

/* FUNCTION TO CREATE THE COLOR PALETTE */
sfSprite *create_palette(sfVector2f pos);
sfRectangleShape *palette_rect(sfVector2f pos);
void draw_palette(sfSprite *sp, sfRectangleShape *rec, win_t *win, int tool);

/* FUNCTION TO ZOOM UP AND DOWN AND MOVE CANVA*/
void zoom_minus(canva_t *canva);
void zoom_plus(canva_t *canva);
void move_canva(win_t *win, canva_t *canva);

/* ALL THE FUNCTION TO CREATE MODIFY AND SHOW DROP MENUS */
button_t *init_drop_menu(button_t *but);
void action_menu(win_t *win, canva_t *canva, menu_t *menu);
menu_t *init_menu(sfVector2f pos, sfVector2f size, char *text);
void action_menu_tool(win_t *win, canva_t *canva, menu_t *menu);
void action_menu_help(win_t *win, canva_t *canva, menu_t *menu);
void action_menu_filter(win_t *win, canva_t *canva, menu_t *menu);
void action_menu_filter(win_t *win, canva_t *canva, menu_t *menu);
void add_menu_option(opt_t **option, sfVector2f pos, sfVector2f size,
    char *text);
void show_option(win_t *win, opt_t *option, int state, canva_t *canva);
void modify_menu_state(menu_t **menu, canva_t *can, win_t *win, int index);
void action_size_tool(win_t *win, canva_t *canva, menu_t *menu, button_t *but);

/* CREATE THE GIUX CONTOUR*/
win_t *create_gui(win_t *win);
obj_t **init_canva_but(sfVector2f pos);
void init_canva_el(canva_t *canva, int wi, int hei, sfVector2f layer_button);

/* FUNCTION TO IMPORT AN IMAGE */
void import_my(canva_t *canva, char *filepath);
void open_file(file_t **file, char *directory);
void import_all(char **envp, canva_t *canva, menu_t *menu);
void free_import(win_t *win, file_t **file, input_t *input);

/* FUNCTION TO EXPORT AN IMAGE */
sfBool is_home(char *str);
int len_list(file_t *list);
sfBool is_image(char *filename);
void modify_position(file_t *file, int mult);
void all_my_concat(canva_t *canva, char *tmp);
void text_input(sfEvent event, input_t *input);
void export_my(sfSprite *sprite, char *filepath);
void open_export_file(file_t **file, char *directory);
void export_all(char **envp, canva_t *canva, menu_t *menu);
void free_new_all(input_t *, sfRenderWindow *, file_t **, sfRectangleShape *);

/* FUNCTION TO SHOW HELP */
void doc_loop(menu_t *menu);
void aboutus_loop(menu_t *menu, win_t *win);

/* FUNCTION FOR OUR MAIN ACTIONS AND WINDOW*/
win_t *init_window(void);
int windows_loop(char **envp);
sfText *create_text(char *text, sfVector2f pos, char *font);
void evenement_user(win_t *win, canva_t *canva, button_t *button);
sfRectangleShape *init_rectshape(sfVector2f pos, sfVector2f size,
    sfColor col, char *filepath);

/* FUNCTION FROM OUR LIBRARIES */
char *find_pwd(char **envp);
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
int my_strncmp(char *s1, char *s2, int n);

/* FUNCTION TO CREATE AND MANAGE LAYERS*/
void add_layer(canva_t **canva);
void set_visible_layer_state(layer_t *layer);
void draw_canva_layer(win_t *win, layer_t *layer);
void reset_actif_layer(canva_t *canva, layer_t *actual_layer);
layer_t *init_layer(canva_t *canva, sfVector2f pos_button_layer);

/* FUNCTION TO LAUNCH A NEW FILE DIRECTLY IN THE MY_PAINT */
void new_file(canva_t *canva, int wi, int hei);

void place_circle(int x, int y, canva_t *canva, layer_t *layer);
void places_pixels(sfVector2i p1, sfVector2i p2, canva_t *canva, layer_t *);

/* DELETE A LAYER CANVA */
void free_node(layer_t **list);
void delete_layer(win_t *win, canva_t *canva, button_t *butt);

/* FILTER */
void xray_filter(canva_t *canva);
void invert_color(canva_t *canva);
void black_and_white(canva_t *canva);

/* SLIDE */
int move_cross(slide_t *slide, win_t *win);
void all_slide(win_t *win, canva_t *canva, button_t *but);
slide_t *create_slide(sfVector2f pos, int max_value, int start_value);
sfCircleShape *create_circle(sfVector2f pos, float radius, sfColor color);

void free_button(button_t *button);
#endif /* !MY_PROJECT */
