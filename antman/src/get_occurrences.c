/*
** EPITECH PROJECT, 2022
** get_occurrences
** File description:
** get_occurrences
*/

#include "antman.h"

static int add_occ_in_list(tree_values_t **head, char c, int frequency)
{
    tree_values_t *node = malloc(sizeof(tree_values_t));
    tree_values_t *lnode;

    if (node == NULL)
        return 84;
    node->c = c;
    node->frequency = frequency;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        lnode = *head;
        if (lnode->c == c)
            return 0;
        while (lnode->next != NULL)
            lnode = lnode->next;
        lnode->next = node;
    }
    return 0;
}

static int already_in(tree_values_t **head, char c)
{
    tree_values_t *tmp = *head;

    while (tmp) {
        if (tmp->c == c)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}

static int get_occurences(tree_values_t **tree, char *str, int i)
{
    int freq = 0;

    for (int j = 0; j < my_strlen(str); j++) {
        if (str[j] == str[i])
            ++freq;
    }
    return add_occ_in_list(tree, str[i], freq);
}

tree_values_t *get_occ_from_str(char *str)
{
    tree_values_t *tree = NULL;

    for (int i = 0; i < my_strlen(str); i++) {
        if (!already_in(&tree, str[i]))
            get_occurences(&tree, str, i);
    }
    return tree;
}
