/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:56:21 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/11/09 11:34:56 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_setwidth(t_print *tp, char s)
{
	if (tp->dot == 1)
	{
		if (tp->strlim == -1)
			tp->strlim = 0;
		tp->strlim = (tp->strlim * 10) + (s - '0');
	}
	else
	{
		if (tp->width == -1)
			tp->width = 0;
		tp->width = (tp->width * 10) + (s - '0');
	}
}

int	ft_setflags(t_print *tp, char s)
{
	if (s == '-')
		tp->min = 1;
	else if (s == '.')
		tp->dot = 1;
	else if (s == '#')
		tp->pound = 1;
	else if (s == ' ')
		tp->sp = 1;
	else if (s == '+')
		tp->plus = 1;
	else if (ft_isdigit(s))
		ft_setwidth(tp, s);
	else
		tp->tl = -1;
	if (tp->sp == 1 || tp->plus == 1)
		tp->with_sign = 1;
	return (1);
}

int	ft_format(t_print *tp, const char *str, int i)
{
	while (!ft_strchr("csdiupxX%", str[i]))
	{
		tp->s = str[i];
		i += ft_setflags(tp, str[i]);
	}
	if (ft_strchr("px", str[i]))
		tp->type = 'x';
	if (ft_strchr("X", str[i]))
		tp->type = 'x';
	if (ft_strchr("diu", str[i]))
		tp->type = 'd';
	if (ft_strchr("cs", str[i]))
		tp->type = 's';
	if (ft_strchr("%", str[i]))
		tp->type = '%';
	if (tp->tl == -1)
		return (tp->tl);
	tp->s = str[i];
	if (tp->s == 'p' || (tp->type == 'x' && tp->pound == 1))
		tp->with_sign = 2;
	ft_write_args(tp);
	return (i);
}

int	ft_itterate(const char *str, int i, t_print *tp)
{
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '0')
				tp->zero = 1;
			if (ft_strchr(" +#", str[i]) && str[i + 1] == '0')
				tp->zero = 1;
			if (str[i] == '\0')
				return (tp->tl);
			i = ft_format(tp, str, i);
		}
		else
			tp->tl += write(1, &str[i], 1);
		if (tp->tl == -1)
			return (tp->tl);
		i++;
		ft_flags_tp(tp, 1);
	}
	return (tp->tl);
}

int	ft_printf(const char *str, ...)
{
	t_print			*tp;
	int				i;

	tp = (t_print *)malloc(sizeof(t_print));
	if (tp == NULL)
		return (-1);
	ft_flags_tp(tp, 0);
	va_start(tp->args, str);
	i = 0;
	ft_itterate(str, i, tp);
	i = tp->tl;
	va_end(tp->args);
	free(tp);
	return (i);
}

// You have to recode the printf() function from libc.
// 
// The prototype of ft_printf() is:
// int ft_printf(const char *, ...);
// 
// Here are the requirements:
// 	• Don’t implement the buffer management of the original printf().
// 	• Your function has to handle the following conversions: cspdiuxX%
// 	• Your function will be compared against the original printf().
// 	• You must use the command ar to create your library.
// Using the libtool command is forbidden.
// 	• Your libftprintf.a has to be created at the root of your repository.
// 
// You have to implement the following conversions:
// 	• %c Prints a single character.
// 	• %s Prints a string (as defined by the common C convention).
// 	• %p The void * pointer argument has to be printed in hexadecimal format.
// 	• %d Prints a decimal (base 10) number.
// 	• %i Prints an integer in base 10.
// 	• %u Prints an unsigned decimal (base 10) number.
// 	• %x Prints a number in hexadecimal (base 16) lowercase format.
// 	• %% Prints a percent sign.
// 	• %X Prints a number in hexadecimal (base 16) uppercase format.