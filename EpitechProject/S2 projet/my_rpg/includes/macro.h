/*
** EPITECH PROJECT, 2024
** macro
** File description:
** macro
*/

#pragma once

#ifdef DEBUG
    #define IF_DEBUG(code) code
#else
    #define IF_DEBUG(code)
#endif

#define ABS(value) ((value < 0) ? (value * -1) : (value))
#define CHECK_NULL(value) if (value == NULL) return (NULL)
#define CREATE_AND_CHECK(value) if (value == NULL) return (NULL)
#define SET_FRATE(window, fps) sfRenderWindow_setFramerateLimit(window, fps)
#define SET_VIEW(window, view) sfRenderWindow_setView(window, view)
#define DESTROY_WINDOW(window) sfRenderWindow_destroy(window)
#define IS_W_OPEN(window) sfRenderWindow_isOpen(window)
#define CLEAR_WINDOW(window, color) sfRenderWindow_clear(window, color)
#define DISPLAY_WINDOW(window) sfRenderWindow_display(window)
#define CLOSE_WINDOW(window) sfRenderWindow_close(window)
#define POLL_EVENT(window, event) sfRenderWindow_pollEvent(window, event)
#define SIZE_INVENTORY = 16
