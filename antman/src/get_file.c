/*
** EPITECH PROJECT, 2022
** get_file
** File description:
** get_file
*/

#include "antman.h"

char *get_file(char *filename)
{
    struct stat st;
    int fd = open(filename, O_RDONLY);
    char *buf;

    if (fd < 0)
        return NULL;
    stat(filename, &st);
    buf = malloc(sizeof(char) * st.st_size + 1);
    if (buf == NULL)
        return NULL;
    read(fd, buf, st.st_size);
    buf[st.st_size] = '\0';
    return buf;
}
