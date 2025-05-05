##
## EPITECH PROJECT, 2024
## c_proj_template
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

.PHONY: all clean fclean re debug

# Directories
LIB_DIR = lib
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Files
LIB = $(LIB_DIR)/libmy.a
SRC = $(SRC_DIR)/main.c
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME = proj

# Compiler
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra
LDFLAGS = -L$(LIB_DIR) -lmy

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(LIB)
	@mkdir -p $(@D)
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIB)
	rm -f $(NAME)

re: fclean all

debug: CFLAGS += -g
debug: re
