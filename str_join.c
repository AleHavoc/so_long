/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:48:34 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/21 18:13:22 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlcpy(char	*dest, char	*src, int	size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size < 1)
		return (i);
	while (src[j] && j < size - 1)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

int	ft_strlen(char *s)
{
	int l;

	l = 0;
	while (s[l] != 0)
		l++;
	return (l);
}

static int	ft_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*strres;
	int		i;
	int		j;
	int		len_max;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	len_max = ((ft_len(s1) + ft_len(s2)) + 1);
	strres = (char *) malloc(len_max * sizeof(char));
	if (!strres)
		return (NULL);
	while (s1[i])
	{
		strres[i] = s1[i];
		i ++;
	}
	while (s2[j])
		strres[i++] = s2[j++];
	strres[i] = '\0';
    free(s1);
	return (strres);
}