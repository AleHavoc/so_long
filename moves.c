/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 17:02:16 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:28:04 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_game *game, void *img, int z, int k)
{
	int	x;
	int	y;

	x = game->px;
	y = game->py;
	game->imgs.img_player = img;
	if (game->map[y + z][x + k] != '1')
	{
		if (game->map[y + z][x + k] == 'E' && game->collcount == 0)
			on_destroy(game);
		else if (game->map[y + z][x + k] == 'C')
			check_coll(game);
		if (game->map[y + z][x + k] != 'E')
		{
			game->map[y + z][x + k] = 'P';
			game->map[y][x] = '0';
			game->py += z;
			game->px += k;
			game->mv_count += 1;
		}
	}
}

void	check_coll(t_game *game)
{
	game->collcount --;
	if (game->collcount == 0)
	{
		mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_ext);
		game->imgs.img_ext = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
					"./texture/download-_1.xpm",
				&(game->imgs.img_width), &(game->imgs.img_height));
	}
}
void	set_texture(t_texture *sprt, t_game *game)
{
	part_one(sprt, game);
	part_two(sprt, game);
	printf("cacca\n");
	return ;
}