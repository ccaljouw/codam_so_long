/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cariencaljouw <cariencaljouw@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/21 16:56:25 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/12/01 12:43:31 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <limits.h>
# include "../libft.h"

// struct to store flags
typedef struct s_print
{
	va_list	args;
	int		s;
	char	type;
	int		pound;
	int		zero;
	int		plus;
	int		min;
	int		sp;
	int		width;
	int		dot;
	int		strlim;
	int		tl;
	int		vl;
	char	s_1;
	int		neg;
	int		start;
	int		with_sign;
}	t_print;
int		ft_printf(const char *str, ...);

//mandatory
void	ft_write_args(t_print *tp);
char	*ft_itoa_base_u(unsigned long n, char *base, t_print *tp);
char	*ft_itoa_base(long long n, char *base, t_print *tp);

// bonus
t_print	*ft_flags_tp(t_print	*tp, int reset);
char	*ft_processflags(char *str, t_print *tp);
char	*ft_starti(char *str, t_print *tp);
char	*ft_sign(char *str, t_print *tp);

#endif