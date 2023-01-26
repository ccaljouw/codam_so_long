/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 15:53:49 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 11:18:48 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_valid(t_gameboard *gb)
{
	if (gb->map->map_width > MAX_X)
		error(FT_INVMAPB, gb);
	if (gb->map->map_height > MAX_Y)
		error(FT_INVMAPB, gb);
	if (gb->map->start_count != 1)
		error(FT_INVMAPP, gb);
	if (gb->map->exit_count != 1)
		error(FT_INVMAPE, gb);
	if (gb->map->coll_count < 1)
		error(FT_INVMAPC, gb);
	gb->map->start_count = 1;
	gb->map->exit_count = 0; 
	gb->map->coll_count = 0;
}

void	check_content(t_gameboard *gb, int x, int y)
{
	if (!ft_strchr("0CPE1", gb->map->arr[y][x]))
		error(FT_INVMAPCH, gb);
	if (gb->map->arr[y][x] == 'C')
		gb->map->coll_count += 1;
	if (gb->map->arr[y][x] == 'P')
		gb->map->start_count += 1;
	if (gb->map->arr[y][x] == 'E')
		gb->map->exit_count += 1;
}

void	check_map_parameters(t_gameboard *gb)
{	
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (gb->map->arr[j][i])
		i++;
	gb->map->map_width = i;
	while (gb->map->arr[j])
	{
		while (gb->map->arr[j][i])
		{
			check_content(gb, i, j);
			i++;
		}
		if (i != gb->map->map_width)
			error(FT_INVMAPR, gb);
		else
			i = 0;
		j++;
	}
	gb->map->map_height = j;
	check_valid(gb);
}

