/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:34:08 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/09 10:03:04 by gacorrei         ###   ########.fr       */
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

/*Creates window and runs game*/
int	startup(char **map, t_coord size)
{
	t_data		data;

	if (size.y * P > 1920 || size.x * P > 1080)
		return (ft_printf("Error\nMap is too big to fit in window.\n"));
	data.init = mlx_init();
	if (!data.init)
		return (1);
	data.window = mlx_new_window(data.init, size.y * P, size.x * P, "So_long");
	if (!data.window)
		return (free_all(&data, 1, 0, 0));
	if (!open_images(&data) || !open_images2(&data))
		return (free_all(&data, 1, 0, 0));
	data.map = map;
	data.pos = find_pos(data.map, size.x, size.y, 'P');
	data.enemy_pos = find_pos(data.map, size.x, size.y, 'B');
	data.size = size;
	data.total_coll = count_coll(data.map, size.x, size.y);
	data.found_coll = 0;
	draw_start(&data, map);
	mlx_loop_hook(data.init, no_event, &data);
	mlx_hook(data.window, 2, 1L << 0, key_release, &data);
	mlx_hook(data.window, 17, 1L << 0, close_window, &data);
	mlx_loop(data.init);
	return (free_all(&data, 1, 1, 1));
}
