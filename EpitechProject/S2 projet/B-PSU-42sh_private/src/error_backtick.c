/*
** EPITECH PROJECT, 2024
** error_backtick.c
** File description:
** that file should handle error backtick
*/
#include "my_project.h"

bool error_backtick(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '`' && is_pos_in_quotes(str, i) != SINGLE_QUOTES)
            count++;
    }
    if (count % 2 != 0) {
        my_printerror("Unmatched '`'.\n", true);
        if (!isatty(STDIN_FILENO))
            exit(1);
        return true;
    }
    return false;
}

int invalid_slash_tick(char *line, char *command, char *tmp)
{
    if (access(command, F_OK) == -1) {
        my_printerror(command, 1);
        my_printerror(": Command not found.\n", 1);
        tmp = my_strcat("`", tmp);
        tmp = my_strcat(tmp, "`");
        replace_strings(line, tmp, " ");
        return -1;
    }
    return 0;
}

int is_invalid_tick_cmd(char **tab_tick, int i, char *line, envp_info_t *info)
{
    char *fct = NULL;
    char *env_find = NULL;
    char *command = my_strtok(tab_tick[i], " ")[0];
    char *tmp = my_strdup(tab_tick[i]);

    if (!is_slash(tmp)) {
        if (tmp[0] == '\0')
            return 0;
        tmp = my_strcat("`", tmp);
        tmp = my_strcat(tmp, "`");
        fct = reduce_path(command);
        env_find = find_path(info->l_envp, fct);
        if (handle_unknown_command(env_find, remove_quotes(command)) != 0) {
            info->return_status = 1;
            replace_strings(line, tmp, " ");
            return -1;
        }
        return 0;
    } else
        return invalid_slash_tick(line, command, tmp);
}
