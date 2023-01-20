/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 16:26:19 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(t_gameboard *gb)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		error(FT_MEMFAIL, gb);
	player->lives = 3;
	player->x_pos = 0;
	player->y_pos = 0;
	player->x_npos = 0;
	player->y_npos = 0;
	return (player);
}

void	init_characters(t_gameboard *gb)
{
	gb->player = init_player(gb);
	gb->patrol = init_player(gb);
}
