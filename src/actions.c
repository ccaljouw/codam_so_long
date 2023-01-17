/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 13:46:07 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_gameboard *gb)
{
	gb->imgs->pl->instances[0].x = gb->player->x_npos;
	gb->imgs->pl->instances[0].y = gb->player->y_npos;
	gb->player->x_pos = gb->player->x_npos;
	gb->player->y_pos = gb->player->y_npos;
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
	
	i = gb->imgs->coll->count - 1;
	gb->coll = 0;
	while (i >= 0)
	{

		if (gb->imgs->coll->instances[i].x == (map_x * (int)gb->text->empty->width) && gb->imgs->coll->instances[i].y == (map_y * (int)gb->text->empty->height))
		{
			gb->imgs->coll->instances[i].enabled = 0;
			ft_printf("collectables left: %d\n", gb->coll + 1);
			// draw correct number to sidebar
		}
		else
			gb->coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (gb->coll == 0)
		gb->imgs->exit->enabled = 1;
}
