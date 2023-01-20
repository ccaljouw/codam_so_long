/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 14:29:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 11:45:21 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_num_sprite(t_gameboard *gb)
{
	gb->text->nums = malloc(sizeof(mlx_texture_t *) * 11);
	if (!gb->text->nums)
		ft_printf("malloc error");
	gb->text->nums[0] = mlx_load_png("./images/numbers/lego0.png");
	gb->text->nums[1] = mlx_load_png("./images/numbers/lego1.png");
	gb->text->nums[2] = mlx_load_png("./images/numbers/lego2.png");
	gb->text->nums[3] = mlx_load_png("./images/numbers/lego3.png");
	gb->text->nums[4] = mlx_load_png("./images/numbers/lego4.png");
	gb->text->nums[5] = mlx_load_png("./images/numbers/lego5.png");
	gb->text->nums[6] = mlx_load_png("./images/numbers/lego6.png");
	gb->text->nums[7] = mlx_load_png("./images/numbers/lego7.png");
	gb->text->nums[8] = mlx_load_png("./images/numbers/lego8.png");
	gb->text->nums[9] = mlx_load_png("./images/numbers/lego9.png");
	gb->text->nums[10] = NULL;
	// error check
}

void	init_patrol_sprite(t_gameboard *gb)
{
	gb->text->patrol = malloc(sizeof(mlx_texture_t *) * 20);
	if (!gb->text->patrol)
		ft_printf("malloc error");
	gb->text->patrol[0] = mlx_load_png("./images/patrol1/1.png");
	gb->text->patrol[1] = mlx_load_png("./images/patrol1/3.png");
	gb->text->patrol[2] = mlx_load_png("./images/patrol1/5.png");
	gb->text->patrol[3] = mlx_load_png("./images/patrol1/7.png");
	gb->text->patrol[4] = mlx_load_png("./images/patrol1/9.png");
	gb->text->patrol[5] = mlx_load_png("./images/patrol1/11.png");
	gb->text->patrol[6] = mlx_load_png("./images/patrol1/13.png");
	gb->text->patrol[7] = mlx_load_png("./images/patrol1/15.png");
	gb->text->patrol[8] = mlx_load_png("./images/patrol1/17.png");
	gb->text->patrol[9] = mlx_load_png("./images/patrol1/19.png");
	gb->text->patrol[10] = mlx_load_png("./images/patrol1/21.png");
	gb->text->patrol[11] = mlx_load_png("./images/patrol1/23.png");
	gb->text->patrol[12] = mlx_load_png("./images/patrol1/25.png");
	gb->text->patrol[13] = mlx_load_png("./images/patrol1/27.png");
	gb->text->patrol[15] = mlx_load_png("./images/patrol1/29.png");
	gb->text->patrol[17] = mlx_load_png("./images/patrol1/31.png");
	gb->text->patrol[18] = mlx_load_png("./images/patrol1/33.png");
	gb->text->patrol[19] = NULL;
	// error check
}

void	init_coll_sprite(t_gameboard *gb)
{
	gb->text->coll = malloc(sizeof(mlx_texture_t *) * 17);
	if (!gb->text->coll)
		ft_printf("malloc error");

	gb->text->coll[0] = mlx_load_png("./images/bricks/3.png");
	gb->text->coll[1] = mlx_load_png("./images/bricks/3.png");
	gb->text->coll[2] = mlx_load_png("./images/bricks/4.png");
	gb->text->coll[3] = mlx_load_png("./images/bricks/4.png");
	gb->text->coll[4] = mlx_load_png("./images/bricks/5.png");
	gb->text->coll[5] = mlx_load_png("./images/bricks/5.png");
	gb->text->coll[6] = mlx_load_png("./images/bricks/6.png");
	gb->text->coll[7] = mlx_load_png("./images/bricks/6.png");
	gb->text->coll[8] = mlx_load_png("./images/bricks/7.png");
	gb->text->coll[9] = mlx_load_png("./images/bricks/7.png");
	gb->text->coll[10] = mlx_load_png("./images/bricks/6.png");
	gb->text->coll[11] = mlx_load_png("./images/bricks/6.png");
	gb->text->coll[12] = mlx_load_png("./images/bricks/5.png");
	gb->text->coll[13] = mlx_load_png("./images/bricks/5.png");
	gb->text->coll[14] = mlx_load_png("./images/bricks/4.png");
	gb->text->coll[15] = mlx_load_png("./images/bricks/4.png");
	gb->text->coll[16] = NULL;
	// error check
}

void	init_player_sprite(t_gameboard *gb)
{
	gb->text->player = malloc(sizeof(mlx_texture_t *) * 7);
	if (!gb->text->player)
		ft_printf("malloc error");

	gb->text->player[0] = mlx_load_png("./images/player/flashman64.png");
	gb->text->player[1] = mlx_load_png("./images/player/flashman64r.png");
	gb->text->player[2] = mlx_load_png("./images/player/flashman64black.png");
	gb->text->player[3] = mlx_load_png("./images/player/flashman64blackr.png");
	gb->text->player[4] = mlx_load_png("./images/player/flashman64grey.png");
	gb->text->player[5] = mlx_load_png("./images/player/flashman64greyr.png");
	gb->text->player[6] = NULL;

	// error check
}
