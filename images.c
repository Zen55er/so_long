/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:46:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 12:04:23 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Opens image files to memory*/
int	open_images(void *init, t_sprites *images)
{
	images = (t_sprites *)malloc(sizeof(t_sprites));
	if (!images)
		return (0);
	images->floor = mlx_xpm_file_to_image(init, "./images/floor.xpm", P, P);
	images->wall = mlx_xpm_file_to_image(init, "./images/wall.xpm", P, P);
	images->closed = mlx_xpm_file_to_image(init, "./images/closed.xpm", P, P);
	images->open = mlx_xpm_file_to_image(init, "./images/open.xpm", P, P);
	images->collect = mlx_xpm_file_to_image(init, "./images/collect.xpm", P, P);
	images->player = mlx_xpm_file_to_image(init, "./images/player.xpm", P, P);
}

/*Chooses which image to use for each position in the map*/
void	choose_image(t_data data, t_sprites *images, t_coord pos, char **map)
{
	if (map[pos.x][pos.y] == '0')
		mlx_put_image_to_window(data.init, data.window,
			images->floor, pos.x * P, pos.y * P);
	else if (map[pos.x][pos.y] == '1')
		mlx_put_image_to_window(data.init, data.window,
			images->wall, pos.x * P, pos.y * P);
	else if (map[pos.x][pos.y] == 'P')
		mlx_put_image_to_window(data.init, data.window,
			images->player, pos.x * P, pos.y * P);
	else if (map[pos.x][pos.y] == 'E')
		mlx_put_image_to_window(data.init, data.window,
			images->closed, pos.x * P, pos.y * P);
	else if (map[pos.x][pos.y] == 'C')
		mlx_put_image_to_window(data.init, data.window,
			images->collect, pos.x * P, pos.y * P);
	return ;
}

/*Iterates through map positions to draw appropriate image*/
void	draw_start(t_data data, t_sprites *images, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
			choose_image(data, images, (t_coord){x, y}, map);
	}
	return ;
}
