/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:09:44 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/18 14:44:59 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// if srcl < dstl copy from back to front else from front to back.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*csrc;
	unsigned char		*cdst;

	if (dst == src || len == 0)
		return (dst);
	cdst = (unsigned char *) dst;
	csrc = (unsigned char *) src;
	if (cdst < csrc)
		ft_memcpy(cdst, csrc, len);
	else
		while (len-- > 0)
			cdst[len] = csrc[len];
	return (dst);
}

// NAME
//      memmove -- copy byte string
// LIBRARY
//      Standard C Library (libc, -lc)
// SYNOPSIS
//      #include <string.h>
//      void *memmove(void *dst, const void *src, size_t len);
// DESCRIPTION
//      The memmove() function copies len bytes from string src to string dst.
// 		The two strings may overlap; the copy is always done in a non-
//      destructive manner.
// RETURN VALUES
//      The memmove() function returns the original value of dst.
// SEE ALSO
//      bcopy(3), memccpy(3), memcpy(3), strcpy(3), wmemmove(3)