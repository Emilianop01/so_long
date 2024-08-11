/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 20:57:46 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/11 17:20:42 by epiacent         ###   ########.fr       */
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

int	quit_map(t_game *game, char *message)
{
	(void)game;
	(void)message;
	return (0);
}