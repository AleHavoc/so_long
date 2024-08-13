/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acaracci <acaracci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 16:28:21 by acaracci          #+#    #+#             */
/*   Updated: 2024/08/13 16:53:40 by acaracci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
	(void) argc;
	char	*map;
	if(checkber(argv[1]) == 0)
	{
		return(1);
	}
	map = readmap(argv[1]);
	//printf("%s\n", map);
	if(map == NULL)
	{
		printf("%p\n", map);
		printf("SUCCHIA PALLE\n");
		return(1);
	}
	if(charscontrol(map) == 1);
	{
		printf("ERRORE\n");
		return(1);
	}
	return(0);
}
int erro(int i)
{
	if (i == 1)
	{
		printf("%s\n", ERROR_1);
	}
	return(0);
}