/*
** EPITECH PROJECT, 2024
** my_lib
** File description:
** my_put_nbr
*/

#include "my_printf.h"

int
printf_putnbr(int fd, int n, buffer_t *buff)
{
    if (n == INT_MIN) {
        printf_putchar(fd, '-', buff);
        printf_putchar(fd, '2', buff);
        n = 147483648;
    } else if (n < 0) {
        printf_putchar(fd, '-', buff);
        n = -n;
    }
    if (n >= 10)
        printf_putnbr(fd, n / 10, buff);
    printf_putchar(fd, n % 10 + '0', buff);
    return 0;
}
