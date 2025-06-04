/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-miniprintf-theophile.riffe
** File description:
** utilities
*/

#include "my_printf.h"

void
print_char(int fd, va_list args, buffer_t *buff)
{
    printf_putchar(fd, va_arg(args, int), buff);
}

void
print_string(int fd, va_list args, buffer_t *buff)
{
    printf_putstr(fd, va_arg(args, char *), buff);
}

void
print_int(int fd, va_list args, buffer_t *buff)
{
    printf_putnbr(fd, va_arg(args, int), buff);
}

void
print_mudulo(int fd, __attribute__((unused))va_list args, buffer_t *buff)
{
    printf_putchar(fd, '%', buff);
}
