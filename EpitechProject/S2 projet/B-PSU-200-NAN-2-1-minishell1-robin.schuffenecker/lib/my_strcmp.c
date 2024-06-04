/*
** EPITECH PROJECT, 2023
** strcmp
** File description:
** stcmp
*/

#include "my.h"

static int cond(char *s1, char *s2, int i)
{
    if (s1[i] > s2[i])
        return 1;
    if (s1[i] < s2[i])
        return -1;
}

int my_strcmp(char *s1, char *s2)
{
    int i = 0;
    int k = 0;

    if (my_strlen(s1) != my_strlen(s2))
        return (84);
    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            k = cond(s1, s2, i);
        }
        if (k != 0)
            return k;
        i++;
    }
    return 0;
}

int my_strncmp(char *s1, char *s2, int n)
{
    if (n > my_strlen(s1) || n > my_strlen(s2))
        return my_strcmp(s1, s2);
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0' && i < n; i++) {
        if (s1[i] != s2[i])
            return 1;
    }
    return 0;
}

char *my_strcat(char *s1, char *s2)
{
    int ls1 = my_strlen(s1);
    int ls2 = my_strlen(s2);
    char *result = malloc(sizeof(char) * (ls1 + ls2) + 1);

    for (int i = 0; i != ls1; i++) {
        result[i] = s1[i];
    }
    for (int j = 0; j != ls2; j++) {
        result[ls1 + j] = s2[j];
    }
    result[ls1 + ls2] = '\0';
    return result;
}
