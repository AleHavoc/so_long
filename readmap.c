/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:24:56 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/02 16:51:03 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*readmap(char *pathmap)
{
	int		fd;
	char	buffer[2];
	int		one;
	char	*backup;
	
	backup = ft_strdup("");
	one = 1;
	fd = open(pathmap, O_RDONLY);
	
	if(fd < 0)
		return(NULL);
	while(one == 1)
	{
		one = read(fd, buffer, 1);
		buffer[1] = '\0';
		if (one == 0)
			break;
		backup = ft_strjoin(backup, buffer);
		if (one == -1)
			return (NULL);
	}
	return (backup);
}

int	charscontrol(char *map)
{
	int	i;
	
	i = -1;

	while(map[++i])
	{
		if(map[i] != 'E' && map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'P' && map[i] != '\n')
			{
				printf("DEVI UTILIZZA SOLO QUESTI\n");
				return(1);
			}
		if(i < ft_strlen(map))
		{
			if(map[i] == '\n' && map[i + 1] == '\n')
			{
				return(1);
			}
		}
	}
	return(0);
}

int oneexit(char *map, t_game *game)
{
	int	i;
	int	e;
	
	i = -1;
	e = 0;
	
	while(map[++i])
	{
		if(map[i] == 'E')
		{
			e++;
		}
	}
	if(e != 1)
	{
		return(1);
	}
	game->exit = e;
	return(0);
}

int	oneplayer(char *map)
{
	t_game game;
	int i;
	int p;
	
	i = -1;
	p = 0;
	
	while(map[++i])
	{
		if(map[i] == 'P')
		{
			p++;
		}
	}
	if(p != 1)
		return(1);
	return(0);
}

int countcollect(char *map, t_game *game)
{
	int	i;
	int	c;
	
	i = -1;
	c = 0;
	
	while(map[++i])
	{
		if(map[i] == 'C')
		{
			c++;
		}
	}
	if(c < 1)
		return(1);
	game->collcount = c;
	return(0);
}
