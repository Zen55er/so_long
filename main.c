/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/01 11:53:52 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_coord	size;
	char	**map;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long PATH_TO_MAP\n"));
	if (check_ber(argv[1]))
		return (ft_printf("Map extension must be .ber\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf("File does not exist\n"));
	size = get_map_size(fd);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map = maps(fd, size);
	close(fd);
	if (!map)
		return (0);
	free_map(map, size.x - 1);
	return (1);
}
