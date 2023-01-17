/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 10:59:27 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_new_position(keys_t key, t_gameboard *gb)
{
	gb->player->x_npos = gb->player->x_pos;
	gb->player->y_npos = gb->player->y_pos;
	if (key == MLX_KEY_UP)
		gb->player->y_npos = gb->player->y_pos - gb->text->empty->height;
	else if (key == MLX_KEY_DOWN)
		gb->player->y_npos = gb->player->y_pos + gb->text->empty->height;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
	{
		change_direction(key, gb->imgs, gb->text);
		if (key == MLX_KEY_LEFT)
			gb->player->x_npos = gb->player->x_pos - gb->text->empty->width;
		else
			gb->player->x_npos = gb->player->x_pos + gb->text->empty->width;
	}
	else
		return (0);
	return (1);
}

int		check_move(keys_t key, t_gameboard *gb)
{
	int	map_x;
	int map_y;
	
	if(!get_new_position(key, gb))
		return (0);
	map_x = gb->player->x_npos / gb->text->empty->width;
	map_y = gb->player->y_npos / gb->text->empty->height;
	if (map_x < 0 || map_y < 0 || map_x > gb->map->map_width || map_y > gb->map->map_height)
		ft_printf("out of map range");
	if (!check_map_pos(gb, map_x, map_y))
		return (0);
	move_player(gb);
	return (1);
}

void	key_hook(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
	if (mlx_is_key_down(gb->mlx, keypress.key))
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			mlx_close_window(gb->mlx);
		check_move(keypress.key, gb);
	}
}

