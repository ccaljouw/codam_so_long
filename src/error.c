/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/20 13:33:52 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/20 15:05:42 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdlib.h>

// Description of the error codes
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
	return (message[val]);
};

void	error(t_errno val, t_gameboard *gb)
{
	if (val == 0)
		return ;
	ft_printf("\nError\n%s\n\n", error_msg(val));
	if (gb)
		ft_printf("Free gb!!");
	exit (1);
};

