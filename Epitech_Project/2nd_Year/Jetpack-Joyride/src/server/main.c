/*
** EPITECH PROJECT, 2025
** B-NWP-400-NAN-4-1-myftp-romain.berard
** File description:
** main
*/

#include "my.h"
#include <signal.h>

static void print_help(void)
{
    printf("USAGE: ./server -p <port> -m <map> [-d]\n");
    printf("  -p port   port number\n");
    printf("  -m map    map file\n");
    printf("  -d        debug mode\n");
}

static int get_port(char **argv, int *i)
{
    int get_port = 0;

    if (strcmp(argv[*i], "-p") == 0) {
        if (argv[*i + 1] == NULL) {
            print_help();
            exit(84);
        }
        get_port = atoi(argv[*i + 1]);
        if (get_port > 65535 || get_port < 1024) {
            printf("Port must be between 1024 and 65535\n");
            exit(84);
        }
        *i += 1;
        return get_port;
    }
    return -1;
}

static char *get_map_path(char **argv, int *i)
{
    char *map = NULL;

    if (strcmp(argv[*i], "-m") == 0) {
        if (argv[*i + 1] == NULL) {
            print_help();
            exit(84);
        }
        map = strdup(argv[*i + 1]);
        if (map == NULL) {
            perror("strdup");
            exit(84);
        }
        *i += 1;
        return map;
    }
    return NULL;
}

static void parameter_parse(char **argv, int *port, bool *debug, char **map)
{
    for (int i = 1; argv[i] != NULL; i++) {
        if (strcmp(argv[i], "-p") != 0 &&
            strcmp(argv[i], "-m") != 0 &&
            strcmp(argv[i], "-d") != 0) {
            print_help();
            exit(84);
        }
        if (*port == -1)
            *port = get_port(argv, &i);
        if (*map == NULL)
            *map = get_map_path(argv, &i);
        if (strcmp(argv[i], "-d") == 0) {
            *debug = true;
        }
    }
}

static int launch_server(int argc, char **argv)
{
    char *map = NULL;
    int port = -1;
    bool debugEnable = false;

    if (argc == 2 && strcmp(argv[1], "-h") == 0) {
        print_help();
        return 0;
    }
    parameter_parse(argv, &port, &debugEnable, &map);
    if (port == -1 || map == NULL) {
        print_help();
        return 84;
    }
    printf("%s\n", debugEnable ? "Debug mode enabled" : "Debug mode disabled");
    create_server(port, debugEnable, map);
    free(map);
    return 0;
}

int main(int argc, char **argv)
{
    return launch_server(argc, argv);
}
