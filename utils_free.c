/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:30:24 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:19:48 by gacorrei         ###   ########.fr       */
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
int	free_window(t_data data)
{
	mlx_destroy_display(data.init);
	free(data.init);
}

/*Frees images*/
void	free_image(void *init, t_sprites *image)
{
	if (image->floor)
		mlx_destroy_image(init, image->floor);
	if (image->wall)
		mlx_destroy_image(init, image->wall);
	if (image->closed)
		mlx_destroy_image(init, image->closed);
	if (image->open)
		mlx_destroy_image(init, image->open);
	if (image->collect)
		mlx_destroy_image(init, image->collect);
	if (image->player)
		mlx_destroy_image(init, image->player);
	free (image);
	return ;
}

/*Gets ifo on what to free and calls appropriate functions*/
int	free_all(t_data data, t_sprites *image, int window, int images)
{
	if (images)
		free_image(data.init, image);
	if (window)
		free_window(data);
	return (1);
}
