/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 19:30:32 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_movescore(int moves, t_gameboard *gb)
{
	int	i;
	char *num;
	
	num = ft_itoa(moves);
	i = ft_strlen(num);
	mlx_draw_texture(gb->imgs->moves_count, gb->text->nums[0], 0, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->text->nums[0], gb->text->nums[0]->width, 0);
	while(i)
	{
		mlx_draw_texture(gb->imgs->moves_count, gb->text->nums[num[ft_strlen(num) - i] - '0'], gb->text->nums[0]->width * (3 - i) + ((gb->text->nums[0]->width - gb->text->nums[num[ft_strlen(num) - i] - '0']->width) / 2), 0);
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
	
	heigth = (gb->height / gb->text->side->height) - 1;
	width = (gb->imgs->side->width / gb->text->side->width) - 1;
	offset = gb->height / 20;
	while (heigth >= 0)
	{
		while (width >= 0)
		{
			mlx_draw_texture(gb->imgs->side, gb->text->side, width * gb->text->side->width, heigth * gb->text->side->height);
			width--;
		}
		width = gb->imgs->side->width / gb->text->side->width;
		heigth--;
	}
	mlx_draw_texture(gb->imgs->side_text, gb->text->lives_title, (gb->imgs->side->width - gb->text->lives_title->width) / 2, offset * 2);
	mlx_draw_texture(gb->imgs->side_text, gb->text->moves_title, (gb->imgs->side->width - gb->text->moves_title->width) / 2, offset * 12);
	mlx_image_to_window(gb->mlx, gb->imgs->side_text, gb->width + (gb->imgs->side->width - gb->imgs->side_text->width) / 2, 0);
	mlx_image_to_window(gb->mlx, gb->imgs->lives_count, gb->width + ((gb->imgs->side->width - gb->imgs->lives_count->width) / 2), offset * 6);
	mlx_image_to_window(gb->mlx, gb->imgs->moves_count, gb->width + ((gb->imgs->side->width - gb->imgs->moves_count->width) / 2), offset * 16);
}

void	init_window(t_gameboard *gb)
{
	gb->width = gb->map->map_width * gb->text->empty->width;
	gb->height = gb->map->map_height * gb->text->empty->height;
	gb->mlx = mlx_init(gb->width + (gb->text->empty->width * 2), \
									gb->height, "So long!", false);
	if (!gb->mlx)
		error(FT_WINFAIL, gb);		
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
	mlx_draw_texture(gb->imgs->lives_count, gb->text->nums[gb->player->lives], 0, 0);

}
