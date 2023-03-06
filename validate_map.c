/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:43:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 09:16:22 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Check if map is rectangular*/
int	check_rectangle(char **map, int x, int y)
{
	int	i;
	int	line0;
	int	check;

	if (x == y)
		return (0);
	i = -1;
	line0 = 0;
	while (map[0][++i] && map[0][i] != '\n')
		line0++;
	while (--x)
	{
		i = -1;
		check = 0;
		while (map[x][++i] && map[x][i] != '\n')
			check++;
		if (check != line0)
			return (0);
	}
	return (1);
}

/*Checks if map only has allowed charaters*/
int	check_values(char **map, int x, int y)
{
	int	j;

	while (--x >= 0)
	{
		j = y;
		while (--j >= 0)
		{
			if (map[x][j] != '0' && map[x][j] != '1' && map[x][j] != 'P'
				&& map[x][j] != 'E' && map[x][j] != 'C')
				return (0);
		}
	}
	return (1);
}

/*Checks if map only has 1s in boundaries*/
int	check_boundary(char **map, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y)
	{
		if (map[0][j] != '1' || map[x - 1][j] != '1')
			return (0);
		j++;
	}
	while (i < x)
	{
		if (map[i][0] != '1' || map[i][y - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

/*Checks if map only has 1 start, 1 exit and at least 1 collectible*/
int	check_pec(char **map, int x, int y)
{
	int	flag_p;
	int	flag_e;
	int	flag_c;
	int	j;

	flag_p = 0;
	flag_e = 0;
	flag_c = 0;
	while (--x)
	{
		j = y;
		while (--j)
		{
			if (map[x][j] == 'P')
				flag_p++;
			else if (map[x][j] == 'E')
				flag_e++;
			else if (map[x][j] == 'C')
				flag_c++;
		}
	}
	if (flag_p == 1 && flag_e == 1 && flag_c > 0)
		return (0);
	else
		return (1);
}

/*Checks if there is a valid path to the exit*/
void	check_path(char **map, t_coord size, t_coord start)
{
	if ((map[start.x][start.y] != '0' && map[start.x][start.y] != 'C'
	&& map[start.x][start.y] != 'P' && map[start.x][start.y] != 'E')
	|| start.x < 0 || start.y < 0 || start.x >= size.x || start.y >= size.y)
		return ;
	if (map[start.x][start.y] == 'E')
		map[start.x][start.y] = 'e';
	if (map[start.x][start.y] == 'P')
		map[start.x][start.y] = 'p';
	if (map[start.x][start.y] == 'C')
		map[start.x][start.y] = 'c';
	if (map[start.x][start.y] == '0')
		map[start.x][start.y] = 'o';
	check_path(map, size, (t_coord){start.x + 1, start.y});
	check_path(map, size, (t_coord){start.x - 1, start.y});
	check_path(map, size, (t_coord){start.x, start.y + 1});
	check_path(map, size, (t_coord){start.x, start.y - 1});
}
