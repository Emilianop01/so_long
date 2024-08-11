/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 15:10:34 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/11 17:19:45 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG
# define SO_LONG
# define TILE_SZ 64
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_item
{
	void	*img;
	int		mapx;
	int		mapy;
}	t_item;

typedef	struct s_img
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
	int		maxx;
	int		maxy;
	char	**map;
	int		coll;
	int		colltoprint;
	int		px;
	int		py;
	t_item	p;
	t_item	e;
	t_item	c;
	t_img	img;
	t_mlxs	mlxs;
	int		mov;
}	t_game;

int		file_ext(char *map);
char	*map_conv(char *file);
int		validate(int argc, char **argv);
int		check_map(char **map, int lenx, int leny);
int		check_char(char c, int *flag);
int		flood_setup(char **map, int leny, int lenx);
void	flood_fill(char **map, int py, int px, int *l);
int		free_exit(char **map);
int		quit_map(t_game *game, char *message);
int		count_coins(char *str);
int		starting(t_game *gm, char **argv);
void	set_images(t_game *gm);
int		key_map(int keycode, t_game *game);
int		main(int argc, char **argv);
int		print_map(t_game *g);


#endif