/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 18:00:22 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/14 21:50:33 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (validate(argc, argv) != 1)
		return (quit_map(&game, "Error\nMappa non valida\n"));
	starting(&game, argv);
	mlx_key_hook(game.mlxs.window, key_map, &game);
	mlx_hook(game.mlxs.window, 17, 0, quit_map2, &game);
	mlx_loop_hook(game.mlxs.mlx, print_map, &game);
	mlx_loop(game.mlxs.mlx);
	return (0);
}
