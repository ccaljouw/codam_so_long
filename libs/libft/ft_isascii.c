/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 10:01:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:09:12 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{	
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

// NAME
//      isascii -- test for ASCII character

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <ctype.h>
//      int   isascii(int c);

// DESCRIPTION
//      The isascii() function tests for an ASCII character, which is any 
// 		character between 0 and octal 0177 inclusive.