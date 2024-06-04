/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z')) {
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}
