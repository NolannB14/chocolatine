/*
** EPITECH PROJECT, 2022
** sort_list
** File description:
** sort_list
*/

#include "antman.h"

static tree_values_t *get_middle(tree_values_t *head)
{
    tree_values_t *slow = head;
    tree_values_t *fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

static tree_values_t *merge(tree_values_t *left, tree_values_t *right)
{
    tree_values_t *result = NULL;

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    if (left->frequency <= right->frequency) {
        result = left;
        result->next = merge(left->next, right);
    } else {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

tree_values_t *mergesort(tree_values_t *head)
{
    tree_values_t *left = NULL;
    tree_values_t *middle = NULL;
    tree_values_t *right = NULL;

    if (!head || !head->next)
        return head;
    middle = get_middle(head);
    left = head;
    right = middle->next;
    middle->next = NULL;
    left = mergesort(left);
    right = mergesort(right);
    return merge(left, right);
}
