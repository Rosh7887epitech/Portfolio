/*
** EPITECH PROJECT, 2024
** auto_completion.c
** File description:
** that file should handle auto completion
*/

#include "my_project.h"
#include <dirent.h>

static void add_to_completion(term_stru_t *term, int len, struct dirent *entry)
{
    struct stat sb;
    char *temp = NULL;

    if (entry->d_name[0] == '.')
        return;
    temp = my_strdup(entry->d_name);
    stat(temp, &sb);
    if (S_ISDIR(sb.st_mode))
        temp = my_strcat(temp, "/");
    else if (access(temp, X_OK) != 0)
        return;
    if (term->tab_cmpletion == NULL)
        term->tab_cmpletion = malloc(sizeof(char *) * 2);
    else
    term->tab_cmpletion = realloc(term->tab_cmpletion,
        sizeof(char *) * (len + 2));
    term->tab_cmpletion[len] = my_strdup(temp);
    term->tab_cmpletion[len + 1] = NULL;
}

void add_file_to_tab(char *str, char *filename, term_stru_t *term)
{
    DIR *dir = opendir(filename);
    struct dirent *entry = NULL;
    int len = 0;

    if (dir == NULL)
        return;
    entry = readdir(dir);
    while (entry) {
        len = array_size(term->tab_cmpletion);
        if (str == NULL && entry->d_name[0] != '.')
            add_to_completion(term, len, entry);
        if (str != NULL && my_strncmp(str, entry->d_name, my_strlen(str)) == 0)
            add_to_completion(term, len, entry);
        entry = readdir(dir);
    }
}

static bool print_or_replace(term_stru_t *term, envp_info_t *info, char *str)
{
    if (array_size(term->tab_cmpletion) == 1) {
        info->tmp_line = my_strcat(str, my_strcat(" ",
            term->tab_cmpletion[0]));
        clean_esperluette(info->tmp_line);
        clean_term(term);
        move_cursor(term->row, term->min_col);
        term->str = my_strdup(info->tmp_line);
        my_putstr(info->tmp_line);
        info->tmp_line = NULL;
        return true;
    } else if (array_size(term->tab_cmpletion) == 0) {
        info->tmp_line = NULL;
        return true;
    } else {
        info->tmp_line = my_strdup(term->str);
        my_putstr("\n");
        print_arg(term->tab_cmpletion);
        return false;
    }
}

static bool autocomplete_no_slash(char **path_array, term_stru_t *term,
    char **cmd, envp_info_t *info)
{
    char *str = NULL;

    for (int i = 0; path_array[i]; i++)
        add_file_to_tab(cmd[array_size(cmd) - 1], path_array[i], term);
    for (int i = 0; cmd[i + 1] != NULL; i++)
        str = my_strcat(my_strcat(str, " "), cmd[i]);
    return print_or_replace(term, info, str);
}

static bool autocomplete_no_empty(term_stru_t *term, envp_info_t *info)
{
    char *path = find_in_envp(info->l_envp, "PATH=", 5);
    char **path_array = NULL;
    char **cmd = NULL;

    if (term->tab_cmpletion != NULL)
        free_array(term->tab_cmpletion);
    term->tab_cmpletion = NULL;
    if (path == NULL)
        return false;
    path += 5;
    path_array = my_strtok(my_strcat(path, ":."), ":");
    cmd = my_strtok(term->str, " ");
    if (cmd == NULL)
        return false;
    if (!is_slash(cmd[array_size(cmd) - 1]))
        return autocomplete_no_slash(path_array, term, cmd, info);
    else
        return tabulation_with_path(cmd, term, info);
}

static int nb_of_file_in_folder(DIR *open_dir)
{
    int size = 0;
    struct dirent *dir = readdir(open_dir);

    while (dir != NULL) {
        if (dir->d_name[0] != '.')
            size++;
        dir = readdir(open_dir);
    }
    closedir(open_dir);
    return size;
}

static void print_completion_no_args(term_stru_t *term)
{
    if (term->tab_cmpletion == NULL)
        return;
    for (int i = 0; term->tab_cmpletion[i]; i++) {
        my_putstr(term->tab_cmpletion[i]);
        my_putstr("  ");
    }
}

void read_auto_completion(char *filename, term_stru_t *term)
{
    DIR *open_dir = opendir(filename);
    struct dirent *dir;
    int size = 0;

    if (open_dir == NULL)
        return;
    size = nb_of_file_in_folder(open_dir);
    term->tab_cmpletion = malloc(sizeof(char *) * (size + 1));
    open_dir = opendir(filename);
    dir = readdir(open_dir);
    for (int i = 0; dir != NULL;) {
        if (dir->d_name[0] != '.') {
            term->tab_cmpletion[i] = my_strdup(dir->d_name);
            i++;
        }
        dir = readdir(open_dir);
    }
    closedir(open_dir);
    term->tab_cmpletion[size] = NULL;
    print_completion_no_args(term);
}

static void tabulation_with_no_args(term_stru_t *term, envp_info_t *info)
{
    char *pwd = NULL;

    if (term->str != NULL && term->str[0] != '\0')
        info->tmp_line = my_strdup(term->str);
    else
        info->tmp_line = NULL;
    pwd = getcwd(NULL, 0);
    term->is_autocompletion = true;
    move_cursor(term->row + 1, 0);
    read_auto_completion(pwd, term);
    term->c = '\n';
    term->str = my_strdup("\n");
    free(pwd);
    free_array(term->tab_cmpletion);
    term->tab_cmpletion = NULL;
}

bool handle_tabulation(envp_info_t *info, term_stru_t *term)
{
    int len = 0;

    len = my_strlen(term->str);
    if (term->str == NULL || term->str[0] == '\0' || term->str[len] == ' ' ||
        (len > 0 && term->str[len - 1] == ' ')) {
            tabulation_with_no_args(term, info);
    } else {
        term->is_autocompletion = true;
        info->tmp_line = my_strdup(term->str);
        if (!autocomplete_no_empty(term, info)) {
            term->c = '\n';
            term->str = my_strdup("\n");
        }
    }
    return true;
}
