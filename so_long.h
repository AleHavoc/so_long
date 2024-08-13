/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:34:50 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/13 16:41:48 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
// #include <mlx.h>
// #include <X11/X.h>
// #include <X11/keysym.h>

#define ERROR_1 "Error\nNeed a .ber"

typedef struct t_game 
{
 char **map;
 int	x;
 int	y;
} game;

char	*readmap(char *pathmap);
int		ft_strlen( char *s);
int		ft_strlcpy(char	*dest, char	*src, int	size);
void	ft_putstr(char *str);
int		checkber(char *str);
void	ft_putchar(char c);
int		erro(int i);
char	*allocate( char *s1, char *s2);
char	*ft_strjoin( char *s1, char *s2);
int	    count_words(char *s, char c);
int	    memory_check(char **array, int position, int len);
int	    fill_array(char **array, char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strdup(char	*src);
int		charscontrol(char *map);

#endif
