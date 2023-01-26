/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hook.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/13 22:44:55 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 17:55:49 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (gb->imgs->patrol->count > 0)
		move_patrol(gb);
}
