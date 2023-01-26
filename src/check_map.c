/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/19 15:53:49 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/26 18:24:37 by ccaljouw      ########   odam.nl         */
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

int	check_map_pos(t_gameboard *gb, int map_x, int map_y)
{
	if (gb->map->arr[map_y][map_x] == '1')
		return (0);
	if (gb->map->arr[map_y][map_x] == 'C')
		get_collectable(gb, map_x, map_y);
	if (gb->map->arr[map_y][map_x] == 'E' && gb->coll == 0)
		end_game(gb, 1);
	if (gb->imgs->pl->enabled == 1)
		gb->moves += 1;
	if (gb->moves > 999)
		end_game(gb, 3);
	set_movescore(gb->moves, gb);
	return (1);
}

void	check_collision(t_gameboard *gb, int i, int dir)
{
	int		x;
	int		y;

	if ((mlx_get_time() - gb->coll_time) < 1.5)
		return ;
	x = (gb->imgs->patrol->instances[i].x + (dir * 32)) / SIZE;
	y = (gb->imgs->patrol->instances[i].y + (dir * 32)) / SIZE;
	if (x == gb->imgs->pl->instances[0].x / SIZE \
		&& y == gb->imgs->pl->instances[0].y / SIZE)
	{
		gb->coll_time = mlx_get_time();
		gb->player->lives -= 1;
		if (gb->player->lives > 0)
			gb->imgs->sprites->player += 2;
		else
			end_game(gb, 0);
		if (gb->player->lives >= 0)
		{
			mlx_draw_texture(gb->imgs->lives_count, \
					gb->text->nums[gb->player->lives], 0, 0);
			mlx_draw_texture(gb->imgs->pl, \
					gb->text->player[gb->imgs->sprites->player], 0, 0);
		}
	}
}
