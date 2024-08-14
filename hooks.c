/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:34:03 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/14 17:22:13 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

long long	get_time(void)
{
	struct timeval	time;
	long long		millitime;

	gettimeofday(&time, NULL);
	millitime = time.tv_sec * 1000LL + time.tv_usec / 1000;
	return (millitime);
}

void	get_milliseconds(t_game *g)
{
	long long	new;

	new = get_time();
	g->ms = new;
}

static void	print_moves(t_game *g)
{
	char	*mosse;

	mosse = ft_itoa(g->mov);
	mlx_string_put(g->mlxs.mlx, g->mlxs.window, 32, 32, 0xFFFF00, "Mosse : ");
	mlx_string_put(g->mlxs.mlx, g->mlxs.window, 80, 32, 0xFFFF00, mosse);
	free(mosse);
}

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

int	print_map(t_game *g)
{
	long long	milliseconds;
	long long	difference;

	milliseconds = get_time();
	difference = milliseconds - g->ms;
	if (difference >= 90)
	{
		get_milliseconds(g);
		g->colltoprint = (g->colltoprint + 1) % 2;
		print_map_call(g);
	}
	return (0);
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

static void	move_monster(t_game *g)
{
	static int	dir;

	if (g->map[g->my][g->mx + 1] != '1'
		&& g->map[g->my][g->mx + 1] != 'E'
		&& g->map[g->my][g->mx + 1] != 'C' && dir)
	{
		g->map[g->my][g->mx] = '0';
		g->map[g->my][g->mx + 1] = 'M';
		g->mx += 1;
	}
	else if (g->map[g->my][g->mx - 1] != '1'
		&& g->map[g->my][g->mx - 1] != 'E'
		&& g->map[g->my][g->mx - 1] != 'C' && dir == 0)
	{
		g->map[g->my][g->mx] = '0';
		g->map[g->my][g->mx - 1] = 'M';
		g->mx -= 1;
	}
	else
	{
		dir++;
		if (g->map[g->my][g->mx + 1] == '1')
			dir = 0;
		move_monster(g);
	}
}

int	move(t_game *g, int plusx, int plusy)
{
	char	newpos;

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
		|| ((g->px - plusx) == g->mx && g->py == g->my))
		quit_map(g, "Skill Issue\n");
	if (newpos == 'E')
		quit_map(g, "Daje Sei Forte\n");
	if (newpos == 'C')
		g->img.ncoll++;
	return (1);
}

int	key_map(int keycode, t_game *game)
{
	if (keycode == 119 || keycode == 65362)
		return (move(game, 0, -1));
	else if (keycode == 115 || keycode == 65364)
		return (move(game, 0, +1));
	else if (keycode == 97 || keycode == 65361)
		return (move(game, -1, 0));
	else if (keycode == 100 || keycode == 65363)
		return (move(game, +1, 0));
	else if (keycode == 65307)
		return (quit_map(game, "\n"));
	else
		return (1);
}