# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 14:39:16 by acaracci          #+#    #+#              #
#    Updated: 2024/08/13 13:27:17 by acaracci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFILES = \
			main.c \
			checkber.c \
			ft_putstr.c \
			readmap.c \
			split.c \
			str_join.c \
			
OBJ = $(CFILES:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 
RM = rm -rf
MLX = mlx/libmlx_Linux.a
HDRS = so_long.h

%.o: %.c
	@$(CC) -g -I/usr/include -Imlx_linux -I ${HDRS} -c $< -o $@;

name : $(NAME)

all : $(NAME)

$(NAME) : $(OBJ)
	@(make -C ./mlx) 2> /dev/null
	@$(CC) -g $(OBJ) $(FLAGS) -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -D LIN=1 -o $(NAME)
	@echo "$(GREEN)$(NAME) compiled succesfully.$(PURPLE)"

clean :
	@ $(RM) $(OBJ)

#@ $(RM) $(MLX)
	
fclean : clean
	@ $(RM) $(NAME)

re : fclean all