/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sidebar.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 14:17:16 by cariencaljo   ########   odam.nl         */
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
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) - (gb->text->num_0->width * 2), ((gb->text->empty->height * gb->map->map_height) / 2) + ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) - (gb->text->num_0->width * 1), ((gb->text->empty->height * gb->map->map_height) / 2) + ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2), ((gb->text->empty->height * gb->map->map_height) / 2) + ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) + (gb->text->num_0->width * 1), ((gb->text->empty->height * gb->map->map_height) / 2) + ((gb->text->bricks_to_get->height * 3)/2));
	
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) - (gb->text->num_0->width * 2), ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) - (gb->text->num_0->width * 1), ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2), ((gb->text->bricks_to_get->height * 3)/2));
	mlx_draw_texture(gb->imgs->side_text, gb->text->num_0, (gb->text->bricks_to_get->width/2) + (gb->text->num_0->width * 1), ((gb->text->bricks_to_get->height * 3)/2));

}