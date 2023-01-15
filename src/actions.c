/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/15 22:32:57 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_gameboard *gb, int pl_x, int pl_y)
{
	gb->imgs->pl->instances[0].x = pl_x;
	gb->imgs->pl->instances[0].y = pl_y;
	gb->imgs->plr->instances[0].x = pl_x;
	gb->imgs->plr->instances[0].y = pl_y;
}

void	change_direction(keys_t key, t_images *imgs)
{
	if (key == MLX_KEY_LEFT)
	{
		imgs->pl->enabled = 1;
		imgs->plr->enabled = 0;
	}
	if (key == MLX_KEY_RIGHT)
	{
		imgs->pl->enabled = 0;
		imgs->plr->enabled = 1;
	}
}

void	get_collectable(t_gameboard *gb, int x_pl, int y_pl)
{
	int i;
	int coll;
	
	i = gb->imgs->coll->count - 1;
	coll = 0;
	while (i >= 0)
	{
		if (gb->imgs->coll->instances[i].x == x_pl && gb->imgs->coll->instances[i].y == y_pl)
			gb->imgs->coll->instances[i].enabled = 0;
		else
			coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (coll == 0)
		gb->imgs->exit->enabled = 1;
}
