/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/27 11:27:11 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		i;
	int		j;
	int		fd;
	char	*filename;
	char	**map;

	filename = "./maps/base_test.ber";
	fd = open(filename, O_RDONLY);
	map = maps(fd);
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
