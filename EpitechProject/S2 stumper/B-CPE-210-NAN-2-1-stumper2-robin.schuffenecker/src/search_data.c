/*
**
** Stumper 2
** Search_data
**
*/

#include "my.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *search_data(char **argv, char *filepath)
{
    struct stat sb;
    int fd = 0;
    int test = 0;
    char *buff;

    if (stat(filepath, &sb) == -1) {
        return NULL;
    }
    fd = open(filepath, O_RDONLY);
    buff = malloc(sizeof(char) * sb.st_size);
    read(fd, buff, sb.st_size);
    return buff;
}
