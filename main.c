/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 15:36:08 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:11:28 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_minilbx lbx;
	
	if (reschecks(argc, argv, &game) == 1 || checkcorners(&game) == 1 )
	{
		printf("ERROIRE=\n");
		return (1);
	}
	mapcopy(&game);
	player_position(&game);
	if(floodandcoll(&game) == 1)
		return(1);
	printfmap(game.mapcopy);
	game.mlx_struct = &lbx;
	game.mlx_struct->mlx_ptr = mlx_init();
	game.mlx_struct->mlx_win = mlx_new_window(game.mlx_struct->mlx_ptr, game.weight *64, game.height * 64, "so_long");
	printf("bella %p\n", game.mlx_struct->mlx_ptr);
	start_game(&game);
	return (0);
}
