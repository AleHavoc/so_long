/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:28:09 by acaracci          #+#    #+#             */
/*   Updated: 2024/09/03 15:21:15 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
int checkber(char *str)
{
	int	flag;
	int	i;

	i=0;
	flag=0;
	if(!str)
		return(erro(1));
	while(str[i])
	{
		if(str[i] == '.')
			flag++;
		i++;
	}	
	if(flag != 1)
		return(erro(1));
	if(str[i - 1] == 'r' && str[i - 2] == 'e' && str[i - 3] == 'b'
		&& str[i - 4] == '.')
		return(1);
	else
		return(erro(1));
}
char	*ft_strdup(char	*src)
{
	char	*copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
