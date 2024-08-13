/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 12:48:34 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/13 15:15:17 by acaracci         ###   ########.fr       */
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

// char	*allocate(char *s1, char *s2)
// {
// 	int	size;
// 	char	*s3;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	size = ft_strlen(s1) + ft_strlen(s2);
// 	s3 = malloc(sizeof(char) * (size + 1));
// 	if (s3 == NULL)
// 		return (NULL);
// 	return (s3);
// }

// char	*ft_strjoin(char *s1, char *s2)
// {
// 	int	i;
// 	int	j;
// 	char	*s3;

// 	i = 0;
// 	j = 0;
// 	s3 = allocate(s1, s2);
// 	if (!s3)
// 		return (NULL);
// 	while (s1[i] != '\0')
// 	{
// 		s3[i] = s1[i];
// 		i++;
// 	}
// 	while (s2[j] != '\0')
// 	{
// 		s3[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	s3[i] = '\0';
//     free(s1);
// 	return (s3);
// }

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