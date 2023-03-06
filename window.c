/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:34:08 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 11:42:46 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates game window*/
int	startup(char **map)
{
	t_data		data;
	t_sprites	*images;

	data.init = mlx_init();
	if (!data.init)
		return (1);
	data.window = mlx_new_window(data.init, 800, 450, "So_long");
	if (!data.window)
		return (free_all(data, images, 1, 0));
	if (!open_images(data.init, images))
		return (free_all(data, images, 1, 1));
	draw_start(data, images, map);
	mlx_loop_hook(data.init, no_event, &data);
	mlx_hook(data.window, 2, 1L << 0, key_release, &data);
	mlx_hook(data.window, 17, 1L << 0, close_window, &data);
	mlx_loop(data.init);
	return (free_all(data, images, 1, 1));
}
