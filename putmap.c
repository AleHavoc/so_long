/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:09:58 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:38:10 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_floor(t_game *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 1;
	while (columns < game->height - 1)
	{
		while (rows < game->weight - 1)
		{
			if (game->map[columns][rows] == '1')
			{
				game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
						game->win_ptr, sprites.img_brr,
						rows * 48, columns * 48);
			}
			else if (game->map[columns][rows] == '0')
				game->img_to_win = mlx_put_image_to_window(game->mlx_struct->mlx_ptr,
						game->mlx_struct->mlx_win, sprites.img_floor,
						rows * 48, columns * 48);
			rows ++;
		}
		rows = 1;
		columns ++;
	}
	return ;
}

void	put_walls(t_game *game, t_texture sprites)
{
	put_right_walls(game, sprites);
	put_left_walls(game, sprites);
	put_central_walls(game, sprites);
	return ;
}

void	put_objects(t_game *game, t_texture sprites)
{
	int	rows;
	int	columns;

	rows = 1;
	columns = 1;
	while (columns < game->height - 1)
	{
		while (rows < game->weight - 1)
		{
			if (game->map[columns][rows] != '0' &&
			game->map[columns][rows] != '1')
			{
				put_objs_ctrl(game, sprites, columns, rows);
			}
			rows ++;
		}
		rows = 1;
		columns ++;
	}
	return ;
}

void	print_map(t_game *game, t_texture sprites)
{
	put_floor(game, sprites);
	put_walls(game, sprites);
	printf("diopo\n");
	put_objects(game, sprites);
	return ;
}