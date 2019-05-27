/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 21:44:47 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 15:30:19 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort_flags(t_stk **stk)
{
	t_stk	*tmp;

	tmp = *stk;
	while (tmp)
	{
		if (tmp->sorted == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		check_swap(t_stk **stk_a, t_stk **stk_b, int size)
{
	int		before;
	int		after;
	
	before = get_sorted_count(*stk_a, find_best_stk(*stk_a, size), size);
	swap_stk(stk_a);
	after = get_sorted_count(*stk_a, find_best_stk(*stk_a, size), size);
	swap_stk(stk_a);
	if (after > before)
		return (1);
	return (0);
}


int				get_index_first_sorted(t_stk **stk_a)
{
	t_stk	*tmp;

	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->sorted)
			return (tmp->index);
		tmp = tmp->next;
	}
	return (-1);
}

int				get_index_last_sorted(t_stk **stk_a)
{
	t_stk	*tmp;
	int		last;

	last = -1;
	tmp = *stk_a;
	while (tmp)
	{
		if (tmp->sorted)
			last = tmp->index;
		tmp = tmp->next;
	}
	return (last);
}

static int		check_push(t_stk **stk_a, t_stk **stk_b, int size)
{
	int		last;
	int		cur;
	int		first;
	int		min;

	if (!stk_b || !*stk_b)
		return (0);
	first = get_index_first_sorted(stk_a);
	last = get_index_last_sorted(stk_a);
	min = get_min_index(stk_a);
	cur  = (*stk_b)->index;
	if (first > cur && cur > last)
		return (1);
	if (cur < first && first == min)
		return (1);
	return (0);
}

void	move_unsorted(t_stk **stk_a, t_stk **stk_b, char **res, int size)
{
	while (!(check_sort_flags(stk_a)))
	{
		if (check_swap(stk_a, stk_b, size))
		{
			sa(stk_a, stk_b, res);
			mark_stk(*stk_a, size);
		}
		else if (check_push(stk_a, stk_b, size))
		{
			pa(stk_a, stk_b, res);
			(*stk_a)->sorted = 1;
		}
		else if ((*stk_a)->sorted == 0)
			pb(stk_a, stk_b, res);
		else
			ra(stk_a, stk_b, res);
	}
}
