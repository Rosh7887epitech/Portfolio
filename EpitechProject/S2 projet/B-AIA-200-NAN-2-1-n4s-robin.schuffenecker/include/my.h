/*
** EPITECH PROJECT, 2024
** rendu_n4S
** File description:
** my
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **my_str_to_word_tok(char *str, char *sep);
int my_strlen(char const *str);

typedef struct info_s {
    char *first_info;
    char *mid_info;
    char *last_info;
    float speed;
    int continue_while;
}info_t;

void move_forward(char *line, size_t buff, float speed);
void move_backwards(char *line, size_t buff, float speed);
void cycle_wait(char *line, size_t buff, int cycles);
void turn(char *line, size_t buff, float degrees);
void get_lidar(char *line, size_t buff, info_t *info);
int stay_straight(char *line, size_t buff, info_t *info);
void start_simulation(char *line, size_t buff);
void stop_simulation(char *line, size_t buff);
int read_stdout(char *line);
void move_forward(char *line, size_t buff, float speed);
void move_backwards(char *line, size_t buff, float speed);
void get_lidar(char *line, size_t buff, info_t *info);
void get_info(char *line, size_t buff);
int read_stdout(char *line);
