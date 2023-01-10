/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: anonymous <anonymous@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/15 21:28:47 by anonymous     #+#    #+#                 */
/*   Updated: 2022/10/20 11:34:32 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write (fd, s, ft_strlen(s));
}

// Parameters       s: The string to output.
//                  fd: The file descriptor on which to write.
// Return value     None
// External functs. write
// 
// Description Outputs the string ’s’ to the given file descriptor.