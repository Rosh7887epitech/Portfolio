/*
** EPITECH PROJECT, 2024
** secured
** File description:
** unit_test
*/
#include <criterion/criterion.h>
#include "../include/my.h"
#include "../include/hashtable.h"

Test(my_put_nbr, null_number)
{
    int i = 0;
    char *result = my_put_nbr(i);
    cr_assert_str_eq(result, "0");
}

Test(my_put_nbr, positive_number)
{
    int i = 55489;
    char *result = my_put_nbr(i);
    cr_assert_str_eq(result, "55489");
}

Test(my_put_nbr, negative_number)
{
    int i = -8214;
    char *result = my_put_nbr(i);
    cr_assert_str_eq(result, "-8214");
}

Test(my_getnbr, null)
{
    char *i = "";
    int result = my_getnbr(i);
    cr_assert_eq(result, NULL);
}

Test(my_getnbr, positive_number)
{
    char *i = "ici54545re";
    int result = my_getnbr(i);
    cr_assert_eq(result, 54545);
}

Test(my_getnbr, negative_number)
{
    char *i = "fhudsjfh-65456fdgdf";
    int result = my_getnbr(i);
    cr_assert_eq(result, -65456);
}

Test(my_strlen, empty_string)
{
    char *str = "";
    int result = my_strlen(str);
    cr_assert_eq(result, 0);
}

Test(my_strlen, valid_string)
{
    char *str = "Hello, World!";
    int result = my_strlen(str);
    cr_assert_eq(result, 13);
}

Test(my_strdup, empty_string)
{
    char *src = "";
    char *result = my_strdup(src);
    cr_assert_str_eq(result, src);
}

Test(my_strdup, valid_string)
{
    char *src = "Hello, World!";
    char *result = my_strdup(src);
    cr_assert_str_eq(result, src);
}

Test(new_hashtable, valid_hashtable)
{
    int len = 10;
    hashtable_t *ht = new_hashtable(&hash, len);

    cr_assert_not_null(ht);
    cr_assert_eq(ht->size, len);
    for (int i = 0; i < len; i++) {
        cr_assert_null(ht->st_tab[i]);
    }
}

Test(new_hashtable, invalid_len)
{
    int len = -1;
    hashtable_t *ht = new_hashtable(&hash, len);
    cr_assert_null(ht);
}

Test(ht_dump, print_hashtable)
{
    int len = 2;
    hashtable_t *ht = new_hashtable(&hash, len);

    cr_assert_not_null(ht);
    ht_insert(ht, "key", "value");
    ht_dump(ht);
    cr_assert_not_null(ht);
}

Test(delete_hashtable, test_null_hashtable)
{
    hashtable_t *ht = NULL;
    delete_hashtable(ht);
    cr_assert_null(ht);
}

Test(ht_insert, test_insert_valid)
{
    int len = 5;
    hashtable_t *ht = new_hashtable(&hash, len);
    char *key = "non_existant_key";
    char *value = "value";

    int result = ht_insert(ht, key, value);
    cr_assert_eq(result, 0);
    int position = hash(key) % len;
    cr_assert_not_null(ht->st_tab[position]);
    cr_assert_str_eq(ht->st_tab[position]->key, my_itoa(hash(key)));
    cr_assert_str_eq(ht->st_tab[position]->value, value,);
    delete_hashtable(ht);
}

Test(ht_insert, test_insert_collision)
{
    int len = 5;
    hashtable_t *ht = new_hashtable(hash, len);
    secured_t *node;

    char *key = "test";
    char *value1 = "value1";
    char *value2 = "value2";

    ht_insert(ht, key, value1);

    int pos = hash(key) % len;

    cr_assert_not_null(ht->st_tab[pos]);
    cr_assert_str_eq(ht->st_tab[pos]->key, my_itoa(hash(key)));
    cr_assert_str_eq(ht->st_tab[pos]->value, value1);
    ht_insert(ht, key, value2);
    cr_assert_not_null(ht->st_tab[pos]);
    cr_assert_str_eq(ht->st_tab[pos]->key, my_itoa(hash(key)));
    cr_assert_str_eq(ht->st_tab[pos]->value, value2);
}

Test(ht_delete, delete_existing_key)
{
    int len = 5;
    int pos = 0;
    hashtable_t *ht = new_hashtable(&hash, len);

    char *key = "key";
    char *value = "value";
    ht_insert(ht, key, value);
    pos = hash(key) % len;
    ht_delete(ht, key);
    cr_assert_null(ht->st_tab[pos]);
    delete_hashtable(ht);
}

Test(ht_delete, delete_nonexistent_key)
{
    int len = 12;
    int pos = 0;
    hashtable_t *ht = new_hashtable(&hash, len);
    char *key = "key";
    char *value = "value";

    ht_insert(ht, key, value);
    pos = hash(key) % len;
    ht_delete(ht, "invalid_key");
    cr_assert_not_null(ht->st_tab[pos]);
    delete_hashtable(ht);
}

Test(null_args_all_functions, null_args)
{
    hashtable_t *ht = new_hashtable(&hash, 0);
    int result = 0;

    result = ht_insert(ht, NULL, "value");
    cr_assert_eq(result, 84);
    ht_dump(ht);
    result = 0;
    result = ht_delete(ht, "key");
    cr_assert_eq(result, 84);
    cr_assert_null(ht_search(ht, "key"));
    result = 0;
    result = hash(NULL);
    cr_assert_eq(result, 1);
    delete_hashtable(ht);
}

Test(search_function, basic_search)
{
    hashtable_t *ht = new_hashtable(&hash, 5);
    char *value = malloc(sizeof(char) * 6);

    ht_insert(ht, "key", "value");
    value = ht_search(ht, "key");
    cr_assert_str_eq(value, "value");

    delete_hashtable(ht);
}