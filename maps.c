/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:02:37 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/24 10:31:36 by gacorrei         ###   ########.fr       */
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
	ft_printf("MAP AFTER FILLING EVERY ROW, BEFORE RETURN\n");
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
char	**make_map(char **base, int x, int y)
{
	int		xi;
	int		yi;
	char	**map;

	xi = 0;
	map = (char **)malloc(sizeof(char *) * x);
	if (!map)
		return (0);
	while (xi < x)
	{
		map[xi] = (char *)malloc(sizeof(char) * (y + 1));
		if (!map[xi])
			return (free_map(map, xi));
		yi = 0;
		while (yi < y)
		{
			map[xi][yi] = base[xi][yi];
			yi++;
		}
		map[xi][yi] = '\0';
		xi++;
	}
	return (map);
}

/*Validates map parameters*/
int	validate_map(char **map, int x, int y)
{
	t_coord	start;
	t_coord	size;
	t_coord	chars;

	if (!check_values(map, x, y))
	{
		ft_printf("FOUND FORBIDDEN VALUE\n");
		return (0);
	}
	if (!check_boundary(map, x, y))
	{
		ft_printf("FOUND BORDER WITH VALUE OTHER THAN 1\n");
		return (0);
	}
	if (check_pec(map, x, y) != 1)
		return (0);
	start = find_start(map, x, y);
	size.x = x;
	size.y = y;
	chars.x = 48;
	chars.y = 67;
	if (!check_path(map, size, start, chars))
		return (0);
	return (1);
}

/*Chooses baseline for map to use, sets size and call map generating function*/
char	**maps(int id)
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
	if (!validate_map(map, x, y))
		return (0);
	return (map);
}
