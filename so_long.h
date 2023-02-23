/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:45:43 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/23 12:15:31 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft_new/libft.h"
# include "../mlx-linux/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

/*maps*/
char	**free_map(char **map, int xi);
char	**make_map(char **base, int x, int y);
char	**maps(int id);
int		validate_map(char **map, int x, int y);

/*validate_map*/
int		check_values(char **map, int x, int y);
int		check_boundary(char **map, int x, int y);
int		check_pec(char **map, int x, int y);
t_coord	find_start(char **map, int x, int y);
int		check_path(char **map, t_coord size, t_coord start, t_coord chars);

#endif