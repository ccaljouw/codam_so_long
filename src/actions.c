/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 10:17:43 by cariencaljo   ########   odam.nl         */
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

void	change_direction(int cur_dir, t_images *imgs, t_textures *text)
{
	if (cur_dir == 0)
		mlx_draw_texture(imgs->pl, text->player[0], 0, 0);
	if (cur_dir == 1)
		mlx_draw_texture(imgs->pl, text->player[1], 0, 0);
}

void	get_collectable(t_gameboard *gb, int map_x, int map_y)
{
	int	i;

	i = gb->imgs->coll->count - 1;
	gb->coll = 0;
	while (i >= 0)
	{
		if (gb->imgs->coll->instances[i].x == \
			(map_x * (int)gb->text->empty->width) \
			&& gb->imgs->coll->instances[i].y == \
			(map_y * (int)gb->text->empty->height))
			gb->imgs->coll->instances[i].enabled = 0;
		else
			gb->coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (gb->coll == 0)
		mlx_draw_texture(gb->imgs->exit, gb->text->exit_open, 0, 0);
}

// void	hit_patrol(t_gameboard *gb, int map_x, int map_y)
// {
// 	gb->player->lives -= 1;
// 	mlx_draw_texture(gb->imgs->lives_count, gb->text->nums[gb->player->lives], 0, 0);
// 	if (gb->player->lives == 2)
// 	{
// 		//free?
// 		gb->text->pll = 
		
// 	}
// }