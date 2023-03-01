/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   baseline_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:02:10 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/01 14:20:13 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mlx-linux/mlx.h"
#include <stdlib.h>

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (1);
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "My first window!");
	if (win_ptr == NULL)
	{
		free(win_ptr);
		return (1);
	}
	while (1)
		;
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
