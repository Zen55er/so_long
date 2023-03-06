/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:46:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 13:39:06 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Opens image files to memory*/
int	open_images(void *init, t_sprites **images)
{
	t_sprites	*image;
	int			s;

	s = P;
	image = (t_sprites *)malloc(sizeof(t_sprites));
	if (!image)
		return (0);
	image->floor = mlx_xpm_file_to_image(init, "./images/floor.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(init, "./images/wall.xpm", &s, &s);
	image->closed = mlx_xpm_file_to_image(init, "./images/closed.xpm", &s, &s);
	image->open = mlx_xpm_file_to_image(init, "./images/open.xpm", &s, &s);
	image->collect = mlx_xpm_file_to_image(init, "./images/coll.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(init, "./images/player.xpm", &s, &s);
	*images = image;
	return (1);
}

/*Chooses which image to use for each position in the map*/
void	choose_image(t_data data, t_sprites *images, t_coord pos, char **map)
{
	if (map[pos.x][pos.y] == '0')
		mlx_put_image_to_window(data.init, data.window,
			images->floor, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == '1')
		mlx_put_image_to_window(data.init, data.window,
			images->wall, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'P')
		mlx_put_image_to_window(data.init, data.window,
			images->player, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'E')
		mlx_put_image_to_window(data.init, data.window,
			images->closed, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'C')
		mlx_put_image_to_window(data.init, data.window,
			images->collect, pos.y * P, pos.x * P);
	return ;
}

/*Iterates through map positions to draw correct image*/
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
