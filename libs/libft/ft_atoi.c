/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 09:25:50 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/10 13:13:31 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	val;
	int	sign;

	val = 0;
	sign = 1;
	if (*str != '\0')
	{
		while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' \
			|| *str == '\f' || *str == '\r')
			str++;
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				sign *= -1;
			str++;
		}
		while (*str >= '0' && *str <= '9')
		{
			val *= 10;
			val += *str - '0';
			str++;
		}
	}
	return (val * sign);
}

// NAME

//      atoi, atoi_l -- convert ASCII string to integer

// LIBRARY
//      Standard C Library (libc, -lc)

// SYNOPSIS
//      #include <stdlib.h>
//      int	atoi(const char *str);

//      #include <xlocale.h>
//      int	atoi_l(const char *str, locale_t loc);

// DESCRIPTION
//      The atoi() function converts the initial portion of the string pointed 
// 		to by str to int representation. It is equivalent to:
//            (int)strtol(str, (char **)NULL, 10);
//      While the atoi() function uses the current locale, the atoi_l() 
// 		function may be passed a locale directly. See xlocale(3) for more 
// 		information.

// IMPLEMENTATION NOTES
//      The atoi() and atoi_l() functions are thread-safe and async-cancel-safe.
//      The strtol() and strtol_l() functions are recommended instead of atoi() 
// 		and atoi_l() functions, especially in new code.

// ERRORS
//      The function atoi() need not affect the value of errno on an error.