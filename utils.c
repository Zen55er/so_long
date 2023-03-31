/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:28:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/31 12:04:56 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*CHecks the final chars of the filename to make sure the extension is .ber*/
int	check_ber(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (1);
	return (0);
}

/*Calculates height and width of selected map*/
t_coord	get_map_size(int fd)
{
	int		buf;
	t_coord	size;
	char	buffer[2];

	size.x = 0;
	size.y = 0;
	buf = 1;
	while (buf > 0)
	{
		buf = read(fd, buffer, 1);
		if (buf == -1)
			return (size);
		buffer[1] = '\0';
		if (size.x == 0 && buffer[0] != '\n')
			size.y++;
		if (buffer[0] == '\n')
			size.x++;
	}
	size.x++;
	return (size);
}

/*Checks if there is any collectible that could not be reached*/
int	check_coll(char **map, int x, int y)
{
	int	j;

	while (--x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[x][j] == 'C')
				return (0);
		}
	}
	return (1);
}

/*Counts number of collectibles*/
int	count_coll(char **map, int x, int y)
{
	int	j;
	int	total;

	total = 0;
	while (--x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[x][j] == 'C')
				total++;
		}
	}
	return (total);
}

/*Counts number of enemy entities (There can only be one)*/
int	count_enemies(char **map, int x, int y)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[i][j] == 'B')
				count++;
		}
	}
	if (count > 1)
		return (1);
	else
		return (0);
}
