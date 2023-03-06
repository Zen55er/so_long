/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 11:14:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_coord	size;
	char	**map;

	if (argc != 2)
		return (ft_printf("Error\nUsage: ./so_long PATH_TO_MAP\n"));
	if (check_ber(argv[1]))
		return (ft_printf("Error\nMap extension must be .ber\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("Error\nFile does not exist\n"));
	size = get_map_size(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = maps(fd, size);
	close(fd);
	if (!map)
		return (0);
	startup(map);
	free_map(map, size.x - 1);
	return (1);
}
