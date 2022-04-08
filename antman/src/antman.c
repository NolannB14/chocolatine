/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#include "antman.h"
#include <string.h>

static int add_code_for_char(tree_values_t **f_tree, binary_tree_t *b_tree)
{
    tree_values_t *temp_tree = *f_tree;
    binary_tree_t *temp_b_tree = b_tree;
    char *code = NULL;

    while (temp_tree) {
        code = malloc(get_length(*f_tree) + 1);
        if (!code)
            return 84;
        code[0] = '\0';
        temp_tree->code =
            my_strdup(get_char_code(temp_b_tree, temp_tree->c, code, 0));
        my_printf("%c%s\a", temp_tree->c, temp_tree->code);
        free(code);
        temp_tree = temp_tree->next;
    }
    return 0;
}

static tree_values_t *build_compression(char *str)
{
    tree_values_t *f_tree = NULL;
    tree_values_t *tmp_tree = NULL;
    binary_tree_t *b_tree = NULL;

    f_tree = get_occ_from_str(str);
    if (!f_tree)
        return NULL;
    f_tree = mergesort(f_tree);
    tmp_tree = f_tree;
    b_tree = build_tree(tmp_tree, 0, NULL);
    if (!b_tree || add_code_for_char(&f_tree, b_tree) == 84)
        return NULL;
    return f_tree;
}

static char *get_binary_code(char *str, tree_values_t *f_tree)
{
    char *binary_code = malloc(get_size(f_tree, str));

    if (!binary_code)
        return NULL;
    binary_code[0] = '\0';
    for (int i = 0; str[i] != '\0'; i++)
        my_strcat(binary_code, get_code(f_tree, str[i]));
    return binary_code;
}

int antman(int ac, char **av)
{
    int nb_zero = 0;
    char *str = NULL;
    char *binary_code = NULL;
    tree_values_t *f_tree = malloc(sizeof(tree_values_t));

    if (check_arguments(ac, av) == 84)
        return 84;
    str = get_file(av[1]);
    f_tree = build_compression(str);
    binary_code = my_strdup(get_binary_code(str, f_tree));
    for (int i = my_strlen(binary_code); (i % 8) != 0; i++) {
        my_strcat(binary_code, "0");
        ++nb_zero;
    }
    for (int i = 0; i < my_strlen(binary_code); i += 8)
        char_from_bin(my_strndup(binary_code + i, 8));
    my_printf("%c", nb_zero + '0');
    return 0;
}
