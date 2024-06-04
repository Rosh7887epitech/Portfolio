/*
** EPITECH PROJECT, 2024
** export.c
** File description:
** that function should export the canva
*/
#include "my_project.h"
#include <string.h>

int len_list(file_t *list)
{
    int count = 0;

    while (list) {
        list = list->next;
        count++;
    }
    return count;
}

void export_my(sfSprite *sprite, char *filepath)
{
    sfImage *image = sfTexture_copyToImage(sfSprite_getTexture(sprite));

    sfImage_saveToFile(image, filepath);
    sfImage_destroy(image);
}

void free_new_all(input_t *input, sfRenderWindow *win, file_t **file,
    sfRectangleShape *rect)
{
    file_t *new = NULL;

    free(input->input);
    free(input->pwd);
    sfRectangleShape_destroy(input->send->rect);
    free(input->send);
    sfText_destroy(input->send_text);
    sfRectangleShape_destroy(input->shape);
    sfText_destroy(input->text);
    free(input);
    sfRenderWindow_destroy(win);
    while (*file) {
        new = (*file)->next;
        free(*file);
        *file = new;
    }
    sfRectangleShape_destroy(rect);
}

void text_input(sfEvent event, input_t *input)
{
    size_t len = 0;

    if (event.type == sfEvtTextEntered && event.text.unicode < 128) {
        len = my_strlen(input->input);
        if (((event.text.unicode >= 'A' && event.text.unicode <= 'Z')
        || (event.text.unicode >= 'a' && event.text.unicode <= 'z')
        || (event.text.unicode == '.') || event.text.unicode == '_')
        && len < 28) {
            input->input[len] = event.text.unicode;
            input->input[len + 1] = '\0';
        }
        if (event.text.unicode == 8 && len > 0)
                input->input[len - 1] = '\0';
        if (event.text.unicode == 13)
            input->input[len] = '\0';
        sfText_setString(input->text, input->input);
    }
}

static void concat_sfuint(sfUint8 *dest, sfUint8 *src, canva_t *canva,
    sfTexture *texture)
{
    int win_size = canva->height * canva->width * 4;

    for (int i = 0; i < win_size; i += 4) {
        if (src[i + 3] != 0) {
            dest[i + 3] = src[i + 3];
            dest[i + 2] = src[i + 2];
            dest[i + 1] = src[i + 1];
            dest[i] = src[i];
        } else {
            dest[i + 3] = dest[i + 3];
            dest[i + 2] = dest[i + 2];
            dest[i + 1] = dest[i + 1];
            dest[i] = dest[i];
        }
    }
    sfTexture_updateFromPixels(texture, dest, canva->width,
        canva->height, 0, 0);
}

void all_my_concat(canva_t *canva, char *tmp)
{
    layer_t *cpy = canva->layer;
    sfTexture *texture = sfTexture_copy(canva->layer->texture);
    int win_size = (canva->width * canva->height * 4);
    sfUint8 *tab_cpy = malloc(sizeof(sfUint8) * win_size);
    sfSprite *sprite = sfSprite_copy(canva->layer->screen_sprite);

    for (int i = 0; i < win_size; i++)
        tab_cpy[i] = canva->layer->uint_tab[i];
    while (cpy) {
        concat_sfuint(tab_cpy, cpy->uint_tab, canva, texture);
        cpy = cpy->next;
    }
    sfSprite_setTexture(sprite, texture, sfFalse);
    export_my(sprite, tmp);
}
