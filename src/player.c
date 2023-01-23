/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   player.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/23 20:53:11 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->lives = 3;
	player->x_pos = 0;
	player->y_pos = 0;
	player->x_npos = 0;
	player->y_npos = 0;
	return (player);
}

void	init_characters(t_gameboard *gb)
{
	gb->player = init_player();
	gb->patrol = init_player();
	if (!gb->player || !gb->patrol)
		error(FT_MEMFAIL, gb);
}
