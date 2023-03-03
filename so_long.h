/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:45:43 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/03 15:10:47 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>>
# include "../libft_new/libft.h"
# include "./mlx_linux/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_data
{
	void		*init;
	void		*window;
}				t_data;

/*Key definitions*/
# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define MOUSE_LEFT		100

/*maps*/
char	**make_map(int fd, int x);
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
int		check_ber(char *filename);
char	**free_map(char **map, int xi);
int		free_window(void *init);
t_coord	get_map_size(int fd);
int		check_coll(char **map, int x, int y);
//void	print_map(char **map, int x, int y);

/*window*/
int		startup(void);

/*window_utils*/
int		no_event(void *ptr);
int		close_window(t_data *data);
int		key_release(int key, t_data *data);
int		mouse(int button, int x, int y, t_data *data);

#endif