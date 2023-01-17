/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sidebar.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 12:39:26 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 13:30:08 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_sidebar(t_gameboard *gb)
{
	int	heigth;

	heigth = ((gb->map->map_height * gb->text->empty->height) / gb->text->side->height) - 1;
	ft_printf("heigth: %d, map: %d, side: %d\n", heigth, (gb->map->map_height * gb->text->empty->height), gb->text->side->height);
	while (heigth >= 0)
	{
		ft_printf("draw y: %d\n", heigth * gb->text->side->height);
		mlx_draw_texture(gb->imgs->side, gb->text->side, 0, heigth * gb->text->side->height);
		heigth--;
	}
	mlx_draw_texture(gb->imgs->side, gb->text->side, 0, (gb->map->map_height * gb->text->empty->height) - gb->text->side->height);
	mlx_draw_texture(gb->imgs->side_text, gb->text->bricks_to_get, 0, (gb->text->empty->height - gb->text->bricks_to_get->height) / 2);
	
}