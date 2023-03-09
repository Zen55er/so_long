/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:30:24 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/09 11:40:12 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Frees each line in the map and then the map itself*/
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

/*Frees mlx window*/
int	free_window(t_data *data)
{
	mlx_destroy_display(data->init);
	free(data->init);
}

/*Frees images*/
void	free_image(t_data *data)
{
	if (data->images->floor)
		mlx_destroy_image(data->init, data->images->floor);
	if (data->images->wall)
		mlx_destroy_image(data->init, data->images->wall);
	if (data->images->closed)
		mlx_destroy_image(data->init, data->images->closed);
	if (data->images->open)
		mlx_destroy_image(data->init, data->images->open);
	if (data->images->collect)
		mlx_destroy_image(data->init, data->images->collect);
	if (data->images->player)
		mlx_destroy_image(data->init, data->images->player);
	if (data->images->player_open)
		mlx_destroy_image(data->init, data->images->player_open);
	if (data->images->player_closed)
		mlx_destroy_image(data->init, data->images->player_closed);
	free (data->images);
	return ;
}

void	free_image2(t_data *data)
{
	if (data->images2->l_counter)
		mlx_destroy_image(data->init, data->images2->l_counter);
	if (data->images2->r_counter)
		mlx_destroy_image(data->init, data->images2->r_counter);
	if (data->images2->enemy)
		mlx_destroy_image(data->init, data->images2->enemy);
	if (data->images2->enemy_closed)
		mlx_destroy_image(data->init, data->images2->enemy_closed);
	if (data->images2->enemy_open)
		mlx_destroy_image(data->init, data->images2->enemy_open);
	if (data->images2->dead)
		mlx_destroy_image(data->init, data->images2->dead);
	free (data->images2);
	return ;
}

/*Gets ifo on what to free and calls appropriate functions*/
int	free_all(t_data *data, int window, int images, int images2)
{
	if (images)
		free_image(data);
	if (images2)
		free_image2(data);
	if (window)
		free_window(data);
	return (1);
}
