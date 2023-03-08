/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:38:26 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/08 14:06:35 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Stops time for a bit and closes window*/
void	wait(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 32767)
	{
		j = 0;
		while (j < 32767)
			j++;
		i++;
	}
	close_window(data);
}

void	display_moves(t_data *data, int moves)
{
	char	*move;
	char	*count;
	int		s;

	s = P;
	count = ft_itoa(moves);
	move = ft_strjoin("Moves ", count);
	mlx_string_put(data->init, data->window, 4, 19, 0255000000, move);
	free (move);
	free (count);
	return ;
}

/*Handles regular cases and walking over the exit*/
void	step_cases(t_data *data, int x, int y)
{
	if (data->map[data->pos.x][data->pos.y] == 'E')
		mlx_put_image_to_window(data->init, data->window,
			data->images->player_closed, data->pos.y * P, data->pos.x * P);
	else if (data->map[data->pos.x][data->pos.y] == 'e')
	{
		mlx_put_image_to_window(data->init, data->window,
			data->images->player_open, data->pos.y * P, data->pos.x * P);
		ft_printf("You escaped the dungeon!\n");
	}
	else
		mlx_put_image_to_window(data->init, data->window,
			data->images->player, data->pos.y * P, data->pos.x * P);
}

/*Executes and counts movements, triggers exit opening*/
void	step(t_data *data, int x, int y)
{
	static int	moves;

	if (data->map[data->pos.x + x][data->pos.y + y] == '1')
		return ;
	if (data->map[data->pos.x + x][data->pos.y + y] == 'C')
	{
		data->map[data->pos.x + x][data->pos.y + y] = 'c';
		if (++data->found_coll == data->total_coll)
			open_exit(data);
	}
	if (data->map[data->pos.x][data->pos.y] == 'E')
		mlx_put_image_to_window(data->init, data->window,
			data->images->closed, data->pos.y * P, data->pos.x * P);
	else
		mlx_put_image_to_window(data->init, data->window,
			data->images->floor, data->pos.y * P, data->pos.x * P);
	data->pos.x += x;
	data->pos.y += y;
	ft_printf("Moves: %i\n", ++moves);
	display_moves(data, moves);
	step_cases(data, x, y);
	return ;
}
