/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** Write a function that splits a string into words.
** Separators will all be non-alphanumeric characters.
** The function returns an array in which each cell contains
** the address of a string (representing a word).
** The last cell must be null to terminate the array
*/
#include <stdlib.h>

static int alpha(char const c)
{
    if (c >= 'A' && c <= 'Z' || c >= 'a' &&
        c <= 'z' || c >= '0' && c <= '9') {
        return (1);
    }else{
        return (0);
    }
}

static int word(char const *str)
{
    int c = 0;
    int m = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (alpha(str[i]) == 1 && m == 0) {
            m = 1;
            c++;
        }
        if (alpha(str[i]) == 0 && m == 1) {
            m = 0;
        }
    }
    return (c);
}
//int space(char const *str)
//{
//  for (int i = 0; str[i] == 0; i++)
//      
//}


char **my_str_to_word_array(char const *str)
{
    char **tab;
    int k = word(str);
    int z = 0;
    int i = 0;
    int u = 0;
    
    tab = malloc(sizeof(char *) * (k + 1));
    while (str[i] != '\0')
    {
        tab[z] = malloc(sizeof(char) * my_strlen(str));
        while (alpha(str[i]) == 1)
        {
            tab[z][u] = str[i];
            i++;
            u++;
        }
        u = 0;
        z++;
        if (alpha(str[i]) == 0) 
            i++;
    }
    tab[i] = 0;
    return (tab);
}
