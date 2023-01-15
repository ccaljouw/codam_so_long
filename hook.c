/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/15 19:05:59 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_pos(t_gameboard *gb, int x, int y, int x_pl, int y_pl)
{
	if (gb->map[y][x] == '1')
		return (0);
	if (gb->map[y][x] == 'C')
		get_collectable(gb, x_pl, y_pl);
	if (gb->map[y][x] == 'E' && gb->imgs->exit->enabled == 1)
	{
		gb->imgs->pl->enabled = 0;
		gb->imgs->plr->enabled = 0;
	}
	return (1);
}

int		check_move(keys_t key, t_gameboard *gb)
{
	int	pl_x;
	int pl_y;
	int map_x;
	int	map_y;

	pl_x = gb->imgs->pl->instances[0].x;
	pl_y = gb->imgs->pl->instances[0].y;
	if (key == MLX_KEY_UP)
		pl_y = gb->imgs->pl->instances[0].y - (gb->imgs->empty->height);
	else if (key == MLX_KEY_DOWN)
		pl_y = gb->imgs->pl->instances[0].y + (gb->imgs->empty->height);
	else if (key == MLX_KEY_LEFT || key == MLX_KEY_RIGHT)
	{
		change_direction(key, gb);	
		if (key == MLX_KEY_LEFT)
			pl_x = gb->imgs->pl->instances[0].x - (gb->imgs->empty->width);
		else
			pl_x = gb->imgs->pl->instances[0].x + (gb->imgs->empty->width);
	}
	else
		return (0);
	map_x = (pl_x)/ gb->imgs->empty->width;
	map_y =(pl_y + (gb->imgs->empty->height - 1)) / gb->imgs->empty->height;
	if (!(map_x >= 0 && map_y >= 0 && map_x < (int)gb->map_width && map_y < (int)gb->map_height))
		ft_printf("out of map range");
	if (check_map_pos(gb, map_x, map_y, pl_x, pl_y))
		move_player(gb, pl_x, pl_y);
	return (1);
}


void	f_move(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
	if (mlx_is_key_down(gb->mlx, keypress.key))
	{
		if (keypress.key == MLX_KEY_ESCAPE)
			mlx_close_window(gb->mlx);
		if (!check_move(keypress.key, gb))
			return ;
		gb->moves += 1;
		mlx_set_window_title(gb->mlx, ft_strjoin("So long!\t\t\tmoves: ", ft_itoa(gb->moves)));
	}
}
