/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:39:52 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/20 13:15:32 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Finds enemy movement direction*/
t_coord	get_dir(t_data *data)
{
	t_coord	dir;

	if (data->map[data->enemy_pos.x][data->enemy_pos.y - 1] != '1'
	&& data->map[data->enemy_pos.x][data->enemy_pos.y - 1] != 'C')
		dir = (t_coord){0, -1};
	else if (data->map[data->enemy_pos.x - 1][data->enemy_pos.y] != '1'
	&& data->map[data->enemy_pos.x - 1][data->enemy_pos.y] != 'C')
		dir = (t_coord){-1, 0};
	else if (data->map[data->enemy_pos.x][data->enemy_pos.y + 1] != '1'
	&& data->map[data->enemy_pos.x][data->enemy_pos.y + 1] != 'C')
		dir = (t_coord){0, 1};
	else if (data->map[data->enemy_pos.x + 1][data->enemy_pos.y] != '1'
	&& data->map[data->enemy_pos.x + 1][data->enemy_pos.y] != 'C')
		dir = (t_coord){1, 0};
	else
		dir = (t_coord){0, 0};
	return (dir);
}

/*Handles special cases for walking over exit*/
void	enemy_step_cases(t_data *data)
{
	if (data->map[data->enemy_pos.x][data->enemy_pos.y] == 'E')
		mlx_put_image_to_window(data->init, data->window,
			data->images2->enemy_closed, data->enemy_pos.y * P,
			data->enemy_pos.x * P);
	else if (data->map[data->enemy_pos.x][data->enemy_pos.y] == 'e')
		mlx_put_image_to_window(data->init, data->window,
			data->images2->enemy_open, data->enemy_pos.y * P,
			data->enemy_pos.x * P);
	else
		mlx_put_image_to_window(data->init, data->window,
			data->images2->enemy, data->enemy_pos.y * P, data->enemy_pos.x * P);
}

/*Handles enemy movement*/
void	enemy_step(t_data *data, t_coord dir)
{
	if (data->map[data->enemy_pos.x][data->enemy_pos.y] == 'E')
		mlx_put_image_to_window(data->init, data->window,
			data->images->closed, data->enemy_pos.y * P, data->enemy_pos.x * P);
	else if (data->map[data->enemy_pos.x][data->enemy_pos.y] == 'e')
		mlx_put_image_to_window(data->init, data->window,
			data->images->open, data->enemy_pos.y * P, data->enemy_pos.x * P);
	else
		mlx_put_image_to_window(data->init, data->window,
			data->images->floor, data->enemy_pos.y * P, data->enemy_pos.x * P);
	data->enemy_pos.x += dir.x;
	data->enemy_pos.y += dir.y;
	enemy_step_cases(data);
	return ;
}

int	test_step(t_data *data, int x, int y)
{
	if (data->map[data->enemy_pos.x + x][data->enemy_pos.y + y] == '1'
	|| data->map[data->enemy_pos.x + x][data->enemy_pos.y + y] == 'C')
		return (1);
	return (0);
}

/*Starts enemy movement logic*/
void	patrol(t_data *data)
{
	static t_coord	dir;
	int				test;

	if (data->map[data->pos.x][data->pos.y] == 'e'
		|| (data->pos.x == data->enemy_pos.x
		&& data->pos.y == data->enemy_pos.y))
		return ;
	if (!dir.x && !dir.y)
		dir = get_dir(data);
	test = test_step(data, dir.x, dir.y);
	if (!test)
	{
		enemy_step(data, dir);
		return ;
	}
	dir = get_dir(data);
	enemy_step(data, dir);
	return ;
}
