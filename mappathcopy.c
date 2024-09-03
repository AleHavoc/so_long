/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mappathcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 19:09:22 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/02 19:51:04 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapcopy(t_game	*game)
{
	int	height;
	int	weight;

	height = 0;
	game->mapcopy = malloc(sizeof(char *) * game->height + 1);
	if (!game->mapcopy)
		return ;
	while (height < game->height)
	{
		weight = 0;
		game->mapcopy[height] = malloc(sizeof(char *) * game->weight + 1);
		if (!game->mapcopy[height])
			return ;
		while (weight < game->weight)
		{
			game->mapcopy[height][weight] = game->map[height][weight];
			weight++;
		}
		game->mapcopy[height][weight] = '\0';
		height++;
	}	
	game->mapcopy[height] = NULL;
}
int	player_position(t_game *game)
{
	int	x;
	int	y;
	
	x = 1;
	y = 1;
	while (game->mapcopy[x])
	{
		while (game->mapcopy[x][y])
		{
			if (game->mapcopy[x][y] == 'P')
			{
				game->px = x;
				game->py = y;
				return(0);
			}
			else
				y++;
		}
		y = 1;
		x++;
	}
	return(0);
}

int	floodandcoll(t_game *game)
{
	flood_fill(game, game->px, game->py);
	if(game->collcount != 0 || game->exit != 0)
		return (1);
	return (0);
}

void	flood_fill(t_game *game, int x, int y)
{
	if (game->mapcopy[x][y] == 'C')
		game->collcount--;
	if (game->mapcopy[x][y] == '1' || game->mapcopy[x][y] == 'x'|| game->mapcopy[x][y] == 'X')
		return ;
	if (game->mapcopy[x][y] == 'E')
		{
		game->exit--;
		game->mapcopy[x][y] = 'X';
		}
	else
		game->mapcopy[x][y] = 'x';
	flood_fill(game,x -1, y);
	flood_fill(game, x, y -1);
	flood_fill(game,x + 1, y);
	flood_fill(game, x, y + 1);
}


