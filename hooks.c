/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:34:03 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 15:59:44 by epiacent         ###   ########.fr       */
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

void	print_moves(t_game *g)
{
	char	*mosse;

	mosse = ft_itoa(g->mov);
	mlx_string_put(g->mlxs.mlx, g->mlxs.window, 32, 40, 0xFFFF00, "Mosse : ");
	mlx_string_put(g->mlxs.mlx, g->mlxs.window, 80, 40, 0xFFFF00, mosse);
	free(mosse);
}
