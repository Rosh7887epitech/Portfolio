/*
** EPITECH PROJECT, 2024
** struct.h
** File description:
** that file should include all the structure of the project
*/

#pragma once
#include <termios.h>
#include <stdbool.h>

enum redirection_type {
    NONE = 0,
    SIMPLE = 1,
    DOUBLE = 2
};


typedef struct alias_structure_s {
    char *name;
    char *value;
    struct alias_structure_s *next;
} alias_t;

typedef struct linked_list_path_s {
    char *value;
    struct linked_list_path_s *next;
}path_t;

typedef struct terminal_info_s {
    char *directory_home;
    char *line_getted;
}info_t;

typedef struct jobs_info_s {
    int *n_jobs;
    char **name_jobs;
}jobs_t;

typedef struct environnement_info_s {
    int status;
    int return_status;
    int is_semicolon;
    char **envp;
    char *old_pwd;
    jobs_t *jobs;
    char *tmp_line;
    info_t *my_cd;
    path_t *l_envp;
    path_t *local;
    alias_t *alias;
} envp_info_t;

typedef struct file_descriptor_s {
    int *fd;
    int joind_fd;
} fd_t;

typedef struct redirection_s {
    char *redi;
    struct redirection_s *next;
} redirection_t;


typedef struct termios_structure_s {
    bool is_history;
    int min_col;
    int row;
    int col;
    int index_str;
    int up_row;
    int move_col;
    char c;
    char *str;
    bool is_autocompletion;
    char **tab_cmpletion;
    struct termios old_settings;
    struct termios new_settings;
} term_stru_t;
