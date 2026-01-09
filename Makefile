# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lunsold <lunsold@student.42heilbronn.de>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/06 10:52:05 by lunsold           #+#    #+#              #
#    Updated: 2026/01/09 02:25:11 by lunsold          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf


################################################################################
#####################            Directories            ########################
################################################################################


OBJS_DIR = _obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC_DIR := includes $(LIBFT_DIR)
SRC_DIR := src src/algo src/swaps src/main
HEADERS = -I $(LIBFT_DIR)/includes


vpath %.c, $(SRC_DIR)
vpath %.h, $(INC_DIR)

################################################################################
#####################            Source Files           ########################
################################################################################

ALGO_FILES := sorting.c help_sorting.c
ALGO := $(addprefix $(SRC_DIR)/algo/, $(ALGO_FILES))

swaps_FILES := do_rr.c do_pa.c do_rb.c do_ra.c do_ss.c \
do_sa.c do_rrr.c do_pb.c do_rrb.c do_rra.c
swaps := $(addprefix $(SRC_DIR)/swaps/, $(swaps_FILES))


SRC_FILES := main.c
SRC := $(addprefix $(SRC_DIR)/, $(SRC_FILES)) $(ALGO) $(swaps)


################################################################################
###################            Object Files & rules        #####################
################################################################################

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC:%.c=%.o))


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

.PHONY: all clean fclean re