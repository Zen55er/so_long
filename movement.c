/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:38:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/07 10:58:39 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Executes and counts movements, triggers exit opening*/
void	step(t_data *data, int x, int y)
{
	static int	moves;

	if (data->map[data->pos.x + x][data->pos.y + y] == '1'
		|| data->map[data->pos.x + x][data->pos.y + y] == 'E')
		return ;
	if (data->map[data->pos.x + x][data->pos.y + y] == 'C')
	{
		data->map[data->pos.x + x][data->pos.y + y] = 'c';
		if (data->++found_coll == data->total_coll)
			open_exit(data);
	}
	mlx_put_image_to_window(data->init, data->window,
		data->images->floor, data->pos.y * P, data->pos.x * P);
	data->pos.x += x;
	data->pos.y += y;
	ft_printf("Moves: %i\n", ++moves);
	if (data->map[data->pos.x][data->pos.y] == 'e')
	{
		mlx_put_image_to_window(data->init, data->window,
			data->images->end, data->pos.y * P, data->pos.x * P);
		return ;
	}
		mlx_put_image_to_window(data->init, data->window,
			data->images->player, data->pos.y * P, data->pos.x * P);
	return ;
}
