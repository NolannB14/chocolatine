/*
** EPITECH PROJECT, 2022
** giantman
** File description:
** giantman
*/

#include "antman.h"

static int get_begin_compressed(char *all_file, int total_len)
{
    int begin_compressed = 0;

    if (!all_file)
        return -1;
    for (int j = 0; j < total_len;
        j += next_step(my_strdup(all_file + j), total_len))
        begin_compressed = j;
    return begin_compressed;
}

static char *get_compressed_data(char *all_file, tree_values_t **tree, \
int total_len, int begin_compressed)
{
    char *encoded = malloc(total_len - begin_compressed);

    if (!all_file || begin_compressed == -1)
        return NULL;
    get_dictionnary(tree, all_file, total_len);
    encoded[0] = '\0';
    for (int j = 0; j < total_len - begin_compressed - 1; j++)
        encoded[j] = all_file[begin_compressed + j];
    encoded[total_len - begin_compressed - 1] = '\0';
    return encoded;
}

static char *get_entire_binary(char *encoded, int total_len, \
int begin_compressed, int *length)
{
    char *entire_binary = malloc((total_len - begin_compressed) * 8);

    if (!entire_binary || !encoded || begin_compressed == -1)
        return NULL;
    entire_binary[0] = '\0';
    for (int j = 0; j < total_len - begin_compressed - 1; j++) {
        my_strcat(entire_binary, get_encoded(encoded[j]));
        *length += 8;
    }
    return entire_binary;
}

int giantman(int ac, char **av)
{
    char *all_file = NULL;
    tree_values_t *tree = NULL;
    int begin_compressed = 0;
    char *entire_binary = NULL;
    char *encoded = NULL;
    int length = 0;
    int i = 0;
    struct stat st;

    if (check_arguments(ac, av) == 84)
        return 84;
    stat(av[1], &st);
    all_file = get_file(av[1]);
    begin_compressed = get_begin_compressed(all_file, st.st_size);
    encoded = get_compressed_data(all_file, &tree,
        st.st_size, begin_compressed);
    entire_binary = get_entire_binary(encoded, st.st_size,
        begin_compressed, &length);
    if (!all_file || !begin_compressed || !encoded || !entire_binary)
        return 84;
    i = display_uncompressed(tree, entire_binary, length);
    return print_last_char(all_file[st.st_size - 1] - '0',
        entire_binary + i, tree);
}
