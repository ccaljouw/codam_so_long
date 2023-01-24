/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/24 09:40:17 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// create screens
void	end_game(t_gameboard *gb, int result)
{
	gb->imgs->pl->enabled = 0;
	if (result == 1)
		ft_printf("You win!!");
	if (result == 2)
		ft_printf("No more lives, you lose....");
	if (result == 3)
		ft_printf("Too many moves, you lose....");
}

void	move_player(t_gameboard *gb, mlx_image_t *image)
{
	image->instances[0].x = gb->player->x_npos;
	image->instances[0].y = gb->player->y_npos;
	gb->player->x_pos = gb->player->x_npos;
	gb->player->y_pos = gb->player->y_npos;
}

void	change_direction(keys_t key, t_images *imgs, t_textures *text)
{
	if (imgs->pl->enabled == 0)
		return ;
	if (key == MLX_KEY_LEFT && imgs->sprites->player % 2 == 1)
		imgs->sprites->player -= 1;
	if (key == MLX_KEY_RIGHT && imgs->sprites->player % 2 == 0)
		imgs->sprites->player += 1;
	mlx_draw_texture(imgs->pl, text->player[imgs->sprites->player], 0, 0);
}

void	get_collectable(t_gameboard *gb, int map_x, int map_y)
{
	int	i;

	i = gb->imgs->coll->count - 1;
	gb->coll = 0;
	while (i >= 0)
	{
		if (gb->imgs->coll->instances[i].x == \
			(map_x * (int)gb->text->empty->width) \
			&& gb->imgs->coll->instances[i].y == \
			(map_y * (int)gb->text->empty->height))
			gb->imgs->coll->instances[i].enabled = 0;
		else
			gb->coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (gb->coll == 0)
		mlx_draw_texture(gb->imgs->exit, gb->text->exit_open, 0, 0);
}

void	hit_patrol(t_gameboard *gb)
{
	gb->player->lives -= 1;
	if (gb->player->lives > 0)
		gb->imgs->sprites->player += 2;
	else
		end_game(gb, 0);
	mlx_draw_texture(gb->imgs->lives_count, \
			gb->text->nums[gb->player->lives], 0, 0);
	mlx_draw_texture(gb->imgs->pl, \
			gb->text->player[gb->imgs->sprites->player], 0, 0);
}
