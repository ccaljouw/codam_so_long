/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 10:47:32 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 17:57:09 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_content(void *param)
{
	t_pos	*content;

	content = param;
	if (content)
		free(content);
}

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
	ft_printf("\nError\n%s\n\n", error_msg(val));
	free_all(gb);
	exit (val);
}
