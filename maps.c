/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:02:37 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/22 14:59:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "so_long.h"

char	**free_big(char **map)
{
	free(map);
	return (0);
}

char	**make_map(char **base, int x, int y)
{
	int		xi;
	int		yi;
	char	**map;

	xi = 0;
	map = (char **)malloc(sizeof(char *) * x);
	if (!map)
	{
		free (map);
		return (0);
	}
	while (xi < x)
	{
		map[xi] = (char *)malloc(sizeof(char) * y);
		if (!map[xi])
			
		yi = 0;
		while (yi < y)
		{
			
		}
	}
}

char	**maps(int id)
{
	int		x;
	int		y;
	char	**base;

	if (id == 1)
	{
		x = 10;
		y = 20;
	}
}
