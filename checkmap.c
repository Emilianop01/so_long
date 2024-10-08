/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 17:52:42 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/19 15:07:48 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_ext(char *map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
	{
		if (map[i + 1] && map[i + 2] && map[i + 3])
		{
			if (map[i] == '.' && map[i + 1] == 'b' && map[i + 2] == 'e'
				&& map[i + 3] == 'r' && !map[i + 4])
				return (1);
		}
		else
			break ;
		i++;
	}
	return (0);
}

char	*map_conv(char *file)
{
	int		fd;
	int		red;
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	char	*old;

	fd = open(file, O_RDONLY);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	red = 1;
	ret = (char *)malloc(sizeof(char));
	ret[0] = 0;
	while (red >= 1)
	{
		red = read(fd, buf, BUFFER_SIZE);
		buf[red] = 0;
		old = ret;
		ret = ft_strjoin(ret, buf);
		free(old);
	}
	close(fd);
	return (ret);
}

int	validate(int argc, char **argv)
{
	int		lenx;
	int		leny;
	char	*file;
	char	**map;

	leny = 0;
	if (argc != 2)
		return (-1);
	if (file_ext(argv[1]) == 0)
		return (-1);
	file = map_conv(argv[1]);
	map = ft_split(file, '\n');
	free(file);
	lenx = ft_strlen(map[0]);
	if (lenx == 0)
		return (free_exit(map));
	while (map[++leny])
	{
		if ((int)ft_strlen(map[leny]) != lenx)
			return (free_exit(map));
	}
	return (check_map(map, lenx, leny));
}

int	check_map(char **map, int lenx, int leny)
{
	int	x;
	int	y;
	int	flag[3];

	y = -1;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	while (++y < leny)
	{
		x = -1;
		while (++x < lenx)
		{
			if (!check_char(map[y][x], flag))
				return (free_exit(map));
			if ((x == 0 || y == 0 || x == lenx - 1 || y == leny - 1)
				&& map[y][x] != '1')
				return (free_exit(map));
		}
	}
	if (flag[0] == 1 && flag[1] == 1 && flag[2] >= 1)
		return (flood_setup(map, leny, lenx));
	return (free_exit(map));
}
