/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#ifndef ANTMAN_H_
    #define ANTMAN_H_

    #include "lib.h"

typedef struct tree_values_s {
    char c;
    int frequency;
    char *code;
    struct tree_values_s *next;
} tree_values_t;

typedef struct binary_tree_s {
    char c;
    int frequency;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

    /* Error handling */

    int check_arguments(int ac, char **av);

    /* List features */

    int get_length(tree_values_t *f_tree);
    char *get_code(tree_values_t *f_tree, char c);
    int get_size(tree_values_t *tree, char *str);

    /* Dev features */

    void display_tree(binary_tree_t *root, int i);

    /* Build dictionnary and code to compressed data */

    tree_values_t *get_occ_from_str(char *str);
    tree_values_t *mergesort(tree_values_t *head);
    binary_tree_t *build_tree(tree_values_t *tree, int cur,
    binary_tree_t *temp);
    char *get_char_code(binary_tree_t *tree, char c, char *code, char branch);
    void char_from_bin(char *bin_str);

    /* Display uncompressed data */

    int print_last_char(int nb_zero, char *last_block, tree_values_t *tree);
    int display_uncompressed(tree_values_t *tree, char *entire_binary, \
    int length);

    /* Retreive compressed data */

    char *get_file(char *filename);
    char *get_encoded(char c);
    int get_dictionnary(tree_values_t **tree, char *str, int length);
    int next_step(char *str, int length);

    /* Binary main_function */

    int antman(int ac, char **av);
    int giantman(int ac, char **av);

#endif /* !MINISHELL1_H_ */
