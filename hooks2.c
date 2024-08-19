/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 15:27:55 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 16:00:59 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *g, int x, int y)
{
	void	*img;

	if (g->map[y][x] == 'P')
		img = g->img.player;
	else if (g->map[y][x] == 'C')
		img = g->img.coll[g->colltoprint];
	else if (g->map[y][x] == 'E')
		img = g->img.exit[g->coll == g->img.ncoll];
	else if (g->map[y][x] == 'M')
		img = g->img.enemy;
	else if (g->map[y][x] == '0')
		img = g->img.floor;
	else
		img = g->img.wall;
	mlx_put_image_to_window(g->mlxs.mlx, g->mlxs.window,
		img, x * TILE_SZ, y * TILE_SZ);
}

void	change_dir(t_game *g, int *dir)
{
	*dir = 1;
	if (g->map[g->my][g->mx + 1] == '1')
		*dir = 0;
}

static void	move_monster(t_game *g)
{
	static int	dir;

	if (g->map[g->my][g->mx + 1] != '1' && g->map[g->my][g->mx + 1] != 'E'
		&& g->map[g->my][g->mx + 1] != 'C' && dir)
	{
		g->map[g->my][g->mx] = '0';
		g->map[g->my][g->mx + 1] = 'M';
		g->mx += 1;
		return ;
	}
	else if (g->map[g->my][g->mx - 1] != '1' && g->map[g->my][g->mx - 1] != 'E'
		&& g->map[g->my][g->mx - 1] != 'C' && dir == 0)
	{
		g->map[g->my][g->mx] = '0';
		g->map[g->my][g->mx - 1] = 'M';
		g->mx -= 1;
		return ;
	}
	else if ((g->map[g->my][g->mx - 1] == '1' || g->map[g->my][g->mx - 1] == 'E'
		|| g->map[g->my][g->mx - 1] == 'C') && (g->map[g->my][g->mx + 1] == '1'
		|| g->map[g->my][g->mx + 1] == 'E' || g->map[g->my][g->mx + 1] == 'C'))
		return ;
	change_dir(g, &dir);
	move_monster(g);
}

int	move(t_game *g, int plusx, int plusy)
{
	char	newpos;

	newpos = 0;
	if (g->map[g->py + plusy][g->px + plusx] != '1'
		&& (g->map[g->py + plusy][g->px + plusx] != 'E'
		|| g->coll == g->img.ncoll))
	{
		g->mov++;
		g->map[g->py][g->px] = '0';
		if (g->mov % 2 == 1)
			move_monster(g);
		newpos = g->map[g->py + plusy][g->px + plusx];
		g->map[g->py + plusy][g->px + plusx] = 'P';
		g->py += plusy;
		g->px += plusx;
		print_map_call(g);
	}
	if (newpos == 'M'
		|| ((g->px) == g->mx && g->py == g->my))
		quit_map(g, "Skill Issue\n");
	if (newpos == 'E')
		quit_map(g, "Daje Sei Forte\n");
	if (newpos == 'C')
		g->img.ncoll++;
	return (1);
}

void	print_map_call(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (g->map[y])
	{
		x = 0;
		while (g->map[y][x])
		{
			put_image(g, x, y);
			x++;
		}
		y++;
	}
	print_moves(g);
}
