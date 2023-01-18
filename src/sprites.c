/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 14:29:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/18 10:00:29 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_num_sprite(t_gameboard *gb)
{
	gb->nums = malloc(sizeof(mlx_texture_t *) * 11);
	if (!gb->nums)
		ft_printf("malloc error");
	gb->nums[0] = mlx_load_png("./images/lego0.png");
	gb->nums[1] = mlx_load_png("./images/lego1.png");
	gb->nums[2] = mlx_load_png("./images/lego2.png");
	gb->nums[3] = mlx_load_png("./images/lego3.png");
	gb->nums[4] = mlx_load_png("./images/lego4.png");
	gb->nums[5] = mlx_load_png("./images/lego5.png");
	gb->nums[6] = mlx_load_png("./images/lego6.png");
	gb->nums[7] = mlx_load_png("./images/lego7.png");
	gb->nums[8] = mlx_load_png("./images/lego8.png");
	gb->nums[9] = mlx_load_png("./images/lego9.png");
	gb->nums[10] = NULL;
	// error check
}

void	init_player_left_sprite(t_player *player)
{
	player->player_l = malloc(sizeof(mlx_texture_t *) * 5);
	if (!player->player_l)
		ft_printf("malloc error");
	player->player_l[0] = mlx_load_png("./images/flasman64.png");
	player->player_l[1] = mlx_load_png("./images/enemy64.png");
	player->player_l[2] = mlx_load_png("./images/flasman64.png");
	player->player_l[3] = mlx_load_png("./images/enemy64.png");
	player->player_l[4] = NULL;
}

void	init_player_right_sprite(t_player *player)
{
	player->player_r = malloc(sizeof(mlx_texture_t *) * 5);
	if (!player->player_r)
		ft_printf("malloc error");
	player->player_r[0] = mlx_load_png("./images/flasman64r.png");
	player->player_r[1] = mlx_load_png("./images/enemy64r.png");
	player->player_r[2] = mlx_load_png("./images/flasman64r.png");
	player->player_r[3] = mlx_load_png("./images/enemy64r.png");
	player->player_r[4] = NULL;
}
