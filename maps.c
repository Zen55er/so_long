/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:02:37 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 11:26:07 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Allocates memory for the 2d array and creates map*/
char	**make_map(int fd, int x)
{
	int		xi;
	char	**map;

	xi = -1;
	map = (char **)malloc(sizeof(char *) * (x + 1));
	if (!map)
		return (0);
	while (++xi < x)
	{
		map[xi] = get_next_line(fd);
		if (!map[xi] && xi == 0)
		{
			ft_printf("Error\nMap file is empty\n");
			return (free_map(map, -1));
		}
		if (!map[xi] && xi < x)
			return (free_map(map, xi));
	}
	map[xi] = 0;
	return (map);
}

/*Resets values in map to originals*/
void	reset_vals(char **map, int x, int y)
{
	int	j;

	while (--x)
	{
		j = y;
		while (--j)
		{
			if (map[x][j] == 'e')
				map[x][j] = 'E';
			if (map[x][j] == 'p')
				map[x][j] = 'P';
			if (map[x][j] == 'c')
				map[x][j] = 'C';
			if (map[x][j] == 'o')
				map[x][j] = '0';
		}
	}
	return ;
}

/*Finds coordinates for specific chars*/
t_coord	find_pos(char **map, int x, int y, char c)
{
	int		i;
	int		j;
	t_coord	pos;

	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[i][j] == c)
				break ;
		}
		if (map[i][j] == c)
			break ;
	}
	pos.x = i;
	pos.y = j;
	return (pos);
}

/*Validates map parameters*/
int	validate_map(char **map, int x, int y)
{
	t_coord	start;
	t_coord	exit;

	if (!check_rectangle(map, x, y))
		return (ft_printf("Error\nMap is not a rectangle\n"));
	if (!check_values(map, x, y))
		return (ft_printf("Error\nFound forbidden value in map\n"));
	if (!check_boundary(map, x, y))
		return (ft_printf("Error\nBorder contains value(s) other than '1'\n"));
	if (check_pec(map, x, y))
		return (ft_printf("Error\nWrong number of start/exit or 0 items\n"));
	start = find_pos(map, x, y, 'P');
	exit = find_pos(map, x, y, 'E');
	check_path(map, (t_coord){x, y}, start);
	if (!check_coll(map, x, y))
		return (ft_printf("Error\nSome collectibles are out of reach\n"));
	if (map[exit.x][exit.y] == 'e')
		reset_vals(map, x, y);
	else
		return (ft_printf("Error\nCould not find path to exit\n"));
	return (0);
}

/*Gets size, starts map generation and paramenter validation*/
char	**maps(int fd, t_coord size)
{
	char	**map;

	map = make_map(fd, size.x);
	if (!map)
		return (0);
	if (validate_map(map, size.x, size.y))
		return (free_map(map, size.x - 1));
	return (map);
}
