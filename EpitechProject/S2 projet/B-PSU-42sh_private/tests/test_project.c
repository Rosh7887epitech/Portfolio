/*
** EPITECH PROJECT, 2023
** test_project.c
** File description:
** a file to test : mysh2
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my_project.h"

void redirect_all_std (void)
{
cr_redirect_stdout ();
cr_redirect_stderr ();
}

Test (my_put_nbr, negative, .init=redirect_all_std)
{
    my_put_nbr(-123);
    cr_assert_stdout_eq_str("-123");
}

Test (my_put_nbr, negative_int, .init=redirect_all_std)
{
    my_put_nbr(-2147483647);
    cr_assert_stdout_eq_str("-2147483647");
}

Test (my_put_nbr, negative_overflow, .init=redirect_all_std)
{
    my_put_nbr(-1234567890);
    cr_assert_stdout_eq_str("-1234567890");
}

Test (my_put_nbr, negative_zero, .init=redirect_all_std)
{
    my_put_nbr(-0);
    cr_assert_stdout_eq_str("0");
}

Test (my_put_nbr, negative_digit, .init=redirect_all_std)
{
    my_put_nbr(-5);
    cr_assert_stdout_eq_str("-5");
}

Test (my_putstr, printstr, .init=redirect_all_std)
{
    my_putstr("je suis romain");
    cr_assert_stdout_eq_str("je suis romain");
}

Test(my_putstr, null_str, .init=redirect_all_std)
{
    my_putstr(NULL);
    cr_assert_stdout_eq_str("null pointeur (normaly segfault)\n");
}

Test (my_strcmp, comp_str, .init=redirect_all_std)
{
    char *str = my_strdup("romain");
    char *str2 = my_strdup("romain");
    int result = my_strcmp(str, str2);
    cr_assert_eq(result, 0);
    free(str);
}

Test (my_strcmp, null_str, .init=redirect_all_std)
{
    int result = my_strcmp(NULL, NULL);
    cr_assert_eq(result, -1);
}

Test (my_strcpy, cpy_str, .init=redirect_all_std)
{
    char *str = my_strdup("romain");
    char *str_tocpy = malloc(sizeof(char) * 7);
    my_strcpy(str_tocpy, "romain");
    cr_assert_str_eq(str_tocpy, "romain");
}

Test (my_getnbr, get_zero, .init=redirect_all_std)
{
    char *str = my_strdup("0");
    cr_assert_eq(my_getnbr(str), 0);
}

Test (my_getnbr, get_pos, .init=redirect_all_std)
{
    char *str = my_strdup("10");
    cr_assert_eq(my_getnbr(str), 10);
}

Test (my_getnbr, get_neg, .init=redirect_all_std)
{
    char *str = my_strdup("-10");
    cr_assert_eq(my_getnbr(str), -10);
}

Test (my_strncmp, not_same, .init=redirect_all_std)
{
    cr_assert_eq(my_strncmp("Romain", "Axel", 4), -1);
}

Test (my_strncmp, same, .init=redirect_all_std)
{
    cr_assert_eq(my_strncmp("romain", "romain", 4), 0);
}

Test (my_strncmp, n_minus_len, .init=redirect_all_std)
{
    cr_assert_eq(my_strncmp("romain", "romain", 20), 0);
}

Test (my_strcat, cat_two_str, .init=redirect_all_std)
{
    cr_assert_str_eq(my_strcat("ROMAIN", "romain"), "ROMAINromain");
}

Test (my_strcat, two_null, .init=redirect_all_std)
{
    cr_assert_null(my_strcat(NULL, NULL));
}

Test (my_strcat, only_one_null, .init=redirect_all_std)
{
    cr_assert_not_null(my_strcat("second null", NULL));
    cr_assert_str_eq(my_strcat("second null", NULL), "second null");
    cr_assert_not_null(my_strcat(NULL,"first null"));
    cr_assert_str_eq(my_strcat(NULL,"first null"), "first null");
}

Test (my_itoa, number, .init=redirect_all_std)
{
    cr_assert_str_eq(my_itoa(10), "10");
}

Test (my_itoa, neg_numb, .init=redirect_all_std)
{
    cr_assert_str_eq(my_itoa(-10), "-10");
}

Test (my_itoa, zero_nb, .init=redirect_all_std)
{
    cr_assert_str_eq(my_itoa(0), "0");
}

Test(my_printerror, print_errors, .init=redirect_all_std)
{
    int status = my_printerror("TEST ERROR MESSAGE", 84);
    cr_assert_eq(status, 84);
    cr_assert_stderr_eq_str("TEST ERROR MESSAGE");
}

Test (print_arg, array_two_rows, .init=redirect_all_std)
{
    char **array = my_strtok("TESTS TEST", " ");

    print_arg(array);
    cr_assert_stdout_eq_str("TESTS\nTEST\n");
    print_arg(NULL);
}

Test (print_list, empty_list, .init=redirect_all_std)
{
    path_t *list = NULL;
    print_list(list);
    add_end(&list, "toprint");
    print_list(list);
    cr_assert_stdout_eq_str("toprint\n");
}

Test (array_cpy, cpy_array, .init=redirect_all_std)
{
    char **array = my_strtok("TESTS test"," ");
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "TESTS");
    cr_assert_str_eq(array[1], "test");
    char **arraycpy = array_cpy(array);
    cr_assert_str_eq(arraycpy[0], "TESTS");
    cr_assert_str_eq(arraycpy[1], "test");
}


Test (add_end, add_list, .init=redirect_all_std)
{
    path_t *list = NULL;

    cr_assert_null(list);
    add_end(&list, "romain");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    add_end(&list, "testunitaire");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "testunitaire");
    modify_node(list, "replacethat", 1);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "replacethat");
    modify_node(list, "replace", 10);
    cr_assert_not_null(list);
}

Test (free_pos, free_given_pos, .init=redirect_all_std)
{
    path_t *list = NULL;
    cr_assert_null(list);
    list = free_pos(list, NULL);
    cr_assert_null(list);
    add_end(&list, "romain");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    list = free_pos(list, "romain");
    cr_assert_null(list);
}

Test (modify_envp, modify_complety_list, .init=redirect_all_std)
{
    path_t *list = NULL;
    cr_assert_null(list);
    int status = modify_envp(&list, "romain", NULL);
    cr_assert_eq(status, 0);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=");
    status = modify_envp(&list, "romain", "addpath");
    cr_assert_eq(status, 0);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=addpath");
    status = modify_envp(&list, "newone", NULL);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=addpath");
    cr_assert_str_eq(list->next->value, "newone=");
    status = modify_envp(&list, "newone", "newargs");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=addpath");
    cr_assert_str_eq(list->next->value, "newone=newargs");
    status = modify_envp(&list, "namenotnull", "notnull");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=addpath");
    cr_assert_str_eq(list->next->value, "newone=newargs");
    cr_assert_str_eq(list->next->next->value, "namenotnull=notnull");
    status = modify_envp(&list, "namenotnull", NULL);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain=addpath");
    cr_assert_str_eq(list->next->value, "newone=newargs");
    cr_assert_str_eq(list->next->next->value, "namenotnull=");
}

Test (remove_envp, remove_all, .init=redirect_all_std)
{
    path_t *list = NULL;

    cr_assert_null(list);
    add_end(&list, "romain");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    add_end(&list, "titouan");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "titouan");
    add_end(&list, "jules");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "titouan");
    cr_assert_str_eq(list->next->next->value, "jules");
    remove_envp(&list, "titouan");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "jules");
    cr_assert_null(list->next->next);
    cr_assert_eq(remove_envp(&list, NULL), 0);
    remove_envp(&list, "unknown");
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "romain");
    cr_assert_str_eq(list->next->value, "jules");
}

Test (envp_to_list, null_envp, .init=redirect_all_std)
{
    path_t *list = NULL;
    cr_assert_null(list);
    list = envp_to_list(NULL);
    cr_assert_null(list);
}

Test (envp_to_list, env_w_value, .init=redirect_all_std)
{
    char **envp = malloc(sizeof(char *) * 3);
    path_t *list = NULL;
    cr_assert_not_null(envp);
    cr_assert_null(list);
    envp[0] = my_strdup("firstele");
    cr_assert_not_null(envp[0]);
    cr_assert_str_eq(envp[0], "firstele");
    envp[1] = my_strdup("secondele");
    cr_assert_str_eq(envp[1], "secondele");
    envp[2] = NULL;
    cr_assert_null(envp[2]);
    list = envp_to_list(envp);
    cr_assert_not_null(list);
    cr_assert_str_eq(list->value, "firstele");
    cr_assert_str_eq(list->next->value, "secondele");
}

Test(is_charalphanum, allfunction, .init=redirect_all_std)
{
    cr_assert_eq(is_charalphanum('-'), 1);
    cr_assert_eq(is_charalphanum('z'), 0);
}

Test(is_alphanum, isnot, .init=redirect_all_std)
{
    char *test = my_strdup("azertyuiop");
    cr_assert_not_null(test);
    cr_assert_eq(is_alphanum(test), 0);
    free(test);
    test = my_strdup("azertyuiop+");
    cr_assert_not_null(test);
    cr_assert_eq(is_alphanum(test), 1);
    cr_assert_eq(is_alphanum(NULL), 1);
}

Test (clean_esperluette, test_esperluette_clean, .init=redirect_all_std)
{
    char *str = NULL;
    cr_assert_null(str);
    str = my_strdup("ls && ls");
    cr_assert_not_null(str);
    clean_esperluette(str);
    cr_assert_str_eq(str, "ls && ls");
    free(str);
    str = my_strdup("ls &&\t\tls  ;     \t ls\n");
    cr_assert_not_null(str);
    clean_esperluette(str);
    cr_assert_str_eq(str, "ls && ls ; ls");
    free(str);
    str = my_strdup("ls\t    \t\t");
    cr_assert_not_null(str);
    clean_esperluette(str);
    cr_assert_str_eq(str, "ls");
}

Test (is_good_redi, testgoodredi, .init=redirect_all_std)
{
    redirection_t *redi = malloc(sizeof(redirection_t));
    cr_assert_not_null(redi);
    redi->redi = my_strdup(">");
    redi->next = malloc(sizeof(redirection_t));
    cr_assert_not_null(redi->next);
    redi->next->redi = my_strdup(">");
    redi->next->next = malloc(sizeof(redirection_t));
    redi->next->next->redi = my_strdup("<");
    redi->next->next->next = NULL;
    cr_assert_eq(is_good_redi(redi), false);
    free(redi->redi);
    free(redi->next->redi);
    free(redi->next);
    free(redi);
    char *str = my_strdup("test");
    cr_assert_not_null(str);
    cr_assert_eq(there_injection(str), false);
    free(str);
    str = my_strdup("test<");
    cr_assert_not_null(str);
    cr_assert_eq(there_injection(str), true);
    free(str);
    char **cmd = malloc(sizeof(char *) * 3);
    cr_assert_not_null(cmd);
    cmd[0] = my_strdup("test");
    cmd[1] = my_strdup("test2");
    cmd[2] = NULL;
    cr_assert_eq(is_ambiguous_redirect(cmd), false);
    free(cmd[0]);
    free(cmd[1]);
    free(cmd);
    char ***cmd2 = malloc(sizeof(char **) * 3);
    cr_assert_not_null(cmd2);
    cmd2[0] = malloc(sizeof(char *) * 3);
    cr_assert_not_null(cmd2[0]);
    cmd2[0][0] = my_strdup("test");
    cmd2[0][1] = my_strdup("test2");
    cmd2[0][2] = NULL;
    cmd2[1] = NULL;
    cr_assert_eq(is_ambiguous_injection(cmd2, 0), false);
}

Test (exit_function, test_exit, .init=redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    exit_function("exitt", info);
    cr_assert_stderr_eq_str("exitt: Command not found.\n");
}

Test (my_build_in, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
        info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("setenv test test2");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(my_build_in(line, info), 0);
    line->line_getted = my_strdup("unsetenv test");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(my_build_in(line, info), 0);
    line->line_getted = my_strdup("env");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(my_build_in(line, info), 0);
    line->line_getted = my_strdup("cd");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(my_build_in(line, info), 1);
}

Test (handle_esperluette, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->return_status = 0;
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->directory_home = my_strdup("/home");
    line->line_getted = my_strdup("ls && ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_esperluette(line->line_getted, info), true);
    line->line_getted = my_strdup("ls &&");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_esperluette(line->line_getted, info), true);
    line->line_getted = my_strdup("ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_esperluette(line->line_getted, info), false);
    line->line_getted = my_strdup("&& ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_esperluette(line->line_getted, info), true);
}

Test (open_file, test_open_file, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *test = NULL;
    info_t *line = malloc(sizeof(info_t));
    info->return_status = 0;
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    test = get_data_file(info);
    cr_assert_eq(test, NULL);
}

Test (delete_line_in_tab, test_search_invalid, .init = redirect_all_std)
{
    int return_value = 0;
    char **tab = my_strtok("coucou test hey", " ");
    char *searched = "hola";

    return_value = search(tab, searched);
    cr_assert_eq(return_value, -1);
}

Test (delete_line_in_tab, test_search_empty, .init = redirect_all_std)
{
    int return_value = 0;
    char **tab = my_strtok("coucou test hey", " ");
    char *searched = NULL;

    return_value = search(tab, searched);
    cr_assert_eq(return_value, -1);
}

Test (delete_line_in_tab, test_search_valid, .init = redirect_all_std)
{
    int return_value = 0;
    char **tab = my_strtok("coucou test hey", " ");
    char *searched = "coucou";

    return_value = search(tab, searched);
    cr_assert_neq(return_value, 1);
}

Test (delete_line_in_tab, test_shift_line, .init = redirect_all_std)
{
    char **return_value = NULL;
    int pos = 1;
    char **tab = my_strtok("coucou test hey", " ");

    return_value = shift_line_in_tab(pos, tab);
    cr_assert_neq(return_value, NULL);
    cr_assert_str_eq(return_value[0], "coucou");
    cr_assert_str_neq(return_value[1], "test");
    cr_assert_str_eq(return_value[1], "hey");
    cr_assert_eq(return_value[2], NULL);
}

Test (delete_line_in_tab, test_delete, .init = redirect_all_std)
{
    char **return_value = NULL;
    char *searched = "test";
    char **tab = my_strtok("coucou test hey", " ");

    return_value = my_delete_line_in_tab(tab, searched);
    cr_assert_neq(return_value, NULL);
    cr_assert_str_eq(return_value[0], "coucou");
    cr_assert_str_neq(return_value[1], "test");
    cr_assert_str_eq(return_value[1], "hey");
    cr_assert_eq(return_value[2], NULL);
}

Test (history_errors, test_errors_history_wtt_err, .init = redirect_all_std)
{
    char line[] = "history";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    return_value = history_error(line, info);
    cr_assert_eq(return_value, 0);
}

Test (history_errors, test_errors_history_wt_err, .init = redirect_all_std)
{
    char line[] = "history test";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);
    return_value = history_error(line, info);
    cr_assert_eq(return_value, 1);
}

Test (history_errors, test_errors_history_wt_null, .init = redirect_all_std)
{
    char *line = NULL;
    cr_assert_null(line);
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);
    cr_assert_eq(history_error(line, info), 1);
}

Test (history_errors, test_errors_history_wt_nb, .init = redirect_all_std)
{
    char line[] = "history 5";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    return_value = history_error(line, info);
    cr_assert_eq(return_value, 0);
}

Test (history_errors, test_check_err_line_minus, .init = redirect_all_std)
{
    char line[] = "-";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    return_value = check_error_line(line, info);
    cr_assert_eq(return_value, -1);
}

Test (history_errors, test_check_err_line_char, .init = redirect_all_std)
{
    char line[] = "test";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    return_value = check_error_line(line, info);
    cr_assert_eq(return_value, -1);
}

Test (history_errors, test_check_err_line_nb, .init = redirect_all_std)
{
    char line[] = "42";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    return_value = check_error_line(line, info);
    cr_assert_eq(return_value, 0);
}

Test (just_history, test_simple_history_cmd, .init = redirect_all_std)
{
    char line[] = "Hey that's a test";
    int return_value = 0;

    return_value = just_history(line);
    cr_assert_eq(return_value, 0);
    cr_assert_stdout_eq_str("Hey that's a test");
}

Test (just_history, test_null_history_cmd, .init = redirect_all_std)
{
    char *line = NULL;
    int return_value = 0;

    return_value = just_history(line);
    cr_assert_eq(return_value, -1);
}

Test (execute_history, test_simple_history, .init = redirect_all_std)
{
    char line[] = "history";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);
    info->return_status = 0;
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    return_value = execute_history(line, info);
    cr_assert_eq(return_value, -1);
}

Test (execute_history, test_multi_history, .init = redirect_all_std)
{
    char line[] = "history 5";
    int return_value = 0;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_not_null(info);
    return_value = execute_history(line, info);
    cr_assert_eq(return_value, 0);
}

Test (is_history_cmd, test_is_history_true, .init = redirect_all_std)
{
    char line[] = "history 5";
    int return_value = 0;

    return_value = is_history_command(line);
    cr_assert_eq(return_value, 0);
}

Test (is_history_cmd, test_is_history_false, .init = redirect_all_std)
{
    char line[] = "ls";
    int return_value = 0;

    return_value = is_history_command(line);
    cr_assert_eq(return_value, 1);
}

Test (is_history_cmd, test_is_history_null, .init = redirect_all_std)
{
    char *line = NULL;
    cr_assert_eq(is_history_command(line), EXIT_FAILURE);
}

Test (history, test_excla_history, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("!");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(history_command(line, info), 1);
}

Test (history, test_history, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));

    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("history");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(history_command(line, info), -1);
}

Test (history, test_non_history, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));

    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(history_command(line, info), 0);
}

Test (history, test_bad_history, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));

    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("history -");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(history_command(line, info), -1);
}

Test (history_wt_args, test_history_too_much_args, .init = redirect_all_std)
{
    char **line_array = my_strtok("history test test1 test2", " ");
    char *data = "ceci est un test";
    int nb_lines = 4;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    cr_assert_eq(history_with_argument(line_array, data, nb_lines, info), -1);
}

Test (history_wt_args, test_history_bad_arg, .init = redirect_all_std)
{
    char **line_array = my_strtok("history test", " ");
    char *data = "ceci est un test";
    int nb_lines = 4;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    cr_assert_eq(history_with_argument(line_array, data, nb_lines, info), -1);
}

Test (history_wt_args, test_history_sup_nb_line, .init = redirect_all_std)
{
    char **line_array = my_strtok("history 10", " ");
    char *data = "ceci est un test";
    int nb_lines = 4;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    cr_assert_not_null(info);

    cr_assert_eq(history_with_argument(line_array, data, nb_lines, info), 0);
}

Test (exclamation_history, test_multi_excla, .init = redirect_all_std)
{
    char *str = "!!";
    cr_assert_eq(multiple_excla(str), 0);
}

Test (exclamation_history, test_one_excla, .init = redirect_all_std)
{
    char *str = "!";
    cr_assert_eq(multiple_excla(str), 1);
}

Test (exclamation_history, test_is_nb_true, .init = redirect_all_std)
{
    char *str = "32";
    cr_assert_eq(is_number(str), 0);
}

Test (exclamation_history, test_is_nb_false, .init = redirect_all_std)
{
    char *str = "test";
    cr_assert_eq(is_number(str), -1);
}

Test (exclamation_history, test_is_nb_null, .init = redirect_all_std)
{
    char *str = NULL;
    cr_assert_eq(is_number(str), -1);
}

Test (exclamation_history, test_is_excla_true, .init = redirect_all_std)
{
    char *str = "!test";
    cr_assert_str_not_empty(str);
    cr_assert_eq(is_exclamation(str), true);
}

Test (exclamation_history, test_is_excla_false, .init = redirect_all_std)
{
    char *str = "test";
    cr_assert_str_not_empty(str);
    cr_assert_eq(is_exclamation(str), false);
}

Test (exclamation_history, test_delete_line_l, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *str = "test";
    int fd = 0;
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_eq(delete_line_f(str, fd, info), -1);
}

Test (exclamation_history, test_execute_excla_error, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("! ");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(execute_exclamation(line, info), 1);
}

Test (exclamation_history, test_execute_excla_multi, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("!!");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(execute_exclamation(line, info), 1);
}

Test (exclamation_history, test_execute_excla_normal, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("!test");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(execute_exclamation(line, info), 1);
}

Test (exclamation_history, test_execute_excla_empty, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = NULL;
    cr_assert_eq(execute_exclamation(line, info), 1);
}

Test (count, test_count_line_file, .init = redirect_all_std)
{
    char *str = "hello\nhow\nare\nyou\n";
    cr_assert_eq(count_line_file(str), 4);
}

Test (count, test_count_line_file_empty, .init = redirect_all_std)
{
    char *str = NULL;
    cr_assert_eq(count_line_file(str), -1);
}

Test (count, test_nb_line_of_array, .init = redirect_all_std)
{
    char **array = my_strtok("hello how are you", " ");
    cr_assert_eq(nb_line_of_array(array), 4);
}

Test (count, test_nb_command_line_empty, .init = redirect_all_std)
{
    char *str = "\n";
    cr_assert_eq(nb_command_line(str), 0);
}

Test (count, test_nb_command_line_good, .init = redirect_all_std)
{
    char *str = "1 10:11  ls";
    cr_assert_eq(nb_command_line(str), 2);
}

Test (count, test_nb_command_line_wrong, .init = redirect_all_std)
{
    char *str = "ls 10:11 ls";
    cr_assert_eq(nb_command_line(str), -1);
}

Test (count, test_nb_command_line_null, .init = redirect_all_std)
{
    char *str = NULL;
    cr_assert_eq(nb_command_line(str), -1);
}

Test (concat_history, test_tab_elem_line_cat, .init = redirect_all_std)
{
    char **array = my_strtok("12 10:28  ls", " ");
    cr_assert_not_null(array);
    cr_assert_str_eq(tab_elem_line_cat(array), "ls ");
}

Test (search_history, test_cmd_good, .init = redirect_all_std)
{
    char **array = my_strtok("12 10:28  ls", " ");
    envp_info_t *info = malloc(sizeof(envp_info_t));
    int fd = 0;
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_eq(found_cmd(fd, array, info), -1);
}

Test (search_history, test_cmd_wrong, .init = redirect_all_std)
{
    char **array = my_strtok("12 10:28  \n", " ");
    envp_info_t *info = malloc(sizeof(envp_info_t));
    int fd = 0;
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_eq(found_cmd(fd, array, info), -1);
}

Test (search_history, test_cmd_empty_array, .init = redirect_all_std)
{
    char **array = NULL;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    int fd = 0;

    cr_assert_eq(found_cmd(fd, array, info), -1);
}

Test (search_history, test_search_cmd_in_history_null)
{
    char *data = NULL;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *search = "test";
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_null(search_cmd_in_history(data, search, info));
}

Test (search_history, test_search_cmd_in_history_non_null)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *data = "0 11:02  test";
    char *search = "test";
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_null(search_cmd_in_history(data, search, info));
}

Test (search_history, test_search_nb_null)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *data = NULL;
    char *search = NULL;
    cr_assert_not_null(info);
    cr_assert_null(search_nb_in_history(data, search, info));
}

Test (search_history, test_search_last_null)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *data = NULL;
    char *search = NULL;
    cr_assert_not_null(info);
    cr_assert_null(search_nb_in_history(data, search, info));
}

// Test (add_history, test_format_line_history_good, .init = redirect_all_std)
// {
//     char *str = my_strdup("ls\n");
//     cr_assert_not_null(str);
//     cr_assert_not_null(format_line_history(str));
// }

Test (add_history, test_format_line_history_bad, .init = redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    char *str = my_strdup("\n");
    info_t *line = malloc(sizeof(info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    cr_assert_null(format_line_history(str, info));
}

Test (add_alias, add_aliases, .init=redirect_all_std)
{
    alias_t *alias = NULL;
    cr_assert_null(alias);
    add_alias(&alias, "name1", "value1");
    cr_assert_not_null(alias);
    cr_assert_null(alias->next);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_str_eq("name1", alias->name);
    cr_assert_str_eq("value1", alias->value);
    add_alias(&alias, "name1", "value2");
    cr_assert_not_null(alias);
    cr_assert_null(alias->next);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_str_eq(alias->name, "name1");
    cr_assert_str_eq(alias->value, "value2");
    add_alias(&alias, "name2", "value3");
    cr_assert_not_null(alias);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_not_null(alias->next);
    cr_assert_str_eq(alias->name, "name2");
    cr_assert_str_eq(alias->value, "value3");
    add_alias(&alias, NULL, NULL);
    add_alias(&alias, "name3", NULL);
    add_alias(&alias, NULL, "value4");
}

Test (handle_alias_command, handling_alias_command, .init=redirect_all_std)
{
    alias_t *alias = NULL;
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->envp = NULL;
    char *str = my_strdup("alias ls pwd");
    cr_assert_eq(handle_alias_command(str, &alias, info), true);
    cr_assert_not_null(alias);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_str_eq(alias->name, "ls");
    cr_assert_str_eq(alias->value, "pwd");
    str = my_strdup("alias ls");
    cr_assert_eq(handle_alias_command(str, &alias, info), true);
    cr_assert_stdout_eq_str("pwd\n");
    str = my_strdup("alias ls ls '--color=auto'");
    cr_assert_not_null(str);
    cr_assert_eq(handle_alias_command(str, &alias, info), true);
    cr_assert_not_null(alias);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_str_eq(alias->name, "ls");
    cr_assert_str_eq(alias->value, "ls --color=auto");
    str = my_strdup("alias cd pwd");
    cr_assert_not_null(str);
    cr_assert_eq(handle_alias_command(str, &alias, info), true);
    cr_assert_not_null(alias);
    cr_assert_not_null(alias->name);
    cr_assert_not_null(alias->value);
    cr_assert_str_eq(alias->name, "cd");
    cr_assert_str_eq(alias->value, "pwd");
    cr_assert_str_eq(replace_alias_in_str("cd", alias), "pwd");
    cr_assert_str_eq(replace_alias_in_str("alias cd", alias), "alias cd");
}

Test (handle_where, handling_where_command, .init=redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->envp = NULL;
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * 2);
    info->envp[0] = my_strdup("PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin");
    info->envp[1] = NULL;
    info->l_envp = malloc(sizeof(path_t));
    info->l_envp->next = NULL;
    info->l_envp->value = my_strdup(info->envp[0]);
    info->return_status = 0;
    info->status = 0;
    char *str = my_strdup("ls");
    cr_assert_not_null(str);
    cr_assert_str_eq("ls", str);
    cr_assert_eq(handle_where(info, str), false);
}

Test (add_alias_from_rc, add_alias_from_rc, .init=redirect_all_std)
{
    envp_info_t *line = malloc(sizeof(envp_info_t));
    line->alias = NULL;
    line->l_envp = NULL;
    cr_assert_null(line->alias);
    add_alias_from_rc(line);
    cr_assert_null(line->alias);
}

Test (is_buildin, test_is_buildin, .init=redirect_all_std)
{
    cr_assert_eq(is_buildin("exit"), true);
    cr_assert_eq(is_buildin("env"), true);
    cr_assert_eq(is_buildin("setenv"), true);
    cr_assert_eq(is_buildin("cd"), true);
    cr_assert_eq(is_buildin("unsetenv"), true);
    cr_assert_eq(is_buildin("alias"), true);
    cr_assert_eq(is_buildin("which"), true);
    cr_assert_eq(is_buildin("nothing"), false);
    cr_assert_eq(is_buildin("history"), true);
    cr_assert_eq(is_buildin("where"), true);
}

Test (where, test_where, .init=redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->envp = NULL;
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * 2);
    info->envp[0] = my_strdup("PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin");
    info->envp[1] = NULL;
    info->l_envp = malloc(sizeof(path_t));
    info->l_envp->next = NULL;
    info->l_envp->value = my_strdup(info->envp[0]);
    info->return_status = 0;
    info->status = 0;
    char *str = my_strdup("ls");
    cr_assert_not_null(str);
    cr_assert_str_eq("ls", str);
    cr_assert_eq(handle_where(info, str), false);
}

Test (alloc_struct, test_alloc_struct, .init=redirect_all_std)
{
    char **envp = malloc(sizeof(char *) * 2);
    envp[0] = my_strdup("PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin");
    envp[1] = NULL;
    envp_info_t *info = alloc_struct(envp);
    info->my_cd->line_getted = my_strdup("nothing");
    cr_assert_not_null(info);
    cr_assert_not_null(info->envp);
    cr_assert_not_null(info->l_envp);
    cr_assert_eq(info->return_status, 0);
    free_struct(info);
}

Test(ignoreeof_funct, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *envp = malloc(sizeof(envp_info_t));
    info_t tmp;
    tmp.line_getted = my_strdup("set IGNOREOF=OFF");
    envp->envp = malloc(sizeof(char *) * 2);
    envp->envp[0] = my_strdup("PATH=/usr/local/bin:/usr/local/sbin:/usr/bin:/usr/sbin");
    envp->envp[1] = NULL;
    envp->local = NULL;
    local_functions(&tmp, envp);
    char *result = find_in_envp(envp->local, "IGNOREOF", 8);
    cr_assert_not_null(result);
    cr_assert_str_eq("IGNOREOF\tOFF", result);
    line->line_getted = my_strdup("set IGNOREOF=ON");
    local_functions(line, envp);
    cr_assert_eq(ignoreeof_function(envp), 0);
    result = find_in_envp(envp->local, "IGNOREOF", 8);
    cr_assert_not_null(result);
    cr_assert_str_eq("IGNOREOF\tON", result);
}

Test(handle_where, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("where ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_where(info, line->line_getted), 1);
}

Test(handle_which, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("which ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_which(line->line_getted, info), 1);
    line->line_getted = my_strdup("which echo");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_which(line->line_getted, info), 1);
    line->line_getted = my_strdup("which pwd");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_which(line->line_getted, info), 1);
}

Test(set_special_variables, test_all_function, .init=redirect_all_std)
{
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->envp = malloc(sizeof(char *) * 2);
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->l_envp = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(info);
    cr_assert_eq(set_special_variables(info), 0);
    free(info->envp[0]);
    free(info->envp);
    free(info);
    info = NULL;
    cr_assert_null(info);
    cr_assert_eq(set_special_variables(info), 1);
}

Test(there_alias_searched, test_all_function, .init=redirect_all_std)
{
    alias_t *alias = NULL;
    cr_assert_null(alias);
    cr_assert_eq(there_alias_searched(alias, "test"), false);
    add_alias(&alias, "test", "test");
    cr_assert_not_null(alias);
    cr_assert_eq(there_alias_searched(alias, "test"), true);
}

Test(exec_precmd, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("echo test");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(exec_precmd(line, info), 0);
}

Test(exec_cwdcmd, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("echo test");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(exec_cwdcmd(line, info), 0);
}

Test(first_pos_esperluette, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    line->line_getted = my_strdup("ls && ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(first_pos_esperluette(line, info), 0);
    line->line_getted = my_strdup("ls &&");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(first_pos_esperluette(line, info), 0);
    line->line_getted = my_strdup("ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(first_pos_esperluette(line, info), 0);
    line->line_getted = my_strdup("&& ls");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(first_pos_esperluette(line, info), 0);
    line->line_getted = my_strdup("&&&&&&&&&&");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(first_pos_esperluette(line, info), 1);
}

Test(my_revstr, test_all_function, .init=redirect_all_std)
{
    char *str = my_strdup("test");
    cr_assert_not_null(str);
    cr_assert_str_eq(my_revstr(str), "tset");
}

Test(my_strncpy, test_all_function, .init=redirect_all_std)
{
    char *str = my_strdup("test");
    char *dest = malloc(sizeof(char) * strlen(str));
    cr_assert_not_null(str);
    my_strncpy(dest, str, 2);
    cr_assert_str_eq(dest, "te");
}

Test(str_cat_at_pos, test_all_function, .init=redirect_all_std)
{
    char *str = my_strdup("test");
    char *dest = my_strdup("test");
    cr_assert_not_null(str);
    cr_assert_not_null(dest);
    cr_assert_str_eq(str_cat_at_pos(dest, str, 2), "tetestst");
}

Test(add_char_str, test_all_function, .init=redirect_all_std)
{
    char *str = my_strdup("test");
    cr_assert_not_null(str);
    cr_assert_str_eq(add_char_str(str, 't', 4), "testt");
}

Test(remove_char_str, test_all_function, .init=redirect_all_std)
{
    char *str = my_strdup("test");
    cr_assert_not_null(str);
    cr_assert_str_eq(remove_char_str(str, 2), "tet");
}

Test(handle_backtick, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("echo `ls`");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(handle_backtick(line->line_getted, info), 1);
}

Test(execute_globbings, test_all_function, .init=redirect_all_std)
{
    info_t *line = malloc(sizeof(info_t));
    envp_info_t *info = malloc(sizeof(envp_info_t));
    info->alias = NULL;
    info->envp = malloc(sizeof(char *) * (2));
    info->envp[0] = my_strdup("PATH=/bin");
    info->envp[1] = NULL;
    info->is_semicolon = false;
    info->l_envp = NULL;
    info->my_cd = NULL;
    info->old_pwd = NULL;
    info->return_status = 0;
    info->status = 0;
    info->tmp_line = NULL;
    cr_assert_not_null(line);
    cr_assert_not_null(info);
    line->line_getted = my_strdup("echo *");
    cr_assert_not_null(line->line_getted);
    cr_assert_eq(execute_globbings(line, info), 0);
}
