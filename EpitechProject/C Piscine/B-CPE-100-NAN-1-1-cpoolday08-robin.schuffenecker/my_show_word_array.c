/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** Write a function that displays the content of an array of words.
** There must be one word per line, and each word must end
** with ‘\n’, including the last one.
*/

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++) {
        my_putstr(tab[i]);
        my_putstr("\n");
    }
}
