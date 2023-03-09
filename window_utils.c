/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:38:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/09 11:26:43 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*For mlx_loop logic, also keeps game open for a bit before closing*/
int	no_event(t_data *data)
{
	if (data->map[data->pos.x][data->pos.y] == 'e'
		|| (data->pos.x == data->enemy_pos.x
		&& data->pos.y == data->enemy_pos.y))
		wait(data);
	return (0);
}

/*Self explanatory*/
int	close_window(t_data *data)
{
	mlx_destroy_window(data->init, data->window);
	return (0);
}

/*Actions for key presses*/
int	key_release(int key, t_data *data)
{
	if (key == XK_Escape)
		close_window(data);
	else if (key == XK_w)
		step(data, -1, 0);
	else if (key == XK_s)
		step(data, 1, 0);
	else if (key == XK_a)
		step(data, 0, -1);
	else if (key == XK_d)
		step(data, 0, 1);
	return (0);
}

/*If all collectibles are found, opens exit*/
void	open_exit(t_data *data)
{
	t_coord	exit;

	exit = find_pos(data->map, data->size.x, data->size.y, 'E');
	mlx_put_image_to_window(data->init, data->window,
		data->images->open, exit.y * P, exit.x * P);
	data->map[exit.x][exit.y] = 'e';
	return ;
}
