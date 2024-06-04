/*
** EPITECH PROJECT, 2023
** my_strcpy
** File description:
** Copy a str into another str
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    return dest;
}
