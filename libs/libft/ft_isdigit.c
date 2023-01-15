/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 16:35:59 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/14 10:09:22 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// NAME  isdigit, isnumber -- decimal-digit character test
// SYNOPSIS
//      #include <ctype.h>
//      int isdigit(int c);
//      int isnumber(int c);

// DESCRIPTION
//      The isdigit() function tests for a decimal digit character.  
//		Regardless of locale, this includes the following characters only:
//      ``0''         ``1''         ``2''         ``3''         ``4''
//      ``5''         ``6''         ``7''         ``8''         ``9''
//      The isnumber() function behaves similarly to isdigit(), but may 
// 		recognize additional characters, depending on the current locale 
// 		setting.
//      The value of the argument must be representable as an unsigned char 
// 		or the value of EOF.

// RETURN VALUES
//      The isdigit() and isnumber() functions return zero if the character 
// 		tests false and return non-zero if the character tests true.