# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 14:39:16 by acaracci          #+#    #+#              #
#    Updated: 2024/09/02 19:53:45 by acaracci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES = \
			main.c \
			rescheck.c \
			checkber.c \
			readmap.c \
			split.c \
			str_join.c \
			allchecks.c \
			mappathcopy.c\
			mlxstruct.c\
			moves.c\
			putmap.c\
			putwalls.c\
			gamestart.c\
			
			
			
OBJ = $(CFILES:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
MLX = mlx_linux/libmlx.a
# HDRS = so_long.h

%.o: %.c
	@$(CC) -g -I/usr/include -Imlx_linux -c $< -o $@;
# @$(CC) -g -I/usr/include -Imlx_linux -I ${HDRS} -c $< -o $@;

name : $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	@(make -C ./mlx_linux)
	@$(CC) -g $(OBJ) $(FLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux ${MLX} -lXext -lX11 -lm -lz -o $(NAME)
# @$(CC) -g $(OBJ) $(FLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LIN=1 -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled succesfully.$(PURPLE)"

clean :
	@ $(RM) $(OBJ)

#@ $(RM) $(MLX)
	
fclean : clean
	@ $(RM) $(NAME)

re : fclean all