/*
**
**
**
**
**
**
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void add_node(char **data, poke_s **poke)
{
    poke_s *new = malloc(sizeof(poke_s));

    new->name = data[0];
    new->attack = my_getnbr(data[1]);
    new->defense = my_getnbr(data[2]);
    new->speed = my_getnbr(data[3]);
    new->health = my_getnbr(data[4]);
    new->next = NULL;
    if (*poke != NULL) {
        new->next = *poke;
    }
    *poke = new;
    free(new);
    return;
}

int pars_arg(char *t1, char *t2, poke_s **poke)
{
    char *temp = malloc(sizeof(char) * strlen(t1));
    char **tempo;
    int g = 0;
    char **team1 = my_str_to_word_array(t1, ';');
    char **team2 = my_str_to_word_array(t2, ';');

    if (temp == NULL)
        return 84;
    for (int i = 20; t1[i] != '\0'; i++) {
        temp[g] = t1[i];
        g++;
    }
    temp[g + 1] = '\0';
    tempo = my_str_to_word_array(temp, ';');
    add_node(team1, poke);
    add_node(team2, poke);
    add_node(tempo, poke);
    free(temp);
    free(team1);
    free(team2);
}
