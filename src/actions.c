/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/15 18:28:29 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 11:23:13 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_gameboard *gb, mlx_image_t *image)
{
	check_collision(gb);
	image->instances[0].x = gb->player->x_npos;
	image->instances[0].y = gb->player->y_npos;
	if (gb->moves % 10 == 0)
		mlx_image_to_window(gb->mlx, gb->imgs->patrol, \
				gb->player->x_pos, gb->player->y_pos);
	gb->player->x_pos = gb->player->x_npos;
	gb->player->y_pos = gb->player->y_npos;
}

void	end_game(t_gameboard *gb, int result)
{
	gb->imgs->pl->enabled = 0;
	ft_printf("%d\n", gb->coll);
	if (result == 1)
		mlx_image_to_window(gb->mlx, gb->imgs->win, \
				(gb->width - gb->imgs->win->width) / 2, \
				(gb->height - gb->imgs->win->height) / 2);
	if (result == 0)
		mlx_image_to_window(gb->mlx, gb->imgs->lose, \
				(gb->width - gb->imgs->lose->width) / 2, \
				(gb->height - gb->imgs->lose->height) / 2);
	if (result == 3)
		mlx_image_to_window(gb->mlx, gb->imgs->moves_exc, \
				(gb->width - gb->imgs->moves_exc->width) / 2, \
				(gb->height - gb->imgs->moves_exc->height) / 2);
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
		if (gb->imgs->coll->instances[i].x == (map_x * SIZE) \
			&& gb->imgs->coll->instances[i].y == (map_y * SIZE))
			gb->imgs->coll->instances[i].enabled = 0;
		else
			gb->coll += gb->imgs->coll->instances[i].enabled;
		i--;
	}
	if (gb->coll == 0)
		mlx_draw_texture(gb->imgs->exit, gb->text->exit_open, 0, 0);
}

void	set_movescore(int moves, t_gameboard *gb)
{
	int		i;
	char	*num;

	num = ft_itoa(moves);
	if (!num)
		error(FT_MEMFAIL, gb);
	i = ft_strlen(num);
	mlx_draw_texture(gb->imgs->moves_count, gb->text->nums[0], 0, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->text->nums[0], \
												gb->text->nums[0]->width, 0);
	while (i)
	{
		mlx_draw_texture(gb->imgs->moves_count, \
			gb->text->nums[num[ft_strlen(num) - i] - '0'] \
			, gb->text->nums[0]->width * (3 - i) \
				+ ((gb->text->nums[0]->width \
				- gb->text->nums[num[ft_strlen(num) - i] - '0']->width) / 2) \
			, 0);
		i--;
	}
	free(num);
}
