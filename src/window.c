/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/24 16:15:54 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sidebar(t_gameboard *gb, int offset)
{
	mlx_draw_texture(gb->imgs->side_text, gb->text->lives_title, \
		(gb->imgs->side->width - gb->text->lives_title->width) / 2, \
		offset * 2);
	mlx_draw_texture(gb->imgs->side_text, gb->text->moves_title, \
		(gb->imgs->side->width - gb->text->moves_title->width) / 2, \
		offset * 12);
	mlx_image_to_window(gb->mlx, gb->imgs->side_text, gb->width \
		+ (gb->imgs->side->width - gb->imgs->side_text->width) / 2, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->lives_count, gb->width \
		+ ((gb->imgs->side->width - gb->imgs->lives_count->width) / 2), \
		offset * 6);
	mlx_image_to_window(gb->mlx, gb->imgs->moves_count, gb->width \
		+ ((gb->imgs->side->width - gb->imgs->moves_count->width) / 2), \
		offset * 16);
}

void	render_sidebar(t_gameboard *gb)
{
	int	heigth;
	int	width;
	int	offset;

	heigth = (gb->height / gb->text->side->height) - 1;
	width = (gb->imgs->side->width / gb->text->side->width) - 1;
	offset = gb->height / 20;
	while (heigth >= 0)
	{
		while (width >= 0)
		{
			mlx_draw_texture(gb->imgs->side, gb->text->side, \
				width * gb->text->side->width, heigth * gb->text->side->height);
			width--;
		}
		width = gb->imgs->side->width / gb->text->side->width;
		heigth--;
	}
	draw_sidebar(gb, offset);
}


void	render_map(t_gameboard *gb, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = x * SIZE;
	y_pos = y * SIZE;
	mlx_draw_texture(gb->imgs->background, gb->text->empty, x_pos, y_pos);
	if (gb->map->arr[y][x] == '1')
		mlx_draw_texture(gb->imgs->wall, gb->text->wall, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'C')
		mlx_image_to_window(gb->mlx, gb->imgs->coll, x_pos, y_pos);
	else if (gb->map->arr[y][x] == 'P')
	{
		check_map(gb, x, y);
		mlx_image_to_window(gb->mlx, gb->imgs->pl, x_pos, y_pos);
		mlx_set_instance_depth(&gb->imgs->pl->instances[0], 10);
		gb->player->x_pos = x_pos;
		gb->player->y_pos = y_pos;
	}
	else if (gb->map->arr[y][x] == 'E')
		mlx_image_to_window(gb->mlx, gb->imgs->exit, x_pos, y_pos);
	else if (gb->map->arr[y][x] != '0')
		error(FT_INVMAPCH, gb);
}

void	render_window(t_gameboard *gb)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	mlx_image_to_window(gb->mlx, gb->imgs->side, gb->width, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->background, 0, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->wall, 0, 0);
	while (gb->map->arr[y])
	{
		while (gb->map->arr[y][x])
		{
			render_map(gb, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	render_sidebar(gb);
	set_movescore(0, gb);
	mlx_draw_texture(gb->imgs->lives_count, \
			gb->text->nums[gb->player->lives], 0, 0);
}

void	init_window(t_gameboard *gb)
{
	gb->width = gb->map->map_width * SIZE;
	gb->height = gb->map->map_height * SIZE;
	gb->mlx = mlx_init(gb->width + SIDE, gb->height, "So long!", false);
	if (!gb->mlx)
		error(FT_WINFAIL, gb);
}
