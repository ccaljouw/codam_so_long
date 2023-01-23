/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   images.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 16:05:30 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/23 20:40:31 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// what happens if load fails...
void	init_textures(t_gameboard *gb)
{
	t_textures	*text;
	
	text = malloc(sizeof(t_textures));
	if (!text)
		error(FT_MEMFAIL, gb);
	text->side = mlx_load_png("./images/red.png");
	text->lives_title = mlx_load_png("./images/lives.png");
	text->moves_title = mlx_load_png("./images/moves.png");
	text->empty = mlx_load_png("./images/green.png");
	text->wall = mlx_load_png("./images/wall.png");
	text->coll = mlx_load_png("./images/bricks/0.png");
	text->exit_open = mlx_load_png("./images/exito.png");
	text->exit_closed = mlx_load_png("./images/exitc.png");
	gb->text = text;
}

void	init_sprites(t_gameboard *gb)
{
	// free somewhere..	
	gb->imgs->sprites = malloc(sizeof(t_sprites));
	if (!gb->imgs->sprites)
		error(FT_MEMFAIL, gb);
	gb->imgs->sprites->patrol = 0;
	gb->imgs->sprites->player = 0;
}

// what happens if load fails...
void	load_images(t_gameboard *gb)
{
	t_images	*imgs;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
		error(FT_MEMFAIL, gb);
	imgs->patrol = mlx_new_image(gb->mlx, gb->text->empty->width, gb->text->empty->height);
	imgs->coll = mlx_texture_to_image(gb->mlx, gb->text->coll);
	imgs->exit = mlx_texture_to_image(gb->mlx,gb->text->exit_closed);
	imgs->pl = mlx_texture_to_image(gb->mlx,gb-> text->player[0]);
	imgs->side = mlx_new_image(gb->mlx, gb->text->empty->width * 2, gb->height);
	imgs->side_text = mlx_new_image(gb->mlx, gb->text->empty->width * 2, gb->height);
	imgs->moves_count = mlx_new_image(gb->mlx, gb->text->nums[0]->width * 3, gb->text->nums[0]->height);
	imgs->lives_count = mlx_new_image(gb->mlx, gb->text->nums[0]->width, gb->text->nums[0]->height);
	imgs->wall = mlx_new_image(gb->mlx, gb->width, gb->height);
	imgs->background = mlx_new_image(gb->mlx, gb->width, gb->height);
	gb->imgs = imgs;
	init_sprites(gb);
}

void	init_images(t_gameboard *gb)
{
	init_num_sprite(gb);
	init_patrol_sprite(gb);
	init_player_sprite(gb);
	load_images(gb);
}