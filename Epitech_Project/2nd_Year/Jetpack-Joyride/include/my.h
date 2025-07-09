/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-jetpack-romain.berard
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define MAX_QUEUE 5
    #define MAX_CLIENT 5
    #include "stdio.h"
    #include "stdlib.h"
    #include "unistd.h"
    #include "string.h"
    #include "stdbool.h"
    #include <netinet/in.h>
    #include <arpa/inet.h>
    #include <poll.h>
    #include <sys/time.h>
    #include "my_struct.h"

// libC
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strcmp(char *s1, char *s2);
char *my_strcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);

// both: server and client
char *read_socket(int socket);
void remove_carriage_return(char *msg);

// server.c
char **copy_map(char **map);
char *get_map_str(char *filepath);
void parse_map(char *map_str, server_t *server_info);

void disconnect_client(server_t *info, int *i);
void create_server(int port, bool showDebug, char *map);

void update_physics(server_t *info, struct timeval *last_print,
    float *elapsedTime);
// server communication with games
void update_player_pos(server_t *info, int i);

void parse_event(char *msg, server_t *info, int i);

void handle_collission(server_t *info, int i);

void send_entities(server_t *info, int i);
void send_connected(server_t *info, int i);
void send_nb_player(int fd, int nbplayers, bool debug);
void send_players_pos(int nbplayers, server_t *info, int i);
void send_start_game(int nbplayers, server_t *info);
void send_player_score(int nbplayers, server_t *info, int i);

double get_elapsed_time(struct timeval *current_time, struct timeval *last);
#endif
