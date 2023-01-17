/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   gameboard.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/17 09:34:37 by cariencaljo   #+#    #+#                 */
/*   Updated: 2023/01/17 14:27:26 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_textures	*init_textures(void)
{
	t_textures	*text;

	text = malloc(sizeof(t_textures));
	if (!text)
		return (NULL);						//handle with error message
	text->empty = mlx_load_png("./images/green.png");
	text->wall = mlx_load_png("./images/wall.png");
	text->side = mlx_load_png("./images/yellow.png");
	text->bricks_to_get = mlx_load_png("./images/bricks256.png");
	text->moves_title = mlx_load_png("./images/moves.png");
	text->pl = mlx_load_png("./images/flashman64.png");
	text->pll = mlx_load_png("./images/flashman64.png");
	text->plr = mlx_load_png("./images/flashman64r.png");
	text->num_0 = mlx_load_png("./images/lego0.png");
	text->num_1 = mlx_load_png("./images/lego1.png");
	text->num_2 = mlx_load_png("./images/lego2.png");
	text->num_3 = mlx_load_png("./images/lego3.png");
	text->num_4 = mlx_load_png("./images/lego4.png");
	text->num_5 = mlx_load_png("./images/lego5.png");
	text->num_6 = mlx_load_png("./images/lego6.png");
	text->num_7 = mlx_load_png("./images/lego7.png");
	text->num_8 = mlx_load_png("./images/lego8.png");
	text->num_9 = mlx_load_png("./images/lego9.png");
	if (!text->empty || !text->wall || !text->pll || !text->plr) //expand
		ft_printf("error loading textures");
	return (text);
}

void	init_images(mlx_t *mlx, t_textures *text, t_map *map, t_gameboard *gb)
{
	t_images	*imgs;

	imgs = malloc(sizeof(t_images));
	if (!imgs)
		ft_printf("error initiating ims"); 													//handle with error message and exit
	imgs->coll = mlx_texture_to_image(mlx, mlx_load_png("./images/coll64.png"));
	imgs->exit = mlx_texture_to_image(mlx, mlx_load_png("./images/exit64.png"));
	imgs->pl = mlx_texture_to_image(mlx, text->pl);
	imgs->side = mlx_new_image(mlx, text->bricks_to_get->width, \
									map-> map_height * text->empty->height);
	imgs->side_text = mlx_new_image(mlx, text->bricks_to_get->width, \
									map-> map_height * text->empty->height);
	imgs->wall = mlx_new_image(mlx, map->map_width * text->empty->width, \
									map-> map_height * text->empty->height);
	imgs->background = mlx_new_image(mlx, map->map_width * text->empty->width, \
									map-> map_height * text->empty->height);
	if (!imgs->background || !imgs->wall || !imgs->pl || !imgs->coll \
									|| !imgs->exit)
		ft_printf("error loading images");
	gb->imgs = imgs;
}


t_gameboard	*init_gameboard(t_map *map)
{	
	t_textures	*text;
	t_player	*player;
	t_gameboard	*gb;
	int			title_h;

	title_h = 64 * 4;
	text = init_textures();
	player = init_player();
	gb = malloc(sizeof(t_gameboard));
	if (!gb || !text || !map || !player)
		return (NULL);											//handle with error message and exit
	gb->player = player;
	gb->text = text;
	gb->map = map;
	gb->moves = 0;
	gb->moves = 0;
	gb->mlx = mlx_init((gb->map->map_width * text->empty->width) \
		+ title_h, (gb->map->map_height * text->empty->height), \
		"So long!\t\t\tmoves: 0", false);
	if (!gb->mlx)
		exit(EXIT_FAILURE);											//handle with error message and exit
	init_images(gb->mlx, gb->text, gb->map, gb);
	return (gb);
}
