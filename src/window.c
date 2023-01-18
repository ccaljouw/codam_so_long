/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/18 10:17:29 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_collectable_score(int coll_count, t_gameboard *gb)
{
	int	i;
	char *num;
	
	num = ft_itoa(coll_count);
	i = ft_strlen(num);
	mlx_draw_texture(gb->imgs->coll_count, gb->nums[0], 0, 0);
	mlx_draw_texture(gb->imgs->coll_count, gb->nums[0], gb->nums[0]->width, 0);
	mlx_draw_texture(gb->imgs->coll_count, gb->nums[0], gb->nums[0]->width * 2, 0);
	while(i)
	{
		mlx_draw_texture(gb->imgs->coll_count, gb->nums[num[ft_strlen(num) - i] - '0'], gb->nums[0]->width * (4 - i) + ((gb->nums[0]->width - gb->nums[num[ft_strlen(num) - i] - '0']->width) / 2), 0);
		i--;
	}
}

void	set_movescore(int moves, t_gameboard *gb)
{
	int	i;
	char *num;
	
	num = ft_itoa(moves);
	i = ft_strlen(num);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], 0, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], gb->nums[0]->width, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], gb->nums[0]->width * 2, 0);
	while(i)
	{
		mlx_draw_texture(gb->imgs->moves_count, gb->nums[num[ft_strlen(num) - i] - '0'], gb->nums[0]->width * (4 - i) + ((gb->nums[0]->width - gb->nums[num[ft_strlen(num) - i] - '0']->width) / 2), 0);
		i--;
	}
}

// sidebarwidth is 3x width of background texture. 
// If textures are bigger than image size that they are loaded to the image will can not
// be loaded
void	render_sidebar(t_gameboard *gb)
{
	int	heigth;
	int	width;
	int	offset;
	
	heigth = gb->height / gb->text->side->height;
	width = gb->imgs->side->width / gb->text->side->width;
	offset = gb->height / 20;
	while (heigth >= 0)
	{
		while (width >= 0)
		{
			mlx_draw_texture(gb->imgs->side, gb->text->side, width * gb->text->side->width, heigth * gb->text->side->height);
			width--;
		}
		width = gb->width / gb->text->side->width;
		heigth--;
	}
	mlx_draw_texture(gb->imgs->side_text, gb->text->bricks_to_get, 0, offset * 2);
	mlx_draw_texture(gb->imgs->side_text, gb->text->moves_title, 0, offset * 12);
	mlx_image_to_window(gb->mlx, gb->imgs->side, gb->width, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->side_text, gb->width + (gb->imgs->side->width - gb->imgs->side_text->width) / 2, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->coll_count, gb->width + ((gb->imgs->side->width - gb->imgs->moves_count->width) / 2), offset * 6);
	mlx_image_to_window(gb->mlx, gb->imgs->moves_count, gb->width + ((gb->imgs->side->width - gb->imgs->coll_count->width) / 2), offset * 16);
}

void	init_window(t_gameboard *gb)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
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
	mlx_set_instance_depth(&gb->imgs->wall->instances[0], 5);
	render_sidebar(gb);
	set_movescore(0, gb);
	set_collectable_score(gb->imgs->coll->count, gb);
}
