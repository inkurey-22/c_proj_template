##
## EPITECH PROJECT, 2024
## my_libc
## File description:
## Makefile
##

# Colors
BOLD=\033[1m
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[0;33m
BLUE=\033[0;34m
NC=\033[0m # No Color

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re debug

SRC 	=   io/my_putnbr.c                   \
            io/my_putchar.c                  \
            io/my_putstr.c                   \
            io/my_puterr.c                   \
            io/my_show_word_array.c          \
            my_printf/my_printf.c            \
            my_printf/my_sprintf.c           \
            my_printf/my_dprintf.c           \
            my_printf/manage_spec.c          \
            my_printf/parse_flags.c          \
            my_printf/printf_g_spec.c        \
            my_printf/printf_n_spec.c        \
            my_printf/printf_putbase.c       \
            my_printf/printf_putchar.c       \
            my_printf/printf_putfloat.c      \
            my_printf/printf_putnbr.c        \
            my_printf/printf_putstr.c        \
            my_printf/printf_scientific.c    \
            my_printf/printf_tab.c           \
            my_printf/put_buffer.c           \
            my_printf/utilities.c            \
            my_printf/utilities2.c           \
            my_printf/utilities3.c           \
            my_printf/utilities4.c           \
            numbers/my_compute_power_rec.c   \
            numbers/my_compute_square_root.c \
            numbers/my_find_prime_sup.c      \
            numbers/my_getnbr.c              \
            numbers/my_isneg.c               \
            numbers/my_is_prime.c            \
            strings/my_str_isalpha.c         \
            strings/my_str_islower.c         \
            strings/my_str_isnum.c           \
            strings/my_str_isprintable.c     \
            strings/my_str_isupper.c         \
            strings/my_strcapitalize.c       \
            strings/my_strcat.c              \
            strings/my_strcmp.c              \
            strings/my_strcpy.c              \
            strings/my_strdup.c              \
            strings/my_strlen.c              \
            strings/my_strlowcase.c          \
            strings/my_strncat.c             \
            strings/my_strncmp.c             \
            strings/my_strncpy.c             \
            strings/my_strstr.c              \
            strings/my_strupcase.c           \
            strings/my_strchr.c              \
            strings/my_revstr.c              \
            strings/split_string.c           \
			lists/add_to_top.c               \
			lists/append.c                   \
			lists/create.c				  	 \
			lists/find.c					 \
			lists/free_list.c				 \
			lists/remove.c					 \
			lists/size.c					 \
			lists/sort.c

INCLUDES=   io/my_io.h	      \
            my_printf/my_printf.h   \
            strings/my_string.h   \
            numbers/my_numbers.h

CC 	    =   gcc

AR 	    =   ar rc

NAME    =   libmy.a

OBJ_DIR =   obj

OBJ     =   $(SRC:%.c=$(OBJ_DIR)/%.o)

CFLAGS  =   -I../include -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@cp io/my_io.h ../include
	@cp my_printf/my_printf.h ../include
	@cp strings/my_strings.h ../include
	@cp numbers/my_numbers.h ../include
	@echo -e "$(YELLOW)[LIBRARY]: $(BLUE)$(NAME) compiled$(NC)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@echo -e "$(YELLOW)[LIBRARY]: $(BLUE)Clean$(NC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@echo -e "$(YELLOW)[LIBRARY]: $(BLUE)Full clean$(NC)"

re: fclean all

debug: CFLAGS += -g
debug: re
