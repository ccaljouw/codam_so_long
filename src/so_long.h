/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/20 19:50:05 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "MLX42.h"

// The error codes used to idenfity the correct error message.
typedef enum s_errno
{
	FT_SUCCESS = 0,	// No Errors
	FT_NOFILE,		// No file provided as program argument.
	FT_INVEXT,		// File has an invalid extension.
	FT_INVFILE,		// File was invalid / does not exist.
	FT_INVPNG,		// Something is wrong the given PNG file.
	FT_INVPOS,		// The specified X/Y positions are out of bounds.
	FT_INVIMG,		// The provided image is invalid, might indicate mismanagement of images.
	FT_MEMFAIL,		// Dynamic memory allocation has failed.
	FT_WINFAIL,		// Failed to create a window.
	FT_ARRTOBIG,	// The array is too big to be drawn.
	FT_INVMAPSH,	// Invallid map: not rectangular.
	FT_INVMAPW,		// Invallid map: not enclosed.
	FT_INVMAPC,		// Invallid map: no collectables.
	FT_INVMAPP,		// Invallid map: no startposition / more than one start position.
	FT_INVMAPE,		// Invallid map: no exit / more than one exit.
	FT_INVMAPR,		// Invallid map: no valid path.
	FT_INVMAPCH,	// Invallid map: invallid character in map.
	FT_ERRMAX,		// Error count.
	
}	t_errno;

typedef struct s_textures
{
	mlx_texture_t	**player;
	mlx_texture_t	**patrol;
	mlx_texture_t	**nums;
	mlx_texture_t	*side;
	mlx_texture_t	*lives_title;
	mlx_texture_t	*moves_title;
	mlx_texture_t	*empty;
	mlx_texture_t	*coll;
	mlx_texture_t	*wall;
	mlx_texture_t	*enemy;
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_closed;
}	t_textures;

typedef struct s_sprites
{
	int				patrol;
	int				player;
}	t_sprites;

typedef struct s_images
{	
	mlx_image_t		*background;
	mlx_image_t		*patrol;
	mlx_image_t		*wall;
	mlx_image_t		*side;
	mlx_image_t		*coll;
	mlx_image_t		*exit;
	mlx_image_t		*pl;
	mlx_image_t		*side_text;
	mlx_image_t		*moves_count;
	mlx_image_t		*lives_count;
	t_sprites		*sprites;
}	t_images;

typedef struct s_map
{
	char		**arr;
	int			map_width;
	int			map_height;
	int			coll_count;
	int			start_count;
	int			exit_count;
}	t_map;

typedef struct s_pos
{
	int	x;
	int y;
}	t_pos;

typedef struct s_player
{
	int				lives;
	int				x_pos;
	int				y_pos;
	int				x_npos;
	int				y_npos;
}	t_player;

typedef struct s_gameboard
{
	char			**errors;
	t_map			*map;
	t_images		*imgs;
	t_textures		*text;
	mlx_t			*mlx;
	t_player		*player;
	t_player		*patrol;
	int				coll;
	int				moves;
	int				width;
	int				height;
} 	t_gameboard;

t_gameboard	*init_gameboard(void);
void		init_map(char *file, t_gameboard *gb);
void		init_window(t_gameboard *gb);
void		init_images(t_gameboard *gb);
void		init_textures(t_gameboard *gb);
void		init_characters(t_gameboard *gb);
void		render_window(t_gameboard *gb);
void		init_num_sprite(t_gameboard *gb);
void		init_player_sprite(t_gameboard *gb);
void		init_patrol_sprite(t_gameboard *gb);
void		init_coll_sprite(t_gameboard *gb);
void		render_map(t_gameboard *gb, int x, int y);
void		key_hook(struct mlx_key_data keypress, void *param);
void		hook(void *param);
int 		check_map_pos(t_gameboard *gb, int map_x, int map_y);
void		change_direction(keys_t key, t_images *imgs, t_textures *text);
void		get_collectable(t_gameboard *gb, int map_x, int map_y);
void		hit_patrol(t_gameboard *gb);
void		move_player(t_gameboard *gb, mlx_image_t *image);
void		set_movescore(int moves, t_gameboard *gb);
int			check_map(t_gameboard *gb, int x, int y);
void		error(t_errno val, t_gameboard *gb);
void		end_game(t_gameboard *gb, int result);
void		free_all(t_gameboard *gb);
void		delete_content(void *param);
#endif
