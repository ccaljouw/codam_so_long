/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/15 22:43:05 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		check_move(keys_t key, t_gameboard *gb, int pl_x, int pl_y)
{
	if (key == MLX_KEY_UP)
		pl_y = pl_y - gb->imgs->empty->height;
	else if (key == MLX_KEY_DOWN)
		pl_y = pl_y + gb->imgs->empty->height;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
	{
		change_direction(key, gb->imgs);
		if (key == MLX_KEY_LEFT)
			pl_x = pl_x - (gb->imgs->empty->width);
		else
			pl_x = pl_x + (gb->imgs->empty->width);
	}
	else
		return (0);
	gb->map->npos_x = pl_x/ gb->imgs->empty->width;
	gb->map->npos_y = pl_y / gb->imgs->empty->height;
	if (!(gb->map->npos_x >= 0 && gb->map->npos_y >= 0 && gb->map->npos_x < (int)gb->map->map_width && gb->map->npos_y < (int)gb->map->map_height))
		ft_printf("out of map range");
	if (check_map_pos(gb, pl_x, pl_y))
		move_player(gb, pl_x, pl_y);
	return (1);
}

void	hook(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
	gb->pl_x = gb->imgs->pl->instances[0].x;
	gb->pl_y = gb->imgs->pl->instances[0].y;
	if (mlx_is_key_down(gb->mlx, keypress.key))
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			mlx_close_window(gb->mlx);
		check_move(keypress.key, gb, gb->pl_x, gb->pl_y);
	}
}
