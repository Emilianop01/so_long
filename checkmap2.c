/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:48:27 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 15:09:46 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_char(char c, int *flag)
{
	if (c == 'E')
		flag[0] += 1;
	else if (c == 'P')
		flag[1] += 1;
	else if (c == 'C')
		flag[2] += 1;
	else if (c != '1' && c != '0')
		return (0);
	return (1);
}

int	flood_setup(char **map, int leny, int lenx)
{
	int	player[2];
	int	len[2];
	int	i;

	i = 0;
	len[0] = leny;
	len[1] = lenx;
	while (i < leny && !ft_strchr(map[i], 'P'))
		i++;
	player[0] = i;
	player[1] = ft_strchr(map[i], 'P') - map[i];
	flood_fill(map, player[0], player[1], len);
	i = -1;
	while (++i < leny)
	{
		if (ft_strchr(map[i], 'E') || ft_strchr(map[i], 'C'))
			return (free_exit(map));
	}
	free_exit(map);
	return (1);
}

void	flood_fill(char **map, int py, int px, int *l)
{
	if (py < 0 || px < 0 || py >= l[0] || px >= l[1]
		|| map[py][px] == '1')
		return ;
	if (map[py][px] == 'E')
	{
		map[py][px] = '1';
		return ;
	}
	map[py][px] = '1';
	flood_fill(map, (py - 1), (px), l);
	flood_fill(map, (py + 1), (px), l);
	flood_fill(map, (py), (px - 1), l);
	flood_fill(map, (py), (px + 1), l);
}
