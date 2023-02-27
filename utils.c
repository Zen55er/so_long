/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/27 09:12:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_map(char **map, int xi)
{
	while (xi >= 0)
	{
		free(map[xi]);
		xi--;
	}
	free(map);
	return (0);
}

int	check_coll(char **map, int x, int y)
{
	int	j;

	while (--x)
	{
		j = -1;
		while (j < y)
		{
			if (map[x][j] == 'C')
				return (ft_printf("Some collectibles out of reach\n"));
		}
	}
	return (0);
}
