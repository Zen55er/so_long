/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/27 15:02:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		fd;
	t_coord	size;
	char	**map;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long PATH_TO_MAP\n"));
	if (check_ber(argv[1]))
		return (ft_printf("Map extension must be .ber"));
	fd = open(argv[1], O_RDONLY);
	size = get_map_size(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = maps(fd, size);
	close(fd);
	if (!map)
		ft_printf("MAP FAILED\n");
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
			ft_printf("%c", map[i][j]);
		ft_printf("\n");
	}
	free_map(map, 10);
	return (1);
}
