/*
** EPITECH PROJECT, 2024
** open_file.c
** File description:
** that function should open a file
*/

#include <dirent.h>
#include "my_project.h"
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

static sfBool is_point(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '.')
            return sfTrue;
    }
    return sfFalse;
}

sfBool is_image(char *filename)
{
    int i = 0;

    for (i = 0; filename[i] != '\0' && filename[i] != '.'; i++);
    if (my_strcmp(filename + i, ".jpg") == 0 ||
        my_strcmp(filename + i, ".jpeg") == 0 ||
        my_strcmp(filename + i, ".png") == 0) {
            return sfTrue;
        }
    return sfFalse;
}

sfText *create_text(char *text, sfVector2f pos, char *font)
{
    sfText *my_text = sfText_create();
    sfFont *my_font = sfFont_createFromFile(font);

    sfText_setColor(my_text, sfWhite);
    sfText_setPosition(my_text, pos);
    sfText_setFont(my_text, my_font);
    sfText_setString(my_text, text);
    sfText_setCharacterSize(my_text, 20);
    return my_text;
}

static void add_node(file_t **file, char *filepath, sfVector2f pos)
{
    file_t *new = malloc(sizeof(file_t));
    sfVector2f size = {500, 30};
    sfVector2f butt_size = (sfVector2f){20, 20};

    new->butt = malloc(sizeof(button_t) * 2);
    new->butt[0] = init_button(pos, size, (sfColor){155, 155, 155, 255}, NULL);
    pos = (sfVector2f){pos.x + 4, pos.y + 5};
    if (is_image(filepath))
        new->butt[1] = init_button(pos, butt_size, sfRed, "img/file_img.png");
    else
        new->butt[1] = init_button(pos, butt_size, sfRed, "img/file_fol.png");
    sfRectangleShape_setOutlineColor(new->butt[1]->rect, sfTransparent);
    pos = sfRectangleShape_getPosition(new->butt[0]->rect);
    pos.x += 40;
    new->text = create_text(filepath, pos, "img/roboto.ttf");
    new->filename = my_strdup(filepath);
    new->next = NULL;
    if (*file != NULL)
        new->next = *file;
    *file = new;
}

void open_file(file_t **file, char *directory)
{
    DIR *dirent = opendir(directory);
    struct dirent *my_dir;
    struct stat sb;
    int count = 1;
    sfVector2f pos;

    if (dirent == NULL)
        return;
    my_dir = readdir(dirent);
    while (my_dir) {
        stat(my_dir->d_name, &sb);
        if (my_dir->d_name[0] != '.' && (S_ISDIR(sb.st_mode)
        && (!is_point(my_dir->d_name) || is_image(my_dir->d_name)))) {
            pos = (sfVector2f){10, 10 + (count * 40)};
            add_node(file, my_dir->d_name, pos);
            count++;
        }
        my_dir = readdir(dirent);
    }
    closedir(dirent);
}

void open_export_file(file_t **file, char *directory)
{
    DIR *dirent = opendir(directory);
    struct dirent *my_dir;
    struct stat sb;
    int count = 1;
    sfVector2f pos;

    if (dirent == NULL)
        return;
    my_dir = readdir(dirent);
    while (my_dir) {
        stat(my_dir->d_name, &sb);
        if (my_dir->d_name[0] != '.' && !is_point(my_dir->d_name)
        && S_ISDIR(sb.st_mode)) {
            pos = (sfVector2f){10, 10 + (count * 40)};
            add_node(file, my_dir->d_name, pos);
            count++;
        }
        my_dir = readdir(dirent);
    }
    closedir(dirent);
}
