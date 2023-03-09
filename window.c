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
