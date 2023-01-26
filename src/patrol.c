/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   patrol.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 12:56:07 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 17:57:58 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_gameboard *gb, int instance, int dir)
{
	int	x;
	int	y;

	if (dir == 1)
	{
		x = (gb->imgs->patrol->instances[instance].x + 32) / SIZE;
		y = (gb->imgs->patrol->instances[instance].y + 32) / SIZE;
		if (!ft_strchr("0CP", gb->map->arr[y][x]))
			dir = 0;
	}	
	else
	{
		x = (gb->imgs->patrol->instances[instance].x) / SIZE;
		y = (gb->imgs->patrol->instances[instance].y) / SIZE;
		if (!ft_strchr("0CP", gb->map->arr[y][x]))
			dir = 1;
	}
	return (dir);
}

void	move_h(t_gameboard *gb, int dir, int i)
{
	if (dir == 1)
		gb->imgs->patrol->instances[i].x++;
	else
		gb->imgs->patrol->instances[i].x--;
}

void	move_v(t_gameboard *gb, int dir, int i)
{
	if (dir == 1)
		gb->imgs->patrol->instances[i].y++;
	else
		gb->imgs->patrol->instances[i].y--;
}

void	move_x(t_gameboard *gb, int dir, int i)
{
	if (dir == 1)
	{
		gb->imgs->patrol->instances[i].x++;
		gb->imgs->patrol->instances[i].y++;
	}
	else
	{
		gb->imgs->patrol->instances[i].x--;
		gb->imgs->patrol->instances[i].y--;
	}
}

void	move_patrol(t_gameboard *gb)
{
	int	i;

	i = 0;
	while (i < gb->imgs->patrol->count)
	{
		if (i % 3 == 0)
		{
			gb->patrol->dir = check_move(gb, i, gb->patrol->dir);
			move_h(gb, gb->patrol->dir, i);
			check_collision(gb, i, gb->patrol->dir);
		}
		if (i % 3 == 1)
		{
			gb->patrol->dir1 = check_move(gb, i, gb->patrol->dir1);
			move_v(gb, gb->patrol->dir1, i);
			check_collision(gb, i, gb->patrol->dir1);
		}
		if (i % 3 == 2)
		{
			gb->patrol->dir2 = check_move(gb, i, gb->patrol->dir2);
			move_x(gb, gb->patrol->dir2, i);
			check_collision(gb, i, gb->patrol->dir2);
		}
		i++;
	}
}
