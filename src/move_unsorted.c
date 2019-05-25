/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_unsorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 21:44:47 by tcase             #+#    #+#             */
/*   Updated: 2019/05/25 21:47:48 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		check_sort_flags(t_stk **stk)
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

static int		check_swap(t_stk **stk_a, t_stk **stk_b, char **res, int size)
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

void	move_unsorted(t_stk **stk_a, t_stk **stk_b, char **res, int size)
{
	while (!(check_sort_flags(stk_a)))
	{
		if (check_swap(stk_a, stk_b, res, size))
			sa(stk_a, stk_b, res);
		else if ((*stk_a)->sorted == 0)
			pb(stk_a, stk_b, res);
		else
			ra(stk_a, stk_b, res);
		mark_stk(*stk_a, size);
	}
}
