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

.PHONY: all clean fclean re debug lib lib_clean lib_fclean

# Directories
LIB_DIR = lib
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
LIB_OBJ_DIR = $(LIB_DIR)/obj

# Files
LIB = $(LIB_DIR)/libmy.a
SRC := $(shell find $(SRC_DIR) -type f -name "*.c")

LIB_SRC := $(shell find $(LIB_DIR) -type f -name "*.c")

LIB_OBJ = $(LIB_SRC:$(LIB_DIR)/%.c=$(LIB_OBJ_DIR)/%.o)

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME = proj

# Calculate total steps for progress
TOTAL_STEPS = $(shell echo "$$(($(words $(LIB_OBJ)) + $(words $(OBJ)) + 2))")
CURRENT_STEP = 0

# Compiler
CC = gcc
AR = ar rc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra
LDFLAGS = -L$(LIB_DIR) -lmy

PROGRESS_FILE = .progress

# Calculate total steps for progress
TOTAL_STEPS = $(shell echo "$$(($(words $(LIB_OBJ)) + $(words $(OBJ)) + 3))")

define update_progress
	@echo $$(( $$(cat $(PROGRESS_FILE) 2>/dev/null || \
		echo 0) + 1 )) > $(PROGRESS_FILE)
endef

define show_progress
	@CURRENT_STEP=$$(cat $(PROGRESS_FILE)); \
	BAR_WIDTH=22; \
	FILLED=$$(( CURRENT_STEP * BAR_WIDTH / $(TOTAL_STEPS) )); \
	EMPTY=$$(( BAR_WIDTH - FILLED )); \
	printf "$(BOLD)$(BLUE)["; \
	for i in $$(seq 1 $$FILLED); do printf "="; done; \
	for i in $$(seq 1 $$EMPTY); do printf " "; done; \
	printf "]$(NC)"; \
	PERCENT=$$(( CURRENT_STEP * 100 / $(TOTAL_STEPS) )); \
	printf "%3s%% " "$$PERCENT"
endef

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
#	$(update_progress)
#	$(show_progress)
	@printf "$(GREEN)$(BOLD)Linking C executable$(NC)"
	@printf "$(YELLOW)$(BOLD)%s$(NC)\n" "$(NAME)"
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
#	$(update_progress)
#	$(show_progress)
	@printf "$(RED)$(BOLD)Built target$(NC)\n"

# Build the library
$(LIB): $(LIB_OBJ)
#	$(update_progress)
#	$(show_progress)
	@$(AR) $(LIB) $(LIB_OBJ)
	@printf "$(GREEN)$(BOLD)Linking C static library$(NC)"
	@printf "$(YELLOW)$(BOLD)%s$(NC)\n" "$(LIB)"

$(LIB_OBJ_DIR)/%.o: $(LIB_DIR)/%.c
	@mkdir -p $(@D)
#	$(update_progress)
#	$(show_progress)
	@printf "$(GREEN)Building C object$(NC)$(YELLOW)%s$(NC)\n" "$@"
	@$(CC) -c $< -o $@ $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
#	$(update_progress)
#	$(show_progress)
	@printf "$(GREEN)Building C object$(NC)$(YELLOW)%s$(NC)\n" "$@"
	@$(CC) -c $< -o $@ $(CFLAGS)

clean: lib_clean
	@rm -rf $(OBJ_DIR)
	@rm -f $(PROGRESS_FILE)
	@printf "$(RED)$(BOLD)Cleaned object files$(NC)\n"

lib_clean:
	@rm -rf $(LIB_OBJ_DIR)

fclean: clean lib_fclean
	@rm -f $(NAME)
	@rm -f $(PROGRESS_FILE)
	@printf "$(RED)$(BOLD)Cleaned all files$(NC)\n"

lib_fclean:
	@rm -f $(LIB)

re: fclean all

debug: CFLAGS += -g
debug: re
