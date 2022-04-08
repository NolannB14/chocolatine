/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** my_strlen
*/

#include <stdlib.h>

int my_strlen(char const *str)
{
    int counter = 0;

    if (str == NULL)
        return -1;
    while (str[counter] != '\0') {
        counter = counter + 1;
    }
    return (counter);
}



