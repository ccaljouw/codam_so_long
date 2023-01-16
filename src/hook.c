/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 00:17:34 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// maak get new position en check move als aparte functies
int		check_move(keys_t key, t_gameboard *gb)
{
	int x_npos;
	int	y_npos;
	int	map_x;
	int map_y;
	
	x_npos = gb->player->x_pos;
	y_npos = gb->player->y_pos;
	if (key == MLX_KEY_UP)
		y_npos = gb->player->y_pos - gb->text->empty->height;
	else if (key == MLX_KEY_DOWN)
		y_npos = gb->player->y_pos + gb->text->empty->height;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
	{
		change_direction(key, gb->imgs, gb->text);
		if (key == MLX_KEY_LEFT)
			x_npos = gb->player->x_pos - gb->text->empty->width;
		else
			x_npos = gb->player->x_pos + gb->text->empty->width;
	}
	else
		return (0);
	map_x = x_npos / gb->text->empty->width;
	map_y = y_npos / gb->text->empty->height;
	if (map_x < 0 || map_y < 0 || map_x > gb->map->map_width || map_y > gb->map->map_height)
		ft_printf("out of map range");
	if (!check_map_pos(gb, map_x, map_y))
		return (0);
	move_player(gb, x_npos, y_npos);
	return (1);
}

void	hook(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
	gb->player->x_pos = gb->imgs->pl->instances[0].x;
	gb->player->y_pos = gb->imgs->pl->instances[0].y;
	if (mlx_is_key_down(gb->mlx, keypress.key))
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			mlx_close_window(gb->mlx);
		check_move(keypress.key, gb);
	}
}
