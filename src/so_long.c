/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   so_long.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/10 12:05:38 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/20 20:06:48 by cariencaljo   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*error_msg(t_errno val)
{
	static char *message[FT_ERRMAX];

	if (val > FT_ERRMAX)
		return ("Error index out of bound");
	if (val < 0)
		return ("Error index must be positive");
	message[0] = "No Errors";
	message[1] = "No file provided as program argument.";
	message[2] = "File has an invalid extension.";
	message[3] = "File was invalid / does not exist.";
	message[4] = "Something is wrong the given PNG file.";
	message[5] = "The specified X/Y positions are out of bounds.";
	message[6] = "The provided image is invalid, might indicate mismanagement of images.";
	message[7] = "Dynamic memory allocation has failed.";
	message[8] = "Failed to create a window.";
	message[9] = "The array is too big to be drawn.";
	message[10] = "Invallid map: not rectangular.";
	message[11] = "Invallid map: not enclosed.";
	message[12] = "Invallid map: no collectables.";
	message[13] = "Invallid map: no startposition / more than one start position.";
	message[14] = "Invallid map: no exit / more than one exit.";
	message[15] = "Invallid map: no valid path.";
	message[16] = "Invallid map: invallid character in map.";
	return (message[val]);
};

void	error(t_errno val, t_gameboard *gb)
{
	if (val == 0)
		return ;
	ft_printf("\nError\n%s\n\n", error_msg(val));
	free_all(gb);
	exit (1);
};

int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 2)
		error(FT_NOFILE, NULL);
	// change check to look from end of file
	while (argv[1][i] != '.')
		i++;
	if (ft_strncmp(argv[1] + i, ".ber", 5) != 0)
		error(FT_INVEXT, NULL);
	return (MLX_SUCCESS);
}

t_gameboard	*init_gameboard(void)
{	
	t_gameboard	*gb;
	
	gb = malloc(sizeof(t_gameboard));
	if (!gb)
		error(FT_MEMFAIL, NULL);
	gb->moves = 0;
	gb->coll = 0;
	return (gb);
}

int	main(int argc, char **argv)
{	
	t_gameboard	*gb;

	check_input(argc, argv);
	gb = init_gameboard();
	init_map(argv[1], gb);
	init_textures(gb);
	init_window(gb); // 1 leak, no malloc only mlx_init??
	init_images(gb);
	init_characters(gb);
	render_window(gb); // leaks in linked lists
	mlx_loop_hook(gb->mlx, hook, gb); // 1 leak
	mlx_key_hook(gb->mlx, key_hook, gb);
	mlx_loop(gb->mlx); // 1 leak
	mlx_terminate(gb->mlx); 
	system("leaks home");
	return (0);
}
