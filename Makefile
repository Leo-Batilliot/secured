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

MAKEFLAGS += --no-print-directory

.PHONY: all clean fclean re debug

# Directories
LIB_DIR = lib
SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj

# Files
LIB	=	$(LIB_DIR)/libmy.a
SRC	=	$(SRC_DIR)/ht_hash.c \
		$(SRC_DIR)/ht_new.c \
		$(SRC_DIR)/ht_delete_table.c \
		$(SRC_DIR)/ht_insert.c \
		$(SRC_DIR)/ht_search.c \
		$(SRC_DIR)/ht_delete.c \
		$(SRC_DIR)/ht_dump.c
SRC_TEST = tests/test.c
OBJ =	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
NAME	=	libhashtable.a

# Compiler
CC = gcc
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra -L$(LIB_DIR) -lmy

all: $(LIB) $(NAME)

$(LIB):
	@$(MAKE) -C $(LIB_DIR)

$(NAME): $(OBJ)
	@ar rcT $(NAME) $(OBJ) $(LIB)
	@echo -e "$(GREEN)[PROGRAM]: $(BLUE)$(NAME) compiled$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	@echo -e "$(GREEN)[PROGRAM]: $(BLUE)Clean$(NC)"
	@$(MAKE) -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(LIB)
	@echo -e "$(YELLOW)[LIBRARY]: $(BLUE)Full clean$(NC)"
	@rm -f $(NAME)
	@echo -e "$(GREEN)[PROGRAM]: $(BLUE)Full clean$(NC)"

re: fclean all

debug: CFLAGS += -g
debug: re

prog_test: all
	@$(CC) -o test $(SRC_TEST) -I$(INCLUDE_DIR) -L. -lhashtable
	@./test
