/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:02:37 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/27 13:38:04 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static void	debug(char **map, int xi, int y)
{
	int	j;

	j = -1;
	while (++j < y)
		ft_printf("%c", map[xi][j]);
	ft_printf("\n");
} */

/* static void	debug2(char **map, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	ft_printf("MAP AFTER FILLING EVERY ROW\n");
	while (++i < x)
	{
		j = -1;
		while (++j < y)
			ft_printf("%c", map[i][j]);
		ft_printf("\n");
	}
	ft_printf("\n");
} */

/*Allocates memory for the 2d array and fills it according to chosen base*/
char	**make_map(int fd, int x, int y)
{
	int		xi;
	char	**map;

	xi = -1;
	map = (char **)malloc(sizeof(char *) * x);
	if (!map)
		return (0);
	while (++xi < x)
	{
		map[xi] = (char *)malloc(sizeof(char) * (y + 1));
		if (!map[xi])
			return (free_map(map, xi));
		map[xi] = get_next_line(fd);
		if (!map[xi] && xi < x)
			return (free_map(map, xi));
	}
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
		return (ft_printf("MAP IS NOT A RECTANGLE\n"));
	if (!check_values(map, x, y))
		return (ft_printf("FOUND FORBIDDEN VALUE\n"));
	if (!check_boundary(map, x, y))
		return (ft_printf("FOUND BORDER WITH VALUE OTHER THAN 1\n"));
	if (check_pec(map, x, y))
		return (1);
	start = find_pos(map, x, y, 'P');
	exit = find_pos(map, x, y, 'E');
	check_path(map, (t_coord){x, y}, start);
	if (map[exit.x][exit.y] == 'e' && !check_coll(map, x, y))
		reset_vals(map, x, y);
	else
		return (1);
	return (0);
}

/*Chooses baseline for map to use, sets size and call map generating function*/
char	**maps(int fd)
{
	int		x;
	int		y;
	char	**map;

	x = 10;
	y = 20;
	map = make_map(fd, x, y);
	if (validate_map(map, x, y))
		return (0);
	return (map);
}

/* char	**maps(int id)
{
	int		x;
	int		y;
	char	*base[] = {
		"11111111111111111111",
		"10C000000000000000E1",
		"10101010101010101C11",
		"10011001100110011001",
		"10001110001110001111",
		"10001110C01110001111",
		"10011001100110011001",
		"10101010101010101011",
		"1P0000000000000C0001",
		"11111111111111111111"
	};
	char	**map;

	if (id == 1)
	{
		x = 10;
		y = 20;
	}
	else
	{
		x = 10;
		y = 20;
	}
	map = make_map(base, x, y);
	if (validate_map(map, x, y))
		return (0);
	return (map);
} */
