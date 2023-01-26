/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 10:29:52 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*error_msg(t_errno val)
{
	static char	*message[FT_ERRMAX];

	if (val > FT_ERRMAX || val < 0)
		return ("Error index out of bound");
	message[0] = "No Errors";
	message[1] = "No file provided as program argument.";
	message[2] = "File has an invalid extension.";
	message[3] = "File was invalid / does not exist.";
	message[4] = "Something is wrong a PNG file.";
	message[5] = "The specified X/Y positions are out of bounds.";
	message[6] = "The provided image is invalid.";
	message[7] = "Dynamic memory allocation has failed.";
	message[8] = "Failed to create a window.";
	message[9] = "The array is too big to be drawn.";
	message[10] = "Invallid map: not rectangular.";
	message[11] = "Invallid map: not enclosed.";
	message[12] = "Invallid map: no collectables.";
	message[13] = "Invallid map: no or more than one start position.";
	message[14] = "Invallid map: no exit / more than one exit.";
	message[15] = "Invallid map: not rectangular.";
	message[16] = "Invallid map: invalid character in map.";
	message[17] = "Invallid map: no valid path.";
	message[18] = "Invallid map: too big for monitor.";
	return (message[val]);
}

void	error(t_errno val, t_gameboard *gb)
{
	if (val == 0)
		return ;
	ft_printf("\nError\n%s\n\n", error_msg(val));
	free_all(gb);
	exit (val);
}

void	check_args(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		error(FT_NOFILE, NULL);
	while (argv[1][i] != '\0')
		i++;
	if (ft_strncmp(argv[1] + (i - 4), ".ber", 5) != 0)
		error(FT_INVEXT, NULL);
}

t_gameboard	*init_gameboard(void)
{	
	t_gameboard	*gb;

	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		error(FT_MEMFAIL, NULL);
	gb->errors = NULL;
	gb->map = NULL;
	gb->imgs = NULL;
	gb->text = NULL;
	gb->mlx = NULL;
	gb->player = NULL;
	gb->patrol = NULL;
	gb->coll = 0;
	gb->moves = 0;
	gb->width = 0;
	gb->height = 0;
	return (gb);
}

void	system_leaks(void)
{
	system("leaks so_long");
}

int	main(int argc, char **argv)
{	
	t_gameboard	*gb;

	// vallid path check nog working if more than one start position
	// empty map gives error  "file was invallid or does nog exist"
	// check walls on outer boundry of map?
	// change enemy position and movement
	atexit(system_leaks);
	check_args(argc, argv);
	gb = init_gameboard();
	init_map(argv[1], gb);
	init_textures(gb);
	init_window(gb);
	init_images(gb);
	init_characters(gb);
	render_window(gb);
	check_map_content(gb);
	mlx_loop_hook(gb->mlx, frame_hook, gb);
	mlx_key_hook(gb->mlx, key_hook, gb);
	mlx_loop(gb->mlx);
	mlx_terminate(gb->mlx);
	free_all(gb);
	return (0);
}
