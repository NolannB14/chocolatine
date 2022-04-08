/*
** EPITECH PROJECT, 2022
** display_results
** File description:
** display_results
*/

#include "antman.h"

static int is_right_code(char *temp, int *k, tree_values_t *tmp)
{
    if (!my_strncmp(temp + *k, tmp->code, my_strlen(tmp->code))) {
        my_printf("%c", tmp->c);
        *k += my_strlen(tmp->code);
        return 1;
    }
    return 0;
}

int print_last_char(int nb_zero, char *last_block, tree_values_t *tree)
{
    char *temp = my_strndup(last_block, my_strlen(last_block) - nb_zero);
    tree_values_t *tmp = tree;
    int k = 0;

    while (k < my_strlen(temp)) {
        while (tmp && !is_right_code(temp, &k, tmp))
            tmp = tmp->next;
        tmp = tree;
    }
    return 0;
}

int display_uncompressed(tree_values_t *tree, char *entire_binary, int length)
{
    tree_values_t *tmp = tree;
    int i = 0;

    while (i < length - 8) {
        while (tmp && !is_right_code(entire_binary, &i, tmp))
            tmp = tmp->next;
        tmp = tree;
    }
    return i;
}
