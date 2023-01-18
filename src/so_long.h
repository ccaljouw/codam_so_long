/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/18 10:02:51 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

typedef struct s_textures
{
	mlx_texture_t	*empty;
	mlx_texture_t	*wall;
	mlx_texture_t	*side;
	mlx_texture_t	*bricks_to_get;
	mlx_texture_t	*moves_title;
	mlx_texture_t	*enemy;
	mlx_texture_t	*pl;
	mlx_texture_t	*plr;
	mlx_texture_t	*pll;
	mlx_texture_t	*exit_open;
}	t_textures;

typedef struct s_images
{	
	mlx_image_t		*background;
	mlx_image_t		*wall;
	mlx_image_t		*side;
	mlx_image_t		*side_text;
	mlx_image_t		*moves_count;
	mlx_image_t		*coll_count;
	mlx_image_t		*coll;
	mlx_image_t		*exit;
	mlx_image_t		*pl;
	mlx_image_t		*enemy;
}	t_images;

typedef struct s_map
{
	char		**arr;
	int			map_width;
	int			map_height;
}	t_map;

typedef struct s_player
{
	mlx_texture_t	**player_l;
	mlx_texture_t	**player_r;
	char			cur_dir;
	int				x_pos;
	int				y_pos;
	int				x_npos;
	int				y_npos;
}	t_player;

typedef struct s_gameboard
{
	t_map			*map;
	t_images		*imgs;
	t_textures		*text;
	mlx_t			*mlx;
	t_player		*player;
	mlx_texture_t	**nums;
	int				coll;
	int				moves;
	int				width;
	int				height;
} 	t_gameboard;

t_gameboard	*init_gameboard(t_map *map);
t_map		*init_map(char *file);
t_player	*init_player(void);
void		init_window(t_gameboard *gb);
void		render_map(t_gameboard *gb, int x, int y);
void		key_hook(struct mlx_key_data keypress, void *param);
int 		check_map_pos(t_gameboard *gb, int map_x, int map_y);
void		change_direction(keys_t key, t_images *imgs, t_textures *text);
void		get_collectable(t_gameboard *gb, int map_x, int map_y);
void		move_player(t_gameboard *gb);
void		init_num_sprite(t_gameboard *gb);
void		set_collectable_score(int coll_count, t_gameboard *gb);
void		set_movescore(int moves, t_gameboard *gb);
void		init_player_left_sprite(t_player *player);
void		init_player_right_sprite(t_player *player);
#endif
