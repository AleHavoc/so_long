/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 12:34:50 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 15:48:09 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <mlx.h>
#include <mlx_int.h>
#include "mlx_linux/mlx.h"
#include "mlx_linux/mlx_int.h"
#include <X11/X.h>
#include <X11/keysym.h>

#define ERROR_1 "Error\nNeed a .ber"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307

typedef struct s_minilbx {
	
	void	*mlx_ptr;
	void	*mlx_win;
	
}	t_minilbx;

typedef struct s_text {
	
	void	*wall[18];
	void	*player[2];
	void	*exit;
	void	*floor;
	void	*enemy[4];
	void	*coin;
	
}	t_text;

typedef struct s_texture
{
	void	*img_player;
	void	*img_prbk;
	void	*img_prdw;
	void	*img_prl;
	void	*img_prr;
	void	*img_ext;
	void	*img_clct;
	void	*img_brr;
	void	*img_tl_crn;
	void	*img_dl_crn;
	void	*img_tr_crn;
	void	*img_dr_crn;
	void	*img_lwall;
	void	*img_rwall;
	void	*img_wall;
	void	*img_floor;
	int		img_width;
	int		img_height;
}	t_texture;

typedef struct s_game 
{
	char	**map;
	char	**mapcopy;
	int	x;
	int	y;
	int	height;
	int	weight;
	int	px;
	int	py;
	int	collcount;
	int	exit;
	int	mv_count;
	void	*win_ptr;
	int	img_to_win;
	t_texture	imgs;
	t_minilbx	*mlx_struct;
	t_text		*texture;
	
} t_game;


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
int		oneexit(char *map, t_game *game);
int		countcollect(char *map, t_game *game);
int		oneplayer(char *map);
int		ft_checks(char	*map, t_game *game);
int		reschecks(int argc, char **argv, t_game *game);
int		checkcorners(t_game	*game);
int		maprect(t_game	*game);
void	mapcopy(t_game	*game);
int		player_position(t_game *game);
void	flood_fill(t_game *game, int x, int y);
int		floodandcoll(t_game *game);
void	check_coll(t_game *game);
void	moves(t_game *game, void *img, int z, int k);
void	part_one(t_texture *sprt, t_game *game);
void	part_two(t_texture *sprt, t_game *game);
void	put_right_walls(t_game *game, t_texture sprites);
void	put_left_walls(t_game *game, t_texture sprites);
void	put_central_walls(t_game *game, t_texture sprites);
void	put_objs_ctrl(t_game *game, t_texture sprites, int columns, int rows);
void	set_texture(t_texture *sprt, t_game *game);
int		start_game(t_game *game);
int		on_destroy(t_game *game);
void	print_map(t_game *game, t_texture sprites);
void	put_objects(t_game *game, t_texture sprites);
void	put_walls(t_game *game, t_texture sprites);
void	put_floor(t_game *game, t_texture sprites);
void	free_matrix(char **matrix);
int	on_keypress(int keysym, t_game *game);

void	printfmap(char **matrix);
#endif
