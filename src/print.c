/*
** EPITECH PROJECT, 2022
** print_readme
** File description:
** print
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include "print_readme.h"
#include "flags.h"

int get_caract(char buffer, int nb)
{
    for (int i = 0; FLAGS[i].flags != NULL; i++) {
        if (buffer == FLAGS[i].flags[0]) {
            return (nb == 1) ? i : 1;
        }
    }
    return -1;
}

int print_readme(char *buffer)
{
    for (int i = 0; buffer[i]; i++) {
        if (get_caract(buffer[i], 0) != -1) {
            i += FLAGS[get_caract(buffer[i], 1)].function(buffer, i);
        } else {
            write(1, &buffer[i], 1);
        }
    }
    write(1, "\n", 1);
    return 0;
}

int main(void)
{
    int fd = open("README.md", O_RDONLY);
    if (fd == -1) {
        return 84;
    }
    struct stat st;
    stat("README.md", &st);
    char *buffer = malloc(sizeof(char) * st.st_size + 1);
    read(fd, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    print_readme(buffer);
    return 0;
}