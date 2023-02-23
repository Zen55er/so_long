/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 09:43:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/23 11:35:34 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Checks if map only has alloed charaters*/
int	check_values(char **map, int x, int y)
{
	while (--x)
	{
		while (--y)
		{
			if (map[x][y] != '0' && map[x][y] != '1' && map[x][y] != 'P'
				&& map[x][y] != 'E' && map[x][y] != 'C')
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

	flag_p = 0;
	flag_e = 0;
	flag_c = 0;
	while (--x)
	{
		while (--y)
		{
			if (map[x][y] == 'P')
				flag_p++;
			else if (map[x][y] == 'E')
				flag_e++;
			else if (map[x][y] == 'C')
				flag_c++;
		}
	}
	if (flag_p == 1 && flag_e == 1 && flag_c > 0)
		return (1);
	else
		return (ft_printf("Error, more than 1 start or exit in map\n"));
}

/*Finds starting coordinates*/
t_coord	find_start(char **map, int x, int y)
{
	int		i;
	int		j;
	t_coord	start;

	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[i][j] == 'P')
				break ;
		}
	}
	start.x = i;
	start.y = j;
	return (start);
}

/*Checks if there is a valid path to the exit*/
/*CHANGE VALUE TO A OR JUST KEEP GOING UNTIL FINDING THE EXIT?*/
int	check_path(char **map, t_coord size, t_coord start, t_coord chars)
{
	if (map[start.x][start.y] == 'E')
		return (1);
	if ((map[start.x][start.y] != chars.x && map[start.x][start.y] != chars.y)
	|| start.x < 0 || start.y < 0 || start.x >= size.x || start.y >= size.y)
		return (0);
	//map[start.x][start.y] = 'A';
	check_path(map, size, (t_coord){start.x + 1, start.y}, chars);
	check_path(map, size, (t_coord){start.x - 1, start.y}, chars);
	check_path(map, size, (t_coord){start.x, start.y + 1}, chars);
	check_path(map, size, (t_coord){start.x, start.y - 1}, chars);
}
