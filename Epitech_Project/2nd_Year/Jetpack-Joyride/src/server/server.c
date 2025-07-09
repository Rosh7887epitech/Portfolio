/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-myftp-romain.berard
** File description:
** server
*/
#include "my.h"

static int initialize_socket(void)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int opt = 1;

    if (sockfd < 0) {
        perror("socket");
        exit(84);
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | 15, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

static void create_queue(server_t *info)
{
    if (listen(info->server_fd, MAX_QUEUE) < 0) {
        perror("listen");
        exit(84);
    }
    info->fds[0].fd = info->server_fd;
    info->fds[0].events = POLLIN;
}

static void bind_socket(server_t *info, int port)
{
    memset(&info->my_addr, 0, sizeof(info->my_addr));
    info->nfds = 1;
    info->my_addr.sin_family = AF_INET;
    info->my_addr.sin_port = htons(port);
    info->my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(info->server_fd, (struct sockaddr *)&info->my_addr,
        sizeof(info->my_addr)) < 0) {
        perror("bind");
        exit(84);
    }
    printf("Server listening at %s:%d\n",
        inet_ntoa(info->my_addr.sin_addr), port);
    info->actual_map_index = 0;
    create_queue(info);
    info->elapsedTime_ = 0.0f;
}

static void init_client_info(server_t *info, int client_fd, size_t len)
{
    info->fds[len].fd = client_fd;
    info->fds[len].events = POLLIN;
    info->fds[len].revents = 0;
    info->clients[len].score = 0;
    info->clients[len].posX = 100;
    info->clients[len].posY = 700;
    info->clients[len].state = -1;
    info->clients[len].player_map = copy_map(info->map);
    info->nfds++;
}

static int connect_new_client(server_t *info)
{
    struct sockaddr_in c_addr;
    socklen_t len = sizeof(c_addr);
    int client_fd = accept(info->server_fd, (struct sockaddr *)&c_addr, &len);

    if (client_fd < 0) {
        perror("accept");
        return -1;
    }
    if (info->nfds < MAX_CLIENT) {
        init_client_info(info, client_fd, info->nfds);
        printf("Connection from %s:%d\n", inet_ntoa(c_addr.sin_addr),
            ntohs(c_addr.sin_port));
    } else
        close(client_fd);
    return 0;
}

void disconnect_client(server_t *info, int *i)
{
    close(info->fds[*i].fd);
    free(info->clients[*i].player_map);
    for (int j = *i; j < info->nfds - 1; j++) {
        info->fds[j] = info->fds[j + 1];
        info->clients[j] = info->clients[j + 1];
    }
    info->nfds--;
    for (int j = 1; j < info->nfds; j++) {
        dprintf(info->fds[j].fd, "901: 1\r\n");
        info->clients[j].state = 1;
    }
    info->actual_map_index = 0;
    printf("Client disconnected\n");
}

static char *read_msg(server_t *info, int *i)
{
    char *msg = read_socket(info->fds[*i].fd);

    if (!msg) {
        disconnect_client(info, i);
        return NULL;
    }
    remove_carriage_return(msg);
    if (info->showDebug)
        printf("$> %s\n", msg);
    return msg;
}

static void handle_event(server_t *info)
{
    char *msg = NULL;

    if (info->fds[0].revents & POLLIN) {
        if (connect_new_client(info) == -1) {
            perror("connect_new_client");
            return;
        }
    }
    for (int i = 1; i < info->nfds; i++) {
        if (info->fds[i].revents & POLLHUP)
            disconnect_client(info, &i);
        if (info->fds[i].revents & POLLIN) {
            msg = read_msg(info, &i);
            parse_event(msg, info, i);
        }
    }
}

static void update_elpased(server_t *server_info, struct timeval *last_print,
    float *elapsedTime)
{
    gettimeofday(&server_info->first_clock, NULL);
    (*elapsedTime) = (server_info->first_clock.tv_sec - last_print->tv_sec) +
        (server_info->first_clock.tv_usec - last_print->tv_usec) / 1000000.0;
}

void create_server(int port, bool debug, char *map)
{
    server_t server_info;
    struct timeval last_print;

    memset(&server_info, 0, sizeof(server_info));
    parse_map(get_map_str(map), &server_info);
    server_info.showDebug = debug;
    server_info.server_fd = initialize_socket();
    bind_socket(&server_info, port);
    gettimeofday(&last_print, NULL);
    gettimeofday(&server_info.first_clock, NULL);
    while (1) {
        update_elpased(&server_info, &last_print, &server_info.elapsedTime_);
        if (poll(server_info.fds, server_info.nfds, 0) < 0) {
            perror("poll");
            break;
        }
        handle_event(&server_info);
        update_physics(&server_info, &last_print, &server_info.elapsedTime_);
    }
    close(server_info.server_fd);
}
