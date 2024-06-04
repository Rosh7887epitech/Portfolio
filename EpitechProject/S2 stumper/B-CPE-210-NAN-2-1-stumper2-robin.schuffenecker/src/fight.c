/*
** EPITECH PROJECT, 2024
** duo stumper
** File description:
** exo duo
*/

#include <string.h>
#include "my.h"
#include <stdio.h>

static int team2(poke_s *poke)
{
    int damage = 0;
    int power = rand(0, poke->attack);

    damage = power - poke->defense;
    poke->health = poke->defense - damage;
    printf("%s %s %d %s", poke->name, "attack for ",
    power, "damage\n");
    printf("%s %s %d %s", poke->name, "block for ",
        poke->defense, "damage\n");
    if (poke->health > 0) {
        printf("%s %s %d %s", poke->name, "loses ", damage,
        "health  (", poke->health, " left)\n");
    } else {
        printf("%s %s %d %s", poke->name, "loses ", damage,
        "health  (", 0, " left)\n");
        printf("%s %s", poke->name, " is KO\n");
        printf("%s %s", poke->name, " wins the fight!\n");
    }
    return (0);
}

static int team1(poke_s *poke)
{
    int damage = 0;
    int power = rand(0, poke->attack);

    damage = power - poke->defense;
    poke->health = poke->defense - damage;
    printf("%s %s %d %s", poke->name, "attack for ",
    power, "damage\n");
    printf("%s %s %d %s", poke->name, "block for ",
    poke->defense, "damage\n");
    if (poke->health > 0) {
        printf("%s %s %d %s", poke->name, "loses ", damage,
        "health  (", poke->health, " left)\n");
    } else {
        printf("%s %s %d %s", poke->name, "loses ", damage,
        "health  (", 0, " left)\n");
        printf("%s %s", poke->name, " is KO\n");
        printf("%s %s", poke->name, " wins the fight!\n");
    }
    return (0);
}

static int fighters(poke_s *poke)
{
    while (poke != NULL) {
        printf("%s %s %s %d %s %d %s %d %s %d %s", "Pokemon",
        poke->name, "has", poke->attack,
        "attack, ", poke->defense, "defense, ",
        poke->speed, "speed and ", poke->health, "health\n");
	poke = poke->next;
    }
    return (0);
}

int play(poke_s *poke, char *player1, char *player2, int speed)
{
    while (poke != NULL) {
	if (speed < poke->speed) {
	    speed = poke->speed;
	    poke = poke->next;
	}
	if (poke->speed == speed) {
	    team1(poke);
	    team2(poke);
	} else {
	    team2(poke);
	    team1(poke);
	}
    }
    return (0);
}

int fight(poke_s *poke, char *player1, char *player2)
{
    int current_speed = 0;

    fighters(poke);
    for (int i = 0; player1[i] != '\0'; i = i + 1) {
	if (player1[i] != poke->name[i]) {
	    return (84);    
	}
    }
    while (poke->health > 0) {
	play(poke, player1, player2, current_speed);
    }
    return (0);
}
