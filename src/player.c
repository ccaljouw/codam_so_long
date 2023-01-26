/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 17:28:07 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <math.h>
#include <stdio.h> //// remove

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

void	check_collision(t_gameboard *gb, int i, int dir)
{
	int		x;
	int		y;

	if ((mlx_get_time() - gb->coll_time) < 1.5)
		return ;
	x = (gb->imgs->patrol->instances[i].x + (dir * 32)) / SIZE;
	y = (gb->imgs->patrol->instances[i].y + (dir * 32)) / SIZE;
	if (x == gb->imgs->pl->instances[0].x / SIZE \
		&& y == gb->imgs->pl->instances[0].y / SIZE)
	{
		gb->coll_time = mlx_get_time();
		gb->player->lives -= 1;
		if (gb->player->lives > 0)
			gb->imgs->sprites->player += 2;
		else
			end_game(gb, 0);
		if (gb->player->lives >= 0)
		{
			mlx_draw_texture(gb->imgs->lives_count, \
					gb->text->nums[gb->player->lives], 0, 0);
			mlx_draw_texture(gb->imgs->pl, \
					gb->text->player[gb->imgs->sprites->player], 0, 0);
		}
	}
}
