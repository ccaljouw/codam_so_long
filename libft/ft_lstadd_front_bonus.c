/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/19 11:19:26 by ccaljouw      #+#    #+#                 */
/*   Updated: 2022/10/19 13:50:14 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	**temp;

	if (new)
	{
		temp = lst;
		new->next = *temp;
		*lst = new;
	}
}
