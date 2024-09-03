/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxstruct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 18:06:56 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 18:37:29 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	part_one(t_texture *sprt, t_game *game)
{
	sprt->img_prbk = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prdw = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prl = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_prr = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_ext = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_clct = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_brr = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm", &(sprt->img_width), &(sprt->img_height));
	sprt->img_tl_crn = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	return ;
}

void	part_two(t_texture *sprt, t_game *game)
{
	sprt->img_dl_crn = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_tr_crn = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_dr_crn = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_lwall = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_rwall = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_wall = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_floor = mlx_xpm_file_to_image(game->mlx_struct->mlx_ptr,
			"/nfs/homes/acaracci/Desktop/solongquellovero/texture/download.xpm",
			&(sprt->img_width), &(sprt->img_height));
	sprt->img_player = sprt->img_prbk;
	return ;
}