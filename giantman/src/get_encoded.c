/*
** EPITECH PROJECT, 2022
** get_encoded
** File description:
** get_encoded
*/

#include "antman.h"

char *get_encoded(char c)
{
    char *encoded = malloc(8);
    unsigned int mask = 0b10000000;
    int temp = 0;

    if (!encoded)
        return NULL;
    for (int i = 0; i < 8; i++) {
        temp = c & mask;
        temp >>= 7;
        encoded[i] = temp + '0';
        c <<= 1;
    }
    return encoded;
}
