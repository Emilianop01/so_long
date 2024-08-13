/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:45:05 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:46:32 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TILE_SZ 64
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*coll[2];
	void	*exit[2];
	void	*enemy;
	void	*player;
	int		ncoll;
	int		h;
	int		l;
}	t_img;

typedef struct s_mlxs
{
	void	*mlx;
	void	*window;
}	t_mlxs;

typedef struct s_game
{
	int			maxx;
	int			maxy;
	char		**map;
	int			coll;
	int			colltoprint;
	int			px;
	int			py;
	int			mx;
	int			my;
	t_img		img;
	t_mlxs		mlxs;
	int			mov;
	long long	ms;
}	t_game;

int			file_ext(char *map);
char		*map_conv(char *file);
int			validate(int argc, char **argv);
int			check_map(char **map, int lenx, int leny);
int			check_char(char c, int *flag);
int			flood_setup(char **map, int leny, int lenx);
void		flood_fill(char **map, int py, int px, int *l);
int			free_exit(char **map);
int			quit_map(t_game *game, char *message);
int			count_coins(char *str);
int			starting(t_game *gm, char **argv);
void		set_images(t_game *gm);
int			key_map(int keycode, t_game *game);
int			main(int argc, char **argv);
int			print_map(t_game *g);
void		print_map_call(t_game *g);
long long	get_time(void);
void		get_milliseconds(t_game *g);

#endif
