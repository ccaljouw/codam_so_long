/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 18:24:45 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->lives = 3;
	player->x_pos = 0;
	player->y_pos = 0;
	player->x_npos = 0;
	player->y_npos = 0;
	player->dir = 0;
	player->dir1 = 0;
	player->dir2 = 0;
	player->dir3 = 0;
	return (player);
}

void	init_characters(t_gameboard *gb)
{
	gb->player = init_player();
	gb->patrol = init_player();
	if (!gb->player || !gb->patrol)
		error(FT_MEMFAIL, gb);
}

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
