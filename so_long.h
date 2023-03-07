/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gacorrei <gacorrei@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:45:43 by gacorrei          #+#    #+#             */
/*   Updated: 2023/03/07 09:26:00 by gacorrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/keysym.h>
# include "../libft_new/libft.h"
# include "./mlx_linux/mlx.h"

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct s_sprites
{
	void		*floor;
	void		*wall;
	void		*closed;
	void		*open;
	void		*collect;
	void		*player;
}				t_sprites;

typedef struct s_data
{
	void		*init;
	void		*window;
	t_sprites	*images;
	char		**map;
	t_coord		*start;
}				t_data;

/*Sprite size (32 pix)*/
# define P 32

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
t_coord	get_map_size(int fd);
int		check_coll(char **map, int x, int y);

/*window*/
int		startup(char **map);

/*window_utils*/
int		no_event(void *ptr);
int		close_window(t_data *data);
int		key_release(int key, t_data *data);

/*images*/
int		open_images(t_data *data);
void	choose_image(t_data *data, t_coord pos, char **map);
void	draw_start(t_data *data, char **map);

/*utils_free*/
char	**free_map(char **map, int xi);
int		free_window(t_data *data);
void	free_image(t_data *data);
int		free_all(t_data *data, int window, int images);

#endif