/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/14 12:19:22 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	f_move(struct mlx_key_data keypress, void *param)
{
	t_gameboard *gb;

	gb = param;
		if (keypress.key == MLX_KEY_ESCAPE)
		mlx_close_window(gb->mlx);
	if (keypress.key == MLX_KEY_UP)
	{
		gb->imgs->pl->instances[0].y -= 16;
		// gb->imgs->plr->instances[0].y -= 16;
	}
	if (keypress.key == MLX_KEY_DOWN)
	{
		gb->imgs->pl->instances[0].y += 16;
		// gb->imgs->plr->instances[0].y += 16;
	}
	if (keypress.key == MLX_KEY_LEFT)
	{
		gb->imgs->pl->instances[0].x -= 16;
		// gb->imgs->plr->instances[0].x -= 16;
	}
	if (keypress.key == MLX_KEY_RIGHT)
	{
		gb->imgs->pl->instances[0].x += 16;
		// gb->imgs->plr->instances[0].x += 16;
	}
}