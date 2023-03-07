/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:38:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/07 09:58:49 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step(t_data *data, int x, int y)
{
	mlx_put_image_to_window(data->init, data->window,
		data->images->floor, data->pos.x * P, data->pos.y * P);
	data->pos.x += y;
	data->pos.y += x;
	mlx_put_image_to_window(data->init, data->window,
		data->images->player, data->pos.x * P, data->pos.y * P);
	return ;
}
