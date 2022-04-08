/*
** EPITECH PROJECT, 2022
** check_errors
** File description:
** check_errors
*/

#include "antman.h"

static int open_file(char *filename)
{
    struct stat st;
    int fd = open(filename, O_RDONLY);
    char *buf;

    if (fd < 0)
        return 84;
    stat(filename, &st);
    buf = malloc(sizeof(char) * st.st_size);
    if (buf == NULL)
        return 84;
    read(fd, buf, st.st_size);
    if (my_strlen(buf) < 1 || !S_ISREG(st.st_mode))
        return 84;
    return 0;
}

static int antman_help(void)
{
    int fd = open("../../../ressources/help.txt", O_RDONLY);
    char *buffer = NULL;
    struct stat st;

    if (fd < 0)
        return 84;
    stat("../../../ressources/help.txt", &st);
    buffer = malloc(sizeof(char) * st.st_size);
    if (buffer == NULL)
        return 84;
    read(fd, buffer, st.st_size);
    my_printf("%s\n", buffer);
    return 0;
}

int check_arguments(int ac, char **av)
{
    if (ac == 2 && !my_strcmp(av[1], "-h")) {
        return antman_help();
    } else if (ac != 3 || open_file(av[1]) == 84) {
        my_printf("antman: Invalid use. Try antman -h.\n");
        return 84;
    }
    return 0;
}
