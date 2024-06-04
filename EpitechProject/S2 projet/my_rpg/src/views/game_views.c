/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** game_views
*/

#include "rpg.h"

bool init_player_view(player_view_t *view)
{
    view->view = sfView_create();
    sfView_setSize(view->view, (sfVector2f){360, 202.5});
    sfView_setCenter(view->view, (sfVector2f){1340, 1390});
    return true;
}
