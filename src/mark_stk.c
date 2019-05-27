/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mark_stk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcase <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 14:44:54 by tcase             #+#    #+#             */
/*   Updated: 2019/05/27 13:42:02 by tcase            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		index_stk(t_stk *stk, int size)
{
	int		index;
	int		min;
	t_stk	*tmp;
	t_stk	*cur;

	index = 0;
	while (index < size)
	{
		min = INT_MAX;
		tmp = stk;
		while (tmp)
		{
			if (tmp->num <= min && tmp->index == -1)
			{
				min = tmp->num;
				cur = tmp;
			}
			tmp = tmp->next;
		}
		cur->index = index;
		index++;
	}
}

int			get_sorted_count(t_stk *stk, t_stk *tstk, int size)
{
	t_stk	*tmp;
	int		i;
	int		cur;

	i = 0;
	tmp = tstk;
	cur = tmp->index;
//	while (size--)
//	{
//		if (cur == tmp->index)
//		{
//			cur++;
//			i++;
//		}
//		if (tmp->next)
//			tmp = tmp->next;
//		else
//			tmp = stk;
//	}
	while (size--)
	{
		if (cur < tmp->index)
		{
			cur = tmp->index;
			i++;
		}
		if (tmp->next)
			tmp = tmp->next;
		else
			tmp = stk;
	}
	return (i);
}

t_stk		*find_best_stk(t_stk *stk, int size)
{
	t_stk	*tmp;
	t_stk	*prev;
	t_stk	*best;
	int		max;
	int		i;

	max = 0;
	best = NULL;
	tmp = stk;
	while (tmp)
	{
		i = get_sorted_count(stk, tmp, size);
		if (i > max)
		{
			max = i;
			best = tmp;
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (best == NULL ? prev : best);
}

static void	clear_sorted_flags(t_stk *stk)
{
	t_stk	*tmp;

	tmp = stk;
	while (tmp)
	{
		tmp->sorted = 0;
		tmp = tmp->next;
	}
}

void		mark_stk(t_stk *stk, int size)
{
	t_stk	*cur;
	t_stk	*next;
	t_stk	*best;
	int		index;

clear_sorted_flags(stk);
best = find_best_stk(stk, size);
cur = best;
//	index = best->index;
//	while (size--)
//	{
//		if (cur->next != NULL)
//			next = cur->next;
//		else
//			next = stk;
//		if (cur->index == index + 1)
//		{
//			cur->sorted = 1;
//			index++;
//		}
//		cur = next;
//	}
	index = -1;
	while (size--)
	{
		if (cur->next != NULL)
			next = cur->next;
		else
			next = stk;
		if (cur->index < next->index && index == -1)
		{
			index = cur->index;
			cur->sorted = 1;
		}
		if (index < next->index && index != -1 && (index = next->index))
			next->sorted = 1;
		cur = next;
	}
}
