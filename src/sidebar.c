/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sidebar.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 15:59:13 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sidebar(t_gameboard *gb)
{
	int	heigth;

	heigth = ((gb->map->map_height * gb->text->empty->height) / gb->text->side->height) - 1;
	while (heigth >= 0)
	{
		mlx_draw_texture(gb->imgs->side, gb->text->side, 0, heigth * gb->text->side->height);
		heigth--;
	}
	mlx_draw_texture(gb->imgs->side, gb->text->side, 0, (gb->map->map_height * gb->text->empty->height) - gb->text->side->height);
	mlx_draw_texture(gb->imgs->side_text, gb->text->bricks_to_get, 0, 0);
	mlx_draw_texture(gb->imgs->side_text, gb->text->moves_title, (gb->text->bricks_to_get->width - gb->text->moves_title->width)/2, (gb->text->empty->height * gb->map->map_height) / 2);
	
	//init moves
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], 0, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], gb->nums[0]->width, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], gb->nums[0]->width * 2, 0);
	mlx_draw_texture(gb->imgs->moves_count, gb->nums[0], gb->nums[0]->width * 3, 0);

	//set coll score
	set_collectable_score(gb->imgs->coll->count, gb);
}
