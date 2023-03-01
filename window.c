/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 12:34:08 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/01 12:43:26 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Creates initial window*/
void	startup(void)
{
	void	*init;
	void	*window;

	init = mlx_init();
	window = mlx_new_window(init, 1600, 900, "Initial");
	mlx_loop(init);
	return ;
}
