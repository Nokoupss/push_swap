# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:50:59 by nbelkace          #+#    #+#              #
#    Updated: 2024/08/03 00:56:13 by nbelkace         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Directory
SRCS = srcs
ALGORITHM = algorithm
COMMAND = command
PARSING = parsing
UTILS = utils

# Utils Directory
UTILS_C = $(SRCS)/$(UTILS)

# Source Files
SRCS_C =	$(SRCS)/$(ALGORITHM)/algo_rotate.c \
			$(SRCS)/$(ALGORITHM)/algo_utils.c \
			$(SRCS)/$(ALGORITHM)/cost_analysis.c \
			$(SRCS)/$(ALGORITHM)/init_data.c \
			$(SRCS)/$(ALGORITHM)/set_target_node.c \
			$(SRCS)/$(ALGORITHM)/sort_stacks.c \
			$(SRCS)/$(ALGORITHM)/sort_three.c \
			$(SRCS)/$(COMMAND)/push_command.c \
			$(SRCS)/$(COMMAND)/reverse-rotate_command.c \
			$(SRCS)/$(COMMAND)/rotate_command.c \
			$(SRCS)/$(COMMAND)/swap_command.c \
			$(SRCS)/$(PARSING)/init_list.c \
			$(SRCS)/$(PARSING)/stack_utils.c \
			main.c \
			
# Object FIles
OBJS = ${SRCS_C:.c=.o}

# Archive and Libraries
LIBFT = $(UTILS_C)/libft/libft.a

# Compiler and Flags
CC = cc
FLAGS = -Wall -Wextra -Werror -g3

# Remove command
RM = rm -f

# Rules
all : ${NAME}

${NAME} : ${OBJS}
	make -C $(UTILS_C)/libft
	${CC} -o ${NAME} ${OBJS} ${LIBFT} -I includes

.c.o :
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean :
	make -C $(UTILS_C)/libft clean
	${RM} ${OBJS}

fclean : clean
	make -C $(UTILS_C)/libft fclean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re