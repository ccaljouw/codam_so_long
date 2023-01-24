/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/24 14:21:06 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_new_position(keys_t key, t_gameboard *gb)
{
	gb->player->x_npos = gb->player->x_pos;
	gb->player->y_npos = gb->player->y_pos;
	if (key == MLX_KEY_UP)
		gb->player->y_npos = gb->player->y_pos - SIZE;
	else if (key == MLX_KEY_DOWN)
		gb->player->y_npos = gb->player->y_pos + SIZE;
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
	{
		if (key == MLX_KEY_LEFT)
			gb->player->x_npos = gb->player->x_pos - SIZE;
		else
			gb->player->x_npos = gb->player->x_pos + SIZE;
		change_direction(key, gb->imgs, gb->text);
	}
	else
		return (0);
	return (1);
}

int	move(keys_t key, t_gameboard *gb)
{
	int	map_x;
	int	map_y;

	if (!get_new_position(key, gb))
		return (0);
	map_x = gb->player->x_npos / gb->text->empty->width;
	map_y = gb->player->y_npos / gb->text->empty->height;
	if (map_x < 0 || map_y < 0 || map_x > gb->map->map_width || \
									map_y > gb->map->map_height)
		error(FT_INVPOS, gb);
	if (!check_map_pos(gb, map_x, map_y))
		return (0);
	move_player(gb, gb->imgs->pl);
	return (1);
}

void	key_hook(struct mlx_key_data keypress, void *param)
{
	t_gameboard	*gb;

	gb = param;
	if (mlx_is_key_down(gb->mlx, keypress.key))
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			mlx_close_window(gb->mlx);
		move(keypress.key, gb);
	}
}

void	move_patrol(t_gameboard *gb)
{
	mlx_draw_texture(gb->imgs->patrol, gb->text->patrol[gb->imgs->sprites->patrol], \
	gb->patrol->x_pos, gb->patrol->y_pos);
	if (gb->imgs->sprites->patrol == 9)
		gb->imgs->sprites->patrol= 0;
	else
		gb->imgs->sprites->patrol += 1;
	// ft_printf("xpos: %d, x_npos: %d, y_pos: %d, y_npos: %d\n", gb->patrol->x_pos, gb->patrol->x_npos, gb->patrol->y_pos, gb->patrol->y_npos);
	if (gb->patrol->x_npos == 0)
		gb->patrol->x_pos++;
	else
		gb->patrol->x_pos--;
	
	if (gb->patrol->x_pos >= (int)gb->imgs->patrol->width - 36)
	{
		gb->patrol->x_npos = 1;
		if (gb->patrol->y_npos == 0)
			gb->patrol->y_pos += 4;
		else
			gb->patrol->y_pos -= 4;
	}
	if (gb->patrol->x_pos <= 4)
	{
		gb->patrol->x_npos = 0;
		if (gb->patrol->y_npos == 0)
			gb->patrol->y_pos++;
		else
			gb->patrol->y_pos--;
	}
	if (gb->patrol->y_pos >= (int)gb->imgs->patrol->height - 36)
		gb->patrol->y_npos = 1;
	if (gb->patrol->y_pos <= 4)
		gb->patrol->y_npos = 0;		
}

void	frame_hook(void *param)
{
	t_gameboard	*gb;
	
	gb = param;
	move_patrol(gb);	
}
