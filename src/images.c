/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 16:05:30 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/24 13:35:00 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_gameboard *gb)
{
	gb->text = malloc(sizeof(t_textures));
	if (!gb->text)
		error(FT_MEMFAIL, gb);
	gb->text->nums = NULL;
	gb->text->player = NULL;
	gb->text->patrol = NULL;
	gb->text->side = mlx_load_png("./images/red.png");
	gb->text->lives_title = mlx_load_png("./images/lives.png");
	gb->text->moves_title = mlx_load_png("./images/moves.png");
	gb->text->empty = mlx_load_png("./images/green.png");
	gb->text->wall = mlx_load_png("./images/wall.png");
	gb->text->coll = mlx_load_png("./images/bricks/0.png");
	gb->text->exit_open = mlx_load_png("./images/exito.png");
	gb->text->exit_closed = mlx_load_png("./images/exitc.png");
	if (!gb->text->side || !gb->text->lives_title || !gb->text->moves_title \
			|| !gb->text->empty || !gb->text->wall || !gb->text->coll \
			|| !gb->text->exit_open || !gb->text->exit_closed)
		error(FT_INVPNG, gb);
}

void	init_sprites(t_gameboard *gb)
{
	gb->imgs->sprites = malloc(sizeof(t_sprites));
	if (!gb->imgs->sprites)
		error(FT_MEMFAIL, gb);
	gb->imgs->sprites->patrol = 0;
	gb->imgs->sprites->player = 0;
}

void	load_images(t_gameboard *gb)
{
	gb->imgs = malloc(sizeof(t_images));
	if (!gb->imgs)
		error(FT_MEMFAIL, gb);
	gb->imgs->patrol = mlx_new_image(gb->mlx, gb->text->empty->width, \
										gb->text->empty->height);
	gb->imgs->coll = mlx_texture_to_image(gb->mlx, gb->text->coll);
	gb->imgs->exit = mlx_texture_to_image(gb->mlx, gb->text->exit_closed);
	gb->imgs->pl = mlx_texture_to_image(gb->mlx, gb->text->player[0]);
	gb->imgs->side = mlx_new_image(gb->mlx, gb->text->empty->width * 2 \
										, gb->height);
	gb->imgs->side_text = mlx_new_image(gb->mlx, gb->text->empty->width * 2 \
										, gb->height);
	gb->imgs->moves_count = mlx_new_image(gb->mlx, gb->text->nums[0]->width * 3 \
										, gb->text->nums[0]->height);
	gb->imgs->lives_count = mlx_new_image(gb->mlx, gb->text->nums[0]->width, \
										gb->text->nums[0]->height);
	gb->imgs->wall = mlx_new_image(gb->mlx, gb->width, gb->height);
	gb->imgs->background = mlx_new_image(gb->mlx, gb->width, gb->height);
	if (!gb->imgs->patrol || !gb->imgs->coll || !gb->imgs->exit || \
			!gb->imgs->pl || !gb->imgs->side || !gb->imgs->side_text \
			|| !gb->imgs->moves_count || !gb->imgs->lives_count || \
			!gb->imgs->wall || !gb->imgs->background)
		error(FT_INVIMG, gb);
	init_sprites(gb);
}

void	init_images(t_gameboard *gb)
{
	init_num_sprite(gb);
	init_patrol_sprite(gb);
	init_player_sprite(gb);
	load_images(gb);
}
