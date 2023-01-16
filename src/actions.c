/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 00:13:11 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_gameboard *gb, int x_npos, int y_npos)
{
	gb->imgs->pl->instances[0].x = x_npos;
	gb->imgs->pl->instances[0].y = y_npos;
}

void	change_direction(keys_t key, t_images *imgs, t_textures *text)
{
	if (key == MLX_KEY_LEFT)
		mlx_draw_texture(imgs->pl, text->pll, 0, 0);
	if (key == MLX_KEY_RIGHT)
		mlx_draw_texture(imgs->pl, text->plr, 0, 0);
}

void	get_collectable(t_gameboard *gb, int map_x, int map_y)
{
	int i;
	int coll;
	
	i = gb->imgs->coll->count - 1;
	coll = 0;
	while (i >= 0)
	{
		if (gb->imgs->coll->instances[i].x == map_x && gb->imgs->coll->instances[i].y == map_y)
			gb->imgs->coll->instances[i].enabled = 0;
		else
			coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (coll == 0)
		gb->imgs->exit->enabled = 1;
}
