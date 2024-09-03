/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 19:32:55 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:25:07 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	start_game(t_game *game)
{
	void *img;
	int w;
	int h;

	if (!game->mlx_struct->mlx_ptr)
		return (1);
	if (!game->mlx_struct->mlx_win)
	{
		free(game->mlx_struct->mlx_ptr);
		return (1);
	}
	// img = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr, "./texture/download.xpm", &w, &h);
	// printf("img:%p\n", img);
	// mlx_put_image_to_window(game->mlx_struct->mlx_ptr,game->mlx_struct->mlx_win, img, 1, 1);
	// while(1)
	set_texture(&(game->imgs), game);
	print_map(game, game->imgs);
	printf("dajeroma \n");
	game->mv_count = 0;
	mlx_hook(game->win_ptr, 02, (1L << 0), &on_keypress, game);
	mlx_hook(game->win_ptr, 17, (1L << 17), &on_destroy, game);
	mlx_loop(game->mlx_struct->mlx_ptr);
	printf("cacca\n");
	return (0);
}

int	on_destroy(t_game *game)
{
	free_matrix(game->map);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_brr);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_clct);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_dl_crn);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_dr_crn);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_ext);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_floor);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_lwall);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_prbk);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_prdw);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_prl);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_prr);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_rwall);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_tl_crn);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_tr_crn);
	mlx_destroy_image(game->mlx_struct->mlx_ptr, game->imgs.img_wall);
	mlx_destroy_window(game->mlx_struct->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_struct->mlx_ptr);
	free(game->mlx_struct->mlx_ptr);
	exit(0);
	return (0);
}

void	free_matrix(char **matrix)
{
	int	rows;

	rows = 0;
	while (matrix[rows])
	{
		free(matrix[rows]);
		rows ++;
	}
	free(matrix);
}

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == UP)
		moves(game, game->imgs.img_prbk, -1, 0);
	else if (keysym == LEFT)
		moves(game, game->imgs.img_prl, 0, -1);
	else if (keysym == DOWN)
		moves(game, game->imgs.img_prdw, 1, 0);
	else if (keysym == RIGHT)
		moves(game, game->imgs.img_prr, 0, 1);
	else if (keysym == ESC)
		on_destroy(game);
	print_map(game, game->imgs);
	return (0);
}