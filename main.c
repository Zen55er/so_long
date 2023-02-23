/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:11 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/23 11:56:27 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	int		i;
	int		j;
	char	**map;

	map = maps(1);
	if (!map)
		ft_printf("MAP FAILED\n");
	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 20)
			ft_printf("%i", map[i][j]);
		ft_printf("\n");
	}
	return (1);
}
