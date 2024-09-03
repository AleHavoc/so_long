/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putwalls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:16:36 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:39:46 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_right_walls(t_game *game, t_texture sprites)
{
	int		rows;
	int		columns;

	rows = game->weight - 1;
	columns = 0;
	while (columns < game->weight)
	{
		if (columns == 0)
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_tr_crn, rows * 64, columns * 64);
		else if (columns == game->weight - 1)
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_dr_crn, rows * 64, columns * 64);
		else
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_rwall, rows * 64, columns * 64);
		columns ++;
	}
	return ;
}

void	put_left_walls(t_game *game, t_texture sprites)
{
	int		rows;
	int		columns;

	rows = 0;
	columns = 0;
	while (columns < game->weight)
	{
		if (columns == 0)
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_tl_crn, rows * 64, columns * 64);
		else if (columns == game->weight - 1)
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_dl_crn, rows * 64, columns * 64);
		else
			game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
					game->win_ptr, sprites.img_lwall, rows * 64, columns * 64);
		columns ++;
	}
	return ;
}

void	put_central_walls(t_game *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 0;
	while (rows < game->height - 1)
	{
		game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
				game->win_ptr, sprites.img_wall, rows * 64, columns * 64);
		rows ++;
	}
	rows = 1;
	columns = game->weight - 1;
	while (rows < game->height - 1)
	{
		game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
				game->win_ptr, sprites.img_wall, rows * 64, columns * 64);
		rows ++;
	}
	return ;
}

void	put_objs_ctrl(t_game *game, t_texture sprites, int columns, int rows)
{
	if (game->map[columns][rows] == 'P')
		game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
				game->win_ptr, sprites.img_player, rows * 64, columns * 64);
	else if (game->map[columns][rows] == 'E')
		game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
				game->win_ptr, sprites.img_ext, rows * 64, columns * 64);
	else if (game->map[columns][rows] == 'C')
		game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
				game->win_ptr, sprites.img_clct, rows * 64, columns * 64);
	return ;
}