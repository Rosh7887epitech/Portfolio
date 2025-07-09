/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_
    #include "my.h"

typedef struct entity_args_s {
    int row;
    int tile_width;
    int tile_height;
} entity_args_t;

typedef struct client_info_s {
    float posX;
    float posY;
    char **player_map;
    int score;
    int state;
} client_t;

struct info_tile_s {
    int x;
    int y;
    int tile_width;
    int tile_height;
    float playerWidth;
    float playerHeight;
    float playerX;
    float playerY;
};

typedef struct server_info_s {
    struct sockaddr_in my_addr;
    struct pollfd fds[MAX_CLIENT];
    int server_fd;
    int nfds;
    client_t clients[MAX_CLIENT];
    char **map;
    bool showDebug;
    size_t actual_map_index;
    float elapsedTime_;
    struct timeval last_upt_enti;
    struct timeval first_clock;
} server_t;

#endif /* !MY_STRUCT_H_ */
