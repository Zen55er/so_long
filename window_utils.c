/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:38:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/06 14:20:58 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_event(void *ptr)
{
	return (0);
}

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
		ft_printf("UP\n");
	else if (key == XK_s)
		ft_printf("DOWN\n");
	else if (key == XK_a)
		ft_printf("LEFT\n");
	else if (key == XK_d)
		ft_printf("RIGHT\n");
	return (0);
}
