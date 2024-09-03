/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rescheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:28:21 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/30 20:05:46 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int reschecks(int argc, char **argv, t_game *game)
{
	char	*map;

	(void) argc;
	if (checkber(argv[1]) == 0)
		return (1);
	map = readmap(argv[1]);
	if (!map || charscontrol(map) == 1 || ft_checks(map, game) == 1)
	{
		free(map);
		write(2, "Error\n", 6);
		return (1);
	}
	game->map = ft_split(map, '\n');
	free(map);
	if (maprect(game) == 1)
	{
		free(game->map);
		return (1);
	}
	return (0);
}

int	maprect(t_game	*game)
{
	int	i;
	int	flag;

	i = 0;
	flag = ft_strlen(game->map[i]);
	i ++;
	while (game->map[i])
	{
		if (flag != ft_strlen(game->map[i]))
		{
			printf("perfavorenetraqua\n");
			return (1);
		}
		i ++;
	}
	game->height = i;
	game->weight = flag;
	return (0);
}

int	checkcorners(t_game	*game)
{
	int	i;
	
	i = -1;
	while (++i < game->weight)
		if (game->map[0][i] != 49)
			return (1);
	i = -1;
	while (++i < game->weight)
		if (game->map[game->height - 1][i] != 49)
			return (1);
	i = -1;
	while (++i < game->height)
		if (game->map[i][0] != 49)
			return (1);
	i = -1;
	while (++i < game->height)
		if (game->map[i][game->weight - 1] != 49)
			return (1);
	return (0);
}

int erro(int i)
{
	if (i == 1)
		printf("%s\n", ERROR_1);
	return (0);
}
void	printfmap(char **matrix)
{
	int i;
	
	i = 0;
	printf("mappa:\n");
	while(matrix[i])
	{
		printf("%s\n", matrix[i]);
		i ++;
	}
	return ;
}
