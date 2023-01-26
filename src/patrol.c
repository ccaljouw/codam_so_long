/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 12:56:07 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 13:19:39 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_patrol_h(t_gameboard *gb, int i)
{
	int x;
	int y;
	
	x = (gb->imgs->patrol->instances[i].x + 20) / SIZE;
	y = gb->imgs->patrol->instances[i].y / SIZE;
	if (!ft_strchr("0CP", gb->map->arr[y][x]))
	{
		if (gb->patrol->dir == 0)
			gb->patrol->dir = 1;
		else
			gb->patrol->dir = 0;
	}
	if (gb->patrol->dir == 0)
		gb->imgs->patrol->instances[i].x++;
	else
		gb->imgs->patrol->instances[i].x--;
}

void	move_patrol_v(t_gameboard *gb, int i)
{
	int x;
	int y;
	
	x = (gb->imgs->patrol->instances[i].x) / SIZE;
	y = (gb->imgs->patrol->instances[i].y - 20) / SIZE;
	if (!ft_strchr("0CP", gb->map->arr[y][x]))
	{
		if (gb->patrol->dir == 0)
			gb->patrol->dir = 1;
		else
			gb->patrol->dir = 0;
	}
	if (gb->patrol->dir == 0)
		gb->imgs->patrol->instances[i].y++;
	else
		gb->imgs->patrol->instances[i].y--;
}