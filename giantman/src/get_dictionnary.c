/*
** EPITECH PROJECT, 2022
** get_dictionnary
** File description:
** get_dictionnary
*/

#include "antman.h"

static int add_code_in_list(tree_values_t **head, char c, char *code)
{
    tree_values_t *node = malloc(sizeof(tree_values_t));
    tree_values_t *lnode;

    if (node == NULL)
        return 84;
    node->c = c;
    node->code = my_strdup(code);
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

int next_step(char *str, int length)
{
    int len = 0;

    for (int i = 0; i < length && str[i] != '\a'; i++)
        ++len;
    return len + 1;
}

int get_dictionnary(tree_values_t **tree, char *str, int length)
{
    int n_dup = 0;

    for (int i = 0; i < length; i += next_step(str + i, length)) {
        n_dup = (i + next_step(str + i, length) - 1) - (i + 1);
        if (i + next_step(str + i, length) <= length) {
            add_code_in_list(tree, str[i], my_strndup(str + i + 1, n_dup));
        }
    }
    return 0;
}
