/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:12:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/24 14:14:16 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "MLX42.h"
# define SIZE 64		//pixel widht and hight per map position
# define SIDE 128		//pixel widht of sidebar

/**
*  The error codes used to idenfity the correct error message.
* @param FT_SUCCESS No Errors
* @param FT_NOFILE No file provided as program argument.
* @param FT_INVEXT File has an invalid extension.
* @param FT_INVFILE File was invalid / does not exist.
* @param FT_INVPNG Something is wrong the given PNG file.
* @param FT_INVPOS The specified X/Y positions are out of bounds.
* @param FT_INVIMG The provided image is invalid.
* @param FT_MEMFAIL Dynamic memory allocation has failed.
* @param FT_WINFAIL Failed to create a window.
* @param FT_ARRTOBIG The array is too big to be drawn.
* @param FT_INVMAPSH Invallid map: not rectangular.
* @param FT_INVMAPW Invallid map: not enclosed.
* @param FT_INVMAPC Invallid map: no collectables.
* @param FT_INVMAPP Invallid map: no or more than one start position.
* @param FT_INVMAPE Invallid map: no exit / more than one exit.
* @param FT_INVMAPR Invallid map: no valid path.
* @param FT_INVMAPCH Invallid map: invallid character in map.
* @param FT_ERRMAX Error count.
*/

typedef enum s_errno
{
	FT_SUCCESS = 0,
	FT_NOFILE,
	FT_INVEXT,
	FT_INVFILE,
	FT_INVPNG,
	FT_INVPOS,
	FT_INVIMG,
	FT_MEMFAIL,
	FT_WINFAIL,
	FT_ARRTOBIG,
	FT_INVMAPSH,
	FT_INVMAPW,
	FT_INVMAPC,
	FT_INVMAPP,
	FT_INVMAPE,
	FT_INVMAPR,
	FT_INVMAPCH,
	FT_ERRMAX,
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
	mlx_texture_t	*exit_open;
	mlx_texture_t	*exit_closed;
	mlx_texture_t	*test;
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
	int	y;
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
}	t_gameboard;

t_gameboard	*init_gameboard(void);
void		init_map(char *file, t_gameboard *gb);
void		init_window(t_gameboard *gb);
void		init_images(t_gameboard *gb);
void		init_textures(t_gameboard *gb);
void		init_characters(t_gameboard *gb);
void		render_map(t_gameboard *gb, int x, int y);
void		render_window(t_gameboard *gb);
int			check_coord(t_gameboard *gb, t_pos *pos);
void		init_num_sprite(t_gameboard *gb);
void		init_player_sprite(t_gameboard *gb);
void		init_patrol_sprite(t_gameboard *gb);
void		key_hook(struct mlx_key_data keypress, void *param);
void		frame_hook(void *param);
int			check_map_pos(t_gameboard *gb, int map_x, int map_y);
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
void		free_sprite(mlx_texture_t **sprite);
void		free_textures(t_textures *text);
void		free_images(t_images *imgs);
#endif
