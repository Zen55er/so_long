/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:34:08 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/03 11:56:08 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates initial window*/
int	startup(void)
{
	t_data	data;

	data.init = mlx_init();
	if (!data.init)
		return (1);
	data.window = mlx_new_window(data.init, 1600, 900, "Initial");
	if (!data.window)
		return (free_window(data.init));
	mlx_loop_hook(data.init, &no_event, &data);
	mlx_key_hook(data.window, &key_press, &data);
	mlx_loop(data.init);
	return (free_window(data.init));
}
