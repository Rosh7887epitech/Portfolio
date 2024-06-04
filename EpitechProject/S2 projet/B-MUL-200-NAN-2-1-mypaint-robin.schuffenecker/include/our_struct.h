/*
** EPITECH PROJECT, 2024
** our_struct.c
** File description:
** that files contains all of our struct
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdlib.h>

#ifndef OUR_STRUCT
    #define OUR_STRUCT

enum shape {
    RECTANGLE = 0,
    CIRCLE
};

enum tools {
    NONE = 0,
    PENCIL,
    RUBBER,
    BUCKET,
    HAND,
    PIPETTE,
    COLOR,
    MYFILE,
    SELECT
};

enum button_state {
    NON = 0,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct color_rgba_s {
    int red;
    int green;
    int blue;
    int alpha;
} color_s;

typedef struct info_windows_s {
    sfRenderWindow *win;
    sfEvent event;
    sfSprite *crosshair;
    sfRectangleShape *background;
    sfRectangleShape *gui;
    sfRectangleShape *gui_left;
    sfRectangleShape *gui_canva;
    sfRectangleShape *gui_layer;
    sfRectangleShape *gui_right;

    char **crossair_tab;
    char **envp;
} win_t;

typedef struct object_s {
    sfRectangleShape *rect;
    sfBool (*is_clicked) (struct object_s *button, sfMouseButtonEvent *evt);
    sfBool (*is_button_hover) (struct object_s *button, sfMouseMoveEvent *evt);
    enum button_state state;
} obj_t;

typedef struct linked_list_layer_s {
    sfSprite *screen_sprite;
    sfUint8 *uint_tab;
    sfTexture *texture;
    sfBool is_visible;
    sfBool is_active;
    obj_t **button;
    struct linked_list_layer_s *next;
}layer_t;

typedef struct canva_where_draw_s {
    layer_t *layer;
    sfFloatRect sprite_rect;
    sfVector2f scale;
    int width;
    sfColor tool_color;
    int height;
    int tools_size;
    int tool;
    int tool_shape;
    sfVector2i old_pos;
} canva_t;

typedef struct file_menu {
    obj_t **butt;
    sfText *text;
    char *filename;
    struct file_menu *next;
} file_t;

typedef struct slide_bar_s {
    sfCircleShape *left;
    sfCircleShape *right;
    sfRectangleShape *bar;
    sfRectangleShape *cross;
    sfVector2f start_pos;
    int max_value;
    int actual_value;
} slide_t;

typedef struct switch_s {
    obj_t *switch_shape;
    sfTexture *switch1;
    sfTexture *switch2;
} switch_t;

typedef struct button_s {
    obj_t *pen;
    obj_t *color;
    obj_t *zoomplus;
    obj_t *zoomminus;
    obj_t *move_hand;
    obj_t *rubber;
    obj_t *pipette;
    obj_t *addlayer;
    obj_t *dellayer;
    obj_t *square;
    obj_t *round;
    switch_t *sw;
    slide_t *slide_size;
    slide_t *slide_trans;

    struct drop_menu_s **menu;

    sfSprite *palette_couleur;
    sfRectangleShape *contour;
} button_t;

typedef struct button_inside_menu_s {
    obj_t *button;
    sfText *text;
    struct button_inside_menu_s *next;
} opt_t;

typedef struct drop_menu_s {
    sfText *text;
    obj_t *button;
    opt_t *options;
    int state;
} menu_t;

typedef struct input_s {
    char *pwd;
    char *input;
    sfText *text;
    sfFont *font;
    obj_t *send;
    sfText *send_text;
    sfRectangleShape *shape;
    obj_t *go_back;
    obj_t *back_img;
}input_t;

#endif /* !MY_PROJECT */
