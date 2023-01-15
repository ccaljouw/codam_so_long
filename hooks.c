/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/15 10:48:43 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_move(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
	// print moves to stdout
	if (keypress.key)
	{
		gb->moves += 1;
		if (gb->moves % 2 == 0)
			ft_printf("moves: %d\n", gb->moves/2);
	}
	// move player
	if (keypress.key == MLX_KEY_ESCAPE)
		mlx_close_window(gb->mlx);
	if (keypress.key == MLX_KEY_UP)
	{
		gb->imgs->pl->instances[0].y -= gb->imgs->empty->height / 4;
		gb->imgs->plr->instances[0].y -= gb->imgs->empty->height / 4;
	}
	if (keypress.key == MLX_KEY_DOWN)
	{
		gb->imgs->pl->instances[0].y += gb->imgs->empty->height / 4;
		gb->imgs->plr->instances[0].y += gb->imgs->empty->height / 4;
	}
	if (keypress.key == MLX_KEY_LEFT)
	{
		gb->imgs->pl->instances[0].x -= gb->imgs->empty->width / 4;
		gb->imgs->plr->instances[0].x -= gb->imgs->empty->width / 4;
		gb->imgs->pl->instances[0].enabled = 1;
		gb->imgs->plr->instances[0].enabled = 0;
	}
	if (keypress.key == MLX_KEY_RIGHT)
	{
		gb->imgs->pl->instances[0].x += gb->imgs->empty->width / 4;
		gb->imgs->plr->instances[0].x += gb->imgs->empty->width / 4;
		gb->imgs->pl->instances[0].enabled = 0;
		gb->imgs->plr->instances[0].enabled = 1;
	}
	// little jump
	if (keypress.key)
	{
		if (keypress.action == MLX_PRESS)
		{
			gb->imgs->pl->instances[0].y -= gb->imgs->empty->height / 20;
			gb->imgs->plr->instances[0].y -= gb->imgs->empty->height / 20;
		}
		if (keypress.action == MLX_RELEASE)
		{
			gb->imgs->pl->instances[0].y += gb->imgs->empty->height / 20;
			gb->imgs->plr->instances[0].y += gb->imgs->empty->height / 20;
		}
	}
}
