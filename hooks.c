/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epiacent <epiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 16:34:03 by epiacent          #+#    #+#             */
/*   Updated: 2024/08/11 18:00:38 by epiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void put_image(t_game *g, int x, int y)
{
    void    *img;
    if (g->map[y][x] == 'P')
        img = g->img.player;
    else if (g->map[y][x] == 'C')
        img = g->img.coll[g->colltoprint];
    else if (g->map[y][x] == 'E')
        img = g->img.exit[g->coll == g->img.ncoll];
    else if (g->map[y][x] == 'N')
        img = g->img.player;
    else if (g->map[y][x] == '0')
        img = g->img.floor;
    else
        img = g->img.wall;
    mlx_put_image_to_window(g->mlxs.mlx, g->mlxs.window, img, x * TILE_SZ, y * TILE_SZ);
}

int print_map(t_game *g)
{
    int x;
    int y;

    x = 0;
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
    return (0);
}

int move(t_game *g, int plusx, int plusy)
{
    char    newpos;

   
        printf("nowposX = %i\nnowposY = %i\n", g->px + plusx, g->py + plusy);
    if (g->map[g->py + plusy][g->px + plusx] != '1' && (g->map[g->py + plusy][g->px + plusx] != 'E' || g->coll == g->img.ncoll))
    {
        g->map[g->py][g->px ] = '0';
        newpos = g->map[g->py + plusy][g->px + plusx];
        g->map[g->py + plusy][g->px + plusx] = 'P';
        g->py += plusy;
        g->px += plusx;
    }
    if (newpos == 'E')
        quit_map(g, "daje sei forte\n");
    if (newpos == 'C')
        g->img.ncoll++;
    return (1);
}

int	key_map(int keycode, t_game *game)
{
	if (keycode == 119)
        return move(game, 0, -1);
    if (keycode == 115)
        return move(game, 0, +1);
    if (keycode == 97)
        return move(game, -1, 0);
    if (keycode == 100)
        return move(game, +1, 0);
    else
        return (1);
}
