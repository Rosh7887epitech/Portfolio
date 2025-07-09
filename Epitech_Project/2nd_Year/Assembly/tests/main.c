/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-robin.schuffenecker
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>

void test_strstr()
{
    void *fct = dlopen("../libasm.so", RTLD_LAZY);
    void *(*my_strstr)(char *str, char *str2) = dlsym(fct, "strstr");
    char *str = strdup("Hello World!");
    char *str2 = strdup("World");
    char *res = my_strstr(str, str2);
    char *res2 = strstr(str, str2);
    printf("my_strstr: %s -- strstr %s strcmp :%d\n", res, res2, strcmp(res, res2));
    str2 = strdup("Hello");
    res = my_strstr(str, str2);
    res2 = strstr(str, str2);
    printf("my_strstr: %s -- strstr %s strcmp :%d\n", res, res2, strcmp(res, res2));
    str2 = strdup("");
    res = my_strstr(str, str2);
    res2 = strstr(str, str2);
    printf("my_strstr: %s -- strstr %s strcmp :%d\n", res, res2, strcmp(res, res2));
    str2 = strdup(" ");
    res = my_strstr(str, str2);
    res2 = strstr(str, str2);
    printf("my_strstr: %s -- strstr %s strcmp :%d\n", res, res2, strcmp(res, res2));
}

void test_memmove(void)
{
    void *fct = dlopen("../libasm.so", RTLD_LAZY);
    void *(*my_memmove)(void *dest, void *src, size_t n) = dlsym(fct, "memmove");

    char *str = strdup("Hello World!");
    char *str2 = strdup("Hello World!");
    my_memmove(str + 6, str, 5);
    memmove(str2 + 6, str2, 5);
    printf("strcmp: %d\n", strcmp(str, str2));
    str = strdup("Hello World!");
    str2 = strdup("Hello World!");
    my_memmove(str + 6, str, 0);
    memmove(str2 + 6, str2, 0);
    printf("strcmp: %d\n", strcmp(str, str2));
    str = strdup("Hello World!");
    str2 = strdup("Hello World!");
    my_memmove(str + 6, str, 6);
    memmove(str2 + 6, str2, 6);
    printf("strcmp: %d\n", strcmp(str, str2));
    str = strdup("Hello World!");
    str2 = strdup("Hello World!");
    my_memmove(str + 6, str, 7);
    memmove(str2 + 6, str2, 7);
    printf("strcmp: %d\n", strcmp(str, str2));
    str = strdup("Hello World!");
    str2 = strdup("Hello World!");
    my_memmove(str, str, strlen(str));
    memmove(str2, str2, strlen(str2));
    printf("strcmp: %d\n", strcmp(str, str2));
    str = strdup("Hello World!");
    str2 = strdup("Hello World!");
    my_memmove(str, str + 6, 5);
    memmove(str2, str2 + 6, 5);
    printf("strcmp: %d\n", strcmp(str, str2));
    char *empty = strdup("");
    char *empty2 = strdup("");
    my_memmove(empty, empty, 0);
    memmove(empty2, empty2, 0);
    printf("strcmp: %d\n", strcmp(empty, empty2));
    my_memmove(NULL, NULL, 0);
    memmove(NULL, NULL, 0);
    printf("strcmp: %d\n", strcmp(empty, empty2));
    dlclose(fct);
}


int main (void)
{
    test_strstr();
    test_memmove();
}
