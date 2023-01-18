/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameboard.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/18 09:51:17 by cariencaljo   ########   odam.nl         */
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
	text->side = mlx_load_png("./images/black.png");
	text->bricks_to_get = mlx_load_png("./images/bricks.png");
	text->moves_title = mlx_load_png("./images/moves.png");
	text->pl = mlx_load_png("./images/flashman64.png");
	text->pll = mlx_load_png("./images/flashman64.png");
	text->plr = mlx_load_png("./images/flashman64r.png");
	text->exit_open = mlx_load_png("./images/exito.png");
	if (!text->empty || !text->wall || !text->pll || !text->plr || !text->exit_open) //expand
		ft_printf("error loading textures");
	return (text);
}

void	init_images(mlx_t *mlx, t_textures *text, t_gameboard *gb)
{
	t_images	*imgs;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
		ft_printf("error initiating ims"); 													//handle with error message and exit
	imgs->coll = mlx_texture_to_image(mlx, mlx_load_png("./images/coll64.png"));
	imgs->exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exitc.png"));
	imgs->pl = mlx_texture_to_image(mlx, text->pl);
	imgs->side = mlx_new_image(mlx, text->empty->width * 3, gb->height);
	imgs->side_text = mlx_new_image(mlx, text->bricks_to_get->width, gb->height);
	imgs->moves_count = mlx_new_image(mlx, gb->nums[0]->width * 4, gb->nums[0]->height);
	imgs->coll_count = mlx_new_image(mlx, gb->nums[0]->width * 4, gb->nums[0]->height);
	imgs->wall = mlx_new_image(mlx, gb->width, gb->height);
	imgs->background = mlx_new_image(mlx, gb->width, gb->height);
	if (!imgs->background || !imgs->wall || !imgs->pl || !imgs->coll \
									|| !imgs->exit)
		ft_printf("error loading images");
	gb->imgs = imgs;
}

t_gameboard	*init_gameboard(t_map *map)
{	
	t_gameboard	*gb;
	
	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		return (NULL);											//handle with error message and exit
	gb->text = init_textures();
	gb->player = init_player();
	gb->map = map;
	gb->moves = 0;
	gb->coll = 0;
	gb->width = gb->map->map_width * gb->text->empty->width;
	gb->height = gb->map->map_height * gb->text->empty->height;
	gb->mlx = mlx_init(gb->width + (gb->text->empty->width * 3), gb->height, "So long!", false);
	if (!gb->mlx)
		exit(EXIT_FAILURE);											//handle with error message and exit
	init_num_sprite(gb);
	init_images(gb->mlx, gb->text, gb);
	return (gb);
}
