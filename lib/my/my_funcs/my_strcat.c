/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** my_strcat
*/

#include "lib.h"

char *my_strcat(char *dest, char const *str)
{
    int end_line = my_strlen(dest);
    int i = 0;

    if (dest == NULL || str == NULL)
        return NULL;
    for (; str[i] != '\0'; i++)
        dest[end_line + i] = str[i];
    dest[end_line + i] = '\0';
    return dest;
}



