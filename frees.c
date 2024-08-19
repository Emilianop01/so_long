/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:57:46 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 15:21:10 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_exit(char **map)
{
	int	i;

	i = 0;
	if (*map != NULL)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (-1);
}

int	quit_map2(t_game *g)
{
	quit_map(g, "See U <3\n");
	return (0);
}

int	quit_map(t_game *game, char *s)
{
	if (game->map)
	{
		mlx_destroy_window(game->mlxs.mlx, game->mlxs.window);
		mlx_destroy_image(game->mlxs.mlx, game->img.coll[0]);
		mlx_destroy_image(game->mlxs.mlx, game->img.coll[1]);
		mlx_destroy_image(game->mlxs.mlx, game->img.enemy);
		mlx_destroy_image(game->mlxs.mlx, game->img.wall);
		mlx_destroy_image(game->mlxs.mlx, game->img.floor);
		mlx_destroy_image(game->mlxs.mlx, game->img.exit[0]);
		mlx_destroy_image(game->mlxs.mlx, game->img.exit[1]);
		mlx_destroy_image(game->mlxs.mlx, game->img.player);
		mlx_destroy_display(game->mlxs.mlx);
		free(game->mlxs.mlx);
		free_exit(game->map);
	}
	ft_putstr_fd(s, 1);
	exit (0);
	return (1);
}
