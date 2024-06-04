/*
** EPITECH PROJECT, 2024
** B-CPE-210-NAN-2-1-stumper5-davy.gatineau
** File description:
** main
*/

#include "my.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

static int write_in_file(char *buff)
{
    int fd = open("crypt", O_WRONLY | O_CREAT, 0444);

    write(fd, buff, strlen(buff));
    close(fd);
    return 0;
}

static int error_key(int key, char *buff)
{
    if (key < 0) {
        key = negatif_to_pos(key);
        return key;
    }
    if (key == 0) {
        write_in_file(buff);
        free(buff);
        return 0;
    }
    if (key > 26) {
        for (key; key > 26; key -= 26);
        return key;
    }
    return key;
}

static char cond_of_change(char c, int key)
{
    if ((my_is_maj(c) == 0 && (c + key) > 90) ||
        (my_is_maj(c) == 1 && (c + key) > 122)) {
        c = c + key - 26;
    } else
        c = c + key;
    return c;
}

static char *init_buff(int fd, char *file, char *buff)
{
    struct stat sb;

    if (stat(file, &sb) == -1) {
        write(2, "No file\n", 8);
        return NULL;
    }
    buff = malloc(sizeof(char) * sb.st_size);
    if (buff == NULL)
        return NULL;
    if (read(fd, buff, sb.st_size) == -1)
        return NULL;
    return buff;
}

static int cesar_encode_file(int key, char *file)
{
    int fd = open(file, O_RDONLY);
    char *buff = init_buff(fd, file, buff);

    if (buff == NULL)
        return 84;
    key = error_key(key, buff);
    if (key == 84)
        return 84;
    if (key == 0)
        return 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (my_char_isalphanum(buff[i]) == 0) {
            buff[i] = cond_of_change(buff[i], key);
        }
    }
    write_in_file(buff);
    free(buff);
    return 0;
}

static int cesar_encode_string(int key, char *file)
{
    struct stat sb;
    char *buff = strdup(file);

    if (buff == NULL)
        return 84;
    key = error_key(key, buff);
    if (key == 84)
        return 84;
    if (key == 0)
        return 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (my_char_isalphanum(buff[i]) == 0) {
            buff[i] = cond_of_change(buff[i], key);
        }
    }
    write_in_file(buff);
    free(buff);
    return 0;
}

int main(int ac, char **av)
{
    int key = 0;

    if (ac != 4)
        return 84;
    if (parcing_error(av) == 84)
        return (84);
    if (strcmp(av[1], "-f") == 0) {
        key = atoi(av[3]);
        if (cesar_encode_file(key, av[2]) == 84)
            return 84;
    }
    if (strcmp(av[1], "-s") == 0) {
        key = atoi(av[3]);
        if (cesar_encode_string(key, av[2]) == 84)
            return 84;
    }
    return 0;
}
