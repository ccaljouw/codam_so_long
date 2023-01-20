/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameboard.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/20 10:15:15 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	*init_textures()
{
	t_textures	*text;

	text = malloc(sizeof(t_textures));
	if (!text)
		return (NULL);						//handle with error message
	text->empty = mlx_load_png("./images/green.png");
	text->wall = mlx_load_png("./images/wall.png");
	text->side = mlx_load_png("./images/red.png");
	text->bricks_to_get = mlx_load_png("./images/lives.png");
	text->moves_title = mlx_load_png("./images/moves.png");
	text->exit_open = mlx_load_png("./images/exito.png");
	if (!text->empty || !text->wall || !text->exit_open) //expand
		ft_printf("error loading textures");
	return (text);
}

void	init_images(mlx_t *mlx, t_textures *text, t_gameboard *gb)
{
	t_images	*imgs;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
		ft_printf("error initiating ims"); 												//handle with error message and exit
	imgs->patrol = mlx_new_image(mlx, text->empty->width, text->empty->height);
	imgs->coll = mlx_texture_to_image(mlx, mlx_load_png("./images/bricks/0.png"));
	imgs->exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exitc.png"));
	imgs->pl = mlx_texture_to_image(mlx, text->player[0]);
	imgs->side = mlx_new_image(mlx, text->empty->width * 2, gb->height);
	imgs->side_text = mlx_new_image(mlx, text->empty->width * 2, gb->height);
	imgs->moves_count = mlx_new_image(mlx, gb->text->nums[0]->width * 3, gb->text->nums[0]->height);
	imgs->lives_count = mlx_new_image(mlx, gb->text->nums[0]->width, gb->text->nums[0]->height);
	imgs->wall = mlx_new_image(mlx, gb->width, gb->height);
	imgs->background = mlx_new_image(mlx, gb->width, gb->height);
	if (!imgs->background || !imgs->wall || !imgs->pl || !imgs->coll \
									|| !imgs->exit)
		ft_printf("error loading images");
	gb->imgs = imgs;
	gb->imgs->fire_state = 0;
	gb->imgs->col_state = 0;
	gb->patrol->x_pos = 0;
	gb->patrol->y_pos = 0;
}

t_gameboard	*init_gameboard(t_map *map)
{	
	t_gameboard	*gb;
	
	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		return (NULL);											//handle with error message and exit
	gb->text = init_textures();
	gb->player = init_player();
	gb->patrol = init_player();
	gb->player->lives = 3;
	gb->map = map;
	gb->moves = 0;
	gb->coll = 0;
	gb->width = gb->map->map_width * gb->text->empty->width;
	gb->height = gb->map->map_height * gb->text->empty->height;
	gb->mlx = mlx_init(gb->width + (gb->text->empty->width * 2), \
									gb->height, "So long!", false);
	if (!gb->mlx)
		exit(EXIT_FAILURE);											//handle with error message and exit
	init_num_sprite(gb);
	init_patrol_sprite(gb);
	init_coll_sprite(gb);
	init_player_sprite(gb);
	init_images(gb->mlx, gb->text, gb);
	return (gb);
}
