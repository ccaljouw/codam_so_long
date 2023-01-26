/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 10:47:32 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 11:26:02 by ccaljouw      ########   odam.nl         */
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
