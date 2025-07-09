/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-myftp-romain.berard
** File description:
** str_clean
*/
#include "my.h"
#include <dirent.h>

void remove_carriage_return(char *msg)
{
    size_t len = my_strlen(msg);

    if (len > 2 && msg[len - 2] == '\r' && msg[len - 1] == '\n') {
        msg[len - 2] = '\0';
    }
}
