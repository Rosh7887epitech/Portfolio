/*
** EPITECH PROJECT, 2024
** injection_handle.c
** File description:
** that function should handle the injection cleaning
*/
#include "my_project.h"
#include <stdlib.h>

static void delete_inje_tab(char ***fct, char **array)
{
    int index = 0;

    for (int i = 0; array[i]; i++) {
        if (!there_injection(array[i])) {
            array[index] = array[i];
            index++;
        }
    }
    array[index] = NULL;
    *fct = array;
}

static char *inje_extract(char **array)
{
    char *inject = NULL;

    for (int i = 0; array[i]; i++) {
        if (is_injection(array[i])) {
            inject = my_strdup(array[i]);
            break;
        }
    }
    return inject;
}

char *make_tab_inje(info_t *line, char ***fct, envp_info_t *info)
{
    char *inject = NULL;
    char **array = NULL;

    if (!there_injection(line->line_getted))
        return NULL;
    array = str_to_word_array(line->line_getted, " ");
    array = remove_quotes_before_list(array, "<", "<<");
    if (there_injection(line->line_getted) && !handle_null_redi(array, info))
        return NULL;
    if (!make_good_tab(&array))
        return NULL;
    inject = inje_extract(array);
    delete_inje_tab(fct, array);
    return inject;
}

int handle_usr_injection(info_t *line, char ***array, envp_info_t *info)
{
    char *inject = make_tab_inje(line, array, info);

    if (inject != NULL) {
        inject = remove_quotes(inject);
        if (!handle_injection((char *[]){inject, NULL}))
            return 1;
    }
    return 0;
}

bool handle_null_command(void)
{
    my_printerror("Invalid null command.\n", true);
    if (!isatty(STDIN_FILENO))
        exit(1);
    return true;
}
