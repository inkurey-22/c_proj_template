/*
** EPITECH PROJECT, 2024
** B-CPE-100-LIL-1-1-cpoolday07-theophile.riffe
** File description:
** putchar
*/

#include "my_printf.h"

void printf_putchar(int fd, char c, buffer_t *buff)
{
    if (buff->pos >= 1024) {
        if (fd == -1)
            return;
        write(fd, buff->buffer, buff->pos);
        buff->pos = 0;
    }
    buff->buffer[buff->pos] = c;
    buff->pos++;
    buff->len++;
}
