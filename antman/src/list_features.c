/*
** EPITECH PROJECT, 2022
** list_features
** File description:
** list_features
*/

#include "antman.h"

int get_length(tree_values_t *f_tree)
{
    int len = 0;
    tree_values_t *tmp = f_tree;

    while (tmp) {
        ++len;
        tmp = tmp->next;
    }
    return len;
}

char *get_code(tree_values_t *f_tree, char c)
{
    tree_values_t *tmp = f_tree;

    while (tmp) {
        if (tmp->c == c)
            return tmp->code;
        tmp = tmp->next;
    }
    return NULL;
}

int get_size(tree_values_t *tree, char *str)
{
    tree_values_t *temp_tree = tree;
    int length = 0;
    int nb_zero = 0;

    for (int i = 0; str[i] != '\0'; i++)
        length += my_strlen(get_code(temp_tree, str[i]));
    for (int i = length; (i % 8) != 0; i++)
        ++nb_zero;
    return nb_zero + length;
}
