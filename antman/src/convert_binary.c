/*
** EPITECH PROJECT, 2022
** convert_binary
** File description:
** convert_binary
*/

#include "antman.h"

void char_from_bin(char *bin_str)
{
    unsigned int i = 0b0;
    unsigned int current = 0;

    for (int k = 0; k < my_strlen(bin_str) - 1; k++) {
        current = bin_str[k] - '0';
        i |= current;
        i <<= 1;
    }
    current = bin_str[my_strlen(bin_str) - 1] - '0';
    i |= current;
    my_printf("%c", i);
    free(bin_str);
}
