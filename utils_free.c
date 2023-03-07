/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:30:24 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/07 09:18:43 by gacorrei         ###   ########.fr       */
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
	free (data->images);
	return ;
}

/*Gets ifo on what to free and calls appropriate functions*/
int	free_all(t_data *data, int window, int images)
{
	if (images)
		free_image(data);
	if (window)
		free_window(data);
	return (1);
}
