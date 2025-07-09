/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-myftp-romain.berard
** File description:
** read_socket
*/
#include "my.h"

char *read_socket(int socket)
{
    char buffer[2] = {0};
    char *msg = NULL;
    int readed = 0;

    readed = read(socket, buffer, 1);
    while (readed > 0) {
        msg = my_strcat(msg, buffer);
        if (buffer[0] == '\n')
            break;
        readed = read(socket, buffer, 1);
    }
    if (readed < 0) {
        perror("read");
        return NULL;
    }
    return msg;
}
