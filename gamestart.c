/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamestart.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 22:36:01 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 13:09:24 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_coins(char *str)
{
	int	i;
	int	ret;

	ret = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			ret++;
		i++;
	}
	return (ret);
}

static void	get_player_pos(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
			{
				g->px = j;
				g->py = i;
			}
			j++;
		}
		i++;
	}
}

static void	spawn_monster(t_game *g)
{
	int	i;
	int	j;

	i = 1;
	while (g->map[i])
	{
		j = 1;
		while (g->map[i][j])
		{
			if (g->map[i][j] == '0')
			{
				g->map[i][j] = 'M';
				g->mx = j;
				g->my = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	starting(t_game *gm, char **argv)
{
	char	*map;
	int		i;

	i = 0;
	map = map_conv(argv[1]);
	gm->map = ft_split(map, '\n');
	free(map);
	gm->maxx = ft_strlen(gm->map[i]);
	gm->coll = 0;
	gm->colltoprint = 0;
	gm->mov = 0;
	gm->ms = 0;
	get_player_pos(gm);
	spawn_monster(gm);
	while (gm->map[i])
	{
		gm->coll += count_coins(gm->map[i]);
		i++;
	}
	gm->maxy = i;
	gm->mlxs.mlx = mlx_init();
	gm->mlxs.window = mlx_new_window(gm->mlxs.mlx, (gm->maxx) * TILE_SZ,
			(i) * TILE_SZ, "so_long window");
	set_images(gm);
	return (1);
}

void	set_images(t_game *gm)
{
	void	*ptr;

	ptr = gm->mlxs.mlx;
	gm->img.ncoll = 0;
	gm->img.h = 64;
	gm->img.l = 64;
	gm->img.wall = mlx_xpm_file_to_image(ptr, "xpm/wall.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.floor = mlx_xpm_file_to_image(ptr, "xpm/floor.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.coll[0] = mlx_xpm_file_to_image(ptr, "xpm/coll1.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.coll[1] = mlx_xpm_file_to_image(ptr, "xpm/coll2.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.exit[0] = mlx_xpm_file_to_image(ptr, "xpm/exit1.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.exit[1] = mlx_xpm_file_to_image(ptr, "xpm/exit2.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.player = mlx_xpm_file_to_image(ptr, "xpm/player.xpm",
			&(gm->img.l), &(gm->img.h));
	gm->img.enemy = mlx_xpm_file_to_image(ptr, "xpm/enemy.xpm",
			&(gm->img.l), &(gm->img.h));
}
