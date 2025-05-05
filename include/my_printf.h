/*
** EPITECH PROJECT, 2024
** B-CPE-101-LIL-1-1-miniprintf-theophile.riffe
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #define BUFF_SIZE 4096

    #include <unistd.h>
    #include <stdarg.h>
    #include <limits.h>

typedef struct buffer_s {
    char buffer[BUFF_SIZE];
    int pos;
    int len;
} buffer_t;

typedef struct printf_s {
    char c;
    void (*func)(int, va_list, buffer_t *);
} printf_t;

void printf_putchar(int, char, buffer_t *);
void printf_putstr(int, char const *, buffer_t *);
int printf_putnbr(int, int, buffer_t *);

int my_printf(char const *, ...);
int my_dprintf(int, char const *, ...);
int my_asprintf(char **, const char *, ...);

void print_char(int, va_list, buffer_t *);
void print_string(int, va_list, buffer_t *);
void print_int(int, va_list, buffer_t *);
void print_mudulo(int, va_list, buffer_t *);

#endif /* !MY_H_ */
