/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 09:39:52 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/09 13:04:09 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Counts number of enemy entities (There can only be one)*/
int	count_enemies(char **map, int x, int y)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = -1;
	while (++i < x)
	{
		j = -1;
		while (++j < y)
		{
			if (map[i][j] == 'B')
				count++;
		}
	}
	if (count > 1)
		return (1);
	else
		return (0);
}

/*Finds enemy movement direction*/
int	get_dir(t_data *data)
{
	int	dir;

	if (data->map[data->enemy_pos.x][data->enemy_pos.y - 1] == '0'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y - 1] == 'B'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y - 1] == 'E'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y - 1] == 'e')
		dir = 1;
	else if (data->map[data->enemy_pos.x - 1][data->enemy_pos.y] == '0'
	|| data->map[data->enemy_pos.x - 1][data->enemy_pos.y] == 'B'
	|| data->map[data->enemy_pos.x - 1][data->enemy_pos.y] == 'E'
	|| data->map[data->enemy_pos.x - 1][data->enemy_pos.y] == 'e')
		dir = 3;
	else if (data->map[data->enemy_pos.x][data->enemy_pos.y + 1] == '0'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y + 1] == 'B'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y + 1] == 'E'
	|| data->map[data->enemy_pos.x][data->enemy_pos.y + 1] == 'e')
		dir = 2;
	else if (data->map[data->enemy_pos.x + 1][data->enemy_pos.y] == '0'
	|| data->map[data->enemy_pos.x + 1][data->enemy_pos.y] == 'B'
	|| data->map[data->enemy_pos.x + 1][data->enemy_pos.y] == 'E'
	|| data->map[data->enemy_pos.x + 1][data->enemy_pos.y] == 'e')
		dir = 4;
	else
		dir = 0;
	return (dir);
}

/*Handles special cases for walking over exit*/
void	enemy_step_cases(t_data *data, int x, int y)
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
void	enemy_step(t_data *data, int x, int y)
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
	data->enemy_pos.x += x;
	data->enemy_pos.y += y;
	enemy_step_cases(data, x, y);
	return ;
}

/*Starts enemy movement logic*/
void	patrol(t_data *data)
{
	int	dir;

	if (data->map[data->pos.x][data->pos.y] == 'e'
		|| (data->pos.x == data->enemy_pos.x
		&& data->pos.y == data->enemy_pos.y))
		return ;
	dir = get_dir(data);
	if (dir == 1)
		enemy_step(data, 0, -1);
	else if (dir == 2)
		enemy_step(data, 0, 1);
	else if (dir == 3)
		enemy_step(data, -1, 0);
	else if (dir == 4)
		enemy_step(data, 1, 0);
	return ;
}
