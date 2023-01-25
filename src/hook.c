/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/25 10:23:04 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(keys_t key, t_gameboard *gb)
{
	int	map_x;
	int	map_y;

	if (!get_new_position(key, gb))
		return (0);
	map_x = gb->player->x_npos / SIZE;
	map_y = gb->player->y_npos / SIZE;
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

void	frame_hook(void *param)
{
	t_gameboard	*gb;

	gb = param;
	mlx_draw_texture(gb->imgs->patrol, \
		gb->text->patrol[gb->imgs->sprites->patrol], \
		gb->patrol->x_pos, (SIZE - gb->text->patrol[0]->height) / 2);
	if (gb->imgs->sprites->patrol == 9)
		gb->imgs->sprites->patrol = 0;
	else
		gb->imgs->sprites->patrol += 1;
	if (gb->patrol->x_npos == 0)
		gb->patrol->x_pos++;
	else
		gb->patrol->x_pos--;
	if (gb->patrol->x_pos >= SIZE - 32)
	{
		// check move to right	
		gb->patrol->x_npos = 1;
	}
	if (gb->patrol->x_pos <= 0)
	{
		// check move to left
		gb->patrol->x_npos = 0;
	}
}
