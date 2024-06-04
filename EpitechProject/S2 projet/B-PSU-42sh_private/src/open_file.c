/*
** EPITECH PROJECT, 2024
** B-PSU-MIRROR-42
** File description:
** open_file
*/

#include "history.h"
#include "my_project.h"
int open_history_read(envp_info_t *envp, char **path)
{
    int fd = 0;

    *path = find_in_envp(envp->l_envp, "HOME=", 5);
    if (*path == NULL)
        return -1;
    *path = my_strcat(*path + 5, "/.42history");
    fd = open(*path, O_RDONLY, 0644);
    return fd;
}

char *search_history_data(envp_info_t *envp)
{
    char *buffer = NULL;
    char *path = NULL;
    struct stat sb;
    int fd = open_history_read(envp, &path);

    if (fd == -1 || stat(path, &sb) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (sb.st_size + 1));
    if (read(fd, buffer, sb.st_size) == -1)
        return NULL;
    buffer[sb.st_size] = '\0';
    return buffer;
}

int open_history_write(envp_info_t *envp)
{
    int fd = 0;
    char *path = NULL;

    path = find_in_envp(envp->l_envp, "HOME=", 5);
    if (path == NULL)
        return -1;
    path = my_strcat(path + 5, "/.42history");
    fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
    return fd;
}

char *open_file(envp_info_t *envp)
{
    char *buffer = NULL;
    char *path = NULL;
    struct stat stats;
    int size = 0;
    int fd = open_history_read(envp, &path);

    if (fd == -1 || stat(path, &stats) == -1)
        return NULL;
    size = stats.st_size + 1;
    buffer = malloc(sizeof(char) * size);
    if (buffer == NULL || read(fd, buffer, size) < 0) {
        close(fd);
        return NULL;
    }
    buffer[size - 1] = '\0';
    close(fd);
    return buffer;
}

char *get_data_file(envp_info_t *envp)
{
    char *buffer = NULL;

    if (envp == NULL)
        return NULL;
    buffer = open_file(envp);
    if (buffer == NULL)
        return NULL;
    return buffer;
}
