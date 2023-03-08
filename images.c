/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:46:35 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/08 13:48:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Opens image files to memory*/
int	open_images(t_data *data)
{
	t_sprites	*image;
	int			s;

	s = P;
	image = (t_sprites *)malloc(sizeof(t_sprites));
	if (!image)
		return (0);
	image->floor = mlx_xpm_file_to_image(data->init,
			"./images/floor.xpm", &s, &s);
	image->wall = mlx_xpm_file_to_image(data->init,
			"./images/wall.xpm", &s, &s);
	image->closed = mlx_xpm_file_to_image(data->init,
			"./images/closed.xpm", &s, &s);
	image->open = mlx_xpm_file_to_image(data->init,
			"./images/open.xpm", &s, &s);
	image->collect = mlx_xpm_file_to_image(data->init,
			"./images/coll.xpm", &s, &s);
	image->player = mlx_xpm_file_to_image(data->init,
			"./images/player.xpm", &s, &s);
	image->player_closed = mlx_xpm_file_to_image(data->init,
			"./images/player_closed.xpm", &s, &s);
	image->player_open = mlx_xpm_file_to_image(data->init,
			"./images/player_open.xpm", &s, &s);
	data->images = image;
	return (1);
}

int	open_images2(t_data *data)
{
	t_sprites2	*image;
	int			s;

	s = P;
	image = (t_sprites2 *)malloc(sizeof(t_sprites2));
	if (!image)
		return (0);
	image->l_counter = mlx_xpm_file_to_image(data->init,
			"./images/l_counter.xpm", &s, &s);
	image->r_counter = mlx_xpm_file_to_image(data->init,
			"./images/r_counter.xpm", &s, &s);
	data->images2 = image;
	return (1);
}

/*Chooses which image to use for each position in the map*/
void	choose_image(t_data *data, t_coord pos, char **map)
{
	if (map[pos.x][pos.y] == '0')
		mlx_put_image_to_window(data->init, data->window,
			data->images->floor, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == '1')
		mlx_put_image_to_window(data->init, data->window,
			data->images->wall, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'P')
		mlx_put_image_to_window(data->init, data->window,
			data->images->player, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'E')
		mlx_put_image_to_window(data->init, data->window,
			data->images->closed, pos.y * P, pos.x * P);
	else if (map[pos.x][pos.y] == 'C')
		mlx_put_image_to_window(data->init, data->window,
			data->images->collect, pos.y * P, pos.x * P);
	return ;
}

/*Iterates through map positions to draw correct image*/
void	draw_start(t_data *data, char **map)
{
	int	x;
	int	y;

	x = -1;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
			choose_image(data, (t_coord){x, y}, map);
	}
	mlx_put_image_to_window(data->init, data->window,
		data->images2->l_counter, 0, 0);
	mlx_put_image_to_window(data->init, data->window,
		data->images2->r_counter, P, 0);
	return ;
}
