/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 14:29:51 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/18 15:01:37 by cariencaljo   ########   odam.nl         */
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

void	init_fire_sprite(t_gameboard *gb)
{
	gb->text->fire = malloc(sizeof(mlx_texture_t *) * 20);
	if (!gb->text->fire)
		ft_printf("malloc error");
	gb->text->fire[0] = mlx_load_png("./images/fire/1.png");
	gb->text->fire[1] = mlx_load_png("./images/fire/3.png");
	gb->text->fire[2] = mlx_load_png("./images/fire/5.png");
	gb->text->fire[3] = mlx_load_png("./images/fire/7.png");
	gb->text->fire[4] = mlx_load_png("./images/fire/9.png");
	gb->text->fire[5] = mlx_load_png("./images/fire/11.png");
	gb->text->fire[6] = mlx_load_png("./images/fire/13.png");
	gb->text->fire[7] = mlx_load_png("./images/fire/15.png");
	gb->text->fire[8] = mlx_load_png("./images/fire/17.png");
	gb->text->fire[9] = mlx_load_png("./images/fire/19.png");
	gb->text->fire[10] = mlx_load_png("./images/fire/21.png");
	gb->text->fire[11] = mlx_load_png("./images/fire/23.png");
	gb->text->fire[12] = mlx_load_png("./images/fire/25.png");
	gb->text->fire[13] = mlx_load_png("./images/fire/27.png");
	gb->text->fire[15] = mlx_load_png("./images/fire/29.png");
	gb->text->fire[17] = mlx_load_png("./images/fire/31.png");
	gb->text->fire[18] = mlx_load_png("./images/fire/33.png");
	gb->text->fire[19] = NULL;
	// error check
}

void	init_coll_sprite(t_gameboard *gb)
{
	gb->text->coll = malloc(sizeof(mlx_texture_t *) * 17);
	if (!gb->text->nums)
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

