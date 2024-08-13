/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:57:46 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/13 22:28:36 by epiacent         ###   ########.fr       */
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

void	quit_map(t_game *game, char *s)
{
	ft_putstr_fd(s, 1);
	free_exit(game->map);
	exit (0);
}
