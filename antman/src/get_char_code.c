/*
** EPITECH PROJECT, 2022
** get_char_code
** File description:
** get_char_code
*/

#include "antman.h"

static char *cat_bin(binary_tree_t *tree, char c, char *code, char branch)
{
    char *temp_code = my_strdup(code);
    char *left = NULL;
    char *right = NULL;

    left = get_char_code(tree->left, c, my_strcat(code, "0"), 'l');
    if (!my_strcmp(left, temp_code)) {
        right = get_char_code(tree->right, c, my_strcat(code, "1"), 'r');
        if (!my_strcmp(right, temp_code)) {
            code[my_strlen(code) - 1] = '\0';
            return code;
        } else {
            return code;
        }
    } else {
        return left;
    }
}

char *get_char_code(binary_tree_t *tree, char c, char *code, char branch)
{
    if (tree->c == c) {
        return code;
    } else if (!tree->left && !tree->right) {
        code[my_strlen(code) - 1] = '\0';
        return code;
    } else {
        return cat_bin(tree, c, code, branch);
    }
}
