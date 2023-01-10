/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 09:17:03 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:08:50 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

// NAME
//      isalnum -- alphanumeric character test

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <ctype.h>
//      int     isalnum(int c);

// DESCRIPTION
//      The isalnum() function tests for any character for which isalpha(3) or
// 		 isdigit(3) is true.  The value of the argument must be repre-
//      sentable as an unsigned char or the value of EOF.

//      In the ASCII character set, this includes the following characters 
// 		(preceded by their numeric values, in octal):

// RETURN VALUES
//      The isalnum() function returns zero if the character tests false and 
// 		returns non-zero if the character tests true.

// COMPATIBILITY
//      The 4.4BSD extension of accepting arguments outside of the range of 
// 		the unsigned char type in locales with large character sets is con-
//      sidered obsolete and may not be supported in future releases.  
// 		The iswalnum() function should be used instead.