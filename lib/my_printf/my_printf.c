/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-miniprintf-theophile.riffe
** File description:
** mini_printf
*/

#include "my_strings.h"

#include "my_printf.h"

static const printf_t SPECIFIERS[] = {
    {'c', print_char},
    {'s', print_string},
    {'d', print_int},
    {'i', print_int},
    {'%', print_mudulo},
    {0, NULL}
};

static void
manage_specifiers(int fd, char c, va_list args, buffer_t *buff)
{
    for (int i = 0; SPECIFIERS[i].c != '\0'; i++) {
        if (c == SPECIFIERS[i].c) {
            SPECIFIERS[i].func(fd, args, buff);
            return;
        }
    }
    printf_putchar(fd, '%', buff);
    printf_putchar(fd, c, buff);
}

void
put_buffer(int fd, buffer_t *buff)
{
    if (buff->pos > 0) {
        write(fd, buff->buffer, buff->pos);
        buff->pos = 0;
    }
}

int
my_printf(char const *format, ...)
{
    va_list args;
    buffer_t buff = {{0}, 0, 0};

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            manage_specifiers(STDOUT_FILENO, format[i], args, &buff);
        } else {
            printf_putchar(STDOUT_FILENO, format[i], &buff);
        }
    }
    va_end(args);
    put_buffer(STDOUT_FILENO, &buff);
    return buff.len;
}

int
my_dprintf(int fd, const char *format, ...)
{
    va_list args;
    buffer_t buff = {{0}, 0, 0};

    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            manage_specifiers(fd, format[i], args, &buff);
        } else {
            printf_putchar(fd, format[i], &buff);
        }
    }
    va_end(args);
    put_buffer(fd, &buff);
    return buff.len;
}

int
my_asprintf(char **str, const char *format, ...)
{
    va_list args;
    buffer_t buff = {{0}, 0, 0};

    if (str == NULL)
        return -1;
    va_start(args, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            manage_specifiers(-1, format[i], args, &buff);
        } else {
            printf_putchar(-1, format[i], &buff);
        }
    }
    va_end(args);
    *str = my_strndup(buff.buffer, buff.pos);
    return buff.len;
}
