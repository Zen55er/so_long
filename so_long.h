/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:45:43 by gacorrei          #+#    #+#             */
/*   Updated: 2023/02/27 14:48:58 by gacorrei         ###   ########.fr       */
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
char	**make_map(int fd, int x, int y);
void	reset_vals(char **map, int x, int y);
t_coord	find_pos(char **map, int x, int y, char c);
int		validate_map(char **map, int x, int y);
char	**maps(int id, t_coord size);

/*validate_map*/
int		check_rectangle(char **map, int x, int y);
int		check_values(char **map, int x, int y);
int		check_boundary(char **map, int x, int y);
int		check_pec(char **map, int x, int y);
void	check_path(char **map, t_coord size, t_coord start);

/*utils*/
char	**free_map(char **map, int xi);
int		check_coll(char **map, int x, int y);
int		check_ber(char *filename);
t_coord	get_map_size(int fd);

#endif