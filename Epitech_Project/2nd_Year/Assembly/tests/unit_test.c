/*
** EPITECH PROJECT, 2025
** B-ASM-400-NAN-4-1-asmminilibc-robin.schuffenecker
** File description:
** test_strlen
*/

#include <criterion/criterion.h>
#include <dlfcn.h>
#include <string.h>
#include <stdio.h>

Test(strlen_in_asm, test_strlen)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    size_t (*my_strlen)(const char *str) = dlsym(fct, "strlen");
    char *str = strdup("Hello World!");
    cr_assert_eq(strlen(str), my_strlen(str));
    str = strdup("");
    cr_assert_eq(strlen(str), my_strlen(str));
    str = strdup("Hello World!\0");
    cr_assert_eq(strlen(str), my_strlen(str));
    str = strdup("fhhfgbsdhfbsdhbsdhbcsdicvsdiujbcsqdjbcsibvsdivbdsijbcsqkjbcjbsdivbkjqbcdsjicbskkdbv");
    cr_assert_eq(strlen(str), my_strlen(str));
    dlclose(fct);
}

Test(strchr_in_asm, test_strchr)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strchr)(const char *str, int c) = dlsym(fct, "strchr");
    char *str = strdup("Hello World!");
    cr_assert_eq(strchr(str, 'o'), my_strchr(str, 'o'));
    cr_assert_eq(strchr(str, 'H'), my_strchr(str, 'H'));
    cr_assert_eq(strchr(str, 'd'), my_strchr(str, 'd'));
    cr_assert_eq(strchr(str, 'z'), my_strchr(str, 'z'));
    cr_assert_eq(strchr(str, 'l'), my_strchr(str, 'l'));
    cr_assert_eq(strchr(str, ' '), my_strchr(str, ' '));
    cr_assert_eq(strchr(str, '!'), my_strchr(str, '!'));
    cr_assert_eq(strchr(str, '\0'), my_strchr(str, '\0'));
    dlclose(fct);
}

Test(strrchr_in_asm, test_strrchr)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    char *(*my_strrchr)(const char *str, int c) = dlsym(fct, "strrchr");
    char *str = strdup("Hello World!");
    cr_assert_eq(strrchr(str, 'o'), my_strrchr(str, 'o'));
    cr_assert_eq(strrchr(str, 'H'), my_strrchr(str, 'H'));
    cr_assert_eq(strrchr(str, 'd'), my_strrchr(str, 'd'));
    cr_assert_eq(strrchr(str, 'z'), my_strrchr(str, 'z'));
    cr_assert_eq(strrchr(str, 'l'), my_strrchr(str, 'l'));
    cr_assert_eq(strrchr(str, ' '), my_strrchr(str, ' '));
    cr_assert_eq(strrchr(str, '!'), my_strrchr(str, '!'));
    cr_assert_eq(strrchr(str, '\0'), my_strrchr(str, '\0'));
    dlclose(fct);
}

Test(memset_in_asm, test_memset)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    void *(*my_memset)(void *str, int c, size_t n) = dlsym(fct, "memset");
    char *str = strdup("Hello World!");
    cr_assert_eq(memset(str, 'a', 5), my_memset(str, 'a', 5));
    cr_assert_eq(memset(str, 'c', 1), my_memset(str, 'c', 1));
    cr_assert_eq(memset(str, 'd', 10), my_memset(str, 'd', 10));
    cr_assert_eq(memset(str, 'e', 20), my_memset(str, 'e', 20));
    cr_assert_eq(memset(str, 'f', 50), my_memset(str, 'f', 50));
    cr_assert_eq(memset(str, 'g', 100), my_memset(str, 'g', 100));
    dlclose(fct);
}

Test(memmove_in_asm, test_memmove)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    void *(*my_memmove)(void *dest, const void *src, size_t n) = dlsym(fct, "memmove");
    char *str = strdup("Hello World!");
    char *str2 = strdup("Hello World!");
    cr_assert_eq(memmove(str, str2, 5), my_memmove(str, str2, 5));
    cr_assert_eq(memmove(str, str2, 1), my_memmove(str, str2, 1));
    cr_assert_eq(memmove(str, str2, 10), my_memmove(str, str2, 10));
    cr_assert_eq(memmove(str, str2, 20), my_memmove(str, str2, 20));
    cr_assert_eq(memmove(str, str2, 50), my_memmove(str, str2, 50));
    cr_assert_eq(memmove(str, str2, 100), my_memmove(str, str2, 100));
    dlclose(fct);
}

Test(memcpy_in_asm, test_memcpy)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    void *(*my_memcpy)(void *dest, const void *src, size_t n) = dlsym(fct, "memcpy");
    char *str = strdup("Hello World!");
    char *str2 = strdup("ffffffffff");
    cr_assert_eq(memcpy(str, str2, 5), my_memcpy(str, str2, 5));
    cr_assert_eq(memcpy(str, str2, 1), my_memcpy(str, str2, 1));
    cr_assert_eq(memcpy(str, str2, 10), my_memcpy(str, str2, 10));
    cr_assert_eq(memcpy(str, str2, 20), my_memcpy(str, str2, 20));
    cr_assert_eq(memcpy(str, str2, 50), my_memcpy(str, str2, 50));
    cr_assert_eq(memcpy(str, str2, 100), my_memcpy(str, str2, 100));
    dlclose(fct);
}


Test(strcmp_in_asm, test_strcmp)
{
    void *fct = dlopen("./libasm.so", RTLD_LAZY);
    int (*my_strcmp)(const char *s1, const char *s2) = dlsym(fct, "strcmp");
    char *str = strdup("Hello World!");
    char *str2 = strdup("Hello World!");
    cr_assert_eq(strcmp(str, str2), my_strcmp(str, str2));
    str2 = strdup("Hello World!!");
    cr_assert_neq(strcmp(str, str2), my_strcmp(str, str2));
    str2 = strdup("9");
    cr_assert_neq(strcmp(str, str2), my_strcmp(str, str2));
    str2 = strdup("4  ");
    cr_assert_neq(strcmp(str, str2), my_strcmp(str, str2));
    str2 = strdup("Hello  ");
    cr_assert_neq(strcmp(str, str2), my_strcmp(str, str2));
    dlclose(fct);
}
