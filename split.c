/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:37:55 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/13 13:00:26 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_words( char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
			if (s[i] == '\0')
			{
				return (count);
			}
		}
		i++;
	}
	return (count);
}

int	memory_check(char **array, int position, int len)
{
	int	i;

	i = 0;
	array[position] = malloc(len);
	if (array[position] == NULL)
	{
		while (i < position)
		{
			free(array[i]);
		}
		free(array);
		return (1);
	}
	return (0);
}

int	fill_array(char **array, char *s, char c)
{
	int	len;
	int	position;

	position = 0;
	while (*s)
	{
		len = 0;
		while (*s && *s == c)
		{
			s++;
		}
		while (*s && *s != c)
		{
			len++;
			s++;
		}
		if (len > 0)
		{
			if (memory_check(array, position, len + 1))
				return (1);
			ft_strlcpy(array[position], s - len, len + 1);
		}
		position++;
	}
	return (0);
}

char	**ft_split(char *s, char c)
{
	int	words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	if (fill_array(array, s, c) == 1)
		return (NULL);
	return (array);
}