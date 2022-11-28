/*
** EPITECH PROJECT, 2022
** print_readme
** File description:
** flags
*/

#ifndef FLAGS_H
#define FLAGS_H

#include "print_readme.h"

int write_line(char const *buffer, int i)
{
    for (i; buffer[i] != '\n'; i++) {
        write(1, &buffer[i], 1);
    }
    return i;
}

int put_hastag(char const *buffer, int count)
{
    int tmp = count;
    my_putstr("\033[37;1m");
    for (count; buffer[count] != '\n'; count++) {
        if (buffer[count] == '#') {
            count++;
            continue;
        }
        write(1, &buffer[count], 1);
    }
    my_putstr("\033[0m");
    return count - tmp - 1;
}

int put_dot(char const *buffer, int count)
{
    write(1, "  • ", 5);
    write_line(buffer, count + 1);
    return 5;
}

int put_pat(char const *buffer, int count)
{
    write(1, "\033[40m", 5);
    int tmp = count;
    count += 1;
    for (count; buffer[count] != '`'; count++) {
        write(1, &buffer[count], 1);
    }
    write(1, "\033[0m", 4);
    return count - tmp;
}

struct list_flags_t {
    char *flags;
    int (*function)(char const *buffer, int count);
};

typedef struct list_flags_t flags;

/// @brief List of all flags
/// @param flags: flags to compare
/// @param function: function to call

const flags FLAGS[] = {
    {flags : "#", function : &put_hastag},
    {flags : "-", function : &put_dot},
    {flags : "`", function : &put_pat},
    {flags : NULL, function : NULL}
};

#endif // FLAGS_H
