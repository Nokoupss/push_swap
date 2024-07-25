# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbelkace <nbelkace@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/13 15:50:59 by nbelkace          #+#    #+#              #
#    Updated: 2024/07/25 05:10:01 by nbelkace         ###   ########.fr        #
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
SRCS_C =	$(SRCS)/$(ALGORITHM)/sort_three.c \
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