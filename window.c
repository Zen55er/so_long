/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:34:08 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/01 14:58:38 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates initial window*/
void	startup(void)
{
	void	*init;
	void	*window;

	init = mlx_init();
	if (!init)
		return (1);
	window = mlx_new_window(init, 1600, 900, "Initial");
	if (!window)
		return (1);
	mlx_loop(init);
	mlx_destroy_window(init, window);
	mlx_destroy_display(init);
	free(init);
	return ;
}
