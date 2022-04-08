/*
** EPITECH PROJECT, 2022
** build_tree
** File description:
** build_tree
*/

#include "antman.h"

void display_tree(binary_tree_t *root, int i)
{
    binary_tree_t *left = NULL;
    binary_tree_t *right = NULL;

    my_printf("|%c -> %d\n", root->c, root->frequency);
    ++i;
    if (root->left) {
        left = root->left;
        for (int j = 0; j < i; j++)
            my_printf("-");
        display_tree(left, i);
    }
    if (root->right) {
        right = root->right;
        for (int j = 0; j < i; j++)
            my_printf("-");
        display_tree(right, i);
    }
}

static binary_tree_t *add_leaf(char c, int frequency, binary_tree_t *left,
binary_tree_t *right)
{
    binary_tree_t *node = malloc(sizeof(binary_tree_t));

    if (node == NULL)
        return NULL;
    node->c = c;
    node->frequency = frequency;
    node->left = left;
    node->right = right;
    return node;
}

static binary_tree_t *build_first_tree(tree_values_t **tree, int cur)
{
    binary_tree_t *childleft = NULL;
    binary_tree_t *childright = NULL;
    binary_tree_t *root = NULL;

    childleft = add_leaf((*tree)->c, (*tree)->frequency, NULL, NULL);
    childright = add_leaf((*tree)->next->c, (*tree)->next->frequency, NULL, NULL);
    root = add_leaf(0, cur, childleft, childright);
    (*tree) = (*tree)->next->next;
    return root;
}

static binary_tree_t *build_temp_tree(tree_values_t **tree, int cur, binary_tree_t *temp)
{
    binary_tree_t *temp_childleft = NULL;
    binary_tree_t *temp_childright = NULL;
    binary_tree_t *temp_root = NULL;
    binary_tree_t *root = NULL;
    int temp_current = 0;

    temp_current = (*tree)->frequency + (*tree)->next->frequency;
    temp_childleft = add_leaf((*tree)->c, (*tree)->frequency, NULL, NULL);
    temp_childright = add_leaf((*tree)->next->c, (*tree)->next->frequency, NULL, NULL);
    temp_root = add_leaf(0, temp_current, temp_childleft, temp_childright);
    cur += temp_current;
    root = add_leaf(0, cur, temp, temp_root);
    (*tree) = (*tree)->next->next;
    return root;
}

binary_tree_t *build_tree(tree_values_t *tree, int cur, binary_tree_t *temp)
{
    binary_tree_t *childleft = NULL;
    binary_tree_t *root = NULL;

    if (tree == NULL)
        return temp;
    if (!cur) {
        if (!tree->next)
            return add_leaf(tree->c, tree->frequency, NULL, NULL);
        cur = tree->frequency + tree->next->frequency;
        root = build_first_tree(&tree, cur);
    } else if (!tree->next || (tree->next && cur < tree->next->frequency)) {
        cur += tree->frequency;
        childleft = add_leaf(tree->c, tree->frequency, NULL, NULL);
        root = add_leaf(0, cur, childleft, temp);
        tree = tree->next;
    } else {
        cur += tree->frequency + tree->next->frequency;
        root = build_temp_tree(&tree, cur, temp);
    }
    return build_tree(tree, cur, root);
}
