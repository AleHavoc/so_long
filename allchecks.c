/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allchecks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 14:25:51 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/02 16:54:23 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_checks(char	*map, t_game *game)
{
	if(oneplayer(map) == 1)
	{
		printf("sono qui");
		return(1);
	}
	if(oneexit(map, game) == 1)
	{
		printf("sono li");
		return(1);
	}
	if(countcollect(map, game) == 1)
	{	
		printf("ero li");
		return(1);
	}
	return(0);
}