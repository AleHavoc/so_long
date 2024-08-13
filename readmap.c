/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 11:24:56 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/13 16:50:22 by acaracci         ###   ########.fr       */
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
		if(one == 0)
			break;
		backup = ft_strjoin(backup, buffer);
		if(one == -1)
			return(NULL);
	}
	return(backup);
}

int	charscontrol(char *map)
{
	int	i;
	
	i = -1;

	while(map[++i])
	{
		if(map[i] != 'E' && map[i] != '0' && map[i] != '1' && map[i] != 'C'
			&& map[i] != 'P')
			{
				printf("DEVI UTILIZZA SOLO QUESTI\n");
				return(1);
			}
		if(i < ft_strlen(map))
		{
			if(map[i] == '\n' && map[i + 1] == '\n')
				return(1);
		}
	}
	return(0);
}
