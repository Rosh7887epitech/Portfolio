/*
** EPITECH PROJECT, 2024
** my_strncpy.c
** File description:
** that function should copy the first n element
*/

void my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
}
