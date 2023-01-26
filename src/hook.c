/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 14:22:56 by ccaljouw      ########   odam.nl         */
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
			error(FT_SUCCESS, gb);
		if (gb->imgs->pl->enabled == 1)
			move(keypress.key, gb);
	}
}

void	frame_hook(void *param)
{
	t_gameboard	*gb;
	int			i;

	gb = param;
	i = 0;
	mlx_draw_texture(gb->imgs->patrol, \
		gb->text->patrol[gb->imgs->sprites->patrol], 0, 0);
	if (gb->imgs->sprites->patrol == 59)
		gb->imgs->sprites->patrol = 0;
	else
		gb->imgs->sprites->patrol += 1;
	while (i < gb->imgs->patrol->count)
	{
		if (i % 2== 0)
			move_patrol_h(gb, i);
		else
			move_patrol_v(gb, i);
		i++;
	}

}
