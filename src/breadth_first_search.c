/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   breadth_first_search.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ccaljouw <ccaljouw@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/26 10:40:37 by ccaljouw      #+#    #+#                 */
/*   Updated: 2023/01/26 11:14:35 by ccaljouw      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_coord(t_gameboard *gb, t_pos *pos)
{
	if (gb->map->arr[pos->y][pos->x] == '1')
		return (0);
	if (gb->map->arr[pos->y][pos->x] == 'C')
		gb->map->coll_count += 1;
	if (gb->map->arr[pos->y][pos->x] == 'P')
		gb->map->start_count += 1;
	if (gb->map->arr[pos->y][pos->x] == 'E')
		gb->map->exit_count += 1;
	return (1);
}

int	check_set(t_gameboard *gb, t_list *set, int x, int y)
{
	t_pos	*pos;
	t_list	*list;

	list = set;
	if (x > gb->map->map_width - 1 || y > gb->map->map_height - 1 \
		|| x < 0 || y < 0)
		error(FT_INVMAPW, gb);
	while (list)
	{
		pos = list->content;
		if (x == pos->x && y == pos->y)
			return (1);
		list = list->next;
	}
	return (0);
}

int	check_neighbor(t_gameboard *gb, t_list **reached, int x, int y)
{
	t_pos	*pos;

	if (!check_set(gb, *reached, x, y))
	{
		pos = malloc(sizeof(t_pos));
		if (!pos)
			error(FT_MEMFAIL, NULL);
		pos->x = x;
		pos->y = y;
		ft_lstadd_back(reached, ft_lstnew(pos));
		if (check_coord(gb, pos))
			return (1);
	}
	return (0);
}

void	bfs(t_gameboard *gb, t_list *frontier, t_list *reached)
{
	t_pos	*pos;
	t_list	*temp;

	if (!frontier)
		return ;
	pos = frontier->content;
	if (check_neighbor(gb, &reached, pos->x + 1, pos->y))
		ft_lstadd_back(&frontier, ft_lstnew(ft_lstlast(reached)->content));
	if (check_neighbor(gb, &reached, pos->x - 1, pos->y))
		ft_lstadd_back(&frontier, ft_lstnew(ft_lstlast(reached)->content));
	if (check_neighbor(gb, &reached, pos->x, pos->y + 1))
		ft_lstadd_back(&frontier, ft_lstnew(ft_lstlast(reached)->content));
	if (check_neighbor(gb, &reached, pos->x, pos->y - 1))
		ft_lstadd_back(&frontier, ft_lstnew(ft_lstlast(reached)->content));
	temp = frontier;
	frontier = frontier->next;
	free(temp);
	bfs(gb, frontier, reached);
}

int	check_map(t_gameboard *gb, int x, int y)
{
	t_list	*frontier;
	t_list	*reached;
	t_pos	*pos;

	pos = malloc(sizeof(pos));
	if (!pos)
		error(FT_MEMFAIL, gb);
	pos->x = x;
	pos->y = y;
	frontier = NULL;
	reached = NULL;
	ft_lstadd_back(&reached, ft_lstnew(pos));
	ft_lstadd_back(&frontier, ft_lstnew(pos));
	bfs(gb, frontier, reached);
	ft_lstclear(&reached, delete_content);
	return (1);
}
