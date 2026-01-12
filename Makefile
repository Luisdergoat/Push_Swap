# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunsold <lunsold@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 14:34:58 by lunsold           #+#    #+#              #
#    Updated: 2026/01/12 16:22:53 by lunsold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
RM = rm -rf

################################################################################
###############                  DIRECTORIES                      ##############
################################################################################

OBJ_DIR = _obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIRS := Includes $(LIBFT_DIR)
SRC_DIRS := src src/parser src/swaps src/algo
HEADERS = -I $(LIBFT_DIR)/include -I

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

################################################################################
###############                  SOURCE FILES                     ##############
################################################################################

PARSING_FILES := input_check.c parser.c free_funktions.c define.c fill_stack.c
PARSING := $(addprefix parser/, $(PARSING_FILES))

SWAPS_FILES := do_rr.c do_pa.c do_rb.c do_ra.c do_ss.c do_sa.c do_sb.c do_rrr.c do_pb.c do_rrb.c do_rra.c
SWAPS := $(addprefix swaps/, $(SWAPS_FILES))

ALGO_FILES := sorting.c help_sorting.c check_funktions.c stack_a_funktions.c rotation.c
ALGO := $(addprefix algo/, $(ALGO_FILES))

SRC_FILES := main.c
SRC := $(addprefix src/, $(SRC_FILES) $(PARSING) $(SWAPS) $(ALGO))

################################################################################
###############               OBJECT FILES & RULES                ##############
################################################################################

OBJS := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

# Compilation flags and linking options
CFLAGS := -Wall -Wextra -Werror -g -IIncludes -Ilibft -MMD -MP $(addprefix -I, $(INC_DIRS))
LDFLAGS := -Llibft -lft
CFLAGS_SAN := $(CFLAGS) -fsanitize=address -g
LDFLAGS_SAN := $(LDFLAGS) -fsanitize=address

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "\033[0;32mLinking $(NAME)...\033[0m"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS) $(LDFLAGS)
	@echo "\033[0;32mSuccessful Compilation of $(NAME)\033[0m"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@mkdir -p $(@D)
	@echo "\033[0;32mCompiling $<...\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT):
	@echo "\033[0;32mCompiling libft..\033[0m"
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "\033[0;32mCleaning object files...\033[0m"
	@$(RM) $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\033[0;32mRemoving $(NAME)...\033[0m"
	@$(RM) $(OBJ_DIR)
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;32mRemoved files succesfully \033[0m"

re: fclean all

CHECKER = ./checker_linux

ARG = "956 187 188 896"

test: all
	ARG="956 187 188 896"; ./push_swap $$ARG | $(CHECKER) $$ARG

test_rand: all
	ARG_RAND=$$(jot -r 36 10000000 99999999) && ./push_swap $$ARG_RAND | ./checker_linux $$ARG_RAND

.PHONY: all clean fclean re test test_rand